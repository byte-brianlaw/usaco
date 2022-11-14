#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::ofstream;

constexpr auto BARN_MAX = 1'000;

auto fin = ifstream("paintbarn.in");
auto fout = ofstream("paintbarn.out");

auto solve() {

    auto k = 0;
    auto n = 0;

    fin >> n >> k;

    auto coats = array<array<int, BARN_MAX + 1>, BARN_MAX + 1>();

    for (auto i = 0; i < n; ++i) {
        auto x_1 = 0;
        auto x_2 = 0;
        auto y_1 = 0;
        auto y_2 = 0;
        fin >> x_1 >> y_1 >> x_2 >> y_2;
        ++coats[y_1][x_1];
        --coats[y_1][x_2];
        --coats[y_2][x_1];
        ++coats[y_2][x_2];
    }

    auto area = 0;

    for (auto i = 0; i <= BARN_MAX; ++i) {
        for (auto j = 0; j <= BARN_MAX; ++j) {
            auto& current = coats[i][j];
            if (i) {
                current += coats[i - 1][j];
            }
            if (j) {
                current += coats[i][j - 1];
            }
            if (i && j) {
                current -= coats[i - 1][j - 1];
            }
            area += current == k;
        }
    }

    fout << area << '\n';

}

int main() {

    solve();

    return 0;

}
