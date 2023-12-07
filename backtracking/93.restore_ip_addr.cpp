class Solution {
public:
    vector<string> result;
    string tmp;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
    bool is_valid(const string& s, int start, int end) {
      if(start > end) return false;
      if (s[start] == '0' && start != end) {
            return false;
      }
      int num = 0;
      for (int i = start; i <= end; i++) {
          if (s[i] > '9' || s[i] < '0') { 
              return false;
          }
          num = num * 10 + (s[i] - '0');
          if (num > 255) { 
              return false;
          }
        }
      return true;
    }

    void backtracking(string& s, int start_index, int dot_cnt) {
        if(dot_cnt == 3) {
            if(is_valid(s, start_index, s.size()-1))
            result.push_back(s);
            return;
        }

        for(int i=start_index; i<s.size(); i++) {
            if(is_valid(s, start_index, i)) {
                s.insert(s.begin() + i + 1, '.');
                dot_cnt++;
                backtracking(s, i+2, dot_cnt);
                dot_cnt--;
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
            
        }
    }
};