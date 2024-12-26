#pragma once
#include <vector>
#include <stdexcept>
#include <cstring>
#include <unordered_map>
#include <debug/logging.h>
class Arg;
enum class listener_cmd {
    SUCCESS = 0,
    STOP_PARSING,
    CONTINUE_PARSING_AT,
    CONTINUE_PARSING_AT_ID,
    ABORT,
};
struct listener_return_t {
    listener_cmd command;
    const char* arg1;
};

#define ND [[nodiscard]]
typedef listener_return_t (*listenerf)(const Arg& arg);
class Arg {
    public:
        const char* prefix;
        std::vector<const char*> values;
        ND bool empty() const;
        ND bool isBool() const;
        void clear();
        ND const char* first() const;
        ND const char* _0() const;
        ND const char* last() const;
        ND const char* operator[](const int v) const;

};
class Args {
    private:
        int argc;
        const char** argv;
        std::vector<Arg> args;
        std::vector<const char*> _unnamed;
        std::unordered_map<const char*, listenerf> listeners;
        std::unordered_map<const char*, listenerf> listeners_parsed;
        std::unordered_map<const char*, listenerf> listeners_unparsed;
    public:
        Args(int argc, const char** argv) : argc(argc), argv(argv) {}
        /**
         * @brief Provide the input argc and argv
         * 
         * @param argc 
         * @param argv 
         */
        void init(int argc, const char** argv);
        void on(const char* prefix, listenerf func);
        void onParsed(const char* prefix, listenerf func);
        void onUnparsed(const char* prefix, listenerf func);
        void parse();
        ND Arg& operator[](const int& id);
        ND std::vector<const char*> unnamed(void);
};