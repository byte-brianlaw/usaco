#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>

template <typename T>
class YCombinator {

private:

    const T lambda = nullptr;

public:

    template <typename U>
    explicit YCombinator(U&& lambda) : lambda(lambda) {}

    template <typename... Arguments>
    decltype(auto) operator()(Arguments&&... arguments) const {

        return lambda(*this, std::forward<Arguments>(arguments)...);

    }

};

template <typename T>
YCombinator(T) -> YCombinator<T>;

using std::count;
using std::find;
using std::ifstream;
using std::ofstream;
using std::vector;

auto fin = ifstream("closing.in");
auto fout = ofstream("closing.out");

auto solve() {

    auto m = 0;
    auto n = 0;

    fin >> n >> m;

    auto neighbors = vector<vector<int>>(n);

    for (auto i = 0; i < m; ++i) {
        auto barn_1 = 0;
        auto barn_2 = 0;
        fin >> barn_1 >> barn_2;
        --barn_1;
        --barn_2;
        neighbors[barn_1].push_back(barn_2);
        neighbors[barn_2].push_back(barn_1);
    }

    auto closed = vector<bool>(n);

    for (auto i = 0; i < n; ++i) {
        auto visited = vector<bool>(n);
        const auto search = YCombinator(
            [&](const auto& search, int barn) -> void {
                visited[barn] = true;
                for (auto x : neighbors[barn]) {
                    if (!closed[x] && !visited[x]) {
                        search(x);
                    }
                }
            }
        );
        search(find(closed.begin(), closed.end(), false) - closed.begin());
        fout << (count(visited.begin(), visited.end(), true) == n - i ? "YES" : "NO") << '\n';
        auto close = 0;
        fin >> close;
        --close;
        closed[close] = true;
    }

}

int main() {

    solve();

    return 0;

}
