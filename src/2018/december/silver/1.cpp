#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("convention.in");
auto fout = ofstream("convention.out");

auto solve() {

    auto c = 0;
    auto m = 0;
    auto n = 0;

    fin >> n >> m >> c;

    auto t = vector<int>(n);

    for (auto& x : t) {
        fin >> x;
    }

    sort(t.begin(), t.end());

    auto high = t[n - 1] + 1;
    auto low = -1;

    while (low < high - 1) {
        auto buses = 1;
        auto first = 0;
        const auto middle = (low + high) >> 1;
        for (auto i = 1; i < n && buses <= m; ++i) {
            if (i >= first + c || t[i] > t[first] + middle) {
                ++buses;
                first = i;
            }
        }
        (buses <= m ? high : low) = middle;
    }

    fout << high << '\n';

}

int main() {

    solve();

    return 0;

}
