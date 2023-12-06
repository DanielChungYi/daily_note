class Solution {
public:
    vector<vector<string>> result;
    vector<string> tmp;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }

    bool is_palindrome(const string & s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    void backtracking(const string& s, int start_index) {
        if(start_index >= s.size()) {
            result.push_back(tmp);
            return;
        }

        for(int i=start_index; i<s.size(); i++) {
            if(is_palindrome(s, start_index, i)) {
                string str = s.substr(start_index, i - start_index + 1);
                tmp.push_back(str);
            } else {
                continue; // super important
            }
            
            backtracking(s, i+1);

            tmp.pop_back();
        }
    }
};