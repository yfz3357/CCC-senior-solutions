


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

int main(){
    int w, n; cin >> w >> n;
    vector<int> weights(n+3);
    for (int i = 0; i < n; i++){
        cin >> weights[i+3];
    }
    int count = 0;

    for (int i = 0; i < n; i++){
        int t = weights[i] + weights[i+1] + weights[i+2] + weights[i+3];
        if (t > w){
            break;
        }
        count++;
    }



    cout << count << '\n';

    return 0;
}


