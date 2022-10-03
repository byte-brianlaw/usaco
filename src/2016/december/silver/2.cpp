#include <fstream>
#include <string>
#include <unordered_map>

using std::ifstream;
using std::ofstream;
using std::string;
using std::unordered_map;

auto fin = ifstream("citystate.in");
auto fout = ofstream("citystate.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto codes = unordered_map<string, int>();

    for (auto i = 0; i < n; ++i) {
        auto city = string();
        auto state = string();
        fin >> city >> state;
        city.erase(2);
        if (city != state) {
            ++codes[city + state];
        }
    }

    auto pairs = 0ll;

    for (const auto& x : codes) {
        const auto reverse = x.first.substr(2) + x.first.substr(0, 2);
        if (codes.count(reverse)) {
            pairs += x.second * codes[reverse];
        }
    }

    pairs >>= 1;

    fout << pairs << '\n';

}

int main() {

    solve();

    return 0;

}
