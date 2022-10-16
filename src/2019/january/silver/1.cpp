#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::max_element;
using std::ofstream;
using std::vector;

auto fin = ifstream("planting.in");
auto fout = ofstream("planting.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto neighbors = vector<int>(n);

    for (auto i = 0; i < n - 1; ++i) {
        auto field_1 = 0;
        auto field_2 = 0;
        fin >> field_1 >> field_2;
        ++neighbors[field_1 - 1];
        ++neighbors[field_2 - 1];
    }

    fout << *max_element(neighbors.begin(), neighbors.end()) + 1 << '\n';

}

int main() {

    solve();

    return 0;

}
