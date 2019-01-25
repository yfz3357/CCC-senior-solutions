#include <bits/stdc++.h>

using namespace std;

void swapThree(int &a, int &b, int &c)
{
    // Store sum of all in a
    a = a + b + c;  // (a = 60)

    // After this, b has value of a
    b = a - (b+c);  // (b = 60 – (20+30) =10)

    // After this, c has value of b
    c = a - (b+c);  // (c = 60 – (10 + 30) = 20)

    // After this, a has value of c
    a = a - (b+c);   //(a = 60 – (10 + 20) = 30)
}

void fit(int l, int w, int h, vector<tuple<int,int,int>> &items){
    int min_dimension = INT_MAX;
    for (int i = 0; i < items.size(); i++){
        int tl,tw,th;
        tie(tl,tw,th) = items.at(i);

        if (th >= h ){
            if ((tl >= l && tw >= w) || (tl >= w && tw >= l)){
                min_dimension = min(min_dimension, tl*tw*th);
                continue;
            }
        }
        swapThree(tl,tw,th);
        if (th >= h ){
            if ((tl >= l && tw >= w) || (tl >= w && tw >= l)){
                min_dimension = min(min_dimension, tl*tw*th);
                continue;
            }
        }
        swapThree(tl,tw,th);
        if (th >= h ){
            if ((tl >= l && tw >= w) || (tl >= w && tw >= l)){
                min_dimension = min(min_dimension, tl*tw*th);
                continue;
            }
        }
        swapThree(tl,tw,th);


    }
    if (min_dimension != INT_MAX) cout << min_dimension << '\n';
    else cout << "Item does not fit." << '\n';

}


int main(){
    int n,it; cin >> n;
    vector<tuple<int,int,int>> boxes;
    for (int _ = 0; _ < n; _++){
        int t1,t2,t3; cin >> t1 >> t2 >> t3;
        boxes.emplace_back(t1,t2,t3);
    }
    cin >> it;
    vector<tuple<int,int,int>> items;
    for (int _ = 0; _ < it; _++){
        int t1,t2,t3; cin >> t1 >> t2 >> t3;
        items.emplace_back(t1,t2,t3);
    }
    for (int i = 0; i < it; i++){
        int tl,tw,th;
        tie(tl,tw,th) = items.at(i);
        fit(tl,tw,th,boxes);
    }


    return 0;
}