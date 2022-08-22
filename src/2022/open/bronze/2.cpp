#include <algorithm>
#include <ios>
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::ios_base;
using std::map;
using std::min;

auto solve() {

    auto n = 0;

    cin >> n;

    auto current = 0;
    auto information = map<int, int>();

    for (auto i = 0; i < n; ++i) {
        auto direction = '\0';
        auto location = 0;
        cin >> direction >> location;
        if (direction == 'G') {
            --information[location];
            ++current;
        } else {
            ++information[location + 1];
        }
    }

    auto lying = current;

    for (const auto& x : information) {
        current += x.second;
        lying = min(current, lying);
    }

    cout << lying << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
