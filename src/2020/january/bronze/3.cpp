#include <fstream>

using std::ifstream;
using std::ofstream;

auto fin = ifstream("race.in");
auto fout = ofstream("race.out");

auto solve() {

    auto k = 0;
    auto n = 0;

    fin >> k >> n;

    for (auto i = 0; i < n; ++i) {
        auto x = 0;
        fin >> x;
        auto time = 0;
        auto traveled = 0;
        for (auto j = 1; traveled < k; ++j) {
            traveled += j;
            ++time;
            if (traveled >= k) {
                break;
            }
            if (j >= x) {
                traveled += j;
                ++time;
            }
        }
        fout << time << '\n';
    }

}

int main() {

    solve();

    return 0;

}
