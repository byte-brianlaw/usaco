#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using Item = array<array<int, 2>, 2>;

auto fin = ifstream("billboard.in");
auto fout = ofstream("billboard.out");

auto solve() {

    auto billboard_1 = Item();
    auto billboard_2 = Item();
    auto truck = Item();
    const auto inputItem = [&](Item& item) {
        fin >> item[0][0] >> item[0][1] >> item[1][0] >> item[1][1];
    };

    inputItem(billboard_1);
    inputItem(billboard_2);
    inputItem(truck);

    const auto calculateVisible = [&](const Item& billboard) {
        return (
            ((billboard[1][0] - billboard[0][0]) * (billboard[1][1] - billboard[0][1])) -
            (
                max(min(billboard[1][0], truck[1][0]) - max(billboard[0][0], truck[0][0]), 0) *
                max(min(billboard[1][1], truck[1][1]) - max(billboard[0][1], truck[0][1]), 0)
            )
        );
    };

    fout << calculateVisible(billboard_1) + calculateVisible(billboard_2) << '\n';

}

int main() {

    solve();

    return 0;

}
