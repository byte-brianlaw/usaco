#include <algorithm>
#include <fstream>
#include <vector>

using std::count;
using std::ifstream;
using std::min;
using std::ofstream;
using std::vector;

auto fin = ifstream("maxcross.in");
auto fout = ofstream("maxcross.out");

auto solve() {

    auto b = 0;
    auto k = 0;
    auto n = 0;

    fin >> n >> k >> b;

    auto broken = vector<bool>(n);

    for (auto i = 0; i < b; ++i) {
        auto signal = 0;
        fin >> signal;
        broken[signal - 1] = true;
    }

    auto current = static_cast<int>(count(broken.begin(), broken.begin() + k, true));
    auto repair = current;

    for (auto i = k; i < n; ++i) {
        current -= broken[i - k];
        current += broken[i];
        repair = min(current, repair);
    }

    fout << repair << '\n';

}

int main() {

    solve();

    return 0;

}
