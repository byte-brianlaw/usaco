#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::ifstream;
using std::max;
using std::ofstream;
using std::vector;

auto fin = ifstream("hps.in");
auto fout = ofstream("hps.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto prefixes = array<vector<int>, 3>();

    prefixes.fill(vector<int>(n));

    for (auto i = 0; i < n; ++i) {
        if (i) {
            for (auto& x : prefixes) {
                x[i] = x[i - 1];
            }
        }
        auto gesture = '\0';
        fin >> gesture;
        if (gesture == 'H') {
            ++prefixes[0][i];
        } else if (gesture == 'P') {
            ++prefixes[1][i];
        } else {
            ++prefixes[2][i];
        }
    }

    auto win = 0;

    for (auto i = 0; i < n; ++i) {
        auto after = 0;
        auto before = 0;
        for (const auto& x : prefixes) {
            after = max(x[n - 1] - x[i], after);
            before = max(x[i], before);
        }
        win = max(after + before, win);
    }

    fout << win << '\n';

}

int main() {

    solve();

    return 0;

}
