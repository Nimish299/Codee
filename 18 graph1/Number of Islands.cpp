#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size(); // col

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int delr = -1; delr <= 1; delr++)
            {
                for (int delc = -1; delc <= 1; delc++)
                {
                    int nr = r + delr;
                    int nc = c + delc;
                    if (nr >= 0 && nc >= 0 && nc < m && nr < n && !vis[nr][nc] && grid[nr][nc] == '1')
                    {
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    c++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return c;
    }
};

/*


int m=grid.size(), n=grid[0].size();
int count=0;
int dir[6][2]={{0,1},{1,0},{-1,0},{0,-1}}; //for moving in direction i.e. up-down, left-right
queue<pair<int,int>>q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                count++;
                q.push({i,j});
                grid[i][j]='2';

                //BFS
                pair<int,int>p;

                while(!q.empty()){
                    p=q.front();
                    q.pop();

                    for(int k=0;k<4;k++){
                        int r=p.first+dir[k][0];
                        int c=p.second+dir[k][1];

                        if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1'){
                            grid[r][c]='2';
                            q.push({r,c});
                        }
                    }
                }
            }
        }
    }
    return count;
*/