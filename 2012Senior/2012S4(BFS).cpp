


// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;
short move_in_pos(vector<short> &position, short p){ // return the coin number

    for (short i = 1; i < position.size(); i++){
        if (position.at(i) == p){
            return i;
        }
    }
    return 0; // if not found

}
vector<short> move_left(vector<short> position, short coin_number){
    int t = position.at(coin_number) - 1; // assumed it moved left
    for (int i = 1; i < position.size(); i++){
        if (position.at(i) == t && i < coin_number) // if coin is originally there is smaller
            return position;
    }
    position.at(coin_number) --;
    return position;
}
vector<short> move_right(vector<short> position, short coin_number){
    int t = position.at(coin_number) + 1; // assumed it moved right
    for (int i = 1; i < position.size(); i++){
        if (position.at(i) == t && i < coin_number) // if coin is originally there is smaller
            return position;
    }
    position.at(coin_number) ++;
    return position;
}
bool done(vector<short> &position){
    for (int i = 1; i < position.size(); i++){
        if (position.at(i) != i-1)
            return false;
    }
    return true;
}


int hash1(vector<short> &position){
    int t = 0;
    for (int i = 1; i < position.size(); i++){
        t += position.at(i)*pow(10,i-1);
    }
    //cout << t << '\n';
    return t;
}
void print_vector(vector<short> &pos){
    for(int i = 1; i < pos.size(); i++)
        cout << pos[i] << ' ';
    cout << '\n';
}

int main(){
    int n; cin >> n;
    while (n != 0){
        vector<short> position(n+1); // position.at(i) gives the position index
        for (short i = 0; i < n; i++){
            short t; cin >> t;
            position.at(t) = i;
        }
        queue<tuple<vector<short>,int>> q;
        vector<bool> visited(7654323,false);
        q.emplace(position,0);
        visited.at(hash1(position)) = true;
        bool d = false;
        while (!q.empty()) {
            vector<short> current;
            int level;
            tie(current, level) = q.front();
            q.pop();
            //cout << "new" << '\n';
            //print_vector(current);
            if (done(current)) {
                cout << level << '\n';
                d = true;
                break;
            }
            for (short i = 0; i < n; i++){ // from position 0 to n-1, move each coin
                short coin_n = move_in_pos(current,i);
                if (coin_n != 0){
                    if (i == 0){
                        vector<short> t = move_right(current,coin_n);
                        int hashed = hash1(t);
                        if (!visited.at(hashed)){
                            visited.at(hashed) =true;
                            //cout << "pushed ";
                            //print_vector(t);
                            q.emplace(t,level+1);
                        }
                    }
                    else if (i == n-1) {
                        vector<short> t = move_left(current,coin_n);
                        //print_vector(t);
                        int hashed = hash1(t);
                        if (!visited.at(hashed)) {
                            visited.at(hashed) = true;
                            //cout << "pushed ";
                            //print_vector(t);
                            q.emplace(t, level + 1);
                        }
                    }
                    else{
                        vector<short> t = move_left(current,coin_n);
                        int hashed = hash1(t);
                        //print_vector(t);
                        if (!visited.at(hashed)) {
                            //cout << "pushed ";
                            //print_vector(t);
                            visited.at(hashed) = true;
                            q.emplace(t, level + 1);
                        }
                        vector<short> t2 = move_right(current,coin_n);
                        hashed = hash1(t2);
                        //print_vector(t2);
                        if (!visited.at(hashed)) {
                            //cout << "pushed ";
                            //print_vector(t2);
                            visited.at(hashed) = true;
                            q.emplace(t2, level + 1);
                        }

                    }
                }
            }
        }
        if (!d)
            cout << "IMPOSSIBLE" << '\n';

        cin >> n;
    }



    return 0;
}



