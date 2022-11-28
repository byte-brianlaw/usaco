#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>

using std::array;
using std::greater;
using std::ifstream;
using std::max;
using std::ofstream;
using std::priority_queue;
using std::sort;
using std::vector;
using Cow = array<int, 3>;

auto fin = ifstream("convention2.in");
auto fout = ofstream("convention2.out");

auto solve() {

    auto n = 0;

    fin >> n;

    auto cows = vector<Cow>(n);

    for (auto i = 0; i < n; ++i) {
        auto& cow = cows[i];
        cow[0] = i;
        fin >> cow[1] >> cow[2];
    }

    sort(
        cows.begin(), cows.end(),
        [](const Cow& cow_1, const Cow& cow_2) {
            return cow_1[1] < cow_2[1] || (cow_1[1] == cow_2[1] && cow_1[0] < cow_2[0]);
        }
    );

    auto finish = 0;
    auto line = priority_queue<Cow, vector<Cow>, greater<Cow>>();
    auto reached = 0;
    auto wait = 0;

    while (!line.empty() || reached < n) {
        while (reached < n && cows[reached][1] <= finish) {
            line.push(cows[reached]);
            ++reached;
        }
        if (line.empty()) {
            line.push(cows[reached]);
            ++reached;
        }
        const auto next = line.top();
        line.pop();
        wait = max(finish - next[1], wait);
        finish = max(finish, next[1]) + next[2];
    }

    fout << wait << '\n';

}

int main() {

    solve();

    return 0;

}
