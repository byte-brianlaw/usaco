#include <algorithm>
#include <array>
#include <cstdlib>
#include <fstream>

using std::abs;
using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;

auto fin = ifstream("buckets.in");
auto fout = ofstream("buckets.out");

auto solve() {

    auto barn = array<int, 2>();
    auto lake = array<int, 2>();
    auto rock = array<int, 2>();

    for (auto i = 0; i < 10; ++i) {
        for (auto j = 0; j < 10; ++j) {
            auto square = '\0';
            fin >> square;
            if (square == 'B') {
                barn[0] = j;
                barn[1] = i;
            } else if (square == 'L') {
                lake[0] = j;
                lake[1] = i;
            } else if (square == 'R') {
                rock[0] = j;
                rock[1] = i;
            }
        }
    }

    auto cows = abs(lake[0] - barn[0]) + abs(lake[1] - barn[1]) - 1;
    const auto isBetween = [](int number, int bound_1, int bound_2) {
        return number > min(bound_1, bound_2) && number < max(bound_1, bound_2);
    };

    if (
        (barn[0] == lake[0] && barn[0] == rock[0] && isBetween(rock[1], barn[1], lake[1])) ||
        (barn[1] == lake[1] && barn[1] == rock[1] && isBetween(rock[0], barn[0], lake[0]))
    ) {
        cows += 2;
    }

    fout << cows << '\n';

}

int main() {

    solve();

    return 0;

}
