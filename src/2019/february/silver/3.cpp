#include <fstream>
#include <utility>
#include <vector>

template <typename T>
class YCombinator {

private:

    const T lambda = nullptr;

public:

    template <typename U>
    explicit YCombinator(U&& lambda) : lambda(lambda) {}

    template <typename... Arguments>
    decltype(auto) operator()(Arguments&&... arguments) const {

        return lambda(*this, std::forward<Arguments>(arguments)...);

    }

};

template <typename T>
YCombinator(T) -> YCombinator<T>;

using std::ifstream;
using std::ofstream;
using std::pair;
using std::vector;

auto fin = ifstream("revegetate.in");
auto fout = ofstream("revegetate.out");

auto solve() {

    auto m = 0;
    auto n = 0;

    fin >> n >> m;

    auto neighbors = vector<vector<pair<int, bool>>>(n);

    for (auto i = 0; i < m; ++i) {
        auto pasture_1 = 0;
        auto pasture_2 = 0;
        auto type = '\0';
        fin >> type >> pasture_1 >> pasture_2;
        --pasture_1;
        --pasture_2;
        neighbors[pasture_1].emplace_back(pasture_2, type == 'S');
        neighbors[pasture_2].emplace_back(pasture_1, type == 'S');
    }

    auto components = 0;
    auto types = vector<int>(n, -1);

    for (auto i = 0; i < n; ++i) {
        if (types[i] == -1) {
            const auto search = YCombinator(
                [&](const auto& search, int pasture, bool type) -> bool {
                    types[pasture] = type;
                    for (const auto& [neighbor, same] : neighbors[pasture]) {
                        if (types[neighbor] == -1) {
                            if (!search(neighbor, !type ^ same)) {
                                return false;
                            }
                        } else if ((type == types[neighbor]) ^ same) {
                            return false;
                        }
                    }
                    return true;
                }
            );
            if (!search(i, false)) {
                fout << 0 << '\n';
                return;
            }
            ++components;
        }
    }

    fout << 1;

    for (auto i = 0; i < components; ++i) {
        fout << 0;
    }

    fout << '\n';

}

int main() {

    solve();

    return 0;

}
