export module DFAS;
import DFA;
import hash;
import dstd;

export class DFAS {
public:
    using StateSet = stdu::vector<DFA::Transitions>;
    using StateSetLocationMap = utype::unordered_map<std::pair<std::size_t, std::size_t>, std::size_t>;
private:
    stdu::vector<DFA> dfas;
public:
    DFAS(const stdu::vector<DFA> &dfas) : dfas(dfas) {};
    DFAS(stdu::vector<DFA> &&dfas) : dfas(std::move(dfas)) {};
    DFAS() {}

    void getStateSet(StateSet &state_set, StateSetLocationMap &location_in_set) const;
    auto getStateSet() const -> std::pair<StateSet, StateSetLocationMap>;
    auto& getDFAS() const {
        return dfas;
    }
    auto& getDFAS() {
        return dfas;
    }
    auto begin() const {
        return dfas.begin();
    }
    auto begin() {
        return dfas.begin();
    }
    auto end() const {
        return dfas.end();
    }
    auto end() {
        return dfas.end();
    }
};