#include <algorithm>
#include <array>
#include <fstream>
#include <limits>
#include <string>
#include <vector>

using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::numeric_limits;
using std::ofstream;
using std::string;
using std::vector;

constexpr auto LARGE_INT = numeric_limits<int>::max();
auto fin = ifstream("traffic.in");
auto fout = ofstream("traffic.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto sensors = vector<array<int, 3>>(n);

    for (auto& x : sensors) {
        auto ramp = string();
        fin >> ramp >> x[0] >> x[1];
        if (ramp == "none") {
            x[2] = 0;
        } else if (ramp == "off") {
            x[2] = -1;
        } else {
            x[2] = 1;
        }
    }

    auto range = array<int, 2>({0, LARGE_INT});

    for (auto i = n - 1; i >= 0; --i) {
        const auto sensor = sensors[i];
        if (sensor[2] == 0) {
            range[0] = max(sensor[0], range[0]);
            range[1] = min(sensor[1], range[1]);
        } else if (range[1] != LARGE_INT) {
            if (sensor[2] == 1) {
                range[0] = max(range[0] - sensor[1], 0);
                range[1] -= sensor[0];
            } else {
                range[0] += sensor[0];
                range[1] += sensor[1];
            }
        }
    }

    fout << range[0] << ' ' << range[1] << '\n';

    range[0] = 0;
    range[1] = LARGE_INT;

    for (const auto& x : sensors) {
        if (x[2] == 0) {
            range[0] = max(x[0], range[0]);
            range[1] = min(x[1], range[1]);
        } else if (range[1] != LARGE_INT) {
            if (x[2] == 1) {
                range[0] += x[0];
                range[1] += x[1];
            } else {
                range[0] = max(range[0] - x[1], 0);
                range[1] -= x[0];
            }
        }
    }

    fout << range[0] << ' ' << range[1] << '\n';

}

int main() {

    solve();

    return 0;

}
