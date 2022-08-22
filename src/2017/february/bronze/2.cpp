#include <bitset>
#include <fstream>
#include <string>

using std::bitset;
using std::ifstream;
using std::ofstream;
using std::string;

auto fin = ifstream("circlecross.in");
auto fout = ofstream("circlecross.out");

auto solve() {

    auto points = string();

    fin >> points;

    auto done = bitset<26>();
    auto pairs = 0;

    for (auto i = 0; i < 52; ++i) {
        const auto cow = points[i];
        if (!done[cow - 'A']) {
            auto crossings = bitset<26>();
            for (auto j = i + 1; j < 52; ++j) {
                if (points[j] == cow) {
                    break;
                }
                crossings.flip(points[j] - 'A');
            }
            pairs += crossings.count();
            done[cow - 'A'] = true;
        }
    }

    pairs /= 2;

    fout << pairs << '\n';

}

int main() {

    solve();

    return 0;

}
