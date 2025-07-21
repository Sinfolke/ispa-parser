export module DFAS;
import DFA;
import hash;
import dstd;

export class DFAS {
public:
    using StateSet = stdu::vector<DFA::SingleState>;
    using StateSetLocationMap = utype::unordered_map<std::pair<std::size_t, std::size_t>, std::size_t>;
    using StateInDfaLocationMap = utype::unordered_map<std::size_t, std::size_t>;
    struct StateSet_t {
        StateSet state_set;
        StateSetLocationMap location_in_set;
        StateInDfaLocationMap state_in_dfa_location_map;
    };
private:
    stdu::vector<DFA> dfas;
    bool isToken = true;
public:
    DFAS(bool isToken, const stdu::vector<DFA> &dfas) : isToken(isToken), dfas(dfas) {};
    DFAS(bool isToken, stdu::vector<DFA> &&dfas) : isToken(isToken), dfas(std::move(dfas)) {};
    DFAS() {}

    void getStateSet(StateSet_t &state_set) const;
    auto getStateSet() const -> StateSet_t;
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