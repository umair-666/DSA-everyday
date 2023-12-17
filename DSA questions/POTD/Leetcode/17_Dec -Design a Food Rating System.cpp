// 2353. Design a Food Rating System
// https://leetcode.com/problems/design-a-food-rating-system/description/?envType=daily-question&envId=2023-12-17

#include <set>
#include <string>
using namespace std;

struct Rate {
    string name;
    string cuisine;
    int rating{};

    Rate() = default;
    Rate(string name, string cuisine, int rating) : name{name}, cuisine{cuisine}, rating{rating}{}

    bool operator<(const Rate& first) const {
        if (rating == first.rating) {
            return name < first.name;
        }
        return rating > first.rating;
    }
};

class FoodRatings {
    
    unordered_map<string, Rate> foodNameToInfo;
    unordered_map<string, set<Rate>> cuisineNameToSortedInfo;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodNameToInfo.emplace(foods[i], Rate(foods[i], cuisines[i], ratings[i]));
            cuisineNameToSortedInfo[cuisines[i]].emplace(foods[i], cuisines[i], ratings[i]);
        }
    }

    void changeRating(const string& food, int newRating) {
        Rate& toUpdate = foodNameToInfo[food];
        cuisineNameToSortedInfo[toUpdate.cuisine].erase(toUpdate);
        toUpdate.rating = newRating;
        cuisineNameToSortedInfo[toUpdate.cuisine].insert(toUpdate);
    }

    string highestRated(const string& cuisine) const {
        return cuisineNameToSortedInfo.at(cuisine).begin()->name;
    }
};
