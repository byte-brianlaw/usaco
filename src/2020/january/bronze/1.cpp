#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

auto fin = ifstream("word.in");
auto fout = ofstream("word.out");

auto solve() {

    auto k = 0;
    auto n = 0;

    fin >> n >> k;

    auto words = vector<string>(n);

    for (auto& x : words) {
        fin >> x;
    }

    auto current = 0;

    for (const auto& x : words) {
        if (current + static_cast<int>(x.length()) > k) {
            current = 0;
            fout << '\n';
        } else if (current != 0) {
            fout << ' ';
        }
        current += x.length();
        fout << x;
    }

    fout << '\n';

}

int main() {

    solve();

    return 0;

}
