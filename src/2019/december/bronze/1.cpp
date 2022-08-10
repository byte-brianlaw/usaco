#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("gymnastics.in");
auto fout = ofstream("gymnastics.out");

auto solve() {

    auto k = 0;
    auto n = 0;

    fin >> k >> n;

    auto rankings = vector<vector<int>>(k, vector<int>(n));

    for (auto& x : rankings) {
        for (auto i = 0; i < n; ++i) {
            auto cow = 0;
            fin >> cow;
            x[cow - 1] = i;
        }
    }

    auto pairs = 0;

    for (auto i = 0; i < n; ++i) {
        for (auto j = i + 1; j < n; ++j) {
            auto consistent = true;
            const auto won = rankings[0][i] < rankings[0][j];
            for (const auto& x : rankings) {
                if (x[i] < x[j] != won) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) {
                ++pairs;
            }
        }
    }

    fout << pairs << '\n';

}

int main() {

    solve();

    return 0;

}
