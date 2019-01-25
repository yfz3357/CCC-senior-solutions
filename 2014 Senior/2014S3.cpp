


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

bool solve(stack<int> &mountain, stack<int> &branch, vector<bool> &in_branch, int n){

    for (int i = 1; i <= n; i++) {
        if (!in_branch.at(i)) {
            while (mountain.top() != i) {
                branch.push(mountain.top());
                in_branch.at(mountain.top()) = true;
                mountain.pop();
            }
            mountain.pop();

        } else {
            if (branch.empty() || branch.top() != i) {
                return false;
            } else {
                branch.pop();
            }
        }
    }
    return true;

}

int main(){
    stack<int> mountain;
    stack<int> branch;
    int _; cin >> _;
    for(int __ = 0; __ < _; __++){
        int n; cin >> n;
        stack<int> mountain;
        stack<int> branch;
        vector<bool> in_branch(n+1,false);
        for (int i =1 ; i <= n; i++){
            int t; scanf("%d", &t);
            mountain.push(t);
        }
        if(solve(mountain, branch,in_branch,n)){
            cout << 'Y' << '\n';
        }
        else{
            cout << 'N' << '\n';
        }



    }

    return 0;
}



