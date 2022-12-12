#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::ifstream;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("reststops.in");
auto fout = ofstream("reststops.out");

auto solve() {

    auto l = 0;
    auto n = 0;
    auto rate_1 = 0;
    auto rate_2 = 0;

    fin >> l >> n >> rate_1 >> rate_2;

    auto stops = vector<array<int, 2>>(n);

    for (auto& x : stops) {
        fin >> x[0] >> x[1];
    }

    sort(stops.begin(), stops.end());

    auto maximum = 0;
    auto rest = vector<bool>(n);

    for (auto i = n - 1; i >= 0; --i) {
        const auto tastiness = stops[i][1];
        if (tastiness > maximum) {
            rest[i] = true;
            maximum = tastiness;
        }
    }

    auto reached = 0;
    auto tastiness = 0ll;

    for (auto i = 0; i < n; ++i) {
        if (rest[i]) {
            const auto location = stops[i][0];
            tastiness += (
                static_cast<long long>(stops[i][1]) * (rate_1 - rate_2) * (location - reached)
            );
            reached = location;
        }
    }

    fout << tastiness << '\n';

}

int main() {

    solve();

    return 0;

}
