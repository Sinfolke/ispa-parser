/*
    The ISC generated parser 
    name: Parser
    This generated parser links with iscstdlibc++ with the version >=1.0

*/

#pragma once

#ifndef ISC_OUT_PARSER
#define ISC_OUT_PARSER
#include <iscstdlibc++.h>

// here it checks according to the backward version
#if _ISC_STD_LIB_VER < 0 // skip subver check
#error  "Your library version is too old. Please, update your library."
#elif (_ISC_STD_LIB_VER > 1 || _ISC_STD_LIB_SUBVER > 0) && (_ISC_STD_LIB_BACKDOWN > 1 || _ISC_STD_LIB_BACKDOWN_SUBVER > 0)
#error  "This parser is generated for the version 1.0 but your newer library is not compatible with it. Generally you would regenerate the parser for the newer library. However if not possible you should backward your library version"
#endif



#endif // ISC_OUT_PARSER