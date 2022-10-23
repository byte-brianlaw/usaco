#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::max;
using std::ofstream;

constexpr auto MOD = 7;

auto fin = ifstream("div7.in");
auto fout = ofstream("div7.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto current = 0;
    auto group = 0;
    auto starts = array<int, 7>();

    starts.fill(-1);
    starts[0] = 0;

    for (auto i = 1; i <= n; ++i) {
        auto id = 0;
        fin >> id;
        current = (current + id) % MOD;
        auto& start = starts[current];
        if (start != -1) {
            group = max(i - start, group);
        } else {
            start = i;
        }
    }

    fout << group << '\n';

}

int main() {

    solve();

    return 0;

}
