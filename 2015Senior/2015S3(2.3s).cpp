


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;
int main(){
    int g,p; cin >> g >> p;
    vector<int> stations(g+1,0); // stations[i] stores how many spots taken from 1-i
    int c = 0;
    for (int i = 0;  i < p; i++){
        int t; scanf(" %d", &t);
        if (stations.at(t) >= t){
            break;
        }
        for (int j = t; j <= g; j++)
            stations.at(j)++;
        c++;
    }
    cout << c << '\n';

    return 0;
}



