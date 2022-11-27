#include <algorithm>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

using std::ifstream;
using std::multiset;
using std::ofstream;
using std::sort;
using std::unordered_map;
using std::vector;

auto fin = ifstream("measurement.in");
auto fout = ofstream("measurement.out");

struct Entry {

    int cow = 0;
    int day = 0;
    int change = 0;

};

auto solve() {

    auto g = 0;
    auto n = 0;

    fin >> n >> g;

    auto entries = vector<Entry>(n);

    for (auto& x : entries) {
        fin >> x.day >> x.cow >> x.change;
    }

    sort(
        entries.begin(), entries.end(),
        [](const Entry& entry_1, const Entry& entry_2) {
            return entry_1.day < entry_2.day;
        }
    );

    auto adjustments = 0;
    auto cows = unordered_map<int, int>();
    auto outputs = multiset<int>({g});

    for (const auto& x : entries) {
        if (cows.count(x.cow) == 0) {
            cows[x.cow] = g;
            outputs.insert(g);
        }
        auto& output = cows[x.cow];
        const auto shown = output == *outputs.rbegin();
        outputs.erase(outputs.find(output));
        const auto maximum = *outputs.rbegin();
        adjustments += (
            output == maximum || (shown && output + x.change <= maximum) ||
            (!shown && output + x.change >= maximum)
        );
        output += x.change;
        outputs.insert(output);
    }

    fout << adjustments << '\n';

}

int main() {

    solve();

    return 0;

}
