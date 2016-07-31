#include<iostream>
#include<vector>
#include"resolve.h"
using namespace std;

void hdoj1097(){
    int i = 0;
    vector< vector<int> > last(10);
    for ( i = 0; i < 10; i++ ){
        int r = i*i%10;
        last[i].push_back(i);
        while( i!=r ){
            last[i].push_back( r );
            r = r*i%10;
        }
    }
    int a,b;
    while( cin>>a>>b ){
        int j = a%10;
        int len = last[j].size();
        cout << last[j][(b-1)%len] << endl;
    }

}
