class Solution {
public:
    vector<string> ans;
    string s;
    const string l_map[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
    };
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        backtracking(digits, 0);
        return ans;
    }

    void backtracking(const string digits, int index) {
        if(index == digits.size()) {
            ans.push_back(s);
            return;
        }
        int dig = digits[index] - '0';
        string button = l_map[dig];

        for(int i=0; i<button.size(); i++) {
            s.push_back(button[i]);
            backtracking(digits, index+1);
            s.pop_back();
        }
    }
};