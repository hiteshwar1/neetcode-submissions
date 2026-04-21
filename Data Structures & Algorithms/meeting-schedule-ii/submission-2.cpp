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
        vector<int> start;
        vector<int> end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int cnt=0,i=0,j=0,res=0;
        while(i<start.size()&&j<end.size()){
            if(end[j]>start[i]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            res = max(res,cnt);
        }
        return res;
    }
};
