#include <algorithm>
#include <fstream>

using std::ifstream;
using std::minmax;
using std::ofstream;

auto fin = ifstream("paint.in");
auto fout = ofstream("paint.out");

auto solve() {

    auto a = 0;
    auto b = 0;
    auto c = 0;
    auto d = 0;

    fin >> a >> b >> c >> d;

    const auto bounds = minmax({a, b, c, d});
    auto painted = 0;

    for (auto i = bounds.first; i < bounds.second; ++i) {
        if ((i >= a && i < b) || (i >= c && i < d)) {
            ++painted;
        }
    }

    fout << painted << '\n';

}

int main() {

    solve();

    return 0;

}
