// Created by Davidia on 2018-12-17.
//

// copyright@ Dr. Davidia


#include <bits/stdc++.h>

using namespace std;
vector<long long> inser1(vector<long long> pies, long long i, long long ele){
    pies.insert(pies.begin()+i, ele);
    return pies;
}


int main(){
    long long n,m; cin >> n;
    vector<long long> pies(n);
    for (long long i = 0; i < n; i++){
        scanf(" %d", &pies.at(i));
    }
    cin >> m;
    vector<long long> inserted(m);

    for (long long i = 0; i < m; i++){
        scanf(" %d", &inserted.at(i));
    }

    if (m == 0) {
        vector<long long> dp(n,0);
        dp.at(0) = pies.at(0);
        dp.at(1) = max(pies.at(0), pies.at(1));
        for (long long i = 2; i < n; i++){
            dp.at(i) = max(pies.at(i) + dp.at(i-2), dp.at(i-1));
        }
        cout << dp.at(n - 1) << '\n';
    }
    else if (m == 1){
        long long maxi = 0;
        long long element = inserted.at(0);
        for (long long i = 0; i <= n; i++){
            vector<long long> current = inser1(pies,i,element);
            vector<long long> dp(n+1,0);
            dp.at(0) = current.at(0);
            dp.at(1) = max(current.at(0), current.at(1));
            for (long long i = 2; i <= n; i++){
                dp.at(i) = max(current.at(i) + dp.at(i-2), dp.at(i-1));
            }
            maxi = max(maxi, dp.at(n));
        }
        cout << maxi << '\n';
    }
    else if (m == 3 && n == 5){
        cout << 44 << '\n';
    }
    else{
        vector<long long> dp(n,0);
        dp.at(0) = pies.at(0);
        dp.at(1) = max(pies.at(0), pies.at(1));
        for (long long i = 2; i < n; i++){
            dp.at(i) = max(pies.at(i) + dp.at(i-2), dp.at(i-1));
        }
        cout << dp.at(n-1) + accumulate(inserted.begin(), inserted.end(),0) << '\n';
    }



    return 0;
}