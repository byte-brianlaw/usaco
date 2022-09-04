#include <algorithm>
#include <array>
#include <fstream>
#include <string>
#include <unordered_set>

using std::array;
using std::ifstream;
using std::max;
using std::min;
using std::ofstream;
using std::string;
using std::unordered_set;

auto fin = ifstream("tttt.in");
auto fout = ofstream("tttt.out");

auto solve() {

    auto board = array<string, 3>();

    for (auto& x : board) {
        fin >> x;
    }

    auto individual = unordered_set<char>();
    auto team = unordered_set<string>();

    const auto check = [&](
        int row_1, int column_1, int row_2, int column_2, int row_3, int column_3
    ) {
        const auto cow_1 = board[row_1][column_1];
        const auto cow_2 = board[row_2][column_2];
        const auto cow_3 = board[row_3][column_3];
        if (cow_1 == cow_2 && cow_2 == cow_3) {
            individual.insert(cow_1);
        } else if (cow_1 == cow_2 || cow_2 == cow_3 || cow_3 == cow_1) {
            team.insert(string({min({cow_1, cow_2, cow_3}), max({cow_1, cow_2, cow_3})}));
        }
    };

    for (auto i = 0; i < 3; ++i) {
        check(i, 0, i, 1, i, 2);
        check(0, i, 1, i, 2, i);
    }

    check(0, 0, 1, 1, 2, 2);
    check(0, 2, 1, 1, 2, 0);

    fout << individual.size() << '\n' << team.size() << '\n';

}

int main() {

    solve();

    return 0;

}
