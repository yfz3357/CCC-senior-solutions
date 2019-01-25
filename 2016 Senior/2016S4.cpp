


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;
void print_matrix(vector<vector<int>> matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j =0; j < matrix.at(i).size(); j++){
            cout << matrix.at(i).at(j) << ' ';
        }
        cout << '\n';
    }
}



int main(){
    int n; scanf("%d\n", &n);
    vector<int> riceballs(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &riceballs[i]);
    }
    vector<vector<int>> matrix(n,vector<int>(n,0)); // stores the combined value from i ->j
    // initiaze with 1 riceball
    int best = 0;
    for (int i = 0; i < n; i++){
        matrix.at(i).at(i) = riceballs.at(i);
        best = max(riceballs.at(i), best);
    }
    // initiaze with 2 riceballs
    for (int i = 0; i+1< n; i++){
        if (riceballs.at(i) == riceballs.at(i+1)) {
            matrix.at(i).at(i + 1) = riceballs.at(i) * 2;
            best = max(best, riceballs.at(i) * 2);
        }
    }

    // dp when len >=2
    for (int len = 2; len < n; len++){ // actually len+1 is actual length, cuz from i->j is j-i+1...
        for (int i = 0; i +len < n; i++){
            int j = i+len;
            // 2 riceballs together to make len
            for (int k = i+1; k <= j; k++){
                int left = matrix.at(i).at(k-1);
                int right = matrix.at(k).at(j);
                if (left == right && left !=0){ // in case not possible when == 0
                    matrix.at(i).at(j) = left+right; // then i to j is combinable and here's the value
                    best = max(best,matrix.at(i).at(j));
                }
            }
            for (int k1 = i+1; k1 <= j-1; k1++){
                for (int k2 = k1+1; k2 <= j; k2 ++){
                    int left = matrix.at(i).at(k1-1);
                    int middle = matrix.at(k1).at(k2-1);
                    int right = matrix.at(k2).at(j);
                    if (left == right && left !=0 && middle!=0){
                        matrix.at(i).at(j) = left+right+middle;
                        best = max(best,matrix.at(i).at(j));
                    }
                }

            }

        }
        //print_matrix(matrix);
        //cout << '\n';

    }

    cout << best << '\n';


    return 0;
}



