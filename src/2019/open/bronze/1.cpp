#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <utility>

using std::abs;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using std::pair;

auto fin = ifstream("buckets.in");
auto fout = ofstream("buckets.out");

auto solve() {

    auto barn = pair<int, int>();
    auto lake = pair<int, int>();
    auto rock = pair<int, int>();

    for (auto i = 0; i < 10; ++i) {
        for (auto j = 0; j < 10; ++j) {
            auto square = '\0';
            fin >> square;
            if (square == 'B') {
                barn.first = j;
                barn.second = i;
            } else if (square == 'L') {
                lake.first = j;
                lake.second = i;
            } else if (square == 'R') {
                rock.first = j;
                rock.second = i;
            }
        }
    }

    auto cows = abs(barn.first - lake.first) + abs(barn.second - lake.second) - 1;

    if (
        (
            barn.first == lake.first && barn.first == rock.first &&
            rock.second > min(barn.second, lake.second) &&
            rock.second < max(barn.second, lake.second)
        ) || (
            barn.second == lake.second && barn.second == rock.second &&
            rock.first > min(barn.first, lake.first) && rock.first < max(barn.first, lake.first)
        )
    ) {
        cows += 2;
    }

    fout << cows << '\n';

}

int main() {

    solve();

    return 0;

}
