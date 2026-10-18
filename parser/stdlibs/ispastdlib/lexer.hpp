/**
 * ispastdlib/lexer.hpp - Lexer_base
 * Part of the split ISPA std lib; include <ispastdlib.hpp> for everything.
 */
#pragma once
#include <stdexcept>
#include <ispastdlib/core.hpp>
#include <ispastdlib/dfa_run.hpp>
#include <ispastdlib/token_flow.hpp>
#include <ispastdlib/raw_token.hpp>
#include <ispastdlib/traits.hpp>

namespace ISPA_STD {

    template<typename Token>
    constexpr bool is_token_end(const Token& token) {
        if constexpr (is_raw_token_v<Token>) {
            return token.empty();
        } else {
            return std::holds_alternative<std::monostate>(token);
        }
    }

    template<typename Token>
    class Lexer_base {
    protected:
        const char* _in = nullptr;
        std::string _owned_input;
        TokenFlow<Token> tokens;
        long long line = 1;

        std::size_t getCurrentPos(const char* pos) const {
            return pos - _in;
        }

        std::size_t skip_spaces(const char*& in) {
            auto prev = in;
            while (isspace(*in)) in++;
            return in - prev;
        }

        std::size_t __line(const char* pos) const {
            std::size_t count = 1;
            for (const char* in = _in; in < pos; in++) {
                if (*in == '\n') count++;
            }
            return count;
        }

        std::size_t __column(const char* pos) const {
            std::size_t count = 1;
            for (const char* in = _in; in < pos; in++) {
                count = (*in == '\n') ? 0 : count + 1;
            }
            return count;
        }

        void panic_mode(const char*& pos) {
            if (*pos != '\0') ++pos;
        }

        template<
            typename SemanticFunc,
            std::size_t table_states,
            std::size_t table_classes,
            std::size_t action_table_states,
            std::size_t debug_size,
            typename Layout
        >
        Token lookup(
            const DFA::API::Table<table_states, table_classes> &table,
            const DFA::API::CharToClass &class_table,
            const DFA::API::LRTable<action_table_states> &action_table,
            Layout layout,
            SemanticFunc semantic,
            const DFA::API::DFADebugTable<debug_size> &debug_array,
            const DFA::API::DebugIndex &debug_index,
            const char* &pos
        ) {
            if (*pos == '\0') {
                return Token {};
            }
            return DFA::run<Token>(
                pos, getCurrentPos(pos), line, table, class_table, action_table,
                semantic, debug_array, debug_index, layout
            );
        }

    public:

        class lazy_iterator {
            struct SharedState {
                const char* pos = nullptr;
                bool eof_processed = false;

                explicit SharedState(const char* in) : pos(in) {}
            };

            Lexer_base* owner = nullptr;
            std::shared_ptr<SharedState> state;
            std::size_t token_index = 0;

            void ensure_token() {
                if (!owner || !state)
                    return;

                // All iterator copies share the token cache and source
                // cursor, but retain independent logical token indices.
                while (owner->tokens.size() <= token_index) {

                    if (state->eof_processed)
                        break;

                    if (!state->pos) {
                        throw std::logic_error(
                            "Lazy lexer has no source input"
                        );
                    }

                    // EOF must be finalized exactly once.
                    if (*state->pos == '\0') {
                        state->eof_processed = true;

                        // Virtual dispatch to language-specific EOF
                        // handling (e.g. PyLexer::finish()).
                        owner->push();
                        break;
                    }

                    const char* before = state->pos;

                    Token raw = owner->makeToken(state->pos);

                    if (state->pos == before) {
                        throw std::runtime_error(
                            "Lazy lexer did not advance source position"
                        );
                    }

                    // Must dispatch through the derived lexer.
                    owner->push(std::move(raw));

                    // push() may emit zero, one, or multiple tokens.
                    // Keep lexing until the requested token exists.
                }
            }

        public:
            lazy_iterator() = default;

            lazy_iterator(Lexer_base* lexer, const char* in)
                : owner(lexer),
                  state(std::make_shared<SharedState>(in)),
                  token_index(0) {
                ensure_token();
            }

            lazy_iterator(Lexer_base& lexer, const char* in)
                : lazy_iterator(&lexer, in) {}

            bool isEnd() const {
                if (!owner || !state)
                    return true;

                const_cast<lazy_iterator*>(this)->ensure_token();

                if (token_index >= owner->tokens.size())
                    return true;

                return is_token_end(owner->tokens[token_index]);
            }

            lazy_iterator& operator++() {
                if (!isEnd()) {
                    const auto old = token_index;
                    ++token_index;
                    ensure_token();

                    std::cerr
                        << "LAZY ++: " << old
                        << " -> " << token_index
                        << " | cache size=" << owner->tokens.size();

                    if (token_index < owner->tokens.size()) {
                        const auto& t = owner->tokens[token_index];

                        std::cerr
                            << " | token type=" << t.index()
                            << " | empty=" << t.empty();
                    }

                    std::cerr << '\n';
                }

                return *this;
            }

            lazy_iterator operator++(int) {
                auto previous = *this;
                ++(*this);
                return previous;
            }

            const Token& operator*() const {
                const_cast<lazy_iterator*>(this)->ensure_token();

                if (token_index >= owner->tokens.size()) {
                    throw std::out_of_range(
                        "lazy_iterator: dereference beyond EOF"
                    );
                }

                return owner->tokens[token_index];
            }

            const Token* operator->() const {
                return &owner->tokens[token_index];
            }

            std::ptrdiff_t operator-(
                const lazy_iterator& other
            ) const {
                return static_cast<std::ptrdiff_t>(token_index) -
                       static_cast<std::ptrdiff_t>(other.token_index);
            }

            std::size_t distance() const {
                return token_index;
            }
            auto &current_state() const {
                return *state;
            }
            auto &current_state() {
                return *state;
            }
            /**
             * Returns the source position immediately after the current token.
             *
             * The returned pointer is suitable for resuming lexing with another
             * lexer, even when this lazy iterator has buffered lookahead tokens.
             */
            const char* resumePosition() const {
                if (!owner || !state)
                    return nullptr;

                auto* self = const_cast<lazy_iterator*>(this);
                self->ensure_token();

                if (token_index >= owner->tokens.size())
                    return state->pos;

                const Token& token = owner->tokens[token_index];

                if (is_token_end(token))
                    return state->pos;

                return token.meta().end();
            }
            /**
             * @brief Resume lexing N bytes after the current token's start.
             *
             * @warning Intended for external parser integration.
             *
             * Invalidates cached tokens starting at the current position,
             * then resumes lexing from the requested source address.
             *
             * All iterator copies share the lexer token cache, so previously
             * created iterators pointing into the invalidated region become
             * logically invalid.
             *
             * @param count Number of source bytes to advance.
             */
            auto advanceCharacters(std::size_t count) -> bool {
                if (!owner || !state)
                    return false;

                ensure_token();

                if (token_index >= owner->tokens.size())
                    return false;

                const Token& current = owner->tokens[token_index];

                if (is_token_end(current))
                    return false;

                const char* start = current.meta().pos;

                if (!start)
                    return false;

                const char* target = start;

                // Avoid stepping past the null terminator.
                for (std::size_t i = 0; i < count; ++i) {
                    if (*target == '\0')
                        return false;
                    ++target;
                }

                // Invalidate tokens that were lexed from the old position.
                owner->tokens.erase(
                    owner->tokens.begin() + token_index,
                    owner->tokens.end()
                );

                state->pos = target;
                state->eof_processed = false;

                ensure_token();
                return true;
            }
        };


        // Iterates already-accumulated tokens; run makeTokens() before using this.
        class iterator {
            Lexer_base* owner = nullptr;
            typename TokenFlow<Token>::iterator pos;

        public:
            iterator() = default;
            iterator(Lexer_base& owner) : owner(&owner), pos(owner.tokens.begin()) {}
            iterator(Lexer_base* owner) : owner(owner), pos(owner->tokens.begin()) {}

            iterator& operator=(const iterator& other) = default;
            void operator+=(std::size_t count) { pos += count; }
            iterator& operator++() { pos += 1; return *this; }
            iterator operator++(int) { auto tmp = *this; pos += 1; return tmp; }
            std::size_t operator-(const iterator& other) const { return pos - other.pos; }
            iterator operator+(std::size_t count) const { auto tmp = *this; tmp += count; return tmp; }

            bool isEnd() const { return is_token_end(*pos); }
            Token& operator*() const { return *pos; }
            Token* operator->() const { return &(*pos); }
            std::size_t distance() const { return pos - owner->tokens.begin(); }
            /**
             * @brief Returns the source position immediately after the current token.
             *
             * @warning Compatibility API for external parser integration.
             * Not recommended for ordinary parser code.
             *
             * Uses token source metadata to reconstruct a character pointer.
             * The source buffer must remain alive, and token metadata must refer
             * to that original buffer.
             *
             * This function does not advance the iterator.
             *
             * @return Pointer immediately after the current token, or nullptr
             *         if its source position cannot be determined.
             *
             * @note Synthetic tokens and EOF tokens may not have meaningful
             *       source spans.
             */
            [[nodiscard]]
            auto resumePosition() const -> const char* {
                if (!owner)
                    return nullptr;

                if (pos == owner->tokens.end())
                    return nullptr;

                const Token& token = *pos;

                if (is_token_end(token))
                    return nullptr;

                const auto& meta = token.meta();

                if (!meta.pos)
                    return nullptr;

                return meta._end;
            }
            auto advanceCharacters(std::size_t count) -> bool {
                throw std::runtime_error("Lexer_base::iterator::advanceCharacters() is not implemented. Use lazy_iterator for external parser integration.");
            }
        };

        virtual Token makeToken(const char*& pos) = 0;
        virtual void init() {}

        Lexer_base() { init(); }
        explicit Lexer_base(const std::string& in) : _owned_input(in), _in(_owned_input.c_str()) { init(); }
        explicit Lexer_base(const char* in) : _in(in) { init(); }
        explicit Lexer_base(const TokenFlow<Token>& tokens) : tokens(tokens) { init(); }
        virtual ~Lexer_base() = default;

        bool hasInput() const { return _in != nullptr; }
        bool hasTokens() const { return !tokens.empty(); }

        Lexer_base& setInput(const std::string& in) {
            _owned_input = in;
            _in = _owned_input.c_str();
            return *this;
        }

        Lexer_base& setInput(const char* in) {
            _owned_input.clear();
            _in = in;
            return *this;
        }

        const TokenFlow<Token>& getTokens() const { return tokens; }
        TokenFlow<Token>& getTokensReference() { return tokens; }
        void clearTokens() { tokens.clear(); }

        virtual void push(Token&& t) { tokens.push_back(std::move(t)); }
        virtual void push(const Token &t) { tokens.push_back(t); }
        virtual void push() { tokens.emplace_back(); }

        virtual TokenFlow<Token>& makeTokens() {
            if (_in == nullptr) {
                throw IspaAPIExcept("can't lex because no input provided. ");
            }
            const char* pos = _in;
            while (*pos != '\0') {
                const char* before = pos;
                Token t = makeToken(pos);
                if (pos == before) {
                    throw IspaInternalExcept(
                        "no matches at position {}, on character {}, and no exception can handle it",
                        "Lexer TDFA generation", true, getCurrentPos(pos), *pos
                    );
                }
                push(std::move(t));
            }
            push();

            return tokens;
        }
        virtual bool has_buffered_tokens() const { return !tokens.empty(); }
        virtual Token pop_buffered_token() {
            Token t = std::move(tokens.front());
            tokens.erase(tokens.begin());
            return t;
        }
        TokenFlow<Token>& makeTokens(const std::string& in) {
            setInput(in);
            return makeTokens();
        }

        TokenFlow<Token>& makeTokens(const char* in) {
            setInput(in);
            return makeTokens();
        }

        virtual TokenFlow<Token>& makeTokensFromFile(const char* path) {
            std::ifstream file(path, std::ios::in | std::ios::binary);
            if (!file) {
                throw IspaAPIExcept("Failed to open file '{}'", path);
            }

            std::string str;
            file.seekg(0, std::ios::end);
            str.reserve(static_cast<std::size_t>(file.tellg()));
            file.seekg(0, std::ios::beg);
            str.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
            return makeTokens(str);
        }

        virtual auto getErrors() -> const std::vector<std::string>& {
            throw IspaInternalExcept("Ispa is not yet able to generate errors and expose their API", "Not implemented", false);
        }

        virtual void append_token(const Token& token) {
            tokens.push_back(token);
        }

        Lexer_base& operator=(const Lexer_base& other) {
            if (this != &other) {
                tokens = other.tokens;
                _owned_input = other._owned_input;
                _in = _owned_input.empty() ? other._in : _owned_input.c_str();
            }
            return *this;
        }

        bool operator==(const Lexer_base& other) const { return tokens == other.tokens; }
        bool operator!=(const Lexer_base& other) const { return tokens != other.tokens; }
    };

} // namespace ISPA_STD