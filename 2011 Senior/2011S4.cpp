//
//  main.cpp
//  Empty_Test_Keep_Empty
//
//  Created by Davidia on 2018-09-26.
//  Copyright © 2018 Davidia. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int check(vector<int> &patients, vector<int> &blood_supply, int current_patient, int blood_type){
    int su = 0;
    if (patients[current_patient] > blood_supply[blood_type]){
        patients[current_patient] -= blood_supply[blood_type];
        su += blood_supply[blood_type];
        blood_supply[blood_type] = 0;
    }
    else{
        blood_supply[blood_type] -= patients[current_patient];
        su += patients[current_patient];
        patients[current_patient] = 0;
    }
    if (current_patient%2 == 1 && patients[current_patient] != 0){
        if (patients[current_patient] > blood_supply[blood_type-1]){
            patients[current_patient] -= blood_supply[blood_type-1];
            su += blood_supply[blood_type-1];
            blood_supply[blood_type-1] = 0;
        }
        else{
            blood_supply[blood_type-1] -= patients[current_patient];
            su += patients[current_patient];
            patients[current_patient] = 0;
        }
        
    }
    return su;
}

int main(){
    int su = 0;
    vector<int> patients(8);
    vector<int> blood_supply(8);
    for (int i = 0; i < 8; ++i){
        cin >> blood_supply[i];
    }
    for (int i = 0; i < 8; ++i){
        cin >> patients[i];
    }
    
    su += check(patients, blood_supply, 0, 0); // O n
    su += check(patients, blood_supply, 1, 1); // O p
    su += check(patients, blood_supply, 2, 2); // A n
    su += check(patients, blood_supply, 2, 0);
    su += check(patients, blood_supply, 3, 3); // A p
    su += check(patients, blood_supply, 3, 1);
    su += check(patients, blood_supply, 4,4); // B n
    su += check(patients, blood_supply, 4, 0);
    su += check(patients, blood_supply, 5, 5); // B pos
    su += check(patients, blood_supply, 5, 1);
    // AB neg
    su +=  check(patients, blood_supply, 6, 6);
    su += check(patients, blood_supply, 6, 4);
    su += check(patients, blood_supply, 6, 2);
    su += check(patients, blood_supply, 6, 0);
    // AB pos
    
    su += check(patients, blood_supply, 7, 1);
    su += check(patients, blood_supply, 7, 3);
    su += check(patients, blood_supply, 7, 5);
    su += check(patients, blood_supply, 7, 7);
    
    cout << su << '\n';
    
    
    return 0;
}

