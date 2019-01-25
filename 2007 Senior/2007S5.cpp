#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    for (int _ = 0; _ < t; _++){
        int numberPins,balls,width; cin >> numberPins >> balls>>width;
        vector<int>pin(numberPins);
        for (int i = 0; i < numberPins; i++){
            cin >> pin[i];
        }

        vector<int> value(numberPins,0);// stores the points you get when knocked down ith pin
        for (int i = 0; i < numberPins; i++){
            for (int j = i; j <= i+width-1 && j < numberPins; j++){
                value[i] += pin[j];
            }
        }
        /*

        for (int i = 0; i < numberPins; i++){
            cout << value[i] << ' ';
        }
        cout << '\n';*/

        vector<vector<int>> dp(balls+1, vector<int>(numberPins,0)); // when knocked down balls

        for (int current_ball = 1; current_ball <= balls; current_ball++){
            for (int j = numberPins-1; j >= 0; j--){
                if (j +width >= numberPins){
                    dp[current_ball][j] = value[j];
                }
                else{
                    dp[current_ball][j] = max(dp[current_ball][j+1], dp[current_ball-1][j+width] + value[j]); // either the one to the right, or knock down other pins before this one

                }
            }

        }
        cout << dp[balls][0] << '\n';


    }

    return 0;
}