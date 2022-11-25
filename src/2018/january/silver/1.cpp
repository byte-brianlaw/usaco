#include <algorithm>
#include <fstream>
#include <unordered_set>
#include <utility>
#include <vector>

using std::ifstream;
using std::min_element;
using std::ofstream;
using std::pair;
using std::sort;
using std::unordered_set;
using std::vector;

auto fin = ifstream("lifeguards.in");
auto fout = ofstream("lifeguards.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto endpoints = vector<pair<int, int>>(n << 1);

    for (auto i = 0; i < n; ++i) {
        auto& start = endpoints[i << 1];
        auto& end = endpoints[i * 2 + 1];
        fin >> start.first >> end.first;
        start.second = i;
        end.second = i;
    }

    sort(endpoints.begin(), endpoints.end());

    auto alone = vector<int>(n);
    auto present = unordered_set<int>();
    auto previous = 0;
    auto time = 0;

    for (const auto& x : endpoints) {
        const auto duration = x.first - previous;
        if (!present.empty()) {
            time += duration;
        }
        if (present.size() == 1) {
            alone[*present.begin()] += duration;
        }
        if (present.count(x.second) == 0) {
            present.insert(x.second);
        } else {
            present.erase(x.second);
        }
        previous = x.first;
    }

    time -= *min_element(alone.begin(), alone.end());

    fout << time << '\n';

}

int main() {

    solve();

    return 0;

}
