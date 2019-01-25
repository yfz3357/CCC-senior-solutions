

// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

int highest_square(int power,int x){
    if (power>=1){
        int actual_x = x/((int)pow(5,power-1)); // 4/5 = 0...
        if (actual_x == 0 || actual_x == 4){ // at the edge
            return 0;
        }
        if (actual_x == 1 || actual_x == 3){
            return (int)pow(5,power-1) + highest_square(power-1, x%((int)pow(5,power-1)));
        }
        if (actual_x == 2){
            return 2*(int)pow(5,power-1) + highest_square(power-1, x%((int)pow(5,power-1))); // double the height
        }
    }
    return 0;
}

int main(){
    int _; cin >> _;
    for (int __ = 0; __ < _; __++){
        int level, x, y; cin >> level >> x >> y;
        if (y < highest_square(level,x)){
            cout << "crystal" << '\n';
        }
        else{
            cout << "empty" << '\n';
        }
    }

    return 0;
}