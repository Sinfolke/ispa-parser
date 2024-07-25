
template<typename ...Args>
void debug(const char* format, Args... args) {
#ifdef DEBUG
    tfm::printf(format, args...);
#endif
}