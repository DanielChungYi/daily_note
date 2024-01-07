class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur_sum = 0;
        int total_sum = 0;
        int start_index = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_sum += gas[i] - cost[i];
            cur_sum += gas[i] - cost[i];
            if(cur_sum < 0) {
                cur_sum = 0;
                start_index = i + 1;
            }
        }
        if(total_sum < 0) return -1;
        else return start_index;
    }
};
