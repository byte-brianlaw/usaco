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

    auto promotions = array<int, 3>({0, 0, after[2] - before[2]});

    promotions[1] = after[1] - before[1] + promotions[2];
    promotions[0] = after[0] - before[0] + promotions[1];

    for (auto x : promotions) {
        fout << x << '\n';
    }

}

int main() {

    solve();

    return 0;

}
