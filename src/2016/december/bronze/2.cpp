#include <algorithm>
#include <array>
#include <fstream>
#include <string>

using std::array;
using std::count;
using std::ifstream;
using std::max;
using std::ofstream;
using std::string;

auto fin = ifstream("blocks.in");
auto fout = ofstream("blocks.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto blocks = array<int, 26>();

    blocks.fill(0);

    for (auto i = 0; i < n; ++i) {
        auto word_1 = string();
        auto word_2 = string();
        fin >> word_1 >> word_2;
        for (auto x = 'a'; x <= 'z'; ++x) {
            blocks[x - 'a'] += max(
                count(word_1.begin(), word_1.end(), x), count(word_2.begin(), word_2.end(), x)
            );
        }
    }

    for (auto x : blocks) {
        fout << x << '\n';
    }

}

int main() {

    solve();

    return 0;

}
