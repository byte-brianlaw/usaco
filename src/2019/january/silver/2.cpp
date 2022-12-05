#include <array>
#include <fstream>
#include <string>
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

using std::array;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

constexpr auto dir_1 = array<int, 4>({1, -1, 0, 0});
constexpr auto dir_2 = array<int, 4>({0, 0, 1, -1});

auto fin = ifstream("perimeter.in");
auto fout = ofstream("perimeter.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto output = vector<string>(n);

    for (auto& x : output) {
        fin >> x;
    }

    auto area = 0;
    auto perimeter = 0;
    auto visited = vector<vector<bool>>(n, vector<bool>(n));

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            if (output[i][j] == '#' && !visited[i][j]) {
                auto cur_area = 0;
                auto cur_perimeter = 0;
                const auto search = YCombinator(
                    [&](const auto& search, int row, int col) -> void {
                        ++cur_area;
                        visited[row][col] = true;
                        for (auto k = 0; k < 4; ++k) {
                            const auto new_row = row + dir_1[k];
                            const auto new_col = col + dir_2[k];
                            if (
                                new_row < 0 || new_row >= n || new_col < 0 || new_col >= n ||
                                output[new_row][new_col] == '.'
                            ) {
                                ++cur_perimeter;
                            } else if (!visited[new_row][new_col]) {
                                search(new_row, new_col);
                            }
                        }
                    }
                );
                search(i, j);
                if (cur_area > area || (cur_area == area && cur_perimeter < perimeter)) {
                    area = cur_area;
                    perimeter = cur_perimeter;
                }
            }
        }
    }

    fout << area << ' ' << perimeter << '\n';

}

int main() {

    solve();

    return 0;

}
