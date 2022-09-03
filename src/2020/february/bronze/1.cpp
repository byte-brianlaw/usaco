#include <algorithm>
#include <array>
#include <fstream>
#include <unordered_map>
#include <vector>

using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using std::unordered_map;
using std::vector;
using Limits = unordered_map<int, array<int, 2>>;

auto fin = ifstream("triangles.in");
auto fout = ofstream("triangles.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto posts = vector<array<int, 2>>(n);
    auto x_limits = Limits();
    auto y_limits = Limits();

    const auto minifyLimit = [](int key, int value, Limits& limits) {
        if (limits.find(key) == limits.end()) {
            limits[key].fill(value);
        } else {
            limits[key][0] = min(value, limits[key][0]);
            limits[key][1] = max(value, limits[key][1]);
        }
    };

    for (auto& x : posts) {
        fin >> x[0] >> x[1];
        minifyLimit(x[1], x[0], x_limits);
        minifyLimit(x[0], x[1], y_limits);
    }

    auto area = 0;

    for (const auto& x : posts) {
        const auto x_limit = x_limits[x[1]];
        const auto y_limit = y_limits[x[0]];
        area = max(
            max(x[0] - x_limit[0], x_limit[1] - x[0]) * max(x[1] - y_limit[0], y_limit[1] - x[1]),
            area
        );
    }

    fout << area << '\n';

}

int main() {

    solve();

    return 0;

}
