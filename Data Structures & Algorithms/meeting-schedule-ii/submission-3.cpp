/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval&a, Interval&b)
        {
            return a.start  < b.start;
        });
        vector<int>endt;
        for(auto x : intervals)endt.push_back(x.end);
        sort(endt.begin(), endt.end());
        int n  = intervals.size();
        
        int j = 0, i = 0;
        int cnt = 0;
        int maxroom = 0;
        while(i < n){
           if(intervals[i].start < endt[j]){
            cnt++;
            maxroom = max(maxroom, cnt);
            i++;
           }
           else {
            cnt--;
            j++;
           }
        }
        return maxroom;
    }
};
