#pragma once
#ifndef CPUF_DEVINFO_C
#define CPUF_DEVINFO_C

#if !defined(__GNUC__) && !defined(_MSC_VER)
# error("The cdevinfo header support only clang, gcc and partially msvc")
#endif

    #define DEVINFO_UNKNOWN "unknown"
    #define DEVINFO_UNDEFINED_ID -1

    #define DEVINFO_AVX 1
    #define DEVINFO_AVX2 2
    #define DEVINFO_AVX512F 512
    #define DEVINFO_AVX512BW 512.1
    #define DEVINFO_AVX512VL 512.2
    #define DEVINFO_AVX512VL 512.2
    #define DEVINFO_AVX512CD 512.3
    #define DEVINFO_AVX512MASK 512.4
    #define DEVINFO_AVX512VBMI 512.5
    #define DEVINFO_AVX512VBM2 512.6

    #define DEVINFO_I386 386
    #define DEVINFO_I486 486
    #define DEVINFO_I586 586
    #define DEVINFO_I686 686
    #define DEVINFO_AMD64 64
    #define DEVINFO_ARMv2 2
    #define DEVINFO_ARMv3 3
    #define DEVINFO_ARMv4 4
    #define DEVINFO_ARMv5 5
    #define DEVINFO_ARMv6 6
    #define DEVINFO_ARMv7 7
    #define DEVINFO_ARMv8 8
    #define DEVINFO_AARCH64 8

    #define DEVINFO_ARMV4T 4.1
    #define DEVINFO_ARMV5T 5.1
    #define DEVINFO_ARMV5E 5.2
    #define DEVINFO_ARMV5TE 5.3
    #define DEVINFO_ARMV5TEJ 5.4
    #define DEVINFO_ARMV6J 6.1
    #define DEVINFO_ARMV6K 6.2
    #define DEVINFO_ARMV6Z 6.3
    #define DEVINFO_ARMV6ZK 6.4
    #define DEVINFO_ARMV6T2 6.5
    #define DEVINFO_ARMV7A 7.1
    #define DEVINFO_ARMV7R 7.2
    #define DEVINFO_ARMV7M 7.3
    #define DEVINFO_ARMV7EM 7.4
    #define DEVINFO_ARMV8A 8.1
    #define DEVINFO_ARMV8_1A 8.2
    #define DEVINFO_ARMV8_2A 8.3
    #define DEVINFO_ARMV8_3A 8.4
    #define DEVINFO_ARMV8_4A 8.5
    #define DEVINFO_ARMV8_5A 8.6
    #define DEVINFO_ARMV8_6A 8.7

    #define DEVINFO_ARM .1
    #define DEVINFO_X86 .2
    #define DEVINFO_POWERPC .3
    #define DEVINFO_MIPS .4
    #define DEVINFO_SPARC .5
    #define DEVINFO_RISCV .6

    #define DEVINFO_CLANG_ID 1
    #define DEVINFO_GNU_ID 2
    #define DEVINFO_MSVC_ID 3

    #define DEVINFO_APPLE 1
    #define DEVINFO_LINUX 2
    #define DEVINFO_FREEBSD 3
    #define DEVINFO_WINDOWS 4


    # ifdef __cplusplus
    #   define DEVINFO_CPP
    #   define DEVINFO_LANG_STR "C++"
    # else
    #   define DEVINFO_C
    #   define DEVINFO_LANG_STR "C"
    # endif


    # if defined (__clang__)
        /**
         * @brief the id of compiler
         * There are constants clang, gnu and msvc defines these values
         * possible values: DEVINFO_CLANG_ID (1), DEVINFO_GNU_ID (2), DEVINFO_MSVC_ID (3)
        */
        #define DEVINFO_COMPILER DEVINFO_CLANG_ID
        /**
         * @brief the compiler in string representaiton
         * possible values: "clang", "gnu", "msvc"
        */
        #define DEVINFO_COMPILER_STR "clang"
        #define DEVINFO_COMPILER_VER_MINOR __clang_minor__
        #define DEVINFO_COMPILER_VER_PATCHLEVEL __clang_patchlevel__
        #define DEVINFO_COMPILER_UNIQUE_VER_STR __VERSION__
    # elif defined(__GNUC__)
        /**
         * @brief the id of compiler
         * There are constants clang, gnu and msvc defines these values
         * possible values: DEVINFO_CLANG_ID (1), DEVINFO_GNU_ID (2), DEVINFO_MSVC_ID (3)
        */
        #define DEVINFO_COMPILER DEVINFO_GNU_ID
        /**
         * @brief the compiler in string representaiton
         * possible values: "clang", "gnu", "msvc"
        */
        #define DEVINFO_COMPILER_STR "gnu"
        #define DEVINFO_COMPILER_VER_MINOR __GNUC_MINOR__
        #define DEVINFO_COMPILER_VER_PATCHLEVEL __GNUC_PATCHLEVEL__
        #define DEVINFO_COMPILER_UNIQUE_VER_STR __VERSION__

    # else
        /**
         * @brief the id of compiler
         * There are constants clang, gnu and msvc defines these values
         * possible values: DEVINFO_CLANG_ID (1), DEVINFO_GNU_ID (2), DEVINFO_MSVC_ID (3)
        */
        #define DEVINFO_COMPILER DEVINFO_MSVC_ID
        /**
         * @brief the compiler in string representaiton
         * possible values: "clang", "gnu", "msvc"
        */
        #define DEVINFO_COMPILER_STR "msvc"
        #define DEVINFO_COMPILER_VER_MINOR (_MSC_FULL_VER / 100) % 100
        #define DEVINFO_COMPILER_VER_PATCHLEVEL _MSC_FULL_VER % 100
        #define DEVINFO_COMPILER_UNIQUE_VER_STR "MSVC " ##_MSC_VER "(" ##_MSC_FULL_VER ")"
    # endif

    # if defined(__i386__) || defined(__x86__) || defined(_M_IX86)
        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_I386
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR "i386"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_X86
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "x86"
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #define DEVINFO_ARCH_BYTESIZE 4

    # elif defined(__i486__)

        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_I486
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR = "i486"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_X86
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "x86"
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #define DEVINFO_ARCH_BYTESIZE 4

    # elif defined(__i586__)

        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_I586
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR = "i586"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_X86
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "x86"
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #define DEVINFO_ARCH_BYTESIZE 4

    # elif defined(__i686__)

        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_I686
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR = "i686"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_X86
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "x86"
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #define DEVINFO_ARCH_BYTESIZE 4

    # elif defined(__arm__)
        # if defined(__ARM_ARCH_2__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV2
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv2"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)

            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV3
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv3"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4

        # elif defined(__ARM_ARCH_4__)

            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV4
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv4"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4


        # elif defined(__ARM_ARCH_4T__)

            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV4T
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv4T"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4


        # elif defined(__ARM_ARCH_5__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV5
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv5"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_5T__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV5T
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv5T"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_5E__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV5E
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv5E"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_5TE__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV5TE
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv5TE"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_5TEJ__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV5TEJ
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv5TEJ"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_6__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV6
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv6"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_6J__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV6J
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv6J"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_6K__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV6K
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv6K"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_6Z__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV6Z
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv6Z"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_6ZK__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV6ZK
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv6ZK"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_6T2__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV6T2
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv6T2"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_7__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV7
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv7"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_7A__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV7A
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv7A"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_7R__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV7R
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv7R"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_7M__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV7M
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv7M"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_7EM__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV7EM
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv7EM"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 4
        # elif defined(__ARM_ARCH_8__) || defined(__aarch64__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV8
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv8"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 8
        # elif defined(__ARM_ARCH_8A__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV8A
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv8A"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 8
        # elif defined(__ARM_ARCH_8_1__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV8_1A
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv8.1A"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 8
        # elif defined(__ARM_ARCH_8_2__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV8_2A
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv8.2A"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 8
        # elif defined(__ARM_ARCH_8_3__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV8_3A
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv8.3A"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 8
        # elif defined(__ARM_ARCH_8_4__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV8_4A
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv8.4A"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 8
        # elif defined(__ARM_ARCH_8_5__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV8_5A
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv8.5A"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 8
        # elif defined(__ARM_ARCH_8_6__)
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH DEVINFO_ARMV8_6A
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "armv8.6A"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE 8
        #else
        #   pragma message("We've defined the ARCH_KIND is ARM but exact version is not defined")
            /**
             * @brief the index of device architecture.
             * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
             * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
             * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
             * amd64 has index 64.
             * There are constants for non obvious cases. Example: 
             * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
             * 
            */
            #define DEVINFO_ARCH -1
            /**
             * @brief the architecture of device in string representation.
             * Possible values: i386, i486, i586, i686, 
             * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
             * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
             * if not supported assigned to undefined_id (-1)
            */
            #define DEVINFO_ARCH_STR = "arm"
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
            #define DEVINFO_ARCH_BYTESIZE -1
        #define ___UNDEFINED_ARCHITECTURE___
        #endif
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_ARM
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "arm"
    # elif defined(__powerpc__) || defined(__PPC__)
        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_POWERPC
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR "powerpc"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_POWERPC
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "powerpc"
        #if defined(__powerpc64__) || defined(__ppc64__)
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
        #   define DEVINFO_BYTESIZE 8
        #else
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
        #   define DEVINFO_BYTESIZE 4
        #endif
    # elif defined(__mips__) || defined(__mips)
            /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_MIPS
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR "mips"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_MIPS
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "mips"
        #if defined(__mips64__) || defined(__mips64)
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
        #   define DEVINFO_ARCH_BYTESIZE 8
        #else
            /**
             * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
             * Possible values: 4, 8
             */
        #   define DEVINFO_ARCH_BYTESIZE 4
        #endif
    # elif defined(__sparc__)
        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_SPARC
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR "sparc"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_SPARC
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "sparc"
        #if defined(__LP64__)
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #   define DEVINFO_ARCH_BYTESIZE 8
        #else
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #   define DEVINFO_ARCH_BYTESIZE 4
        #endif
    # elif defined(__riscv__)
        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_RISCV
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR "riscv"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_RISCV
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "riscv"
        #if defined(__LP64__)
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #   define DEVINFO_ARCH_BYTESIZE 8
        #else
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #   define DEVINFO_ARCH_BYTESIZE 4
        #endif
    # elif defined(__x86_64__) || defined(__amd64__)  || defined(_M_X64) || defined(_M_AMD64)
        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_AMD64
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR "amd64"
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_X86
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR "x86"
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #define DEVINFO_ARCH_BYTESIZE 8
    # else
    #   pragma message("Undefined architecture")

        /**
         * @brief the index of device architecture.
         * The index is determined by the architecture index. For example i386 has index 386, i686 has index 686 and so on
         * For arm the index is main version of architecture and the decimal part is responsible for each subversion in sequence. For example:
         * armv5 (5), armv5T (5.1), armv5E (5.2), armv5TE (5.3) and so on.
         * amd64 has index 64.
         * There are constants for non obvious cases. Example: 
         * if (devinfo::ARCH >= devinfo::armv7A && devinfo::ARCH <= armv8) // for arm devices within armv7 architecture
         * 
        */
        #define DEVINFO_ARCH DEVINFO_UNDEFINED_ID
        /**
         * @brief the architecture of device in string representation.
         * Possible values: i386, i486, i586, i686, 
         * armv2, armv3, armv4, armv4T, armv5, armv5T, armv5TE, armv5TEJ, armv6, armv6J, armv6K, armv6Z, armv6ZK, armv6T2
         * armv7, armv7A, armv7R, armv7E, armv7EM, armv8, armv8A, armv8.1A, armv8.2A, armv8.3A, armv8.4A, armv8.5A, armv8.6A
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_ARCH_STR DEVINFO_UNKNOWN
        /**
         * @brief The kind of architecture. 
         * Possible values: DEVINFO_ARM (.1), DEVINFO_X86 (.2), DEVINFO_POWERPC (.3), DEVINFO_MIPS (.4), DEVINFO_SPARC (.5), DEVINFO_RISCV (.6)
        */
        #define DEVINFO_ARCH_KIND DEVINFO_UNDEFINED_ID
        /**
         * @brief The kind of architecture in string representation. 
         * Possible values: "arm", "x86", "powerpc", "mips", "sparc", "riscv"
         */
        #define DEVINFO_ARCH_KIND_STR DEVINFO_UNKNOWN
        /**
         * @brief The amount of bytes an architecture does support (either 4 or 8 byte architecture. Older are more 4 byte and newer more 8 byte). 
         * Possible values: 4, 8
         */
        #define DEVINFO_ARCH_BYTESIZE DEVINFO_UNDEFINED_ID
        #define ___UNDEFINED_ARCHITECTURE___

    # endif
    # if defined(__SSE4_2__)
        /**
         * @brief the SSE version.
         * Possible values: 1 (SSE supported), 2 (SSE2), 3 (SSE3), 3.1 (SSSE3), 4.1 (SSE4.1), 4.2 (SSE4.2)
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_SSE_VER 4.2
    # elif defined(__SSE4_1)
        /**
         * @brief the SSE version.
         * Possible values: 1 (SSE supported), 2 (SSE2), 3 (SSE3), 3.1 (SSSE3), 4.1 (SSE4.1), 4.2 (SSE4.2)
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_SSE_VER 4.1
    # elif defined(__SSSE3__)
        /**
         * @brief the SSE version.
         * Possible values: 1 (SSE supported), 2 (SSE2), 3 (SSE3), 3.1 (SSSE3), 4.1 (SSE4.1), 4.2 (SSE4.2)
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_SSE_VER 3.1
    # elif defined(__SSE3__)
        /**
         * @brief the SSE version.
         * Possible values: 1 (SSE supported), 2 (SSE2), 3 (SSE3), 3.1 (SSSE3), 4.1 (SSE4.1), 4.2 (SSE4.2)
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_SSE_VER 3
    # elif defined(__SSE2__)
        /**
         * @brief the SSE version.
         * Possible values: 1 (SSE supported), 2 (SSE2), 3 (SSE3), 3.1 (SSSE3), 4.1 (SSE4.1), 4.2 (SSE4.2)
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_SSE_VER 2
    # elif defined(__SSE2__)
        /**
         * @brief the SSE version.
         * Possible values: 1 (SSE supported), 2 (SSE2), 3 (SSE3), 3.1 (SSSE3), 4.1 (SSE4.1), 4.2 (SSE4.2)
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_SSE_VER 2
    # elif defined(__SSE__)
        /**
         * @brief the SSE version.
         * Possible values: 1 (SSE supported), 2 (SSE2), 3 (SSE3), 3.1 (SSSE3), 4.1 (SSE4.1), 4.2 (SSE4.2)
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_SSE_VER 1
    # else
        /**
         * @brief the SSE version.
         * Possible values: 1 (SSE supported), 2 (SSE2), 3 (SSE3), 3.1 (SSSE3), 4.1 (SSE4.1), 4.2 (SSE4.2)
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_SSE_VER DEVINFO_UNDEFINED_ID
    # endif
    # if defined(__AVX__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx
    # elif defined(__AVX2__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx2
    # elif defined(__AVX512F__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx512F
    # elif defined(__AVX512BW__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx512BW
    # elif defined(__AVX512VL__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx512VL
    # elif defined(__AVX512CD__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx512CD
    # elif defined(__AVX512MASK__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx512MASK
    # elif defined(__AVX512VBMI__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx512VBMI
    # elif defined(__AVX512VBM2__)
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER avx512VBM2
    # else
        /**
         * @brief the AVX version.
         * Possible values: avx (1), avx2 (2) avx512F (512), avx512BW (512.1),  avx512VL (512.2) avx512CD (512.3), avx512MASK (512.4), avx512VBMI (512.5), avx512VBM2 (512.6).
         * if not supported assigned to undefined_id (-1)
        */
        #define DEVINFO_AVX_VER DEVINFO_UNDEFINED_ID
    # endif

    # if defined(__APPLE__)
        /**
         * @brief The OS of device
         * Posible values: DEVINFO_APPLE (1), DEVINFO_LINUX (2), DEVINFO_FREEBSD (3), DEVINFO_WINDOWS (4)
         */
        #define DEVINFO_OS DEVINFO_APPLE
        /**
         * @brief The OS in string representation
         * Possible values: "apple", "linux", "freebsd", "windows"
         */
        #define DEVINFO_OS_STR "apple"
        #if defined(__LP64__) && __LP64__
            /**
             * @brief The bytesize of OS.
             * Possible values: 4, 8
             * 
             */
            #define DEVINFO_OS_BYTESIZE 8
        #else
            /**
             * @brief The bytesize of OS.
             * Possible values: 4, 8
             * 
             */
            #define DEVINFO_OS_BYTESIZE 4
        #endif
    # elif defined(__linux__)
        /**
         * @brief The OS of device
         * Posible values: DEVINFO_APPLE (1), DEVINFO_LINUX (2), DEVINFO_FREEBSD (3), DEVINFO_WINDOWS (4)
         */
        #define DEVINFO_OS DEVINFO_LINUX
        /**
         * @brief The OS in string representation
         * Possible values: "apple", "linux", "freebsd", "windows"
         */
        #define DEVINFO_OS_STR "linux"
        #if defined(__LP64__) || defined(_LP64)
            /**
             * @brief The bytesize of OS.
             * Possible values: 4, 8
             * 
             */
            #define DEVINFO_OS_BYTESIZE 8
        #else
            /**
             * @brief The bytesize of OS.
             * Possible values: 4, 8
             * 
             */
            #define DEVINFO_OS_BYTESIZE 4
        #endif
    # elif defined(__FreeBSD__)
        /**
         * @brief The OS of device
         * Posible values: DEVINFO_APPLE (1), DEVINFO_LINUX (2), DEVINFO_FREEBSD (3), DEVINFO_WINDOWS (4)
         */
        #define DEVINFO_OS DEVINFO_FREEBSD
        /**
         * @brief The OS in string representation
         * Possible values: "apple", "linux", "freebsd", "windows"
         */
        #define DEVINFO_OS_STR "freebsd"
        #if defined(__LP64__)
            /**
             * @brief The bytesize of OS.
             * Possible values: 4, 8
             * 
             */
            #define DEVINFO_OS_BYTESIZE 8
        #else
            /**
             * @brief The bytesize of OS.
             * Possible values: 4, 8
             * 
             */
            #define DEVINFO_OS_BYTESIZE 4
        #endif
    # elif defined(_WIN32)
        /**
         * @brief The OS of device
         * Posible values: DEVINFO_APPLE (1), DEVINFO_LINUX (2), DEVINFO_FREEBSD (3), DEVINFO_WINDOWS (4)
         */
        #define DEVINFO_OS DEVINFO_WINDOWS
        /**
         * @brief The OS in string representation
         * Possible values: "apple", "linux", "freebsd", "windows"
         */
        #define DEVINFO_OS_STR "windows"
        #if defined(_WIN64)
            /**
             * @brief The bytesize of OS.
             * Possible values: 4, 8
             * 
             */
            #define DEVINFO_OS_BYTESIZE 8
        #else
            /**
             * @brief The bytesize of OS.
             * Possible values: 4, 8
             * 
             */
            #define DEVINFO_OS_BYTESIZE 4
        #endif
    # else
    #   pragma message("Undefined platform. The platforms it able to determine are: Linux, FreeBSD, MacOS and Windows")
    #   define ___UNDEFINED_OS___
        /**
         * @brief The OS of device
         * Posible values: DEVINFO_APPLE (1), DEVINFO_LINUX (2), DEVINFO_FREEBSD (3), DEVINFO_WINDOWS (4)
         */
    #   define DEVINFO_OS DEVINFO_UNDEFINED_ID
        /**
         * @brief The OS in string representation
         * Possible values: "apple", "linux", "freebsd", "windows"
         */
    #   define DEVINFO_OS_STR DEVINFO_UNKNOWN
        /**
         * @brief The bytesize of OS.
         * Possible values: 4, 8
         * 
         */
    #   define DEVINFO_OS_BYTESIZE DEVINFO_UNDEFINED_ID
    # endif

    # ifndef ___UNDEFINED_ARCHITECTURE___
        /**
         * @brief the highest amount of bits the architecture does support. Varying between 32 and 64 bits. Equals ARCH_BYTESIZE * 8
        */
        #define DEVINFO_ARCH_BITSIZE DEVINFO_ARCH_BYTESIZE * 8
    # else
    #   undef ___UNDEFINED_ARCHITECTURE___
        /**
         * @brief the highest amount of bits architecture does support. Varying between 32 and 64 bits. Equals ARCH_BYTESIZE * 8
        */
        #define DEVINFO_ARCH_BITSIZE DEVINFO_UNDEFINED_ID
    # endif

    # ifndef ___UNDEFINED_OS___
        /**
         * @brief the highest amount of bits OS does support. Varying between 32 and 64 bits. Equals ARCH_BYTESIZE * 8
        */
        #define DEVINFO_OS_BITSIZE DEVINFO_OS_BYTESIZE * 8
    # else
    #   undef ___UNDEFINED_ARCHITECTURE___
        /**
         * @brief the highest amount of bits OS does support. Varying between 32 and 64 bits. Equals ARCH_BYTESIZE * 8
        */
        #define DEVINFO_OS_BITSIZE DEVINFO_UNDEFINED_ID
    # endif

#endif // CPUF_DEVINFO_C