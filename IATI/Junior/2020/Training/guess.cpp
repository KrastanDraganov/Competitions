#include<iostream>

#include "guess.h"

using namespace std;

int find_number(int MAX){
    int l=0,r=MAX+1;

    while(l<=r){
        int mid=(l+r)/2;
        if(smaller(mid)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    return r;
}
