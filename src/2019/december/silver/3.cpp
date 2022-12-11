#include <fstream>
#include <string>
#include <utility>
#include <vector>

template <typename FunctionObject>
class YCombinator {

private:

    const FunctionObject function = nullptr;

public:

    template <typename Lambda>
    explicit YCombinator(Lambda&& lambda) : function(lambda) {}

    template <typename... Arguments>
    decltype(auto) operator()(Arguments&&... arguments) const {

        return function(*this, std::forward<Arguments>(arguments)...);

    }

};

template <typename Lambda>
YCombinator(Lambda) -> YCombinator<Lambda>;

using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

auto fin = ifstream("milkvisits.in");
auto fout = ofstream("milkvisits.out");

auto solve() {

    auto m = 0;
    auto n = 0;
    auto types = string();

    fin >> n >> m >> types;

    auto neighbors = vector<vector<int>>(n);

    for (auto i = 0; i < n - 1; ++i) {
        auto farm_1 = 0;
        auto farm_2 = 0;
        fin >> farm_1 >> farm_2;
        --farm_1;
        --farm_2;
        neighbors[farm_1].push_back(farm_2);
        neighbors[farm_2].push_back(farm_1);
    }

    auto components = vector<int>(n, -1);

    for (auto i = 0; i < n; ++i) {
        if (components[i] == -1) {
            const auto search = YCombinator(
                [&](const auto& search, int farm, int parent) -> void {
                    components[farm] = i;
                    for (auto x : neighbors[farm]) {
                        if (types[x] == types[i] && x != parent) {
                            search(x, farm);
                        }
                    }
                }
            );
            search(i, -1);
        }
    }

    for (auto i = 0; i < m; ++i) {
        auto farm_1 = 0;
        auto farm_2 = 0;
        auto type = '\0';
        fin >> farm_1 >> farm_2 >> type;
        --farm_1;
        --farm_2;
        fout << (components[farm_1] != components[farm_2] || types[farm_1] == type);
    }

    fout << '\n';

}

int main() {

    solve();

    return 0;

}
