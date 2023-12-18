class Solution {
public:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; 
        }
        result.push_back("JFK");
        backtraking(tickets.size(), result);
        return result;
    }

    bool backtraking(int tick_num, vector<string>& result) {
        if(result.size() == tick_num + 1) {
            return true;
        }

        for(pair<const string, int> &target: targets[result[result.size() - 1]]) {
            if(target.second > 0) {
                result.push_back(target.first);
                target.second--;
                if(backtraking(tick_num, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
};