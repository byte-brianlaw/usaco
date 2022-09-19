#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::ifstream;
using std::make_pair;
using std::map;
using std::ofstream;
using std::string;
using std::vector;

auto fin = ifstream("lineup.in");
auto fout = ofstream("lineup.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto requirements = map<string, vector<string>>(
        {
            make_pair(string("Beatrice"), vector<string>()),
            make_pair(string("Belinda"), vector<string>()),
            make_pair(string("Bella"), vector<string>()),
            make_pair(string("Bessie"), vector<string>()),
            make_pair(string("Betsy"), vector<string>()),
            make_pair(string("Blue"), vector<string>()),
            make_pair(string("Buttercup"), vector<string>()),
            make_pair(string("Sue"), vector<string>())
        }
    );

    for (auto i = 0; i < n; ++i) {
        auto x = string();
        fin >> x;
        fin.ignore(23);
        auto y = string();
        fin >> y;
        requirements[x].push_back(y);
        requirements[y].push_back(x);
    }

    auto next = string();
    auto ordering = vector<string>();

    for (auto i = 0; i < 8; ++i) {
        if (!next.empty()) {
            auto neighbors = requirements[next];
            ordering.push_back(next);
            requirements.erase(next);
            if (neighbors.size() == 2) {
                if (neighbors[0] != ordering[ordering.size() - 2]) {
                    next = neighbors[0];
                } else {
                    next = neighbors[1];
                }
            } else {
                next.clear();
            }
        } else {
            for (const auto& x : requirements) {
                if (x.second.size() <= 1) {
                    if (!x.second.empty()) {
                        next = x.second[0];
                    }
                    ordering.push_back(x.first);
                    requirements.erase(x.first);
                    break;
                }
            }
        }
    }

    for (const auto& x : ordering) {
        fout << x << '\n';
    }

}

int main() {

    solve();

    return 0;

}
