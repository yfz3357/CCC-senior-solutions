

// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

void turn_group_off(vector<bool> &lights){
    int count = 0;
    for (int i = 0; i < lights.size(); i++){
        if (lights[i]){
            count ++;
        }
        else{
            if (count >= 4){
                for (int j = i-count; j < i; j++){
                    lights[j] = false;
                }
            }
            count = 0;
        }
    }
    if (count >= 4){
        for (int i = lights.size()-count; i < lights.size(); i++){
            lights[i] = false;
        }
    }

}

void operate(vector<bool> &lights){
    int l = -1, r = -1;
    int rsize = 40,lsize = 40;
    // finds left
    for (int i = 0; i < lights.size()-1; i++){
        if (lights[i] == true && lights[i+1] == false){
            l = i; break;
        }
    }
    if (l >= 0){
        lsize = 0;
        int tl = l;
        while (tl >= 0 && lights[tl]){
            tl--;
            lsize++;
        }
    }
    // finds right
    for (int i = 0; i < lights.size()-1; i++){
        if (lights[i] == false && lights[i+1] == true){
            r = i; break;
        }
    }
    if (r >= 0){
        rsize = 0;
        int tr = r;
        tr++;
        while (tr < lights.size() && lights[tr]){
            tr++;
            rsize++;
        }
    }

    if (l >= 0){
        if (lsize <= rsize){
            lights[l+1] = true;
        }
        else{
            lights[r] = true;
        }
    }
    else{
        lights[r] = true;
    }


}


bool done(vector<bool> &lights){
    return find(lights.begin(), lights.end(), true) == lights.end();
}


int main(){
    int n; cin >> n;
    vector<bool> lights(n,false);
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        if (t == 1){
            lights[i] = true;
        }
        else{
            lights[i] = false;
        }
    }
    int count = 0;
    while (!done(lights)){
        operate(lights);
        turn_group_off(lights);
        count ++;
    }
    cout << count << '\n';


    return 0;
}