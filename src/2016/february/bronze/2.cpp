#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::min;
using std::ofstream;
using std::vector;

auto fin = ifstream("cbarn.in");
auto fout = ofstream("cbarn.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto cows = 0;
    auto r = vector<int>(n);

    for (auto& x : r) {
        fin >> x;
        cows += x;
    }

    auto current = 0;

    for (auto i = 0; i < n; ++i) {
        current += r[i] * i;
    }

    auto distance = current;

    for (auto i = 0; i < n - 1; ++i) {
        current += r[i] * n - cows;
        distance = min(current, distance);
    }

    fout << distance << '\n';

}

int main() {

    solve();

    return 0;

}
