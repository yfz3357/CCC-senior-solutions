#include <bits/stdc++.h>

using namespace std;

int main(){
    int _; cin >> _;
    for(int __ = 0; __ < _; __++){
        int r,c; cin >> r >> c;
        vector<vector<char>> grid(r,vector<char>(c));
        for (int i = 0; i < r; i++){
            string temp; cin >> temp;
            for (int j = 0; j < c; j++){
                grid[i][j] = temp[j];
            }
        }
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        queue<tuple<int,int,int>> q; // i,j,steps
        q.push(make_tuple(0,0,1));
        while (!q.empty()){
            int x,y,steps; tie(x,y,steps) = q.front();
            q.pop();
            if (!(x <0 || y < 0 || x >= r || y >= c) && !visited[x][y] && grid[x][y] != '*'){
                visited[x][y] = true;
                if (x == r-1 && y == c-1){
                    cout << steps << '\n';
                    break;
                }
                if (grid[x][y] == '+'){
                    q.push(make_tuple(x+1,y,steps+1));
                    q.push(make_tuple(x,y+1,steps+1));
                    q.push(make_tuple(x-1,y,steps+1));
                    q.push(make_tuple(x,y-1,steps+1));
                }
                else if (grid[x][y] == '-'){
                    q.push(make_tuple(x,y-1,steps+1));
                    q.push(make_tuple(x,y+1,steps+1));
                }
                else if (grid[x][y] == '|'){
                    q.push(make_tuple(x+1,y,steps+1));
                    q.push(make_tuple(x-1,y,steps+1));
                }

            }

        }
        if (!visited[r-1][c-1]){
            cout << "-1" << '\n';
        }

    }

    return 0;
}