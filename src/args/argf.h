namespace argf {
    std::string storev(const std::string& val) {
        return val;
    }
    std::string ignorev(const std::string& val) {
        return "";
    }
    COMPILE_LANGUAGE lang(std::string in) {
        if (in == "C")
            return COMPILE_LANGUAGE::C;
        else 
            return COMPILE_LANGUAGE::CPP;
    }
}