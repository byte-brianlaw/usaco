#include <fstream>
#include <string>
#include <unordered_set>

using std::ifstream;
using std::ofstream;
using std::string;
using std::unordered_set;

auto fin = ifstream("whereami.in");
auto fout = ofstream("whereami.out");

auto solve() {

    auto mailboxes = string();
    auto n = 0;

    fin >> n >> mailboxes;

    for (auto i = 1; i <= n; ++i) {
        auto seen = unordered_set<string>();
        auto valid = true;
        for (auto j = 0; j <= n - i; ++j) {
            const auto location = mailboxes.substr(j, i);
            if (seen.count(location)) {
                valid = false;
                break;
            }
            seen.insert(location);
        }
        if (valid) {
            fout << i << '\n';
            break;
        }
    }

}

int main() {

    solve();

    return 0;

}
