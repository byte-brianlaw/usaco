#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

auto fin = ifstream("cowsignal.in");
auto fout = ofstream("cowsignal.out");

auto solve() {

    auto k = 0;
    auto m = 0;
    auto n = 0;

    fin >> m >> n >> k;

    for (auto i = 0; i < m; ++i) {
        auto enlarged = string();
        for (auto j = 0; j < n; ++j) {
            auto character = '\0';
            fin >> character;
            enlarged.append(k, character);
        }
        for (auto j = 0; j < k; ++j) {
            fout << enlarged << '\n';
        }
    }

}

int main() {

    solve();

    return 0;

}
