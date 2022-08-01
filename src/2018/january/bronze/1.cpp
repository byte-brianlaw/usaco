#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using Billboard = array<array<int, 2>, 2>;

auto fin = ifstream("billboard.in");
auto fout = ofstream("billboard.out");

auto solve() {

    auto cow_feed = Billboard();
    auto lawnmower = Billboard();

    fin >> lawnmower[0][0] >> lawnmower[0][1] >> lawnmower[1][0] >> lawnmower[1][1] >>
    cow_feed[0][0] >> cow_feed[0][1] >> cow_feed[1][0] >> cow_feed[1][1];

    auto tarp = (lawnmower[1][0] - lawnmower[0][0]) * (lawnmower[1][1] - lawnmower[0][1]);

    if (
        cow_feed[0][0] <= lawnmower[0][0] && cow_feed[1][0] >= lawnmower[1][0] &&
        (cow_feed[0][1] <= lawnmower[0][1] || cow_feed[1][1] >= lawnmower[1][1])
    ) {
        tarp -= (
            max(min(cow_feed[1][1], lawnmower[1][1]) - max(cow_feed[0][1], lawnmower[0][1]), 0) *
            (lawnmower[1][0] - lawnmower[0][0])
        );
    } else if (
        cow_feed[0][1] <= lawnmower[0][1] && cow_feed[1][1] >= lawnmower[1][1] &&
        (cow_feed[0][0] <= lawnmower[0][0] || cow_feed[1][0] >= lawnmower[1][0])
    ) {
        tarp -= (
            max(min(cow_feed[1][0], lawnmower[1][0]) - max(cow_feed[0][0], lawnmower[0][0]), 0) *
            (lawnmower[1][1] - lawnmower[0][1])
        );
    }

    fout << tarp << '\n';

}

int main() {

    solve();

    return 0;

}
