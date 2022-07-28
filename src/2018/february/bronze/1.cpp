#include <algorithm>
#include <cstdlib>
#include <fstream>

using std::abs;
using std::ifstream;
using std::min;
using std::ofstream;

auto fin = ifstream("teleport.in");
auto fout = ofstream("teleport.out");

auto solve() {

    auto a = 0;
    auto b = 0;
    auto x = 0;
    auto y = 0;

    fin >> a >> b >> x >> y;

    fout << min({abs(b - a), abs(x - a) + abs(b - y), abs(y - a) + abs(b - x)}) << '\n';

}

int main() {

    solve();

    return 0;

}
