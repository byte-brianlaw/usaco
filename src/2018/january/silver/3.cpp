#include <array>
#include <fstream>
#include <utility>
#include <vector>

template <typename FunctionObject>
class YCombinator {

private:

    const FunctionObject function = nullptr;

public:

    template <typename Lambda>
    explicit YCombinator(Lambda&& lambda) : function(lambda) {}

    template <typename... Arguments>
    decltype(auto) operator()(Arguments&&... arguments) const {

        return function(*this, std::forward<Arguments>(arguments)...);

    }

};

template <typename Lambda>
YCombinator(Lambda) -> YCombinator<Lambda>;

using std::array;
using std::ifstream;
using std::ofstream;
using std::vector;
using Comparison = array<int, 2>;

auto fin = ifstream("mootube.in");
auto fout = ofstream("mootube.out");

auto solve() {

    auto n = 0;
    auto q = 0;

    fin >> n >> q;

    auto neighbors = vector<vector<Comparison>>(n);

    for (auto i = 0; i < n - 1; ++i) {
        auto relevance = 0;
        auto video_1 = 0;
        auto video_2 = 0;
        fin >> video_1 >> video_2 >> relevance;
        --video_1;
        --video_2;
        neighbors[video_1].push_back(Comparison({video_2, relevance}));
        neighbors[video_2].push_back(Comparison({video_1, relevance}));
    }

    for (auto i = 0; i < q; ++i) {
        auto minimum = 0;
        auto video = 0;
        fin >> minimum >> video;
        --video;
        auto suggest = -1;
        const auto search = YCombinator(
            [&](const auto& search, int current, int parent) -> void {
                ++suggest;
                for (const auto& [neighbor, relevance] : neighbors[current]) {
                    if (relevance >= minimum && neighbor != parent) {
                        search(neighbor, current);
                    }
                }
            }
        );
        search(video, -1);
        fout << suggest << '\n';
    }

}

int main() {

    solve();

    return 0;

}
