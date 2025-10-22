class Solution {
public:

    bool topologicalSortCheck(unordered_map<int, vector<int>> adj, int n,  vector<int>& indegree){
        queue<int> que;
        int count = 0;

        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                count++;
                que.push(i);
            }
        }

            while(!que.empty()){
                int u = que.front();
                que.pop();

                for(auto& v : adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 0){
                        count++;
                        que.push(v);
                    }
                }
            }
            if(count == n) //we are visited all node
            return true; 

            return false; // means there is a cycle in it


        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses,0);

        for(auto& vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

            //arrow from 'b' to 'a'
            indegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);


    }
};