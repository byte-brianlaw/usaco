#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using std::array;
using std::count_if;
using std::ifstream;
using std::min;
using std::ofstream;
using std::sort;
using std::vector;
using Cow = array<int, 2>;

auto fin = ifstream("reduce.in");
auto fout = ofstream("reduce.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto cows = vector<Cow>(n);
    auto cows_y = vector<int>();

    cows_y.reserve(n);

    for (auto& x : cows) {
        fin >> x[0] >> x[1];
        cows_y.push_back(x[1]);
    }

    sort(cows.begin(), cows.end());
    sort(cows_y.begin(), cows_y.end());

    auto area = 10ll * 1000 * 1000 * 1000;

    for (auto i = 0; i <= 3; ++i) {
        for (auto j = 0; j <= 3 - i; ++j) {
            for (auto k = 0; k <= 3; ++k) {
                for (auto l = 0; l <= 3 - k; ++l) {
                    const auto x_1 = cows[i][0];
                    const auto x_2 = cows[n - j - 1][0];
                    const auto y_1 = cows_y[k];
                    const auto y_2 = cows_y[n - l - 1];
                    if (
                        count_if(
                            cows.begin(), cows.end(),
                            [&](const Cow& cow) {
                                return (
                                    cow[0] >= x_1 && cow[0] <= x_2 && cow[1] >= y_1 && cow[1] <= y_2
                                );
                            }
                        ) >= n - 3
                    ) {
                        area = min(static_cast<long long>(x_2 - x_1) * (y_2 - y_1), area);
                    }
                }
            }
        }
    }

    fout << area << '\n';

}

int main() {

    solve();

    return 0;

}
