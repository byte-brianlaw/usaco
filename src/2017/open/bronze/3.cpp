#include <algorithm>
#include <array>
#include <fstream>
#include <string>
#include <vector>

using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using std::string;
using std::vector;

auto fin = ifstream("art.in");
auto fout = ofstream("art.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto canvas = vector<string>(n);
    auto rectangles = array<array<array<int, 2>, 2>, 9>();

    for (auto& x : rectangles) {
        x[0].fill(-1);
        x[1].fill(-1);
    }

    for (auto i = 0; i < n; ++i) {
        fin >> canvas[i];
        for (auto j = 0; j < n; ++j) {
            auto color = canvas[i][j];
            if (color != '0') {
                auto& [corner_min, corner_max] = rectangles[color - '1'];
                if (corner_min[0] != -1) {
                    corner_min[1] = min(j, corner_min[1]);
                } else {
                    corner_min[0] = i;
                    corner_min[1] = j;
                }
                corner_max[0] = i;
                corner_max[1] = max(j, corner_max[1]);
            }
        }
    }

    auto layers = vector<vector<int>>(n, vector<int>(n));

    for (const auto& x : rectangles) {
        if (x[0][0] != -1) {
            for (auto i = x[0][0]; i <= x[1][0]; ++i) {
                for (auto j = x[0][1]; j <= x[1][1]; ++j) {
                    ++layers[i][j];
                }
            }
        }
    }

    auto colors = 0;

    for (auto i = 0; i < 9; ++i) {
        const auto& rectangle = rectangles[i];
        if (rectangle[0][0] != -1) {
            auto valid = true;
            for (auto j = rectangle[0][0]; j <= rectangle[1][0] && valid; ++j) {
                for (auto k = rectangle[0][1]; k <= rectangle[1][1] && valid; ++k) {
                    valid = canvas[j][k] != i + '1' || layers[j][k] == 1;
                }
            }
            colors += valid;
        }
    }

    fout << colors << '\n';

}

int main() {

    solve();

    return 0;

}
