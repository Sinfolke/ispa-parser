#if defined(DEBUG) && DEBUG != 1
    #undef DEBUG
    #define DEBUG 1
#endif
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

#include <tinyformat.h>

#include <cpuf/cdevinfo> // cdevinfo, devinfo.h
#include <cpuf/color>
#include <cpuf/dlib>
#include <cpuf/let>


#ifndef NO_HEAD
#include "head.h"
#endif
#undef NO_HEAD


#include "err.h"
#include "debug.h"
#include "devinfolog.h"
#include "args/table.h"
