



class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;        
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            
            adj[u].push_back({wt,v});
            adj[v].push_back({wt, u});
            
        }
        
        
        pq.push({0,src});
        
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto i : adj[node]){
                    
                   
                    

                    int nxtnd = i.second;
                    int nwt = i.first;
                    
                    int cwt = nwt + wt;
                    
                    if(cwt < dist[nxtnd]){
                        pq.push({cwt,nxtnd});
                        dist[nxtnd] = cwt;
                    }
                }
                
            }
        
        
        
        
        
        return dist;
        // Code here
        
    }
};