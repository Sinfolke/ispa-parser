module;
#include <tsl/ordered_map.h>
module LLIR.Serialize;
import corelib;

namespace LLIR::Serialize {

// ---- wiring note ------------------------------------------------------
// Every write(ostream&, const T&) / read(istream&, T&) pair below is an
// ordinary (non-template) overload for one concrete LangAPI/LLIR type, PLUS
// a handful of generic templates for primitives, vector, pair, optional,
// shared_ptr and std::variant. Overload resolution always prefers an exact
// non-template match over a template instantiation reached through a
// derived-to-base conversion (relevant for Statements/Expression, which
// derive from stdu::vector<T>), so the explicit overloads below are safe
// even though the generic vector template could technically also bind.
//
// Several types are mutually recursive (Symbol <-> FunctionCall <-> Type
// <-> RValue <-> Expression <-> Statement ...), so every overload is
// forward-declared first, then defined after. Don't reorder without
// keeping that split.
// -------------------------------------------------------------------------

// ---- generic containers: forward declarations ----------------------------
template<typename T>
    requires std::is_trivially_copyable_v<T> && (!std::is_pointer_v<T>) && (!std::is_enum_v<T>)
void write(std::ostream &os, const T &v);
template<typename T>
    requires std::is_trivially_copyable_v<T> && (!std::is_pointer_v<T>) && (!std::is_enum_v<T>)
void read(std::istream &is, T &v);

void write(std::ostream &os, const std::string &s);
void read(std::istream &is, std::string &s);

template<typename T> void write(std::ostream &os, const stdu::vector<T> &v);
template<typename T> void read(std::istream &is, stdu::vector<T> &v);

template<typename A, typename B> void write(std::ostream &os, const std::pair<A,B> &p);
template<typename A, typename B> void read(std::istream &is, std::pair<A,B> &p);

template<typename T> void write(std::ostream &os, const std::shared_ptr<T> &p);
template<typename T> void read(std::istream &is, std::shared_ptr<T> &p);

template<typename T> void write(std::ostream &os, const std::optional<T> &o);
template<typename T> void read(std::istream &is, std::optional<T> &o);

template<typename E> requires std::is_enum_v<E> void write(std::ostream &os, E e);
template<typename E> requires std::is_enum_v<E> void read(std::istream &is, E &e);

template<typename ...Ts> void write(std::ostream &os, const std::variant<Ts...> &v);
template<typename ...Ts> void read(std::istream &is, std::variant<Ts...> &v);

template<typename K, typename V> void write(std::ostream &os, const tsl::ordered_map<K,V> &m);
template<typename K, typename V> void read(std::istream &is, tsl::ordered_map<K,V> &m);

// ---- forward declarations: every aggregate on the Production closure ----
void write(std::ostream&, const LangAPI::Char&);           void read(std::istream&, LangAPI::Char&);
void write(std::ostream&, const LangAPI::Int&);             void read(std::istream&, LangAPI::Int&);
void write(std::ostream&, const LangAPI::Bool&);            void read(std::istream&, LangAPI::Bool&);
void write(std::ostream&, const LangAPI::Float&);           void read(std::istream&, LangAPI::Float&);
void write(std::ostream&, const LangAPI::String&);          void read(std::istream&, LangAPI::String&);
void write(std::ostream&, const LangAPI::Pos&);              void read(std::istream&, LangAPI::Pos&);
void write(std::ostream&, const LangAPI::Type&);             void read(std::istream&, LangAPI::Type&);
void write(std::ostream&, const LangAPI::Expression&);       void read(std::istream&, LangAPI::Expression&);
void write(std::ostream&, const LangAPI::ExpressionValue&);  void read(std::istream&, LangAPI::ExpressionValue&);
void write(std::ostream&, const LangAPI::RValue&);           void read(std::istream&, LangAPI::RValue&);
void write(std::ostream&, const LangAPI::Array&);             void read(std::istream&, LangAPI::Array&);
void write(std::ostream&, const LangAPI::FixedSizeArray&);    void read(std::istream&, LangAPI::FixedSizeArray&);
void write(std::ostream&, const LangAPI::Map&);               void read(std::istream&, LangAPI::Map&);
void write(std::ostream&, const LangAPI::ArrayMethodCall&);   void read(std::istream&, LangAPI::ArrayMethodCall&);
void write(std::ostream&, const LangAPI::FunctionCall&);      void read(std::istream&, LangAPI::FunctionCall&);
void write(std::ostream&, const LangAPI::IspaLibSymbol&);     void read(std::istream&, LangAPI::IspaLibSymbol&);
void write(std::ostream&, const LangAPI::Symbol&);            void read(std::istream&, LangAPI::Symbol&);
void write(std::ostream&, const LangAPI::StorageOffset&);     void read(std::istream&, LangAPI::StorageOffset&);
void write(std::ostream&, const LangAPI::Property&);          void read(std::istream&, LangAPI::Property&);
void write(std::ostream&, const LangAPI::StorageSymbol&);     void read(std::istream&, LangAPI::StorageSymbol&);
void write(std::ostream&, const LangAPI::IspaLibFunctionCall&); void read(std::istream&, LangAPI::IspaLibFunctionCall&);
void write(std::ostream&, const LangAPI::Inheritance&);       void read(std::istream&, LangAPI::Inheritance&);
void write(std::ostream&, const LangAPI::IspaLibDfaTransition&); void read(std::istream&, LangAPI::IspaLibDfaTransition&);
void write(std::ostream&, const LangAPI::IspaLibDfaSpanCharState&); void read(std::istream&, LangAPI::IspaLibDfaSpanCharState&);
void write(std::ostream&, const LangAPI::IspaLibDfaSpanMultiTableState&); void read(std::istream&, LangAPI::IspaLibDfaSpanMultiTableState&);
void write(std::ostream&, const LangAPI::IspaLibDfaEmptyState&); void read(std::istream&, LangAPI::IspaLibDfaEmptyState&);
void write(std::ostream&, const LangAPI::IspaLibDfaSpan&);    void read(std::istream&, LangAPI::IspaLibDfaSpan&);
void write(std::ostream&, const LangAPI::Reference&);         void read(std::istream&, LangAPI::Reference&);
void write(std::ostream&, const LangAPI::Span&);              void read(std::istream&, LangAPI::Span&);
void write(std::ostream&, const LangAPI::EmptyInitializer&);  void read(std::istream&, LangAPI::EmptyInitializer&);
void write(std::ostream&, const LangAPI::MakeTuple&);         void read(std::istream&, LangAPI::MakeTuple&);
void write(std::ostream&, const LangAPI::GetVariant&);        void read(std::istream&, LangAPI::GetVariant&);
void write(std::ostream&, const LangAPI::CheckVariant&);      void read(std::istream&, LangAPI::CheckVariant&);
void write(std::ostream&, const LangAPI::CharToStringConstructor&); void read(std::istream&, LangAPI::CharToStringConstructor&);
void write(std::ostream&, const LangAPI::ToString&);          void read(std::istream&, LangAPI::ToString&);
void write(std::ostream&, const LangAPI::Cast&);               void read(std::istream&, LangAPI::Cast&);
void write(std::ostream&, const LangAPI::GetFromBox&);         void read(std::istream&, LangAPI::GetFromBox&);
void write(std::ostream&, const LangAPI::Break&);               void read(std::istream&, LangAPI::Break&);
void write(std::ostream&, const LangAPI::Continue&);            void read(std::istream&, LangAPI::Continue&);
void write(std::ostream&, const LangAPI::Return&);              void read(std::istream&, LangAPI::Return&);
void write(std::ostream&, const LangAPI::StringCompare&);       void read(std::istream&, LangAPI::StringCompare&);
void write(std::ostream&, const LangAPI::VariableAssignment&);  void read(std::istream&, LangAPI::VariableAssignment&);
void write(std::ostream&, const LangAPI::CounterIncreament&);   void read(std::istream&, LangAPI::CounterIncreament&);
void write(std::ostream&, const LangAPI::AssignCounter&);       void read(std::istream&, LangAPI::AssignCounter&);
void write(std::ostream&, const LangAPI::ResetPosCounter&);     void read(std::istream&, LangAPI::ResetPosCounter&);
void write(std::ostream&, const LangAPI::PushPosCounter&);      void read(std::istream&, LangAPI::PushPosCounter&);
void write(std::ostream&, const LangAPI::PopPosCounter&);       void read(std::istream&, LangAPI::PopPosCounter&);
void write(std::ostream&, const LangAPI::SkipSpaces&);          void read(std::istream&, LangAPI::SkipSpaces&);
void write(std::ostream&, const LangAPI::DfaLookup&);           void read(std::istream&, LangAPI::DfaLookup&);
void write(std::ostream&, const LangAPI::ReportError&);         void read(std::istream&, LangAPI::ReportError&);
void write(std::ostream&, const LangAPI::Lambda&);               void read(std::istream&, LangAPI::Lambda&);
void write(std::ostream&, const LangAPI::DFADebug&);             void read(std::istream&, LangAPI::DFADebug&);
void write(std::ostream&, const LangAPI::Variable&);             void read(std::istream&, LangAPI::Variable&);
void write(std::ostream&, const LangAPI::ConditionalElement&);   void read(std::istream&, LangAPI::ConditionalElement&);
void write(std::ostream&, const LangAPI::If&);                    void read(std::istream&, LangAPI::If&);
void write(std::ostream&, const LangAPI::While&);                 void read(std::istream&, LangAPI::While&);
void write(std::ostream&, const LangAPI::DoWhile&);               void read(std::istream&, LangAPI::DoWhile&);
void write(std::ostream&, const LangAPI::Switch&);                void read(std::istream&, LangAPI::Switch&);
void write(std::ostream&, const LangAPI::Throw&);                 void read(std::istream&, LangAPI::Throw&);
void write(std::ostream&, const LangAPI::Comment&);               void read(std::istream&, LangAPI::Comment&);
void write(std::ostream&, const LangAPI::Statement&);             void read(std::istream&, LangAPI::Statement&);
void write(std::ostream&, const LangAPI::Statements&);            void read(std::istream&, LangAPI::Statements&);
void write(std::ostream&, const DataBlock&);                      void read(std::istream&, DataBlock&);

// ---- generic primitive and string definitions ---------------------------
template<typename T>
    requires std::is_trivially_copyable_v<T> && (!std::is_pointer_v<T>) && (!std::is_enum_v<T>)
void write(std::ostream &os, const T &v) {
    os.write(reinterpret_cast<const char*>(&v), sizeof(T));
}
template<typename T>
    requires std::is_trivially_copyable_v<T> && (!std::is_pointer_v<T>) && (!std::is_enum_v<T>)
void read(std::istream &is, T &v) {
    is.read(reinterpret_cast<char*>(&v), sizeof(T));
}

void write(std::ostream &os, const std::string &s) {
    std::size_t len = s.size();
    write(os, len);
    os.write(s.data(), static_cast<std::streamsize>(len));
}
void read(std::istream &is, std::string &s) {
    std::size_t len;
    read(is, len);
    s.resize(len);
    if (len) is.read(s.data(), static_cast<std::streamsize>(len));
}

// ---- generic container definitions --------------------------------------
template<typename T> void write(std::ostream &os, const stdu::vector<T> &v) {
    write(os, v.size());
    for (auto &e : v) write(os, e);
}
template<typename T> void read(std::istream &is, stdu::vector<T> &v) {
    std::size_t n; read(is, n);
    v.clear(); v.reserve(n);
    for (std::size_t i = 0; i < n; ++i) { T e{}; read(is, e); v.push_back(std::move(e)); }
}

template<typename A, typename B> void write(std::ostream &os, const std::pair<A,B> &p) {
    write(os, p.first); write(os, p.second);
}
template<typename A, typename B> void read(std::istream &is, std::pair<A,B> &p) {
    read(is, p.first); read(is, p.second);
}

template<typename T> void write(std::ostream &os, const std::shared_ptr<T> &p) {
    bool has = static_cast<bool>(p);
    write(os, has);
    if (has) write(os, *p);
}
template<typename T> void read(std::istream &is, std::shared_ptr<T> &p) {
    bool has; read(is, has);
    if (has) { p = std::make_shared<T>(); read(is, *p); } else p.reset();
}

template<typename T> void write(std::ostream &os, const std::optional<T> &o) {
    bool has = o.has_value();
    write(os, has);
    if (has) write(os, *o);
}
template<typename T> void read(std::istream &is, std::optional<T> &o) {
    bool has; read(is, has);
    if (has) { T v{}; read(is, v); o = std::move(v); } else o.reset();
}

template<typename E> requires std::is_enum_v<E>
void write(std::ostream &os, E e) { write(os, static_cast<std::underlying_type_t<E>>(e)); }
template<typename E> requires std::is_enum_v<E>
void read(std::istream &is, E &e) { std::underlying_type_t<E> v{}; read(is, v); e = static_cast<E>(v); }

template<typename Variant, std::size_t I = 0>
void read_variant_alt(std::istream &is, Variant &v, std::size_t idx) {
    if constexpr (I < std::variant_size_v<Variant>) {
        if (idx == I) {
            using Alt = std::variant_alternative_t<I, Variant>;
            if constexpr (std::is_same_v<Alt, std::monostate>) v = std::monostate{};
            else { Alt a{}; read(is, a); v = std::move(a); }
            return;
        }
        read_variant_alt<Variant, I + 1>(is, v, idx);
    }
}
template<typename ...Ts> void write(std::ostream &os, const std::variant<Ts...> &v) {
    write(os, v.index());
    std::visit([&](const auto &alt) {
        using Alt = std::decay_t<decltype(alt)>;
        if constexpr (!std::is_same_v<Alt, std::monostate>) write(os, alt);
    }, v);
}
template<typename ...Ts> void read(std::istream &is, std::variant<Ts...> &v) {
    std::size_t idx; read(is, idx);
    read_variant_alt(is, v, idx);
}

template<typename K, typename V> void write(std::ostream &os, const tsl::ordered_map<K,V> &m) {
    write(os, m.size());
    for (auto &[k, val] : m) { write(os, k); write(os, val); }
}
template<typename K, typename V> void read(std::istream &is, tsl::ordered_map<K,V> &m) {
    std::size_t n; read(is, n); m.clear();
    for (std::size_t i = 0; i < n; ++i) {
        K k{}; V val{};
        read(is, k); read(is, val);
        m.try_emplace(std::move(k), std::move(val));
    }
}

// ---- DFADebug escape hatch: see module header comment -------------------
thread_local bool g_hit_dfadebug = false;

// ---- definitions, leaves first -------------------------------------------
void write(std::ostream &os, const LangAPI::Char &v)  { write(os, v.value); write(os, v.escaped); }
void read (std::istream &is, LangAPI::Char &v)        { read(is, v.value); read(is, v.escaped); }
void write(std::ostream &os, const LangAPI::Int &v)   { write(os, v.value); }
void read (std::istream &is, LangAPI::Int &v)         { read(is, v.value); }
void write(std::ostream &os, const LangAPI::Bool &v)  { write(os, v.value); }
void read (std::istream &is, LangAPI::Bool &v)        { read(is, v.value); }
void write(std::ostream &os, const LangAPI::Float &v) { write(os, v.value); }
void read (std::istream &is, LangAPI::Float &v)       { read(is, v.value); }
void write(std::ostream &os, const LangAPI::String &v){ write(os, v.value); }
void read (std::istream &is, LangAPI::String &v)      { read(is, v.value); }
void write(std::ostream &os, const LangAPI::Pos &v)   { write(os, v.dereference); write(os, v.offset); }
void read (std::istream &is, LangAPI::Pos &v)         { read(is, v.dereference); read(is, v.offset); }

void write(std::ostream &os, const LangAPI::Array &v) { write(os, v.values); write(os, v.template_parameters); }
void read (std::istream &is, LangAPI::Array &v)       { read(is, v.values); read(is, v.template_parameters); }
void write(std::ostream &os, const LangAPI::FixedSizeArray &v) { write(os, v.values); write(os, v.template_parameters); }
void read (std::istream &is, LangAPI::FixedSizeArray &v)       { read(is, v.values); read(is, v.template_parameters); }
void write(std::ostream &os, const LangAPI::Map &v) { write(os, v.keys); write(os, v.values); write(os, v.template_parameters); }
void read (std::istream &is, LangAPI::Map &v)       { read(is, v.keys); read(is, v.values); read(is, v.template_parameters); }
void write(std::ostream &os, const LangAPI::ArrayMethodCall &v) { write(os, v.method); write(os, v.args); }
void read (std::istream &is, LangAPI::ArrayMethodCall &v)       { read(is, v.method); read(is, v.args); }

void write(std::ostream &os, const LangAPI::IspaLibSymbol &v) {
    write(os, v.exports); write(os, v.template_parameters); write(os, v.Const); write(os, v.Reference);
}
void read (std::istream &is, LangAPI::IspaLibSymbol &v) {
    read(is, v.exports); read(is, v.template_parameters); read(is, v.Const); read(is, v.Reference);
}

void write(std::ostream &os, const LangAPI::FunctionCall &v) {
    write(os, v.name); write(os, v.template_parameters); write(os, v.args);
}
void read (std::istream &is, LangAPI::FunctionCall &v) {
    read(is, v.name); read(is, v.template_parameters); read(is, v.args);
}

void write(std::ostream &os, const LangAPI::Symbol &v) { write(os, v.path); }
void read (std::istream &is, LangAPI::Symbol &v)       { stdu::vector<LangAPI::Symbol::PathPart> p; read(is, p); v.path = std::move(p); }

void write(std::ostream &os, const LangAPI::StorageOffset &v) { write(os, v.offset); }
void read (std::istream &is, LangAPI::StorageOffset &v)       { read(is, v.offset); }
void write(std::ostream &os, const LangAPI::Property &v) { write(os, v.name); }
void read (std::istream &is, LangAPI::Property &v)       { read(is, v.name); }

void write(std::ostream &os, const LangAPI::StorageSymbol &v) { write(os, v.what); write(os, v.path); }
void read (std::istream &is, LangAPI::StorageSymbol &v) {
    read(is, v.what);
    stdu::vector<LangAPI::StorageSymbol::PathPart> p; read(is, p); v.path = std::move(p);
}

void write(std::ostream &os, const LangAPI::IspaLibFunctionCall &v) { write(os, v.symbol); write(os, v.args); }
void read (std::istream &is, LangAPI::IspaLibFunctionCall &v)       { read(is, v.symbol); read(is, v.args); }
void write(std::ostream &os, const LangAPI::Inheritance &v) { write(os, v.name); write(os, v.args); }
void read (std::istream &is, LangAPI::Inheritance &v)       { read(is, v.name); read(is, v.args); }

void write(std::ostream &os, const LangAPI::IspaLibDfaTransition &v) {
    write(os, v.symbol); write(os, v.next); write(os, v.new_cst_node); write(os, v.new_member);
    write(os, v.close_cst_node); write(os, v.new_group); write(os, v.group_close); write(os, v.accept);
    write(os, v.transition_type); write(os, v.is_refferring_char_table);
}
void read (std::istream &is, LangAPI::IspaLibDfaTransition &v) {
    read(is, v.symbol); read(is, v.next); read(is, v.new_cst_node); read(is, v.new_member);
    read(is, v.close_cst_node); read(is, v.new_group); read(is, v.group_close); read(is, v.accept);
    read(is, v.transition_type); read(is, v.is_refferring_char_table);
}
void write(std::ostream &os, const LangAPI::IspaLibDfaSpanCharState &v) {
    write(os, v.else_goto); write(os, v.else_goto_accept); write(os, v.state_id);
}
void read (std::istream &is, LangAPI::IspaLibDfaSpanCharState &v) {
    read(is, v.else_goto); read(is, v.else_goto_accept); read(is, v.state_id);
}
void write(std::ostream &os, const LangAPI::IspaLibDfaSpanMultiTableState &v) {
    write(os, v.else_goto); write(os, v.else_goto_accept); write(os, v.state_id); write(os, v.mutli_table_transitions);
}
void read (std::istream &is, LangAPI::IspaLibDfaSpanMultiTableState &v) {
    read(is, v.else_goto); read(is, v.else_goto_accept); read(is, v.state_id); read(is, v.mutli_table_transitions);
}
void write(std::ostream &os, const LangAPI::IspaLibDfaEmptyState &v) {
    write(os, v.token_name); write(os, v.construction_lambda);
}
void read (std::istream &is, LangAPI::IspaLibDfaEmptyState &v) {
    read(is, v.token_name); read(is, v.construction_lambda);
}
void write(std::ostream &os, const LangAPI::IspaLibDfaSpan &v) { write(os, v.type); write(os, v.assing_name); }
void read (std::istream &is, LangAPI::IspaLibDfaSpan &v)       { read(is, v.type); read(is, v.assing_name); }

void write(std::ostream &os, const LangAPI::Reference &v) { write(os, v.value); }
void read (std::istream &is, LangAPI::Reference &v)       { read(is, v.value); }
void write(std::ostream &os, const LangAPI::Span &v) { write(os, v.type); write(os, v.sym); }
void read (std::istream &is, LangAPI::Span &v)       { read(is, v.type); read(is, v.sym); }
void write(std::ostream &os, const LangAPI::EmptyInitializer&) {}
void read (std::istream &, LangAPI::EmptyInitializer&) {}
void write(std::ostream &os, const LangAPI::MakeTuple &v) { write(os, v.args); }
void read (std::istream &is, LangAPI::MakeTuple &v)       { read(is, v.args); }
void write(std::ostream &os, const LangAPI::GetVariant &v) { write(os, v.type); write(os, v.sym); }
void read (std::istream &is, LangAPI::GetVariant &v)       { read(is, v.type); read(is, v.sym); }
void write(std::ostream &os, const LangAPI::CheckVariant &v) { write(os, v.type); write(os, v.sym); }
void read (std::istream &is, LangAPI::CheckVariant &v)       { read(is, v.type); read(is, v.sym); }
void write(std::ostream &os, const LangAPI::CharToStringConstructor &v) { write(os, v.what); }
void read (std::istream &is, LangAPI::CharToStringConstructor &v)       { read(is, v.what); }
void write(std::ostream &os, const LangAPI::ToString &v) { write(os, v.what); }
void read (std::istream &is, LangAPI::ToString &v)       { read(is, v.what); }
void write(std::ostream &os, const LangAPI::Cast &v) { write(os, v.type); write(os, v.what); }
void read (std::istream &is, LangAPI::Cast &v)       { read(is, v.type); read(is, v.what); }
void write(std::ostream &os, const LangAPI::GetFromBox &v) { write(os, v.what); }
void read (std::istream &is, LangAPI::GetFromBox &v)       { read(is, v.what); }

void write(std::ostream &os, const LangAPI::RValue &v) { write(os, v.get()); }
void read (std::istream &is, LangAPI::RValue &v)       { read(is, v.get()); } // v.get() returns a mutable ref

void write(std::ostream &os, const LangAPI::Type &v) { write(os, v.type); write(os, v.template_parameters); }
void read (std::istream &is, LangAPI::Type &v)       { read(is, v.type); read(is, v.template_parameters); }

void write(std::ostream &os, const LangAPI::Break&) {}
void read (std::istream &, LangAPI::Break&) {}
void write(std::ostream &os, const LangAPI::Continue&) {}
void read (std::istream &, LangAPI::Continue&) {}
void write(std::ostream &os, const LangAPI::Return &v) { write(os, v.value); }
void read (std::istream &is, LangAPI::Return &v)       { read(is, v.value); }
void write(std::ostream &os, const LangAPI::StringCompare &v) { write(os, v.str); write(os, v.is_string); }
void read (std::istream &is, LangAPI::StringCompare &v)       { read(is, v.str); read(is, v.is_string); }
void write(std::ostream &os, const LangAPI::VariableAssignment &v) { write(os, v.name); write(os, v.type); write(os, v.value); }
void read (std::istream &is, LangAPI::VariableAssignment &v)       { read(is, v.name); read(is, v.type); read(is, v.value); }
void write(std::ostream &os, const LangAPI::CounterIncreament&) {}
void read (std::istream &, LangAPI::CounterIncreament&) {}
void write(std::ostream &os, const LangAPI::AssignCounter &v) { write(os, v.v); }
void read (std::istream &is, LangAPI::AssignCounter &v)       { read(is, v.v); }
void write(std::ostream &os, const LangAPI::ResetPosCounter&) {}
void read (std::istream &, LangAPI::ResetPosCounter&) {}
void write(std::ostream &os, const LangAPI::PushPosCounter &v) { write(os, v.name); }
void read (std::istream &is, LangAPI::PushPosCounter &v)       { read(is, v.name); }
void write(std::ostream &os, const LangAPI::PopPosCounter&) {}
void read (std::istream &, LangAPI::PopPosCounter&) {}
void write(std::ostream &os, const LangAPI::SkipSpaces &v) { write(os, v.isToken); }
void read (std::istream &is, LangAPI::SkipSpaces &v)       { read(is, v.isToken); }
void write(std::ostream &os, const LangAPI::DfaLookup &v) {
    write(os, v.dfa_count); write(os, v.return_type); write(os, v.output_name);
}
void read (std::istream &is, LangAPI::DfaLookup &v) {
    read(is, v.dfa_count); read(is, v.return_type); read(is, v.output_name);
}
void write(std::ostream &os, const LangAPI::ReportError &v) { write(os, v.message); }
void read (std::istream &is, LangAPI::ReportError &v)       { read(is, v.message); }
void write(std::ostream &os, const LangAPI::Lambda &v) { write(os, v.parameters); write(os, v.statements); }
void read (std::istream &is, LangAPI::Lambda &v)       { read(is, v.parameters); read(is, v.statements); }

// AST::RuleMember is not serialized (unknown layout) — see module header.
// Known fields round-trip; `member` stays default-constructed on read,
// which is only ever exercised if the DFADebug escape hatch is bypassed.
void write(std::ostream &os, const LangAPI::DFADebug &v) {
    g_hit_dfadebug = true;
    write(os, v.token_name); write(os, v.position_in_token); write(os, v.call);
    write(os, v.group); write(os, v.rule_run); write(os, v.offset); write(os, v.length); write(os, v.ch);
}
void read (std::istream &is, LangAPI::DFADebug &v) {
    read(is, v.token_name); read(is, v.position_in_token); read(is, v.call);
    read(is, v.group); read(is, v.rule_run); read(is, v.offset); read(is, v.length); read(is, v.ch);
}

void write(std::ostream &os, const LangAPI::ExpressionValue &v) { write(os, v.value); }
void read (std::istream &is, LangAPI::ExpressionValue &v)       { read(is, v.value); }

void write(std::ostream &os, const LangAPI::Expression &v) {
    write(os, static_cast<const stdu::vector<LangAPI::ExpressionValue>&>(v));
}
void read (std::istream &is, LangAPI::Expression &v) {
    stdu::vector<LangAPI::ExpressionValue> tmp; read(is, tmp); v = LangAPI::Expression(std::move(tmp));
}

void write(std::ostream &os, const LangAPI::Variable &v) {
    write(os, v.name); write(os, v.type); write(os, v.value); write(os, v.set);
    write(os, v.nested_array_type); write(os, v.is_static);
}
void read (std::istream &is, LangAPI::Variable &v) {
    read(is, v.name); read(is, v.type); read(is, v.value); read(is, v.set);
    read(is, v.nested_array_type); read(is, v.is_static);
}

void write(std::ostream &os, const LangAPI::ConditionalElement &v) { write(os, v.expr); write(os, v.stmt); }
void read (std::istream &is, LangAPI::ConditionalElement &v)       { read(is, v.expr); read(is, v.stmt); }
void write(std::ostream &os, const LangAPI::If &v) {
    write(os, static_cast<const LangAPI::ConditionalElement&>(v)); write(os, v.else_stmt);
}
void read (std::istream &is, LangAPI::If &v) {
    read(is, static_cast<LangAPI::ConditionalElement&>(v)); read(is, v.else_stmt);
}
void write(std::ostream &os, const LangAPI::While &v) { write(os, static_cast<const LangAPI::ConditionalElement&>(v)); }
void read (std::istream &is, LangAPI::While &v)       { read(is, static_cast<LangAPI::ConditionalElement&>(v)); }
void write(std::ostream &os, const LangAPI::DoWhile &v) { write(os, static_cast<const LangAPI::ConditionalElement&>(v)); }
void read (std::istream &is, LangAPI::DoWhile &v)       { read(is, static_cast<LangAPI::ConditionalElement&>(v)); }

void write(std::ostream &os, const LangAPI::Switch &v) { write(os, v.expression); write(os, v.cases); }
void read (std::istream &is, LangAPI::Switch &v)       { read(is, v.expression); read(is, v.cases); }
void write(std::ostream &os, const LangAPI::Throw &v) { write(os, v.throw_value); }
void read (std::istream &is, LangAPI::Throw &v)       { read(is, v.throw_value); }
void write(std::ostream &os, const LangAPI::Comment &v) { write(os, v.value); }
void read (std::istream &is, LangAPI::Comment &v)       { read(is, v.value); }

void write(std::ostream &os, const LangAPI::Statement &v) { write(os, v.value); }
void read (std::istream &is, LangAPI::Statement &v)       { read(is, v.value); }
void write(std::ostream &os, const LangAPI::Statements &v) {
    write(os, static_cast<const stdu::vector<LangAPI::Statement>&>(v));
}
void read (std::istream &is, LangAPI::Statements &v) {
    stdu::vector<LangAPI::Statement> tmp; read(is, tmp); v = LangAPI::Statements(std::move(tmp));
}

void write(std::ostream &os, const DataBlock &v) { write(os, v.value); }
void read (std::istream &is, DataBlock &v)       { read(is, v.value); }

// ---- top-level entry points ----------------------------------------------
auto writeProductionRecord(std::ostream &os, const Production &p) -> bool {
    g_hit_dfadebug = false;

    std::ostringstream body;
    write(body, p.block);
    write(body, static_cast<const stdu::vector<std::string>&>(p.name));
    write(body, p.members);

    if (g_hit_dfadebug) {
        return false; // caller must not persist this record — see header note
    }

    const std::string bytes = body.str();
    const std::size_t len = bytes.size();
    write(os, len);
    os.write(bytes.data(), static_cast<std::streamsize>(len));
    return true;
}

auto readProductionRecord(std::istream &is) -> std::optional<Production> {
    std::size_t len;
    read(is, len);
    if (!is) return std::nullopt;

    std::string bytes(len, '\0');
    is.read(bytes.data(), static_cast<std::streamsize>(len));
    if (!is) return std::nullopt;

    try {
        std::istringstream body(bytes);
        Production p;
        stdu::vector<std::string> name;
        read(body, p.block);
        read(body, name);
        p.name = name;
        read(body, p.members);
        if (!body) return std::nullopt;
        return p;
    } catch (...) {
        return std::nullopt; // corrupt/foreign record — skip, don't crash the run
    }
}

} // namespace LLIR::Serialize