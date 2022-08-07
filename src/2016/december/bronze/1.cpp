#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using Pasture = array<array<int, 2>, 2>;

auto fin = ifstream("square.in");
auto fout = ofstream("square.out");

auto solve() {

    auto pasture_1 = Pasture();
    auto pasture_2 = Pasture();
    const auto inputPasture = [&](Pasture& pasture) {
        fin >> pasture[0][0] >> pasture[0][1] >> pasture[1][0] >> pasture[1][1];
    };

    inputPasture(pasture_1);
    inputPasture(pasture_2);

    const auto side = max(
        max(pasture_1[1][0], pasture_2[1][0]) - min(pasture_1[0][0], pasture_2[0][0]),
        max(pasture_1[1][1], pasture_2[1][1]) - min(pasture_1[0][1], pasture_2[0][1])
    );

    fout << side * side << '\n';

}

int main() {

    solve();

    return 0;

}
