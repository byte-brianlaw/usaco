#include <algorithm>
#include <array>
#include <ios>
#include <iostream>

using std::array;
using std::cin;
using std::cout;
using std::ios_base;
using std::sort;

auto solve() {

    auto numbers = array<int, 7>();

    for (auto& x : numbers) {
        cin >> x;
    }

    sort(numbers.begin(), numbers.end());

    cout << numbers[0] << ' ' << numbers[1] << ' ' << numbers[6] - numbers[0] - numbers[1] << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
