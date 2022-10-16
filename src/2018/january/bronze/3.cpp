#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("outofplace.in");
auto fout = ofstream("outofplace.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto cows = vector<int>(n);

    for (auto& x : cows) {
        fin >> x;
    }

    auto proper = cows;

    sort(proper.begin(), proper.end());

    auto swaps = 0;

    for (auto i = 0; i < n; ++i) {
        swaps += cows[i] != proper[i];
    }

    if (swaps) {
        --swaps;
    }

    fout << swaps << '\n';

}

int main() {

    solve();

    return 0;

}
