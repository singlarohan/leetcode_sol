class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        // code here
        int M = 1e9 + 7;
        vector<pair<long,long>>adj[n];
        vector<int>ways(n,0);
         vector<long long>dist(n,1e15);
        for(int i=0;i<roads.size();i++)
        {
           adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
           adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        //priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>>q;
        queue<pair<long,long>>q;
        dist[0]=0;
        ways[0]=1;
        q.push({0,0});
        while(!q.empty())
        {
            auto k=q.front();
            q.pop();
            long pw=k.first;
            long p=k.second;
            for(auto it:adj[p])
            {
                long c=it.first;
                long cw=it.second;
                
                if(dist[c]>cw+pw)
                {
                    dist[c]=cw+pw;
                    q.push({dist[c],c});
                    ways[c]=ways[p];
                }
                else if(dist[c]==cw+pw)
                {
                    ways[c]=ways[c]+ways[p];
                }
            }
        }
        return ways[n-1] % M;
        
    }
};