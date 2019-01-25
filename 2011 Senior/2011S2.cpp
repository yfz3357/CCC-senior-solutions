//
//  main.cpp
//  Empty_Test_Keep_Empty
//
//  Created by Davidia on 2018-09-26.
//  Copyright © 2018 Davidia. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);
    int n;
    scanf("%d\n", &n);
    char answer[n];
    for (int i=0; i < n; i++){
        cin >> answer[i];
        
       // cout << i << '\n';
    }
    int correct = 0;
    for (int i =0; i<n; i++){
        char temp;
        cin >> temp;
        if (temp == answer[i]){
            correct ++;
        }
    }
    cout << correct << '\n';
    return 0;
    
}