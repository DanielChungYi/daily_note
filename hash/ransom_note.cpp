#include <map>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> my_map;
        for(const auto& c : magazine) {
            auto it = my_map.find(c);
            // if char not found, add it to map
            if (it == my_map.end()) { my_map.insert({c, 1}); }
            // else increase the times it appears
            else { my_map[c]++; }
        }

        for(const auto& c : ransomNote) {
            auto it = my_map.find(c);
            if (it == my_map.end()) { return false; }
            else { my_map[c]--; }
        }

        for(const auto& n : my_map) {
            if(n.second < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution S;
    string r = "aa";
    string m = "aab";
    bool result = S.canConstruct(r, m);
    cout << result << endl;
    return 0;
}
