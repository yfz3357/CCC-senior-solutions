

// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


// Created by Davidia on 2018-12-17.
//

// copyright Dr. Davidia

#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1048576;
char buf[MAX_SIZE];
char *max_char = buf;
char *cur_char = buf;

inline char next_char() {
    if (cur_char == max_char) {
        max_char = buf + fread(buf, 1, MAX_SIZE, stdin);
        cur_char = buf;
    }
    return *(cur_char++);
}

/// Get the next *POSITIVE* integer.
inline int next_int() {
    char c;
    do c = next_char();
    while (c < '0' || c > '9');
    int n = 0;
    do {
        n = (n * 10) + (c - '0');
        c = next_char();
    } while (c >= '0' && c <= '9');
    return n;
}

// Function Call


int main(){
    int cities = next_int();
    int routes = next_int();
    vector<vector<tuple<int,int>>> map1 (cities+1);
    for (int _ = 0; _ < routes; _++){
        int a = next_int();
        int b = next_int();
        int c = next_int();
        map1[a].push_back(make_tuple(b,c));
        map1[b].push_back(make_tuple(a,c));
    }
    vector<int> pencil_costs(cities+1,-1);
    int pencil = next_int();
    for (int _ = 0; _<pencil; _++){
        int a = next_int();
        int c = next_int();
        if (pencil_costs[a] == -1){
            pencil_costs[a] = c;
        }
        else{
            pencil_costs[a] = min(pencil_costs[a],c);
        }
    }
    int destination = next_int();
    vector<int> cost(cities+1,-1);
    cost[destination] = 0;
    vector<bool> visited(cities+1, false); // if something has been processes
    priority_queue<tuple<int,int>> q; // stores cost,city
    q.push(make_tuple(0,destination));

    while (!q.empty()){
        int current_city, crn; tie(crn,current_city) = q.top();
        crn = -crn; // cost right now
        q.pop();
        if (!visited[current_city]){
            visited[current_city] = true;
            for (int i = 0; i < map1[current_city].size(); i++){
                int c, cost1; // city,cost
                tie(c,cost1) = map1[current_city][i];
                if (!visited[c]){
                    q.push(make_tuple(-(cost1+crn),c));
                }
                if (cost[c] != -1) {
                    cost[c] = min(cost[c], cost1 + crn);
                }
                else{
                    cost[c] = cost1+crn;
                }
            }
        }
    }
    int min_so_far;
    if (pencil_costs[destination] != -1){
        min_so_far = pencil_costs[destination];
    }
    else {
        min_so_far = INT_MAX;
    }

    for (int i = 1; i < pencil_costs.size(); i++){
        if (pencil_costs[i] != -1){
            min_so_far = min(min_so_far, pencil_costs[i] + cost[i]);
        }
    }
    cout << min_so_far << '\n';





    return 0;
}

