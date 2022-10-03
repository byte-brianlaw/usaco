#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::ifstream;
using std::max;
using std::ofstream;
using std::vector;

auto fin = ifstream("lifeguards.in");
auto fout = ofstream("lifeguards.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto counts = array<int, 1000>();
    auto shifts = vector<array<int, 2>>(n);
    auto total = 0;

    for (auto& x : shifts) {
        fin >> x[0] >> x[1];
        for (auto i = x[0]; i < x[1]; ++i) {
            total += counts[i] == 0;
            ++counts[i];
        }
    }

    auto covered = 0;

    for (const auto& x : shifts) {
        auto current = total;
        for (auto i = x[0]; i < x[1]; ++i) {
            if (counts[i] < 2) {
                --current;
            }
        }
        covered = max(current, covered);
    }

    fout << covered << '\n';

}

int main() {

    solve();

    return 0;

}
