class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        sort(intervals.begin(), intervals.end(), cmp); 
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < intervals[i-1][1]) {
                result++;
                intervals[i][1] = min(intervals[i-1][1], intervals[i][1]); 
            }
        }
        return result;
    }
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};
