
export module dstd;
export import dstd.vector;
export import dstd.variant;
export import std;
export namespace stdu {
#ifdef DEBUG
    using namespace dstd;
#else
    using namespace std;
#endif
};