#include <cstdlib>
#include <fstream>

using std::abs;
using std::ifstream;
using std::ofstream;

auto fin = ifstream("lostcow.in");
auto fout = ofstream("lostcow.out");

auto solve() {

    auto x = 0;
    auto y = 0;

    fin >> x >> y;

    const auto distance = abs(y - x);
    auto move = x > y ? 2 : 1;

    while (move < distance) {
        move *= 4;
    }

    fout << (move - 1) * 2 + distance << '\n';

}

int main() {

    solve();

    return 0;

}
