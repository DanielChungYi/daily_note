#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int slow_index = 0;
            for(int i=0; i<nums.size(); i++) {
                if ( nums[i] != val) {
                       nums[slow_index++] = nums[i]; 
                }
            }
            return slow_index; 
        }
};

