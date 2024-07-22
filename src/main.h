#if defined(DEBUG) && DEBUG != 1
    #undef DEBUG
    #define DEBUG 1
#endif
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <tinyformat.h>

#include <cpuf/cdevinfo> // cdevinfo, devinfo.h
#include <cpuf/color>
#include <cpuf/dlib>
#include "head.h"
#include "err.cpp"
#include "debug.cpp"
#include "devinfolog.h"