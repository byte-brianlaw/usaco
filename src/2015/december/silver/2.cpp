#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("highcard.in");
auto fout = ofstream("highcard.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto taken = vector<bool>(n * 2 + 1);

    for (auto i = 0; i < n; ++i) {
        auto card = 0;
        fin >> card;
        taken[card] = true;
    }

    auto bessie = vector<int>();

    bessie.reserve(n);

    auto elsie = vector<int>();

    elsie.reserve(n);

    for (auto i = 1; i <= n << 1; ++i) {
        (taken[i] ? elsie : bessie).push_back(i);
    }

    auto points = 0;
    auto reached = 0;

    for (auto x : elsie) {
        while (reached < n && bessie[reached] < x) {
            ++reached;
        }
        if (reached == n) {
            break;
        }
        ++points;
        ++reached;
    }

    fout << points << '\n';

}

int main() {

    solve();

    return 0;

}
