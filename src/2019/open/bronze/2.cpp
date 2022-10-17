#include <fstream>
#include <unordered_set>

using std::ifstream;
using std::ofstream;
using std::unordered_set;

auto fin = ifstream("factory.in");
auto fout = ofstream("factory.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto stations = unordered_set<int>();

    for (auto i = 1; i <= n; ++i) {
        stations.insert(i);
    }

    for (auto i = 0; i < n - 1; ++i) {
        auto start = 0;
        fin >> start;
        stations.erase(start);
        fin.ignore(10, '\n');
    }

    if (stations.size() == 1) {
        fout << *stations.begin();
    } else {
        fout << -1;
    }

    fout << '\n';

}

int main() {

    solve();

    return 0;

}
