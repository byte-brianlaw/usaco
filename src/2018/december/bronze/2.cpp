#include <algorithm>
#include <fstream>
#include <map>

using std::ifstream;
using std::map;
using std::max;
using std::ofstream;

auto fin = ifstream("blist.in");
auto fout = ofstream("blist.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto times = map<int, int>();

    for (auto i = 0; i < n; ++i) {
        auto buckets = 0;
        auto end = 0;
        auto start = 0;
        fin >> start >> end >> buckets;
        times[start] = buckets;
        times[end] = -buckets;
    }

    auto buckets = 0;
    auto current = 0;

    for (const auto& x : times) {
        current += x.second;
        buckets = max(current, buckets);
    }

    fout << buckets << '\n';

}

int main() {

    solve();

    return 0;

}
