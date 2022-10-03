#include <fstream>
#include <unordered_map>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::unordered_map;
using std::vector;

auto fin = ifstream("milkorder.in");
auto fout = ofstream("milkorder.out");

auto solve() {

    auto k = 0;
    auto m = 0;
    auto n = 0;

    fin >> n >> m >> k;

    auto hierarchy = unordered_map<int, int>();

    for (auto i = 0; i < m; ++i) {
        auto cow = 0;
        fin >> cow;
        hierarchy[cow] = i + 1;
    }

    auto done = false;
    auto ordering = vector<int>(n);

    for (auto i = 0; i < k; ++i) {
        auto cow = 0;
        auto position = 0;
        fin >> cow >> position;
        if (cow == 1) {
            fout << position << '\n';
            done = true;
        }
        ordering[position - 1] = cow;
    }

    if (done) {
        return;
    }

    for (auto i = 0; i < n; ++i) {
        if (ordering[i] == 0) {
            ordering[i] = 1;
            auto previous = 0;
            auto space = 0;
            auto valid = true;
            for (auto j = 0; j < n; ++j) {
                const auto cow = ordering[j];
                if (cow) {
                    if (hierarchy.count(cow)) {
                        if (space < hierarchy[cow] - hierarchy[previous] - 1) {
                            valid = false;
                            break;
                        }
                        previous = cow;
                        space = 0;
                    }
                } else {
                    ++space;
                }
            }
            if (valid) {
                fout << i + 1 << '\n';
                break;
            }
            ordering[i] = 0;
        }
    }

}

int main() {

    solve();

    return 0;

}
