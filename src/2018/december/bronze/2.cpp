#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::ifstream;
using std::max;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("blist.in");
auto fout = ofstream("blist.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto times = vector<array<int, 2>>(n * 2);

    for (auto i = 0; i < n; ++i) {
        auto buckets = 0;
        fin >> times[i * 2][0] >> times[i * 2 + 1][0] >> buckets;
        times[i * 2][1] = buckets;
        times[i * 2 + 1][1] = -buckets;
    }

    sort(times.begin(), times.end());

    auto buckets = 0;
    auto current = 0;

    for (const auto& x : times) {
        current += x[1];
        buckets = max(current, buckets);
    }

    fout << buckets << '\n';

}

int main() {

    solve();

    return 0;

}
