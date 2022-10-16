#include <ios>
#include <iostream>

using std::cin;
using std::cout;
using std::ios_base;

auto solve() {

    auto n = 0;

    cin >> n;

    auto even = 0;
    auto odd = 0;

    for (auto i = 0; i < n; ++i) {
        auto breed = 0;
        cin >> breed;
        if (breed & 1) {
            ++odd;
        } else {
            ++even;
        }
    }

    if (even > odd) {
        cout << odd * 2 + 1;
    } else {
        const auto remaining = odd - even;
        auto groups = (even + remaining / 3) * 2;
        if (remaining % 3 == 1) {
            --groups;
        } else if (remaining % 3 == 2) {
            ++groups;
        }
        cout << groups;
    }

    cout << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
