#include <fstream>
#include <functional>
#include <queue>
#include <vector>

using std::greater;
using std::ifstream;
using std::ofstream;
using std::priority_queue;
using std::vector;

auto fin = ifstream("cowdance.in");
auto fout = ofstream("cowdance.out");

auto solve() {

    auto maximum = 0;
    auto n = 0;

    fin >> n >> maximum;

    auto d = vector<int>(n);

    for (auto& x : d) {
        fin >> x;
    }

    auto high = n + 1;
    auto low = 0;

    while (low < high - 1) {
        const auto middle = (low + high) >> 1;
        auto dancing = priority_queue<int, vector<int>, greater<int>>(
            d.begin(), d.begin() + middle
        );
        auto finish = true;
        auto reached = middle;
        while (!dancing.empty()) {
            const auto time = dancing.top();
            dancing.pop();
            if (reached < n) {
                dancing.push(time + d[reached]);
                ++reached;
            }
            if (time > maximum) {
                finish = false;
                break;
            }
        }
        (finish ? high : low) = middle;
    }

    fout << high << '\n';

}

int main() {

    solve();

    return 0;

}
