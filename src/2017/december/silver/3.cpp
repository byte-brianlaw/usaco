#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("shuffle.in");
auto fout = ofstream("shuffle.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto a = vector<int>(n);

    for (auto& x : a) {
        fin >> x;
        --x;
    }

    auto positions = 0;
    auto processed = vector<bool>(n);

    for (auto i = 0; i < n; ++i) {
        auto reached = i;
        auto visited = vector<bool>(n);
        while (!visited[reached] && !processed[reached]) {
            visited[reached] = true;
            processed[reached] = true;
            reached = a[reached];
        }
        if (visited[reached]) {
            auto current = reached;
            do {
                ++positions;
                current = a[current];
            } while (current != reached);
        }
    }

    fout << positions << '\n';

}

int main() {

    solve();

    return 0;

}
