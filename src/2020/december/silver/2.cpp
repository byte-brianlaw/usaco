#include <algorithm>
#include <array>
#include <ios>
#include <iostream>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::ios_base;
using std::minmax;
using std::sort;
using std::vector;
using Cow = array<int, 2>;

auto solve() {

    auto n = 0;

    cin >> n;

    auto cows = vector<Cow>(n);

    for (auto& x : cows) {
        cin >> x[0] >> x[1];
    }

    sort(cows.begin(), cows.end());

    for (auto i = 0; i < n; ++i) {
        cows[i][0] = i;
    }

    sort(
        cows.begin(), cows.end(),
        [](const Cow& cow_1, const Cow& cow_2) {
            return cow_1[1] < cow_2[1];
        }
    );

    for (auto i = 0; i < n; ++i) {
        cows[i][1] = i;
    }

    auto prefixes = vector<vector<int>>(n + 1, vector<int>(n + 1));

    for (const auto& x : cows) {
        prefixes[x[1] + 1][x[0] + 1] = 1;
    }

    for (auto i = 1; i <= n; ++i) {
        for (auto j = 1; j <= n; ++j) {
            prefixes[i][j] += prefixes[i][j - 1] + prefixes[i - 1][j] - prefixes[i - 1][j - 1];
        }
    }

    auto subsets = 1ll;

    for (const auto& x : cows) {
        for (auto i = x[1]; i < n; ++i) {
            const auto query = [&](int x_1, int y_1, int x_2, int y_2) {
                return (
                    prefixes[y_2 + 1][x_2 + 1] - prefixes[y_2 + 1][x_1] - prefixes[y_1][x_2 + 1] +
                    prefixes[y_1][x_1]
                );
            };
            const auto [left, right] = minmax(x[0], cows[i][0]);
            subsets += (
                static_cast<long long>(query(0, x[1], left, i)) * query(right, x[1], n - 1, i)
            );
        }
    }

    cout << subsets << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
