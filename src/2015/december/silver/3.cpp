#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("bcount.in");
auto fout = ofstream("bcount.out");

auto solve() {

    auto n = 0;
    auto q = 0;

    fin >> n >> q;

    auto prefixes = array<vector<int>, 3>();

    prefixes.fill(vector<int>(n + 1));

    for (auto i = 1; i <= n; ++i) {
        for (auto& x : prefixes) {
            x[i] = x[i - 1];
        }
        auto breed = 0;
        fin >> breed;
        ++prefixes[breed - 1][i];
    }

    for (auto i = 0; i < q; ++i) {
        auto a = 0;
        auto b = 0;
        fin >> a >> b;
        for (auto j = 0; j < 3; ++j) {
            fout << prefixes[j][b] - prefixes[j][a - 1] << (j != 2 ? ' ' : '\n');
        }
    }

}

int main() {

    solve();

    return 0;

}
