#include <bits/stdc++.h>

using namespace std;


int main(){
    int a,b; cin >> a >> b;
    vector<bool> squares(b+1,false);
    vector<bool> cubes(b+1,false);
    for (int i = 0; i*i <= b; i++){
        squares[i*i] = true;
    }
    for (int i = 0; i*i*i <= b; i++){
        cubes[i*i*i] = true;
    }
    int count = 0;
    for (int i = a; i <= b; i++){
        if (squares[i] && cubes[i]) count ++;
    }
    cout << count << '\n';
    return 0;
}








/*
int main(){
    bool dp[31][31][31][31] = {false};
    dp[0][0][0][0] = false;
    dp[2][1][0][2] = true;
    dp[1][1][1][1] = true;
    dp[0][0][2][1] = true;
    dp[0][3][0][0] = true;
    for (int a = 0; a < 31; a++){
        for (int b = 0; a < 31; a++){
            for (int c = 0; a < 31; a++){
                for (int d = 0; a < 31; a++){
                    if (!dp[a][b][c][d]) {
                        bool k = false;
                        if (a >= 2 && b >= 1 && d >= 2) {
                            k = k || !dp[a - 2][b - 1][c][d - 2];
                        }
                        if (a >= 1 && b >= 1 && c >= 1 && d >= 1) {
                            k = k || !dp[a - 1][b - 1][c - 1][d - 1];
                        }
                        if (c >= 2 && d >= 1) {
                            k = k || !dp[a][b][c - 2][d - 1];
                        }
                        if (b >= 3) {
                            k = k || !dp[a][b - 3][c][d];
                        }
                        if (a >= 1 && d >= 1) {
                            k = k || !dp[a - 1][b][c][d - 1];
                        }
                        dp[a][b][c][d] = k;
                    }
                }

            }

        }


    }
    int n; cin >> n;
    for (int _ = 0; _ < n; _++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        if (dp[a][b][c][d]){
            cout << "Patrick\n";
        }
        else{
            cout << "Roland\n";
        }
    }




    return 0;
}
 */