#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("cowtip.in");
auto fout = ofstream("cowtip.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto farm = vector<vector<bool>>(n);

    for (auto& x : farm) {
        for (auto i = 0; i < n; ++i) {
            auto cow = '\0';
            fin >> cow;
            x.push_back(cow - '0');
        }
    }

    auto apply = 0;

    while (true) {
        auto done = true;
        for (auto i = n - 1; i >= 0; --i) {
            for (auto j = n - 1; j >= 0; --j) {
                if (farm[i][j]) {
                    for (auto k = 0; k <= i; ++k) {
                        for (auto l = 0; l <= j; ++l) {
                            farm[k][l] = !farm[k][l];
                        }
                    }
                    done = false;
                    break;
                }
            }
            if (!done) {
                break;
            }
        }
        if (done) {
            break;
        }
        ++apply;
    }

    fout << apply << '\n';

}

int main() {

    solve();

    return 0;

}
