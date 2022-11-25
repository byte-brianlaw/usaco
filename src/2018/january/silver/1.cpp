#include <algorithm>
#include <array>
#include <fstream>
#include <unordered_set>
#include <vector>

using std::array;
using std::ifstream;
using std::min_element;
using std::ofstream;
using std::sort;
using std::unordered_set;
using std::vector;

auto fin = ifstream("lifeguards.in");
auto fout = ofstream("lifeguards.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto endpoints = vector<array<int, 2>>(n << 1);

    for (auto i = 0; i < n; ++i) {
        auto& start = endpoints[i << 1];
        auto& end = endpoints[i * 2 + 1];
        fin >> start[0] >> end[0];
        start[1] = i;
        end[1] = i;
    }

    sort(endpoints.begin(), endpoints.end());

    auto alone = vector<int>(n);
    auto present = unordered_set<int>();
    auto previous = 0;
    auto time = 0;

    for (const auto& x : endpoints) {
        const auto duration = x[0] - previous;
        const auto lifeguard = x[1];
        if (!present.empty()) {
            time += duration;
        }
        if (present.size() == 1) {
            alone[*present.begin()] += duration;
        }
        if (present.count(lifeguard) == 0) {
            present.insert(lifeguard);
        } else {
            present.erase(lifeguard);
        }
        previous = x[0];
    }

    time -= *min_element(alone.begin(), alone.end());

    fout << time << '\n';

}

int main() {

    solve();

    return 0;

}
