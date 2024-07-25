void err(const char* mes, ...) {
    std::perror(color::red);

    va_list args;
    va_start(args, mes);
    vprintf(mes, args);
    va_end(args);

    printf(color::reset);
    printf("\n");

    exit(1);
}