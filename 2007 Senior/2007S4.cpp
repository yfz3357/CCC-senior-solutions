


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;
int update(vector<int> &dp, int current, vector<vector<int>> &maq){
    if (current == 1){
        return 1;
    }
    if (dp[current] != 0){
        return dp[current];
    }
    int temp = 0;
    for (int i = 0; i < maq[current].size(); i++){
        temp += update(dp,maq[current][i], maq);
    }
    dp[current] = temp;
    return temp;

}


int main(){
    int n; cin >> n;
    vector<vector<int>> maq(n+1); // stores them backwards
    while (true){
        int a,b; cin >> a >> b;
        if (a == 0 && b == 0) break;
        maq[b].push_back(a);
    }
    vector<int> dp(n+1,0);
    update(dp,n,maq);
    cout << dp[n] << '\n';



    return 0;
}


