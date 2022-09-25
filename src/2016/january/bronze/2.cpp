#include <algorithm>
#include <fstream>
#include <vector>

using std::ifstream;
using std::max;
using std::ofstream;
using std::sort;
using std::vector;

auto fin = ifstream("angry.in");
auto fout = ofstream("angry.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto x = vector<int>(n);

    for (auto& y : x) {
        fin >> y;
    }

    sort(x.begin(), x.end());

    auto hay_bales = 0;

    for (auto i = 0; i < n; ++i) {
        auto current = 1;
        auto radius = 1;
        auto reached = i;
        for (auto j = i - 1; j >= 0; --j) {
            if (x[j] < x[reached] - radius) {
                if (j == reached - 1) {
                    break;
                } else {
                    reached = j + 1;
                    ++radius;
                    ++j;
                }
            } else if (j == 0) {
                reached = 0;
            }
        }
        current += i - reached;
        radius = 1;
        reached = i;
        for (auto j = i + 1; j < n; ++j) {
            if (x[j] > x[reached] + radius) {
                if (j == reached + 1) {
                    break;
                } else {
                    reached = j - 1;
                    ++radius;
                    --j;
                }
            } else if (j == n - 1) {
                reached = n - 1;
            }
        }
        current += reached - i;
        hay_bales = max(current, hay_bales);
    }

    fout << hay_bales << '\n';

}

int main() {

    solve();

    return 0;

}
