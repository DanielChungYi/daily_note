// See more at https://programmercarl.com/kama54.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.html#%E6%80%9D%E8%B7%AF

#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        static void stringRelace(string& s) {
            // Get how many `number` exists in string
            uint16_t cnt = 0;
            uint16_t old_size = s.size();
            for(const auto& c : s) {
                if(c >= '0' && c <= '9') cnt ++;
            }

            // Sting resize
            uint16_t new_size= s.size() + cnt * 5;
            s.resize(new_size);

            // Replace `number` 
            for(int i = old_size - 1, j = new_size - 1; i >= 0; i --) {
               if( s[i] >= '0' && s[i] <= '9') {
                   s[j--] = 'r';
                   s[j--] = 'e';
                   s[j--] = 'm';
                   s[j--] = 'b';
                   s[j--] = 'n';
               } else {
                   s[j--] = s[i];
               }
            }
        }
};


int main() {

    string s;
    while(cin >> s) {
        Solution::stringRelace(s);
        cout << s << endl;
        cout << "------------------------" << endl;
    }
    return 0;
}
