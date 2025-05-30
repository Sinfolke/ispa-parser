
export module dstd;
export import dstd.vector;
export import dstd.variant;
export import std;
export namespace stdu {
#ifdef DEBUG
    using dstd::vector;
    using dstd::variant;
#else
    using std::vector;
    using std::variant;
#endif
}