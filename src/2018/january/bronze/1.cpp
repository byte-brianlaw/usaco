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
    const auto inputBillboard = [&](Billboard& billboard) {
        fin >> billboard[0][0] >> billboard[0][1] >> billboard[1][0] >> billboard[1][1];
    };

    inputBillboard(cow_feed);
    inputBillboard(lawnmower);

    auto covered = 0;
    const auto checkCovered = [&](int x, int y) {
        if (
            x >= lawnmower[0][0] && x <= lawnmower[1][0] && y >= lawnmower[0][1] &&
            y <= lawnmower[1][1]
        ) {
            ++covered;
        }
    };

    checkCovered(cow_feed[0][0], cow_feed[0][1]);
    checkCovered(cow_feed[0][0], cow_feed[1][1]);
    checkCovered(cow_feed[1][0], cow_feed[0][1]);
    checkCovered(cow_feed[1][0], cow_feed[1][1]);

    auto tarp = 0;

    if (covered < 4) {
        tarp = (cow_feed[1][0] - cow_feed[0][0]) * (cow_feed[1][1] - cow_feed[0][1]);
    }

    if (covered == 2) {
        tarp -= (
            (min(cow_feed[1][0], lawnmower[1][0]) - max(cow_feed[0][0], lawnmower[0][0])) *
            (min(cow_feed[1][1], lawnmower[1][1]) - max(cow_feed[0][1], lawnmower[0][1]))
        );
    }

    fout << tarp << '\n';

}

int main() {

    solve();

    return 0;

}
