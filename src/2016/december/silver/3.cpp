#include <algorithm>
#include <array>
#include <fstream>
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

using std::array;
using std::count;
using std::ifstream;
using std::max;
using std::ofstream;
using std::vector;

auto fin = ifstream("moocast.in");
auto fout = ofstream("moocast.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto cows = vector<array<int, 3>>(n);

    for (auto& x : cows) {
        fin >> x[0] >> x[1] >> x[2];
    }

    auto neighbors = vector<vector<int>>(n);

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            const auto square = [](int base) {
                return base * base;
            };
            if (
                square(cows[j][0] - cows[i][0]) + square(cows[j][1] - cows[i][1]) <=
                square(cows[i][2])
            ) {
                neighbors[i].push_back(j);
            }
        }
    }

    auto reach = 0;

    for (auto i = 0; i < n; ++i) {
        auto visited = vector<bool>(n);
        const auto search = YCombinator(
            [&](const auto& search, int cow) -> void {
                visited[cow] = true;
                for (auto x : neighbors[cow]) {
                    if (!visited[x]) {
                        search(x);
                    }
                }
            }
        );
        search(i);
        reach = max(static_cast<int>(count(visited.begin(), visited.end(), true)), reach);
    }

    fout << reach << '\n';

}

int main() {

    solve();

    return 0;

}
