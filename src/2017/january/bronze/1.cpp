#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>

using std::ifstream;
using std::literals::operator""s;
using std::min;
using std::ofstream;
using std::string;
using std::unordered_map;

auto fin = ifstream("notlast.in");
auto fout = ofstream("notlast.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto milk = unordered_map<string, int>();

    milk["Annabelle"s];
    milk["Bessie"s];
    milk["Daisy"s];
    milk["Elsie"s];
    milk["Gertie"s];
    milk["Henrietta"s];
    milk["Maggie"s];

    for (auto i = 0; i < n; ++i) {
        auto amount = 0;
        auto cow = string();
        fin >> cow >> amount;
        milk[cow] += amount;
    }

    auto min_milk = 10000;

    for (const auto& x : milk) {
        min_milk = min(x.second, min_milk);
    }

    auto need = 10001;

    for (const auto& x : milk) {
        if (x.second != min_milk) {
            need = min(x.second, need);
        }
    }

    auto cow = "Tie"s;

    for (const auto& x : milk) {
        if (x.second == need) {
            if (cow == "Tie") {
                cow = x.first;
            } else {
                cow = "Tie"s;
                break;
            }
        }
    }

    fout << cow << '\n';

}

int main() {

    solve();

    return 0;

}
