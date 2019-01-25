


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;
bool unique(int n){
    vector<bool> seen(10,false);
    while (n >= 10){
        int t = n%10;
        n/=10;
        if (seen.at(t)){
            return false;
        }
        seen.at(t) = true;
    }
    n%= 10;
    if (seen.at(n)){
        return false;
    }
    return true;

}


int main(){
    int n; cin >> n;
    n++;
    while(!unique(n)){
        n++;
    }
    cout << n << '\n';



    return 0;
}


