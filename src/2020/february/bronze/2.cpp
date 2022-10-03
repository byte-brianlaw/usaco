#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

auto fin = ifstream("breedflip.in");
auto fout = ofstream("breedflip.out");

auto solve() {

    auto a = string();
    auto b = string();
    auto n = 0;

    fin >> n >> a >> b;

    auto apply = 0;
    auto different = false;

    for (auto i = 0; i < n; ++i) {
        if (b[i] != a[i]) {
            if (!different) {
                ++apply;
                different = true;
            }
        } else {
            different = false;
        }
    }

    fout << apply << '\n';

}

int main() {

    solve();

    return 0;

}
