#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::string;
using std::unordered_set;
using std::vector;

auto fin = ifstream("cownomics.in");
auto fout = ofstream("cownomics.out");

auto solve() {

    auto m = 0;
    auto n = 0;

    fin >> n >> m;

    auto spotty = vector<string>(n);

    for (auto& x : spotty) {
        fin >> x;
    }

    auto plain = vector<string>(n);

    for (auto& x : plain) {
        fin >> x;
    }

    auto sets = 0;

    for (auto i = 0; i < m; ++i) {
        for (auto j = i + 1; j < m; ++j) {
            for (auto k = j + 1; k < m; ++k) {
                auto seen = unordered_set<string>();
                for (const auto& x : spotty) {
                    seen.insert(string({x[i], x[j], x[k]}));
                }
                auto valid = true;
                for (const auto& x : plain) {
                    if (seen.count(string({x[i], x[j], x[k]}))) {
                        valid = false;
                        break;
                    }
                }
                sets += valid;
            }
        }
    }

    fout << sets << '\n';

}

int main() {

    solve();

    return 0;

}
