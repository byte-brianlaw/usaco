#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::max_element;
using std::ofstream;

auto fin = ifstream("shell.in");
auto fout = ofstream("shell.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto pebbles = array<int, 3>({1, 2, 3});
    auto scores = array<int, 3>({0, 0, 0});

    for (auto i = 0; i < n; ++i) {
        auto a = 0;
        auto b = 0;
        auto g = 0;
        fin >> a >> b >> g;
        for (auto j = 0; j < 3; ++j) {
            if (pebbles[j] == a) {
                pebbles[j] = b;
            } else if (pebbles[j] == b) {
                pebbles[j] = a;
            }
            if (pebbles[j] == g) {
                ++scores[j];
            }
        }
    }

    fout << *max_element(scores.begin(), scores.end()) << '\n';

}

int main() {

    solve();

    return 0;

}
