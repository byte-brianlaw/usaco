#include <algorithm>
#include <array>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using std::array;
using std::ifstream;
using std::map;
using std::max_element;
using std::min;
using std::ofstream;
using std::string;
using std::vector;

auto _ = string();
auto fin = ifstream("balancing.in");
auto fout = ofstream("balancing.out");

auto solve() {

    auto n = 0;

    fin >> n >> _;

    auto cows_x = map<int, vector<int>>();
    auto cows_y = map<int, vector<int>>();

    for (auto i = 0; i < n; ++i) {
        auto x_coord = 0;
        auto y_coord = 0;
        fin >> x_coord >> y_coord;
        cows_x[x_coord].push_back(y_coord);
        cows_y[y_coord].push_back(x_coord);
    }

    auto current = 0;
    auto m = n;

    for (const auto& x : cows_x) {
        auto counts = array<int, 4>({current, n - current, 0, 0});
        for (const auto& y : cows_y) {
            for (auto z : y.second) {
                if (z < x.first - 1) {
                    --counts[0];
                    ++counts[2];
                } else {
                    --counts[1];
                    ++counts[3];
                }
            }
            m = min(*max_element(counts.begin(), counts.end()), m);
        }
        current += x.second.size();
    }

    fout << m << '\n';

}

int main() {

    solve();

    return 0;

}
