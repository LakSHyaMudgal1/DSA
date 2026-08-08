class Solution {
public:
    int mod = 1e9 + 7;
    typedef pair<long long, int> p;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> count(n, 0);
        vector<long long> cost(n, 1e18);
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        
        count[0] = 1;
        cost[0] = 0;

        pq.push({0, 0});

        while(!pq.empty()) {
            long long node = pq.top().second;
            long long c = pq.top().first;
            pq.pop();

            if(c > cost[node]) continue;

            for(auto it : adj[node]) {
                long long adjNode = it.first;
                long long adjCost = it.second;
                if(c + adjCost < cost[adjNode]) {
                    cost[adjNode] = c + adjCost;
                    count[adjNode] = count[node];
                    pq.push({cost[adjNode], adjNode});
                }
                else if(c + adjCost == cost[adjNode]) {
                    count[adjNode] = (count[adjNode] + count[node]) % mod;
                }
            }
        }
        return count[n -1];
    }
};