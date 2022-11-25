#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("pairup.in");
auto fout = ofstream("pairup.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto cows = vector<array<int, 2>>(n);

    for (auto& x : cows) {
        fin >> x[1] >> x[0];
    }

    sort(cows.begin(), cows.end());

    auto ptr_1 = 0;
    auto ptr_2 = n - 1;
    auto time = 0;

    while (ptr_1 < ptr_2) {
        auto& low = cows[ptr_1];
        auto& high = cows[ptr_2];
        time = max(low[0] + high[0], time);
        const auto pairs = min(low[1], high[1]);
        low[1] -= pairs;
        high[1] -= pairs;
        ptr_1 += low[1] == 0;
        ptr_2 -= high[1] == 0;
    }

    if (ptr_1 == ptr_2) {
        time = max(cows[ptr_1][1] << 1, time);
    }

    fout << time << '\n';

}

int main() {

    solve();

    return 0;

}
