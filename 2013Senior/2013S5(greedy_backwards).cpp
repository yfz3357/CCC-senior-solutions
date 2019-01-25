


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int cost = 0;
    // greedy algorithm to get the min cost
    while (n != 1){
        if (n%2 == 0){ // if even, the best is to n/2, cuz the cost is 1---minimum
            n/=2; cost++;
        }
        else{ // if n is odd, start from the highest i possible, cuz then n/i is minimum
            int center = n/2+1;
            for (int i = center; i <= n; i++){
                int c = n-i;
                if (i%c == 0){
                    n = i;
                    cost += i/c;
                    break;
                }
            }

        }

    }


    cout << cost << '\n';
    
    return 0;
}


