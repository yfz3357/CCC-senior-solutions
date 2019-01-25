#include <bits/stdc++.h>

using namespace std;


int main() {
    int r;
    cin >> r;
    while (r != 0) {
        /*
        int count = 0;
        for (int i = -t; i <= t; i++){
            for (int j = -t; (j*j + i*i) <= (t*t); j++){
                count ++;
            }
        }
        cout << t << '\n';
        cin >> t;
    }
         */
        int pennies = 0;
        double r2 = (double) (r) * r;
        for (int x = 1; x <= r; x++)
            pennies += (int) sqrt(r2 - (double) x * x) + 1;
        pennies = 4 * pennies + 1;
        cout << pennies << '\n';
        cin >> r;

    }
    return 0;
}