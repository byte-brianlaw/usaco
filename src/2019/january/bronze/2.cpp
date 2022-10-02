#include <algorithm>
#include <fstream>
#include <functional>
#include <vector>

using std::greater;
using std::ifstream;
using std::is_sorted_until;
using std::ofstream;
using std::vector;

auto fin = ifstream("sleepy.in");
auto fout = ofstream("sleepy.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto p = vector<int>(n);

    for (auto& x : p) {
        fin >> x;
    }

    fout << p.rend() - is_sorted_until(p.rbegin(), p.rend(), greater<int>()) << '\n';

}

int main() {

    solve();

    return 0;

}
