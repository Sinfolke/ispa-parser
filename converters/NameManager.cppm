export module Converter.NameManager;

import dstd;
import std;
export namespace Converter {
    class NameManager {
    public:
        struct NameData {
            std::size_t line;
            std::size_t latest_line;
        };
        void update(const stdu::vector<std::string> &name, const NameData &new_name_data) {
            name_to_line[name] = new_name_data;
        }
        void update(const stdu::vector<std::string> &name, NameData &&new_name_data) {
            name_to_line[name] = std::move(new_name_data);
        }
        auto getNameInRange(std::size_t begin, std::size_t end) -> const stdu::vector<std::string>* {
            const stdu::vector<std::string> *result_name = nullptr;
            const NameData *range = &name_to_line.begin()->second;
            for (const auto &[name, value] : name_to_line) {
                if (value.line >= begin && value.latest_line <= end && range->line < value.line || range->latest_line > value.latest_line) {
                    range = &value;
                    result_name = &name;
                }
            }
            return result_name;
        }
        void increase(const stdu::vector<std::string> &name, std::size_t count = 1) {
            name_to_line[name].latest_line += count;
        }
        auto getLineBySymbol(const stdu::vector<std::string> &sym) -> NameData {
            return name_to_line[sym];
        }
    private:
        std::unordered_map<stdu::vector<std::string>, NameData> name_to_line;
    };
}