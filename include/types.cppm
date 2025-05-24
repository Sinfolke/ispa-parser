
export module types;
import std;
import dstd.vector;

#ifdef DEBUG
export using dstd::vector;
#else
export using std::vector;
#endif
