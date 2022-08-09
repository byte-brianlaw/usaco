#include <algorithm>
#include <fstream>

using std::ifstream;
using std::max;
using std::ofstream;

auto fin = ifstream("pails.in");
auto fout = ofstream("pails.out");

auto solve() {

    auto m = 0;
    auto x = 0;
    auto y = 0;

    fin >> x >> y >> m;

    auto filled = 0;

    for (auto i = 0; i <= m; i += x) {
        filled = max(m - (m - i) % y, filled);
    }

    fout << filled << '\n';

}

int main() {

    solve();

    return 0;

}
