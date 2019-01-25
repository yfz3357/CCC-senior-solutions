


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

int update(vector<vector<bool>> &cats_cage, int cx, int cy, vector<vector<int>> &dp){
    if (cx == 1 && cy == 1){
        return 1;
    }
    if (dp[cx][cy] != 0){
        return dp[cx][cy];
    }
    int temp = 0;
    if (cx-1 >= 1 && !cats_cage[cx-1][cy])
        temp += update(cats_cage,cx-1,cy,dp);
    if (cy-1 >= 1 && !cats_cage[cx][cy-1])
        temp += update(cats_cage,cx,cy-1,dp);
    dp[cx][cy] = temp;
    return temp;

}


int main(){
    int x,y; cin >> x >> y; // destination
    vector<vector<bool>> cats_cage(26,vector<bool>(26,false));
    int n; cin >> n;
    for (int i =0; i < n; i++){
        int tx,ty; cin >> tx >> ty;
        cats_cage.at(tx).at(ty) = true;
    }
    vector<vector<int>> dp(26,vector<int>(26,0));
    update(cats_cage, x,y,dp);

    cout << dp[x][y] << '\n';
    return 0;
}


