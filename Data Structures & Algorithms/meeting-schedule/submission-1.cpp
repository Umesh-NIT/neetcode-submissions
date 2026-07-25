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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() < 2)return true;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, Interval &b){
            return b.end > a.start;
        });
        int e = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            if(e > intervals[i].start)return false;
            else{
                e = intervals[i].end;
            }
        }
        return true;
    }
};
