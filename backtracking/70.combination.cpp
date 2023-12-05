class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    void backtracking(int n, int k, int start_index) {
        if(tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        
        
        for(int i=start_index; i<=n; i++) {
            tmp.push_back(i);
            backtracking(n,k,i+1);
            tmp.pop_back();
        }
        
        

        
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return result;
    }
};