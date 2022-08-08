#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::min;
using std::ofstream;

auto fin = ifstream("mixmilk.in");
auto fout = ofstream("mixmilk.out");

auto solve() {

    auto c = array<int, 3>();
    auto m = array<int, 3>();

    for (auto i = 0; i < 3; ++i) {
        fin >> c[i] >> m[i];
    }

    for (auto i = 0; i < 100; ++i) {
        const auto from = i % 3;
        const auto to = (i + 1) % 3;
        const auto amount = min(m[from], c[to] - m[to]);
        m[from] -= amount;
        m[to] += amount;
    }

    for (auto x : m) {
        fout << x << '\n';
    }

}

int main() {

    solve();

    return 0;

}
