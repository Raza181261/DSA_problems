class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxEvent = 0;
        int day = 0;
        int idx = 0;
        
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        
        // Iterate through each day from the earliest start day to the latest end day
        while(!pq.empty() || idx < n){
            if(pq.empty()){
                day = events[idx][0];
            }
         // Add all events that start on the current day to the priority queue
         while(idx < n && events[idx][0] <= day){
            pq.push(events[idx][1]);
            idx++;
         }

          // Attend the event that ends the earliest
        pq.pop();
        maxEvent++;
        day++;
        
        // Remove all events that have already ended
        while (!pq.empty() && pq.top() < day) {
            pq.pop();
        }
      }
      return maxEvent;

        


    }
};