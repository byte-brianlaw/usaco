#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

using std::ifstream;
using std::max;
using std::ofstream;
using std::string;
using std::unordered_set;
using std::vector;

auto fin = ifstream("guess.in");
auto fout = ofstream("guess.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto animals = vector<unordered_set<string>>(n);

    for (auto& x : animals) {
        fin.ignore(100, ' ');
        auto k = 0;
        fin >> k;
        for (auto j = 0; j < k; ++j) {
            auto characteristic = string();
            fin >> characteristic;
            x.insert(characteristic);
        }
    }

    auto answers = 0;

    for (auto i = 0; i < n; ++i) {
        for (auto j = i + 1; j < n; ++j) {
            auto current = 1;
            for (const auto& x : animals[i]) {
                current += animals[j].count(x);
            }
            answers = max(current, answers);
        }
    }

    fout << answers << '\n';

}

int main() {

    solve();

    return 0;

}
