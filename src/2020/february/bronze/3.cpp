#include <algorithm>
#include <fstream>
#include <numeric>
#include <vector>

using std::ifstream;
using std::iota;
using std::ofstream;
using std::reverse;
using std::vector;

auto fin = ifstream("swap.in");
auto fout = ofstream("swap.out");

auto solve() {

    auto a_1 = 0;
    auto a_2 = 0;
    auto b_1 = 0;
    auto b_2 = 0;
    auto k = 0;
    auto n = 0;

    fin >> n >> k >> a_1 >> a_2 >> b_1 >> b_2;

    auto to = vector<int>(n);

    iota(to.begin(), to.end(), 0);

    reverse(to.begin() + b_1 - 1, to.begin() + b_2);
    reverse(to.begin() + a_1 - 1, to.begin() + a_2);

    auto cows = vector<int>(n);

    for (auto i = 0; i < n; ++i) {
        auto current = i;
        auto cycle = vector<int>();
        do {
            cycle.push_back(current);
            current = to[current];
        } while (current != i);
        cows[cycle[k % cycle.size()]] = i + 1;
    }

    for (auto x : cows) {
        fout << x << '\n';
    }

}

int main() {

    solve();

    return 0;

}
