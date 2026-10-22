// Canonical LR(k) table generator for ISPA's normalized AST::Tree productions.
// Builds parsing tables only. The target-language LangAPI lowering is a separate step.
export module LRParser;
export import LRBase;
export import AST.Tree;
export import AST.API;
export import AST.types;
export import hash;
export import dstd;
import std;

// C++ module export controls visibility to importers, not DLL symbol exports.
// LALR and LR_STAR need the protected constructor and inherited virtual methods
// even when MSVC would otherwise inline them away in the LR DLL.
#if defined(_WIN32)
#define ISPA_LR_EXPORT __declspec(dllexport)
#else
#define ISPA_LR_EXPORT
#endif

export class ISPA_LR_EXPORT LRParser : public LRBase {
protected:
    AST::Tree* tree = nullptr; // borrowed; must outlive parser
    ActionTable action_table; // populated only when k==1
    KActionTable k_action_table;
    GotoTable goto_table;
    Rules rules;
    CanonicalItemSet canonical_item_set;
    std::vector<TransitionRow> transitions;
    std::vector<Production> productions; // [0] is synthetic augmented production
    std::vector<Conflict> conflicts;
    std::vector<Resolution> resolutions;
    bool auto_conflicts = false;
    std::size_t decision_k = 1;
    std::map<Name, std::vector<std::size_t>> productions_by_lhs;
    std::map<Name, Lookaheads> first_k;
    bool skip_automatic_whitespace = false;
    std::size_t k = 1;
    Name eof = Name{"$"};
    Name augmented = Name{"__ispa_lr_augmented"};

    explicit LRParser(AST::Tree* t, std::size_t k, bool build_immediately);
    virtual void build();
    void buildCanonical();
    void buildTables();
    void prepareProductions();
    void computeFirstK();
    auto concatenate(const Lookaheads& left, const Lookaheads& right) const -> Lookaheads;
    auto firstOfSuffix(const Production& production, std::size_t begin,
                       const Lookahead& trailing, const Name* prepend = nullptr) const -> Lookaheads;
    auto closure(CanonicalItem items) const -> CanonicalItem;
    auto closureUncached(CanonicalItem items) const -> CanonicalItem;

    struct Proposal { Lookahead window; Action action; LR0Core item; };
    std::vector<std::string> production_keys;
    std::map<std::string, std::size_t> production_ids;
    std::vector<std::string> state_keys;
    std::map<std::string, std::size_t> state_ids;
    mutable std::map<std::string, std::string> cached_closures, current_closures;
    std::map<std::string, std::string> cached_rows, current_rows;
    std::string cached_resolutions;
    mutable std::map<std::set<LR0Core>, std::string> dependency_stamps;
    virtual auto cacheKind() const -> std::string_view { return "LR"; }
    void loadCache(std::string_view bytes);
    void prepareCacheKeys();
    auto itemKey(const CanonicalItem& items) const -> std::string;
    auto dependencyStamp(const CanonicalItem& items) const -> std::string;
    auto encodeItems(const CanonicalItem& items) const -> std::string;
    auto decodeItems(std::string_view bytes) const -> CanonicalItem;
    auto proposalsForState(std::size_t state) -> std::vector<Proposal>;
    auto restoreResolutions(std::size_t max_lookahead) -> bool;
    void cacheResolutions(std::size_t max_lookahead);
    auto resolutionKey(std::size_t max_lookahead) const -> std::string;

    auto goTo(const CanonicalItem& items, const Name& symbol) const -> CanonicalItem;
    auto isNonterminal(const Name& name) const -> bool;
    static bool looksLikeTerminal(const Name& name);
    auto conflictOrigin(Action action, const LR0Core& core) const -> ConflictOrigin;
    auto formatConflict(const Conflict& conflict) const -> std::string;
    static auto formatName(const Name& name) -> std::string;
    static auto formatSequence(const Lookahead& sequence) -> std::string;
    static auto formatItem(const LR0Core& core, const Lookaheads& lookahead,
                           const std::vector<Production>& productions) -> std::string;

public:
    struct CacheStats {
        std::size_t closures_reused = 0, closures_built = 0;
        std::size_t rows_reused = 0, rows_built = 0;
        bool resolutions_reused = false;
    };
private:
    mutable CacheStats cache_stats;
public:
    auto getCacheStats() const -> const CacheStats& { return cache_stats; }
    auto saveCache() const -> std::string;
    explicit LRParser(AST::Tree* tree, std::size_t k = 1, std::string_view cache = {});
    explicit LRParser(AST::Tree& tree, std::size_t k = 1);
    virtual ~LRParser() = default;
    LRParser(const LRParser&) = delete;
    LRParser& operator=(const LRParser&) = delete;

    void resolveConflicts(std::size_t max_lookahead = 3) override;
    bool automaticConflictResolution() const noexcept override { return auto_conflicts; }
    auto getConflictResolutions() const -> const std::vector<Resolution>& override { return resolutions; }
    bool needsRuntimeConflictResolution() const noexcept override {
        return std::any_of(resolutions.begin(), resolutions.end(), [](const auto& r) { return r.lookahead == 0; });
    }
    auto getDecisionLookaheadK() const noexcept -> std::size_t override { return auto_conflicts ? decision_k : k; }
    bool skipsAutomaticWhitespace() const noexcept override { return skip_automatic_whitespace; }
    virtual bool isSupported() const noexcept override { return true; }
    static auto ActionTypeToString(Action_type type) -> std::string;
    auto getLookaheadK() const noexcept -> std::size_t override { return k; }
    auto getActionTable() const -> const ActionTable& override; // throws for k>1
    auto getKActionTable() const -> const KActionTable& override { return k_action_table; }
    auto getGotoTable() const -> const GotoTable& override { return goto_table; }
    auto getRulesTable() const -> const Rules& override { return rules; }
    auto getProductions() const -> const std::vector<Production>& override { return productions; }
    auto getCanonicalCollection() const -> const CanonicalItemSet& override { return canonical_item_set; }
    auto getConflicts() const -> const std::vector<Conflict>& override { return conflicts; }
    bool hasConflicts() const noexcept override { return !conflicts.empty(); }
    void requireConflictFree() const override;
    auto getActionTableAsRow() const -> stdu::vector<utype::unordered_map<Name, Action>> override;
    auto getKActionTableAsRow() const -> stdu::vector<std::map<Lookahead, Action>> override;
    auto getGotoTableAsRow() const -> stdu::vector<utype::unordered_map<Name, std::size_t>> override;
    auto getMaxStatesCount() const -> std::size_t override;
    void printTables(const std::string& filename) const override;
    void printCanonicalCollection(const std::string& filename) const override;
};

#undef ISPA_LR_EXPORT
