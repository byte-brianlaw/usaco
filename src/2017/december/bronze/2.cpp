#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("shuffle.in");
auto fout = ofstream("shuffle.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto a = vector<int>(n);

    for (auto& x : a) {
        fin >> x;
        --x;
    }

    auto order = vector<int>(n);

    for (auto& x : order) {
        fin >> x;
    }

    for (auto i = 0; i < 3; ++i) {
        auto previous = vector<int>(n);
        for (auto j = 0; j < n; ++j) {
            previous[j] = order[a[j]];
        }
        order = previous;
    }

    for (auto x : order) {
        fout << x << '\n';
    }

}

int main() {

    solve();

    return 0;

}
