#include <algorithm>
#include <array>
#include <cstdlib>
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

using std::abs;
using std::array;
using std::ifstream;
using std::max;
using std::ofstream;
using std::vector;

constexpr auto dir_1 = array<int, 4>({1, -1, 0, 0});
constexpr auto dir_2 = array<int, 4>({0, 0, 1, -1});

auto fin = ifstream("ccski.in");
auto fout = ofstream("ccski.out");

auto solve() {

    auto m = 0;
    auto n = 0;

    fin >> m >> n;

    auto elevations = vector<vector<int>>(m, vector<int>(n));
    auto high = 0;

    for (auto& x : elevations) {
        for (auto& y : x) {
            fin >> y;
            high = max(y + 1, high);
        }
    }

    auto waypoints = vector<array<int, 2>>();

    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            auto waypoint = false;
            fin >> waypoint;
            if (waypoint) {
                waypoints.push_back(array<int, 2>({i, j}));
            }
        }
    }

    auto low = -1;

    while (low < high - 1) {
        const auto middle = (low + high) >> 1;
        auto visited = vector<vector<bool>>(m, vector<bool>(n));
        const auto search = YCombinator(
            [&](const auto& search, int row, int col) -> void {
                visited[row][col] = true;
                for (auto i = 0; i < 4; ++i) {
                    const auto new_row = row + dir_1[i];
                    const auto new_col = col + dir_2[i];
                    if (
                        new_row >= 0 && new_row < m && new_col >= 0 && new_col < n &&
                        abs(elevations[new_row][new_col] - elevations[row][col]) <= middle &&
                        !visited[new_row][new_col]
                    ) {
                        search(new_row, new_col);
                    }
                }
            }
        );
        search(waypoints[0][0], waypoints[0][1]);
        auto valid = true;
        for (const auto& [row, col] : waypoints) {
            if (!visited[row][col]) {
                valid = false;
                break;
            }
        }
        (valid ? high : low) = middle;
    }

    fout << high << '\n';

}

int main() {

    solve();

    return 0;

}
