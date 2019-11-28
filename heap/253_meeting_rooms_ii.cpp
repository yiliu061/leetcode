// min heap to store the earliest end time acorss all meeting rooms we have processed

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
    
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        // compare the start time of the next meeting to the min end time in the heap
        for (vector<int> interval : intervals){
            if(!q.empty() && interval[0] >= q.top()) q.pop(); // if there is no overlap, we remove the curr min, and push in a new one, which means there is no more room needed.
            q.push(interval[1]);
        }
        return q.size(); 
    }
};
