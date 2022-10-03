#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

auto fin = ifstream("censor.in");
auto fout = ofstream("censor.out");

auto solve() {

    auto s = string();
    auto t = string();

    fin >> s >> t;

    auto final = string();
    const auto t_size = static_cast<int>(t.size());

    for (auto x : s) {
        final.push_back(x);
        const auto size = static_cast<int>(final.size());
        if (size >= t_size && final.substr(size - t_size) == t) {
            final.erase(size - t_size);
        }
    }

    fout << final << '\n';

}

int main() {

    solve();

    return 0;

}
