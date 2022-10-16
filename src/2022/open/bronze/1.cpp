#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::ios_base;
using std::string;

auto solve() {

    auto n = 0;
    auto ordering = string();

    cin >> n >> ordering;

    auto reversals = 0;

    for (auto i = n - 1; i >= 0; i -= 2) {
        if (ordering[i] != ordering[i - 1] && (ordering[i] == 'H') ^ (reversals & 1)) {
            ++reversals;
        }
    }

    cout << reversals << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
