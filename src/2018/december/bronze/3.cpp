#include <fstream>
#include <unordered_map>
#include <unordered_set>

using std::ifstream;
using std::ofstream;
using std::unordered_map;
using std::unordered_set;

auto fin = ifstream("backforth.in");
auto fout = ofstream("backforth.out");

auto recurse(
    int milk, int day, unordered_map<int, int>& buckets_1, unordered_map<int, int>& buckets_2,
    unordered_set<int>& readings
) {

    if (day == 5) {
        readings.insert(milk);
        return;
    }

    if (day % 2 == 1) {
        for (auto& x : buckets_1) {
            if (x.second > 0) {
                --x.second;
                ++buckets_2[x.first];
                recurse(milk - x.first, day + 1, buckets_1, buckets_2, readings);
                ++x.second;
                --buckets_2[x.first];
            }
        }
    } else {
        for (auto& x : buckets_2) {
            if (x.second > 0) {
                --x.second;
                ++buckets_1[x.first];
                recurse(milk + x.first, day + 1, buckets_1, buckets_2, readings);
                ++x.second;
                --buckets_1[x.first];
            }
        }
    }

}

auto solve() {

    auto buckets_1 = unordered_map<int, int>();
    auto buckets_2 = unordered_map<int, int>();

    for (auto i = 0; i < 10; ++i) {
        auto size = 0;
        fin >> size;
        ++buckets_1[size];
        buckets_2[size];
    }

    for (auto i = 0; i < 10; ++i) {
        auto size = 0;
        fin >> size;
        ++buckets_2[size];
        buckets_1[size];
    }

    auto readings = unordered_set<int>();

    recurse(1000, 1, buckets_1, buckets_2, readings);

    fout << readings.size() << '\n';

}

int main() {

    solve();

    return 0;

}
