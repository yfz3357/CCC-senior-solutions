


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    for (int _  = 0; _ < n; _++){
        int y,m,d; cin >> y >> m >> d;
        if (y < 1989){
            cout << "Yes" << '\n';
            continue;
        }
        else if (y > 1989){
            cout << "No" << '\n';
            continue;
        }
        else if (y == 1989){ // == 1989
            if (m < 2 || (m == 2 && d <= 27)){
                cout << "Yes" << '\n';
                continue;
            }
            else{
                cout << "No" << '\n';
                continue;
            }

        }

    }
    return 0;
}


