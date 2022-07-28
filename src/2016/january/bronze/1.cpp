#include <array>
#include <fstream>
#include <ios>
#include <limits>

using std::array;
using std::ifstream;
using std::numeric_limits;
using std::ofstream;
using std::streamsize;

auto fin = ifstream("promote.in");
auto fout = ofstream("promote.out");

auto solve() {

    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto after = array<int, 3>();
    auto before = array<int, 3>();

    for (auto i = 0; i < 3; ++i) {
        fin >> before[i] >> after[i];
    }

    const auto gold_to_platinum = after[2] - before[2];
    const auto silver_to_gold = after[1] - before[1] + gold_to_platinum;

    fout << after[0] - before[0] + silver_to_gold << '\n' << silver_to_gold << '\n' <<
    gold_to_platinum << '\n';

}

int main() {

    solve();

    return 0;

}
