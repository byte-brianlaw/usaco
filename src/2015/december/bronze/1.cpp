#include <algorithm>
#include <fstream>

using std::ifstream;
using std::max;
using std::min;
using std::ofstream;

auto fin = ifstream("paint.in");
auto fout = ofstream("paint.out");

auto solve() {

    auto a = 0;
    auto b = 0;
    auto c = 0;
    auto d = 0;

    fin >> a >> b >> c >> d;

    fout << b - a + d - c - max(min(b, d) - max(a, c), 0) << '\n';

}

int main() {

    solve();

    return 0;

}
