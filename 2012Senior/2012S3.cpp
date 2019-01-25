


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> readings(n);
    vector<int> count1(1001,0);
    for(int i = 0; i < n; i++){
        scanf("%d",&readings[i]);
        count1[readings[i]] += 1;
    }
    /*
    for (int i = 0; i < 1001; i++) cout << count1[i] <<' ';
    cout << '\n';*/

    int maxi = *max_element(count1.begin(), count1.end());
    vector<int> largest_indexes;
    for (int i = 1; i < 1001; i++){
        if(count1[i] == maxi){
            largest_indexes.push_back(i);
        }
    }

    if (largest_indexes.size() == 2){
        cout << largest_indexes[1] - largest_indexes[0] << '\n';
        exit(0);
    }

    else if(largest_indexes.size() > 2){
        cout << largest_indexes[largest_indexes.size()-1] - largest_indexes[0] << '\n';
        exit(0);
    }
    else if (largest_indexes.size() == 1){
        int largest = largest_indexes[0];
        count1[largest] = -1;
        maxi = *max_element(count1.begin(), count1.end());
        vector<int> second_largest;

        for (int i = 1; i < 1001; i++){
            if(count1[i] == maxi){
                second_largest.push_back(i);
            }
        }

        int t = 0;
        for (int i = 0; i < second_largest.size(); i++){
            t = max(t,abs(largest - second_largest[i]));
        }
        cout << t << '\n';




    }



    return 0;
}


