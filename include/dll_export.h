#if defined(_WIN32) || defined(_WIN64)
  #ifdef BUILDING_DLL  // Defined only when building the DLL
    #define EXPORT __declspec(dllexport)
  #else
    #define EXPORT __declspec(dllimport)
  #endif
#else
  #define EXPORT  // Empty for non-Windows
#endif