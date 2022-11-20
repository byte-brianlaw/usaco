#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <vector>

using std::abs;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using std::vector;

auto fin = ifstream("lazy.in");
auto fout = ofstream("lazy.out");

auto solve() {

    auto k = 0;
    auto n = 0;

    fin >> n >> k;

    auto prefixes = vector<vector<int>>(n, vector<int>(n + 1));

    for (auto& x : prefixes) {
        for (auto i = 1; i <= n; ++i) {
            fin >> x[i];
            x[i] += x[i - 1];
        }
    }

    auto grass = 0;

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            auto current = 0;
            for (auto l = 0; l < n; ++l) {
                const auto extra = k - abs(i - l);
                if (extra >= 0) {
                    current += prefixes[l][min(j + extra + 1, n)] - prefixes[l][max(j - extra, 0)];
                }
            }
            grass = max(current, grass);
        }
    }

    fout << grass << '\n';

}

int main() {

    solve();

    return 0;

}
