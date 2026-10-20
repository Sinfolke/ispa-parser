export module LRBase;
export import AST.API;
export import AST.Tree;
export import AST.types;
export import hash;
export import dstd;
import std;

// Shared, borrowed table interface for LR-family builders and consumers.
export class LRBase {
public:
    using Name = AST::Name;
    enum class Action_type { SHIFT, REDUCE, ACCEPT, DFA_RESOLVE, ERR };

    struct Action {
        Action_type type = Action_type::ERR;
        std::size_t state = 0; // SHIFT target state, REDUCE zero-based rule index
        bool operator==(const Action&) const = default;
    };

    // Lookahead is deliberately not part of the key: propagation must not mutate hash keys.
    struct LR0Core {
        std::size_t production = 0;
        std::size_t dot_pos = 0;
        auto operator<=>(const LR0Core&) const = default;
    };
    using Lookahead = AST::LLkSeq; // k terminals (each terminal is an AST::Name)
    using Lookaheads = AST::LLkSet;

    using CanonicalItem = std::map<LR0Core, Lookaheads>;
    using CanonicalItemSet = std::vector<CanonicalItem>;
    using TransitionRow = std::map<Name, std::size_t>;

    struct Production {
        Name lhs;
        std::vector<Name> rhs;
        // One flag per RHS gap, including the leading/trailing gaps.
        std::vector<bool> whitespace_gaps;
        std::vector<std::size_t> source_members;
        AST::Rule source; // retain the original AST/capture metadata for semantic lowering
    };
    struct ConflictOrigin {
        Action action;
        LR0Core item;
        Name rule;
        std::size_t member = 0; // one-based; end-of-rule reductions point after the last member
        AST::SourcePosition position;
        bool at_end = false;
    };
    struct Conflict {
        std::size_t state = 0;
        Name lookahead;
        std::vector<Action> actions; // all distinct actions, never silently resolved
        Lookahead lookahead_sequence; // full k-symbol window; lookahead is the first symbol
        std::vector<ConflictOrigin> origins;
    };

    struct Decision {
        std::size_t state;
        Lookahead window;
        Action action;
    };
    struct Resolution {
        std::size_t conflict; // index in getConflicts(); original diagnostics remain intact
        std::size_t lookahead = 0; // zero means runtime branching is required
        std::vector<Decision> decisions;
    };

    // Keep the old consumer-facing table / reduction-table types.
    // Compatibility: the original one-token ACTION table works for k=1 only.
    using ActionTable = utype::unordered_map<std::size_t, utype::unordered_map<Name, Action>>;
    using KActionTable = std::map<std::size_t, std::map<Lookahead, Action>>;
    using GotoTable = utype::unordered_map<std::size_t, utype::unordered_map<Name, std::size_t>>;
    using Rules_part = std::pair<Name, std::pair<std::size_t, stdu::vector<std::shared_ptr<AST::RuleMember>>>>;
    using Rules = stdu::vector<Rules_part>;

    virtual ~LRBase() = default;
    virtual void resolveConflicts(std::size_t max_lookahead = 3) = 0;
    virtual bool automaticConflictResolution() const noexcept = 0;
    virtual auto getConflictResolutions() const -> const std::vector<Resolution>& = 0;
    virtual bool needsRuntimeConflictResolution() const noexcept = 0;
    virtual auto getDecisionLookaheadK() const noexcept -> std::size_t = 0;
    virtual bool skipsAutomaticWhitespace() const noexcept { return false; }
    virtual bool isSupported() const noexcept = 0;
    virtual auto getLookaheadK() const noexcept -> std::size_t = 0;
    virtual auto getActionTable() const -> const ActionTable& = 0;
    virtual auto getKActionTable() const -> const KActionTable& = 0;
    virtual auto getGotoTable() const -> const GotoTable& = 0;
    virtual auto getRulesTable() const -> const Rules& = 0;
    virtual auto getProductions() const -> const std::vector<Production>& = 0;
    virtual auto getCanonicalCollection() const -> const CanonicalItemSet& = 0;
    virtual auto getConflicts() const -> const std::vector<Conflict>& = 0;
    virtual bool hasConflicts() const noexcept = 0;
    virtual void requireConflictFree() const = 0;
    virtual auto getActionTableAsRow() const -> stdu::vector<utype::unordered_map<Name, Action>> = 0;
    virtual auto getKActionTableAsRow() const -> stdu::vector<std::map<Lookahead, Action>> = 0;
    virtual auto getGotoTableAsRow() const -> stdu::vector<utype::unordered_map<Name, std::size_t>> = 0;
    virtual auto getMaxStatesCount() const -> std::size_t = 0;
    virtual void printTables(const std::string& filename) const = 0;
    virtual void printCanonicalCollection(const std::string& filename) const = 0;
};
