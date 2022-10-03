#include <algorithm>
#include <fstream>
#include <vector>

using std::count;
using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("taming.in");
auto fout = ofstream("taming.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto events = vector<int>(n);

    events[0] = 1;

    for (auto i = 0; i < n; ++i) {
        auto entry = 0;
        fin >> entry;
        if (entry == -1) {
            continue;
        }
        if (entry > i || events[i - entry] == -1) {
            fout << -1 << '\n';
            return;
        }
        events[i - entry] = 1;
        for (auto j = i - entry + 1; j <= i; ++j) {
            if (events[j] == 1) {
                fout << -1 << '\n';
                return;
            }
            events[j] = -1;
        }
    }

    auto minimum = count(events.begin(), events.end(), 1);

    fout << minimum << ' ' << minimum + count(events.begin(), events.end(), 0) << '\n';

}

int main() {

    solve();

    return 0;

}
