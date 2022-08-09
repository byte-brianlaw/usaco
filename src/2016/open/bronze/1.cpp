#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::max;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("diamond.in");
auto fout = ofstream("diamond.out");

auto solve() {

    auto k = 0;
    auto n = 0;

    fin >> n >> k;

    auto diamonds = vector<int>(n);

    for (auto& x : diamonds) {
        fin >> x;
    }

    sort(diamonds.begin(), diamonds.end());

    auto showcase = 0;

    for (auto i = 0; i < n; ++i) {
        auto current = 1;
        for (auto j = i + 1; j < n; ++j) {
            if (diamonds[j] > diamonds[i] + k) {
                break;
            }
            ++current;
        }
        showcase = max(current, showcase);
    }

    fout << showcase << '\n';

}

int main() {

    solve();

    return 0;

}
