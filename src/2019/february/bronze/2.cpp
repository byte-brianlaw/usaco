#include <bitset>
#include <fstream>
#include <vector>

using std::bitset;
using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("revegetate.in");
auto fout = ofstream("revegetate.out");

auto solve() {

    auto m = 0;
    auto n = 0;

    fin >> n >> m;

    auto neighbors = vector<vector<int>>(n);

    for (auto i = 0; i < m; ++i) {
        auto pasture_1 = 0;
        auto pasture_2 = 0;
        fin >> pasture_1 >> pasture_2;
        --pasture_1;
        --pasture_2;
        if (pasture_1 < pasture_2) {
            neighbors[pasture_1].push_back(pasture_2);
        } else {
            neighbors[pasture_2].push_back(pasture_1);
        }
    }

    auto used = vector<bitset<4>>(n);

    for (auto i = 0; i < n; ++i) {
        auto seed = 0;
        for (auto j = 0; j < 4; ++j) {
            if (!used[i][j]) {
                seed = j + 1;
                break;
            }
        }
        fout << seed;
        for (auto x : neighbors[i]) {
            used[x][seed - 1] = true;
        }
    }

    fout << '\n';

}

int main() {

    solve();

    return 0;

}
