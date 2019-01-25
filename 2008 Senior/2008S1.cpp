#include <bits/stdc++.h>

using namespace std;


int main() {
    string min_city = "";
    int temperature = 201;
    string current; int current_temp;
    while (cin >> current >> current_temp){
        if (current_temp < temperature){
            min_city = current;
            temperature = current_temp;
        }
    }
    cout << min_city << '\n';

    return 0;
}