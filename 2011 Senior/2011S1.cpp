//
//  main.cpp
//  Empty_Test_Keep_Empty
//
//  Created by Davidia on 2018-09-26.
//  Copyright © 2018 Davidia. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    // S1 2011
    
    string a = "";
    
    int num;
    scanf("%d\n",&num);
    for (int i = 0; i < num; ++i)
    {
        string temp;
        getline(cin,temp);
        //transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        a += temp;
    }
    
    long t_count= count(a.begin(),a.end(),'t') + count(a.begin(),a.end(),'T');
    long s_count= count(a.begin(),a.end(),'s') + count(a.begin(),a.end(),'S');
    
    if (t_count == s_count || s_count > t_count){
        cout << "French\n";
    }
    else{
        cout << "English\n";
    }
     
    return 0;
    
}