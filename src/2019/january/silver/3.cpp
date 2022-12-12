#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::ifstream;
using std::ofstream;
using std::sort;
using std::vector;
using Mountain = array<int, 2>;

auto fin = ifstream("mountains.in");
auto fout = ofstream("mountains.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto mountains = vector<Mountain>(n);

    for (auto& x : mountains) {
        auto x_coord = 0;
        auto y_coord = 0;
        fin >> x_coord >> y_coord;
        x[0] = x_coord - y_coord;
        x[1] = x_coord + y_coord;
    }

    sort(
        mountains.begin(), mountains.end(),
        [](const Mountain& mountain_1, const Mountain& mountain_2) {
            return (
                mountain_1[0] < mountain_2[0] ||
                (mountain_1[0] == mountain_2[0] && mountain_1[1] > mountain_2[1])
            );
        }
    );

    auto peaks = n;
    auto reached = 0;

    for (const auto& [_, end] : mountains) {
        if (end > reached) {
            reached = end;
        } else {
            --peaks;
        }
    }

    fout << peaks << '\n';

}

int main() {

    solve();

    return 0;

}
