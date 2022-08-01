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

    const auto calculateArea = [](Item& item) {
        return (item[1][0] - item[0][0]) * (item[1][1] - item[0][1]);
    };
    const auto calculateIntersection = [](Item& item_1, Item& item_2) {
        return (
            max(min(item_1[1][0], item_2[1][0]) - max(item_1[0][0], item_2[0][0]), 0) *
            max(min(item_1[1][1], item_2[1][1]) - max(item_1[0][1], item_2[0][1]), 0)
        );
    };

    fout << (
        calculateArea(billboard_1) + calculateArea(billboard_2) -
        calculateIntersection(billboard_1, truck) - calculateIntersection(billboard_2, truck)
    ) << '\n';

}

int main() {

    solve();

    return 0;

}
