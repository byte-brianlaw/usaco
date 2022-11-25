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

    auto reached = 0;
    auto together = vector<int>(n);

    for (auto i = 0; i < n; ++i) {
        while (reached < n && diamonds[reached] <= diamonds[i] + k) {
            ++reached;
        }
        together[i] = reached - i;
    }

    auto after = vector<int>(n + 1);
    auto showcase = 0;

    for (auto i = n - 1; i >= 0; --i) {
        const auto current = together[i];
        after[i] = max(current, after[i + 1]);
        showcase = max(current + after[i + current], showcase);
    }

    fout << showcase << '\n';

}

int main() {

    solve();

    return 0;

}
