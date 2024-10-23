// get cpu vendor on current machine
#ifdef _WIN32
#include <intrin.h>  // windows __cpuidex
#else
#include <cpuid.h>   // linux __get_cpuid
#endif
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void get_cpu_vendor(char* vendor) {
    uint32_t regs[4] = {0};

#ifdef _WIN32
    __cpuidex((int *)regs, 0, 0);
#else
    __get_cpuid(0, &regs[0], &regs[1], &regs[2], &regs[3]);
#endif

    memcpy(&vendor[0], &regs[1], 4);
    memcpy(&vendor[4], &regs[3], 4);
    memcpy(&vendor[8], &regs[2], 4);
    vendor[12] = '\0';
}

int main() {
    char brand[13];
    get_cpu_vendor(brand);
    if (strstr(brand, "Intel"))
        return 0;
    else if (strstr(brand, "AMD"))
        return 1;
    return 2;
}
