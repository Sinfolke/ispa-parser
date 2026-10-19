/* Benchmark driver: flex+bison ISPA parser with AST construction.
 *
 *   ./bench_malloc|bench_arena [-t] [-n iters] [-r reps] file.isc ...
 *
 * 1. Parses each file on its own and reports OK/FAIL (-t also dumps the tree).
 * 2. Concatenates all files, repeated `reps` times, and parses it `iters`
 *    times. Parse time (lex+parse+AST build) and tree release time are
 *    reported separately; input is already in memory.
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ast.h"
#include "lex.yy.h"

int yyparse(void);
static int quiet;

void yyerror(const char *msg) {
    if (!quiet) fprintf(stderr, "  line %d: %s\n", yylineno, msg);
}

static int parse_buf(const char *buf, size_t len) {
    yylineno = 1;
    ast_root = NULL;
    YY_BUFFER_STATE b = yy_scan_bytes(buf, (int)len);
    int rc = yyparse();
    yy_delete_buffer(b);
    return rc;
}

static char *slurp(const char *path, size_t *len) {
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); exit(2); }
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *p = malloc((size_t)n + 1);
    if (fread(p, 1, (size_t)n, f) != (size_t)n) { perror(path); exit(2); }
    fclose(f);
    p[n] = 0;
    *len = (size_t)n;
    return p;
}

static double now(void) {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec * 1e-9;
}

int main(int argc, char **argv) {
    int iters = 1, reps = 1, dump = 0, i = 1;
    for (; i < argc && argv[i][0] == '-'; i++) {
        if (!strcmp(argv[i], "-t")) dump = 1;
        else if (!strcmp(argv[i], "-n") && i + 1 < argc) iters = atoi(argv[++i]);
        else if (!strcmp(argv[i], "-r") && i + 1 < argc) reps = atoi(argv[++i]);
        else { fprintf(stderr, "usage: %s [-t] [-n iters] [-r reps] files...\n", argv[0]); return 2; }
    }
    if (i >= argc) { fprintf(stderr, "no input files\n"); return 2; }

    size_t total = 0;
    char *all = NULL;
    int bad = 0;
    for (int k = i; k < argc; k++) {
        size_t len;
        char *src = slurp(argv[k], &len);
        printf("%-24s ", argv[k]);
        fflush(stdout);
        int rc = parse_buf(src, len);
        if (rc == 0) printf("OK (%ld nodes)\n", ast_nodes);
        else puts("FAIL");
        if (rc == 0 && dump) ast_dump(ast_root, 0);
        if (rc == 0) ast_release(ast_root);
        bad |= rc;
        all = realloc(all, total + len + 1);
        memcpy(all + total, src, len);
        total += len;
        free(src);
    }
    if (bad) return 1;

    size_t big_len = total * (size_t)reps;
    char *big = malloc(big_len + 1);
    for (int r = 0; r < reps; r++) memcpy(big + r * total, all, total);

    quiet = 1;
    double t_parse = 0, t_free = 0;
    long nodes = 0;
    for (int n = 0; n < iters; n++) {
        double t0 = now();
        int rc = parse_buf(big, big_len);
        double t1 = now();
        if (rc != 0) { fprintf(stderr, "parse failed on bench input\n"); return 1; }
        nodes = ast_nodes;
        ast_release(ast_root);
        double t2 = now();
        t_parse += t1 - t0;
        t_free += t2 - t1;
    }

    double mb = (double)big_len * iters / (1024.0 * 1024.0);
    printf("\nmode: %s allocator, %ld AST nodes per parse\n", ast_mode, nodes);
    printf("input %zu bytes x %d iters = %.2f MiB\n", big_len, iters, mb);
    printf("parse+AST: %.3f s -> %.1f MiB/s, %.3f ms/iter\n", t_parse, mb / t_parse, t_parse * 1000.0 / iters);
    printf("release  : %.3f ms/iter\n", t_free * 1000.0 / iters);
    printf("total    : %.3f ms/iter\n", (t_parse + t_free) * 1000.0 / iters);
    return 0;
}
