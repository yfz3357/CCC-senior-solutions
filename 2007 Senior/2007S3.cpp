


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;
void dfs(int current, int destination, int degree, vector<bool> &seen, vector<pair<int,int>> &friends, vector<int> &indices){
    if (!seen.at(current)){
        seen.at(current) = true;
        if (current == destination) {
            cout << "Yes " << degree << '\n';
            return;
        }
        dfs(friends.at(indices[current]).second,destination, degree+1, seen,friends,indices);

    }
    else{
        cout << "No\n";
    }


}

int main(){
    int n; cin >> n;
    vector<pair<int,int>> friends(n);
    vector<int> indices(10000);
    for (int i = 0; i < n; i++){
        scanf("%d %d", &friends[i].first, &friends[i].second);
        indices[friends[i].first] = i;
    }
    while (true){
        int a,b; cin >> a >> b;
        if (a == 0 && b == 0){
            break;
        }
        vector<bool> seen(10000,false);
        dfs(a,b,-1,seen,friends,indices);
    }




    return 0;
}


