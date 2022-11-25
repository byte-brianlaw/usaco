#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <vector>

using std::array;
using std::greater;
using std::ifstream;
using std::min;
using std::ofstream;
using std::sort;
using std::vector;
using Store = array<int, 2>;

auto fin = ifstream("rental.in");
auto fout = ofstream("rental.out");

auto solve() {

    auto m = 0;
    auto n = 0;
    auto r = 0;

    fin >> n >> m >> r;

    auto c = vector<int>(n);

    for (auto& x : c) {
        fin >> x;
    }

    sort(c.begin(), c.end(), greater<int>());

    auto stores = vector<Store>(m);

    for (auto& x : stores) {
        fin >> x[0] >> x[1];
    }

    sort(
        stores.begin(), stores.end(),
        [](const Store& store_1, const Store& store_2) {
            return store_1[1] > store_2[1];
        }
    );

    auto neighbors = vector<int>(r);

    for (auto& x : neighbors) {
        fin >> x;
    }

    auto potential = vector<long long>(n);
    auto reached = 0;

    for (auto i = 0; i < n && reached < m; ++i) {
        auto& need = c[i];
        while (need && reached < m) {
            auto& store = stores[reached];
            auto gallons = min(need, store[0]);
            potential[i] += static_cast<long long>(gallons) * store[1];
            need -= gallons;
            store[0] -= gallons;
            reached += store[0] == 0;
        }
    }

    sort(neighbors.begin(), neighbors.end());

    auto profit = 0ll;

    for (auto i = n - 1; i >= 0; --i) {
        if (neighbors.empty() || neighbors.back() < potential[i]) {
            profit += potential[i];
        } else {
            profit += neighbors.back();
            neighbors.pop_back();
        }
    }

    fout << profit << '\n';

}

int main() {

    solve();

    return 0;

}
