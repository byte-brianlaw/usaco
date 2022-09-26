#include <cstdlib>
#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using std::abs;
using std::cin;
using std::cout;
using std::ios_base;
using std::literals::operator""s;
using std::make_pair;
using std::string;
using std::unordered_map;

const auto ZODIAC = unordered_map<string, int>(
    {
        make_pair("Ox"s, 0), make_pair("Tiger"s, 1), make_pair("Rabbit"s, 2),
        make_pair("Dragon"s, 3), make_pair("Snake"s, 4), make_pair("Horse"s, 5),
        make_pair("Goat"s, 6), make_pair("Monkey"s, 7), make_pair("Rooster"s, 8),
        make_pair("Dog"s, 9), make_pair("Pig"s, 10), make_pair("Rat"s, 11)
    }
);

auto solve() {

    auto n = 0;

    cin >> n;

    auto animals = unordered_map<string, int>();
    auto years = unordered_map<string, int>();

    for (auto i = 0; i < n; ++i) {
        auto new_cow = string();
        cin >> new_cow;
        cin.ignore(9);
        auto animal = string();
        auto relation = string();
        cin >> relation >> animal;
        cin.ignore(11);
        auto old_cow = string();
        cin >> old_cow;
        const auto new_index = ZODIAC.at(animal);
        animals[new_cow] = new_index;
        const auto old_index = animals[old_cow];
        const auto old_year = years[old_cow];
        years[new_cow] = old_year;
        if (relation == "next") {
            if (new_index == old_index) {
                years[new_cow] += 12;
            } else {
                years[new_cow] += (new_index - old_index + 12) % 12;
            }
        } else if (new_index == old_index) {
            years[new_cow] -= 12;
        } else {
            years[new_cow] -= (old_index - new_index + 12) % 12;
        }
    }

    cout << abs(years["Elsie"s] - years["Bessie"s]) << '\n';

}

int main() {

    cin.tie(nullptr);

    ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
