#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::max;
using std::ofstream;
using std::sort;
using std::upper_bound;
using std::vector;

auto fin = ifstream("angry.in");
auto fout = ofstream("angry.out");

auto solve() {

    auto k = 0;
    auto n = 0;

    fin >> n >> k;

    auto high = 0;
    auto x = vector<int>(n);

    for (auto& y : x) {
        fin >> y;
        high = max(y, high);
    }

    sort(x.begin(), x.end());

    auto low = -1;

    while (low < high - 1) {
        const auto middle = (low + high) >> 1;
        auto reached_it = x.begin();
        for (auto i = 0; i < k && reached_it != x.end(); ++i) {
            reached_it = upper_bound(reached_it, x.end(), *reached_it + middle * 2);
        }
        (reached_it == x.end() ? high : low) = middle;
    }

    fout << high << '\n';

}

int main() {

    solve();

    return 0;

}
