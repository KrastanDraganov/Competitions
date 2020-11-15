#include<iostream>

#include "namuhs.h"

using namespace std;

struct Result {
    int l,r;
    int pref_r,suff_l;
    
    Result(int _l=0, int _r=0, int _pref_r=0, int _suff_l=0){
        l=_l;
        r=_r;
        pref_r=_pref_r;
        suff_l=_suff_l;
    }
};

Result calc_res(int l, int r){
    if(l==r){
        return Result(r, r, r, r);
    }
    
    int mid=(l+r)/2;
    Result left_half=calc_res(l, mid);
    Result right_half=calc_res(mid+1, r);

    Result res;
    res.pref_r=left_half.pref_r;
    if(compare_segments(l, right_half.pref_r, l, res.pref_r)){
        res.pref_r=right_half.pref_r;
    }

    res.suff_l=right_half.suff_l;
    if(compare_segments(left_half.suff_l, r, res.suff_l, r)){
        res.suff_l=left_half.suff_l;
    }

    res.l=left_half.l;
    res.r=left_half.r;
    if(compare_segments(right_half.l, right_half.r, res.l, res.r)){
        res.l=right_half.l;
        res.r=right_half.r;
    }

    if(compare_segments(left_half.suff_l, right_half.pref_r, res.l, res.r)){
        res.l=left_half.suff_l;
        res.r=right_half.pref_r;
    }

    return res;
}

void find_max(int n, int& left, int& right){
    Result res=calc_res(1, n);
    left=res.l;
    right=res.r;
}