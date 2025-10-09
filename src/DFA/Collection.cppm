export module DFA.Collection;

import DFA.API;
import DFA.CharMachineDFA;
import hash;
import dstd;
import std;
export namespace DFA {
    template<typename DfaTable>
    class Collection {
    public:
        using StateSet = DfaTable::StatesType;
        using StateSetLocationMap = utype::unordered_map<std::pair<std::size_t, std::size_t>, std::size_t>;
        using StateInDfaLocationMap = utype::unordered_map<std::size_t, std::size_t>;
        using StateToType = utype::unordered_map<std::size_t, std::pair<DfaType, stdu::vector<std::string>>>;
        struct StateSet_t {
            StateSet state_set {nullptr};
            StateSetLocationMap location_in_set;
            StateInDfaLocationMap state_in_dfa_location_map;
            StateToType state_to_type;
        };
    private:
        stdu::vector<DfaTable> collection;
        bool isToken = true;
        const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct;
    public:
        Collection(bool isToken, const stdu::vector<DfaTable> &collection, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) : isToken(isToken), collection(collection), dct(dct) {};
        Collection(bool isToken, stdu::vector<DfaTable> &&collection, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) : isToken(isToken), collection(std::move(collection)), dct(dct) {};
        Collection() {};

        void getStateSet(StateSet_t &state_set) const;
        auto getStateSet() const -> StateSet_t;
        auto& get() const {
            return collection;
        }
        auto getDct() const {
            return dct;
        }
        auto& get() {
            return collection;
        }
        auto begin() const {
            return collection.begin();
        }
        auto begin() {
            return collection.begin();
        }
        auto end() const {
            return collection.end();
        }
        auto end() {
            return collection.end();
        }
    };
}