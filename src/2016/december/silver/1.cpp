#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::lower_bound;
using std::ofstream;
using std::sort;
using std::upper_bound;
using std::vector;

auto fin = ifstream("haybales.in");
auto fout = ofstream("haybales.out");

auto solve() {

    auto n = 0;
    auto q = 0;

    fin >> n >> q;

    auto haybales = vector<int>(n);

    for (auto& x : haybales) {
        fin >> x;
    }

    sort(haybales.begin(), haybales.end());

    for (auto i = 0; i < q; ++i) {
        auto a = 0;
        auto b = 0;
        fin >> a >> b;
        fout << (
            upper_bound(haybales.begin(), haybales.end(), b) -
            lower_bound(haybales.begin(), haybales.end(), a)
        ) << '\n';
    }

}

int main() {

    solve();

    return 0;

}
