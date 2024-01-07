class Solution {
public:
    vector<int> partitionLabels(string s) {
        int a[26] = {0};
        int index = 0;
        for(const char c : s) {
            a[c - 'a'] = max(a[c - 'a'], index);
            index++;
        }
        
        int max_index = 0;
        int cnt = 0;
        vector<int> result;
        for(int i = 0; i < s.size(); i++) {
            max_index  = max(a[s[i] - 'a'], max_index);
            cnt++;
            if(max_index == i){
                result.push_back(cnt);
                cnt = 0;
            }
        }
        return result;
    }
};
