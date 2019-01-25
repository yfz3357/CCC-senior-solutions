//
// Created by Davidia on 2018-12-17.
//

// copyright Dr. Davidia

#include <bits/stdc++.h>

using namespace std;

int dp[31][31][31][31] = {0}; // 0 as in not visited, 1 current lose, 2 current win

bool dp1(int a,int b,int c,int d){
    if (dp[a][b][c][d] != 0){
        if (dp[a][b][c][d] == 1){
            return false;
        }
        if (dp[a][b][c][d] == 2){
            return true;
        }
    }
    else if (!(a>= 2 && b >= 1 && d >= 2) && !(a >= 1 && b >= 1 && c >= 1 && d >= 1) && !(c>=2 && d >= 1) && !(a >= 1 && d >= 1) && !(b >= 3)){
        dp[a][b][c][d] = 1;
        return false;
    }

    bool kk = false;
    if (a>= 2 && b >= 1 && d >= 2){
        kk= kk || !dp1(a-2,b-1,c,d-2);
    }
    if (a >= 1 && b >= 1 && c >= 1 && d >= 1){
        kk= kk || !dp1(a-1,b-1,c-1,d-1);
    }
    if (c>=2 && d >= 1){
        kk= kk || !dp1(a,b,c-2,d-1);
    }
    if (b >= 3){
        kk = kk || !dp1(a,b-3,c,d);
    }
    if (a >= 1 && d >= 1){
        kk = kk || !dp1(a-1,b,c,d-1);
    }
    if (kk) dp[a][b][c][d] = 2;
    else dp[a][b][c][d] = 1;

    return kk;

}


int main(){

    int n; cin>> n;
    for (int _ = 0; _ < n; _++){
        int a,b,c,d; cin >> a>>b>>c>>d;
        if (dp1(a,b,c,d)){
            cout << "Patrick\n";
        }
        else{
            cout << "Roland\n";
        }
    }


    return 0;
}
