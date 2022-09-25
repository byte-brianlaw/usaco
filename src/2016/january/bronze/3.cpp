#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::min;
using std::ofstream;

constexpr auto GRID_SIZE = 2001;

auto fin = ifstream("mowing.in");
auto fout = ofstream("mowing.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto farm = array<array<int, GRID_SIZE>, GRID_SIZE>();
    auto t = 0;
    auto x = 1001;
    auto x_pos = 1000;
    auto y_pos = 1000;

    for (auto& y : farm) {
        y.fill(-1);
    }

    farm[1000][1000] = 0;

    for (auto i = 0; i < n; ++i) {
        auto d = '\0';
        auto s = 0;
        fin >> d >> s;
        auto x_change = 0;
        auto y_change = 0;
        if (d == 'E') {
            x_change = 1;
        } else if (d == 'N') {
            y_change = 1;
        } else if (d == 'S') {
            y_change = -1;
        } else {
            x_change = -1;
        }
        for (auto j = 0; j < s; ++j) {
            ++t;
            x_pos += x_change;
            y_pos += y_change;
            if (farm[x_pos][y_pos] != -1) {
                x = min(t - farm[x_pos][y_pos], x);
            }
            farm[x_pos][y_pos] = t;
        }
    }

    if (x != 1001) {
        fout << x;
    } else {
        fout << -1;
    }

    fout << '\n';

}

int main() {

    solve();

    return 0;

}
