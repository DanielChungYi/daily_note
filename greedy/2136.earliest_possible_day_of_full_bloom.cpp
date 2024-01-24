class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> m_map;
        for(int i = 0; i < plantTime.size(); i++) {
            pair<int, int> p(plantTime[i], growTime[i]);
            m_map.push_back(p);
        }

        auto cmp = [](const auto &lhs, const auto &rhs) {
            return lhs.second > rhs.second;
        };
        
        sort(m_map.begin(), m_map.end(), cmp);

        int ans = 0;
        int sum = 0;
        for(int i = 0; i < plantTime.size(); i++) {
            sum += m_map[i].first;
            ans = max(sum, sum + m_map[i].second);
        }
        return ans;
    }
};