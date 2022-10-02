#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::max;
using std::ofstream;
using std::sort;

auto fin = ifstream("herding.in");
auto fout = ofstream("herding.out");

auto solve() {

    auto locations = array<int, 3>();

    fin >> locations[0] >> locations[1] >> locations[2];

    sort(locations.begin(), locations.end());

    const auto diff_1 = locations[1] - locations[0];
    const auto diff_2 = locations[2] - locations[1];

    if (diff_1 == 1 && diff_2 == 1) {
        fout << 0;
    } else if (diff_1 == 2 || diff_2 == 2) {
        fout << 1;
    } else {
        fout << 2;
    }

    fout << '\n' << max(diff_1, diff_2) - 1 << '\n';

}

int main() {

    solve();

    return 0;

}
