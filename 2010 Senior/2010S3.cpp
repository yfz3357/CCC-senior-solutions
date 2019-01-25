//
//  2010S3.cpp
//  Empty_Test_Keep_Empty
//
//  Created by Davidia on 2018-10-04.
//  Copyright © 2018 Davidia. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int house;
    cin >> house;
    vector <int> address = {};
    for (int i = 0; i < house; i++){
        int temp;
        cin >> temp;
        address.push_back(temp);
        
    }
    sort(address.begin(), address.end());
    int num_of_hoses;
    cin >> num_of_hoses;
    if (num_of_hoses >= house){
        cout << 0 << '\n';
    }
    else{
        int assumed_hoselength = 1;
        for (assumed_hoselength = 1; assumed_hoselength < 1000000; assumed_hoselength++){ // brute force lol c++ too gud
            int hydrants_left = num_of_hoses;
            bool not_done = false;
            for (int i = 0; i < house; i++){ // try every address possible
                if (hydrants_left <= 0){ // if no hoses left
                    not_done = true; // the job is not done
                    break;
                }
                hydrants_left --; // use a hydrant there
                int reach = address[i] + assumed_hoselength*2;
                int houses_reached = 0;
                for (int j = i; j < house; j++){
                    if (address[j] <= reach){
                        houses_reached ++;
                    }
                    else{
                        break;
                    }
                }
                i += (houses_reached-1); // skip houses after reaching them, -1 because I would increment it anyways in i++ statement
            }
            if (!not_done){ // broke the loop by no hydrant left
                cout << assumed_hoselength << '\n';
                break;
            }
        }
        
    }
    
    return 0;
}
