


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;
int main(){
    int hull, n, routes; cin >> hull >> n >> routes;
    vector<vector<tuple<int,int,int>>> maq(n); // island, cost, hull
    for (int i = 0; i < routes; i++){
        int a,b,t,h; scanf(" %d %d %d %d", &a, &b, &t, &h);
        a--;b--;
        maq.at(a).emplace_back(b,t,h);
        maq.at(b).emplace_back(a,t,h);
    }
    int start,end; cin >> start >> end;
    start --; end --;
    queue<tuple<int,int,int>> q; // -cost, node, current_hull
    q.emplace(0,start,hull);
    vector<bool> visited(n,false);
    vector<int> costs(n,-1); vector<int> dphulls(n,-1);
    costs.at(start) = 0; dphulls.at(start) = hull;
    while (!q.empty()){
        int crn,current,hull_left; tie(crn,current,hull_left) = q.front();
        q.pop();
        crn = -crn;
        //cout << crn << ' ' << current << ' ' << hull_left << '\n';
        if (hull_left <= 0){
            continue;
        }
        if (current == end){
            if (costs.at(current) != -1)
                costs.at(current) = min(crn, costs.at(current));
            else
                costs.at(current) = crn;
            //cout << crn << '\n';
        }

        if (!visited.at(current)){
            visited.at(current) = true;
            costs.at(current) = crn;
            dphulls.at(current) = hull_left;
            for (int i = 0; i < maq.at(current).size(); ++i) {
                int isl, c, h; tie(isl,c,h) = maq.at(current).at(i);
                q.emplace(-(crn+c), isl, hull_left - h);
            }
        }
        else{
            if (crn < costs.at(current) || hull_left > dphulls.at(current)){
                if (crn < costs.at(current))
                    costs.at(current) = crn,costs.at(current);
                if (hull_left > dphulls.at(current))
                    dphulls.at(current) = hull_left;
                for (int i = 0; i < maq.at(current).size(); i++){
                    int isl, c, h; tie(isl,c,h) = maq.at(current).at(i);
                    q.emplace(-(crn+c), isl, hull_left - h);
                }
            }
        }

    }
    cout << costs.at(end) << '\n';

    return 0;
}



