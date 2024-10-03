
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdarg>
#include <unordered_map>
#include <tinyformat.h>

#include <cpuf/cdevinfo> // cdevinfo, devinfo.h
#include <cpuf/color>
#include <cpuf/dlib>
#include <cpuf/let>


#ifndef NO_HEAD
#undef NO_HEAD
#include "head.h"
#endif
#define ND [[nodiscard]]
#define elif else if

#include <logging.h>
#include "args/args.h"