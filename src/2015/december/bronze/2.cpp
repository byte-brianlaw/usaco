#include <algorithm>
#include <array>
#include <fstream>

using std::array;
using std::fill_n;
using std::ifstream;
using std::max;
using std::max_element;
using std::ofstream;

auto fin = ifstream("speeding.in");
auto fout = ofstream("speeding.out");

auto solve() {

    auto m = 0;
    auto n = 0;

    fin >> n >> m;

    auto exceeds = array<int, 100>();
    auto location = 0;

    for (auto i = 0; i < n; ++i) {
        auto length = 0;
        auto limit = 0;
        fin >> length >> limit;
        fill_n(exceeds.begin() + location, length, -limit);
        location += length;
    }

    location = 0;

    for (auto i = 0; i < m; ++i) {
        auto length = 0;
        auto speed = 0;
        fin >> length >> speed;
        for (auto j = location; j < location + length; ++j) {
            exceeds[j] += speed;
        }
        location += length;
    }

    fout << max(*max_element(exceeds.begin(), exceeds.end()), 0) << '\n';

}

int main() {

    solve();

    return 0;

}
