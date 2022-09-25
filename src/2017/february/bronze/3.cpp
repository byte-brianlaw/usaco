#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::ifstream;
using std::max;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("cowqueue.in");
auto fout = ofstream("cowqueue.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto cows = vector<array<int, 2>>(n);

    for (auto& x : cows) {
        fin >> x[0] >> x[1];
    }

    sort(cows.begin(), cows.end());

    auto time = 0;

    for (const auto& x : cows) {
        time = max(x[0], time) + x[1];
    }

    fout << time << '\n';

}

int main() {

    solve();

    return 0;

}
