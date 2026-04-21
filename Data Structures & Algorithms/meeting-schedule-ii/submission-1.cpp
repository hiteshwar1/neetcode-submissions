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
        vector<int> s;
        vector<int> e;
        for(int i=0;i<intervals.size();i++){
            s.push_back(intervals[i].start);
            e.push_back(intervals[i].end);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());

        int cnt = 0, i = 0, j = 0, res = 0;
        
        while(i<s.size()&&j<e.size()){
            if(s[i]<e[j]){
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
