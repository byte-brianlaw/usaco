#include <algorithm>
#include <array>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

using std::array;
using std::ifstream;
using std::multiset;
using std::ofstream;
using std::sort;
using std::unordered_map;
using std::vector;
using Entry = array<int, 3>;

auto fin = ifstream("measurement.in");
auto fout = ofstream("measurement.out");

auto solve() {

    auto g = 0;
    auto n = 0;

    fin >> n >> g;

    auto entries = vector<Entry>(n);

    for (auto& x : entries) {
        fin >> x[2] >> x[0] >> x[1];
    }

    sort(
        entries.begin(), entries.end(),
        [](const Entry& entry_1, const Entry& entry_2) {
            return entry_1[2] < entry_2[2];
        }
    );

    auto adjustments = 0;
    auto cows = unordered_map<int, int>();
    auto outputs = multiset<int>({g});

    for (const auto& x : entries) {
        if (cows.count(x[0]) == 0) {
            cows[x[0]] = g;
            outputs.insert(g);
        }
        auto& output = cows[x[0]];
        const auto shown = output == *outputs.rbegin();
        outputs.erase(outputs.find(output));
        const auto maximum = *outputs.rbegin();
        adjustments += (
            output == maximum || (shown && output + x[1] <= maximum) ||
            (!shown && output + x[1] >= maximum)
        );
        output += x[1];
        outputs.insert(output);
    }

    fout << adjustments << '\n';

}

int main() {

    solve();

    return 0;

}
