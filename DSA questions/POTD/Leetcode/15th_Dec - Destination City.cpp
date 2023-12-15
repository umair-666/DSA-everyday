// 1436. Destination City
// https://leetcode.com/problems/destination-city/description/?envType=daily-question&envId=2023-12-15

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

       unordered_set<string> cities;

       //store outgoing cities
       for(const auto& path : paths){
           cities.insert(path[0]);
       }

       //find city with no outgoing path
       for(const auto& path : paths){
           string dest = path[1];
           if(cities.find(dest) == cities.end())    //agar nhi mila
            return dest;
       }

       return "";
    }
};
