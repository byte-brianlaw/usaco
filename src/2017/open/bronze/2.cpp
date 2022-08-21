#include <bitset>
#include <fstream>
#include <string>
#include <vector>

using std::bitset;
using std::ifstream;
using std::ofstream;
using std::string;
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

    auto positions = 0;
    const auto getIndex = [](char character) {
        if (character == 'A') {
            return 0;
        }
        if (character == 'C') {
            return 1;
        }
        if (character == 'G') {
            return 2;
        }
        return 3;
    };

    for (auto i = 0; i < m; ++i) {
        auto seen = bitset<4>();
        for (const auto& x : spotty) {
            seen[getIndex(x[i])] = true;
        }
        auto valid = true;
        for (const auto& x : plain) {
            if (seen[getIndex(x[i])]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ++positions;
        }
    }

    fout << positions << '\n';

}

int main() {

    solve();

    return 0;

}
