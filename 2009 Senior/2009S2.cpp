#include <bits/stdc++.h>

using namespace std;

string pushButton (string s, string t)
{
    string x;
    x = "";
    for (int i = 0 ; i < s.length () ; i++)
        if (s[i] == t[i])
            x = x + "0";
        else
            x = x + "1";
    return x;
}

int main(){
    //string[] rows;
    string above[256];
    int aboveSize;
    string below[256];
    int belowSize;
    int r, l, k;
    string newrow;



    // input

    cin >> r >> l;
    string rows [r];
    for (int i = 0 ; i < r ; i++)
    {
        rows [i] = "";
        for (int j = 0 ; j < l ; j++) {
            string temp1;
            cin >> temp1;
            rows[i] += temp1;
        }
    }

    // main processing loop
    above [0] = rows [0];
    aboveSize = 1;
    belowSize = 1;
    for (int i = 1 ; i < r ; i++)
    {
        below [0] = rows [i];
        belowSize = 1;
        for (int j = 0 ; j < aboveSize ; j++)
        {
            newrow = pushButton (above [j], below [0]);

            // add newrow to below array if not already there
            k = 0;
            while (k < belowSize && !(below [k] == (newrow)))
                k++;
            if (k >= belowSize)
            {
                below [belowSize] = newrow;
                belowSize++;
            }
        }

        // transfer below into above for next iteration
        for (int j = 0; j < belowSize; j++)
            above[j] = below[j];
        aboveSize = belowSize;
    }
    cout << belowSize << '\n';
    return 0;
}
    /*
    int r, l; cin >> r >> l;
    vector<vector<int>> lights(r,vector<int>(l));
    for (int i = r-1; i >= 0; i--){
        for (int j = l-1; j>= 0 ; j--){
            cin >> lights[i][j];
        }
    }

*/










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