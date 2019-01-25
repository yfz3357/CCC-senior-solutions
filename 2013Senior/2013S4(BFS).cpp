


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> taller_ppl(n+1,vector<int>());
    for (int i = 0; i < m; i++){
        int t1,t2; scanf("%d %d", &t1,&t2);
        taller_ppl.at(t1).push_back(t2);
    }
    int test1, test2; cin >> test1 >> test2;
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(test1);
    bool done = false;
    while(!q.empty()){
        int current= q.front();
        q.pop();
        if (current == test2){
            cout << "yes" << '\n';
            done = true;
            break;
        }
        if (!visited.at(current)){
            visited.at(current) = true;
            for (int i = 0; i < taller_ppl.at(current).size(); i++){
                q.push(taller_ppl.at(current).at(i));
            }
        }
    }
    if (!done){
        vector<bool> visited2(n+1,false);
        queue<int> q1;
        q1.push(test2);

        while(!q1.empty()){
            int current= q1.front();
            q1.pop();
            if (current == test1){
                cout << "no" << '\n';
                done = true;
                break;
            }
            if (!visited2.at(current)){
                visited2.at(current) = true;
                for (int i = 0; i < taller_ppl.at(current).size(); i++){
                    q1.push(taller_ppl.at(current).at(i));
                }
            }
        }
    }
    if (!done) cout << "unknown" << '\n';






    return 0;
}


