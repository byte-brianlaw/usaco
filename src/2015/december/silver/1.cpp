#include <algorithm>
#include <array>
#include <fstream>
#include <numeric>
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

using std::accumulate;
using std::array;
using std::count;
using std::ifstream;
using std::ofstream;
using std::vector;
using Room = array<int, 2>;

constexpr auto dir_1 = array<int, 4>({1, -1, 0, 0});
constexpr auto dir_2 = array<int, 4>({0, 0, 1, -1});

auto fin = ifstream("lightson.in");
auto fout = ofstream("lightson.out");

auto solve() {

    auto m = 0;
    auto n = 0;

    fin >> n >> m;

    auto switches = vector<vector<vector<Room>>>(n, vector<vector<Room>>(n));

    for (auto i = 0; i < m; ++i) {
        auto a = 0;
        auto b = 0;
        auto x = 0;
        auto y = 0;
        fin >> x >> y >> a >> b;
        --a;
        --b;
        --x;
        --y;
        switches[y][x].push_back(Room({b, a}));
    }

    auto illuminated = vector<vector<bool>>(n, vector<bool>(n));

    illuminated[0][0] = true;

    auto visited = vector<vector<bool>>(n, vector<bool>(n));

    const auto search = YCombinator(
        [&](const auto& search, int row, int col) -> void {
            visited[row][col] = true;
            const auto isValid = [&](int test_row, int test_col) {
                return test_row >= 0 && test_row < n && test_col >= 0 && test_col < n;
            };
            for (const auto& [switch_row, switch_col] : switches[row][col]) {
                if (!illuminated[switch_row][switch_col]) {
                    illuminated[switch_row][switch_col] = true;
                    for (auto i = 0; i < 4; ++i) {
                        const auto new_row = switch_row + dir_1[i];
                        const auto new_col = switch_col + dir_2[i];
                        if (isValid(new_row, new_col) && visited[new_row][new_col]) {
                            search(switch_row, switch_col);
                            break;
                        }
                    }
                }
            }
            for (auto i = 0; i < 4; ++i) {
                const auto new_row = row + dir_1[i];
                const auto new_col = col + dir_2[i];
                if (
                    isValid(new_row, new_col) && illuminated[new_row][new_col] &&
                    !visited[new_row][new_col]
                ) {
                    search(new_row, new_col);
                }
            }
        }
    );

    search(0, 0);

    fout << accumulate(
        illuminated.begin(), illuminated.end(), 0,
        [](int a, const vector<bool>& b) {
            return a + count(b.begin(), b.end(), true);
        }
    ) << '\n';

}

int main() {

    solve();

    return 0;

}
