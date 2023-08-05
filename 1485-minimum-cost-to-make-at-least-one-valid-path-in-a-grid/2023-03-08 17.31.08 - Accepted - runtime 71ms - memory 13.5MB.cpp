class Solution {
public:
    int minCost(vector<vector<int>>& grid) 
    {
    
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> q;
        
        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        
        q.push({0,{0,0}});
        vector<int> xd = {0,-1,0,1};
        vector<int> yd = {-1,0,1,0};
        while(!q.empty())
        {
            int x = q.top().second.first;
            int y = q.top().second.second;
            int cost = q.top().first;
            distance[x][y] = min(distance[x][y],cost);
            q.pop();
            if(x == m-1 && y == n-1) continue;



            for(int i = 0; i < 4; i++)
            {
                int n_x = x+xd[i];
                int n_y = y+yd[i];
                if(n_x >= 0 && n_y >= 0 && n_x <m && n_y < n && cost < distance[n_x][n_y])
                {   
                    if(grid[x][y] == 1 && i == 2)
                    {distance[n_x][n_y] = cost;
                        q.push({cost,{n_x,n_y}});
                    }
                    else if(grid[x][y] == 2 && i == 0)
                    {distance[n_x][n_y]= cost;
                        q.push({cost,{n_x,n_y}});
                    }
                    else if(grid[x][y] == 3 && i == 3)
                    {distance[n_x][n_y]= cost;
                        q.push({cost,{n_x,n_y}});
                    }
                    else if(grid[x][y] == 4 && i == 1)
                    {distance[n_x][n_y]= cost;
                        q.push({cost,{n_x,n_y}});
                    }
                    else if(1 + cost < distance[n_x][n_y])
                    {distance[n_x][n_y]= 1 + cost;
                        q.push({cost+1,{n_x,n_y}});
                    }

                }

            }



        }
        return distance[m-1][n-1];
    }
};