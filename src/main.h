
#define __SOURCE_ROOT__ __FILE__
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdarg>
#include <unordered_map>
#include <stdexcept>
#include <stdlib.h>


#include <cpuf/cdevinfo> // cdevinfo, devinfo.h
#include <cpuf/color>
#include <cpuf/dlib>
#include <cpuf/let>
#include <cpuf/printf>
#include <cpuf/constexpr>

#include <debug.h>
#ifndef NO_HEAD
#undef NO_HEAD
// if somebody opens in dissasembly/hex editor they'll find important links
#include "head.h"
#endif
#define ND [[nodiscard]]
//#define elif else if

#include <logging.h>
#include "args/args.h"