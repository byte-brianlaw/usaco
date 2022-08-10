#include <ios>
#include <iostream>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::ios_base;
using std::unordered_set;
using std::vector;

auto solve() {

    auto n = 0;

    cin >> n;

    auto p = vector<int>(n);

    for (auto& x : p) {
        cin >> x;
    }

    auto photos = 0;

    for (auto i = 0; i < n; ++i) {
        auto flowers = unordered_set<int>();
        auto petals = 0;
        for (auto j = i; j < n; ++j) {
            flowers.insert(p[j]);
            petals += p[j];
            if (petals % (j - i + 1) == 0 && flowers.find(petals / (j - i + 1)) != flowers.end()) {
                ++photos;
            }
        }
    }

    cout << photos << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
