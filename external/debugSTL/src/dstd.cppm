
export module dstd;
export import dstd.vector;
export import dstd.variant;
export import std;
export namespace stdu {
#if defined(DEBUG) && !defined(DSTD_NO_DEBUG)
    using dstd::vector;
    using dstd::variant;
    using dstd::holds_alternative;
    using dstd::get;
#else
    using std::vector;
    using std::variant;
#endif
}