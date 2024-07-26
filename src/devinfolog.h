void devinfolog(void) {
    # if defined(DEBUG) && !defined(NO_HEAD)
        std::cout << "\t#########################" << '\n';
            std::cout << "\t#\tDEBUG BUILD\t#\t" << '\n';
            std::cout << "\t#\t" << devinfo::ARCH_STR << " x" << devinfo::ARCH_BITSIZE << "\t#\t" << '\n';
            std::cout << "\t#\t" << devinfo::OS_STR << " x" << devinfo::OS_BITSIZE << "\t#\t" << '\n';
        std::cout << "\t#########################" << std::endl;
    # endif
}
