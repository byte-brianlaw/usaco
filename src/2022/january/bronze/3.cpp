#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::ios_base;
using std::vector;

auto solve() {

    auto n = 0;

    cin >> n;

    auto h = vector<int>(n);

    for (auto& x : h) {
        cin >> x;
    }

    auto bags = 0ll;

    for (auto i = 1; i < n - 1; ++i) {
        auto feed = h[i] - h[i - 1];
        if (feed > 0) {
            h[i] -= feed;
            h[i + 1] -= feed;
            bags += feed * 2;
        }
    }

    for (auto i = n - 2; i > 0; --i) {
        auto feed = h[i] - h[i + 1];
        if (feed > 0) {
            h[i] -= feed;
            h[i - 1] -= feed;
            bags += feed * 2;
        }
    }

    if (count(h.begin(), h.end(), h[0]) == n && h[0] >= 0) {
        cout << bags;
    } else {
        cout << -1;
    }

    cout << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    auto t = 0;

    cin >> t;

    for (auto i = 1; i <= t; ++i) {
        solve();
    }

    return 0;

}
