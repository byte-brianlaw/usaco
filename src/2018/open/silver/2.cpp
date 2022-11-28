#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("lemonade.in");
auto fout = ofstream("lemonade.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto w = vector<int>(n);

    for (auto& x : w) {
        fin >> x;
    }

    sort(w.begin(), w.end());

    auto before = 0;

    for (auto i = n - 1; i >= 0; --i) {
        if (w[i] < before) {
            break;
        }
        ++before;
    }

    fout << before << '\n';

}

int main() {

    solve();

    return 0;

}
