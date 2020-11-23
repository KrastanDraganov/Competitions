#include<iostream>
#include<vector>

#include "biggest.h"

using namespace std;

vector<int> bubble_sort(int n, int k){
    vector<int> nums;
    for(int i=1;i<=n;++i){
        nums.push_back(i);
    }

    vector<int> res;
    for(int target=n-1;target>=n-k;--target){
        for(int i=1;i<=target;++i){
            if(compare(nums[i-1], nums[i])==nums[i-1]){
                swap(nums[i-1], nums[i]);
            }
        }

        res.push_back(nums[target]);
    }

    return res;
}

vector<int> merge_sort(int l, int r, vector<int>& nums){
    if(l==r){
        return {nums[l]};
    }

    int mid=(l+r)/2;
    vector<int> left_half=merge_sort(l, mid, nums);
    vector<int> right_half=merge_sort(mid+1, r, nums);

    int i=0,i2=0;
    int n=(int)left_half.size(),m=(int)right_half.size();

    vector<int> res;
    while(i<n and i2<m){
        if(compare(left_half[i], right_half[i2])==right_half[i2]){
            res.push_back(left_half[i++]);
        }else{
            res.push_back(right_half[i2++]);
        }
    }

    while(i<n){
        res.push_back(left_half[i++]);
    }
    while(i2<m){
        res.push_back(right_half[i2++]);
    }

    return res;
}

vector<int> biggest(int n, int k){
    if(k<=100){
        return bubble_sort(n, k);
    }

    vector<int> nums;
    for(int i=1;i<=n;++i){
        nums.push_back(i);
    }

    nums=merge_sort(0, n-1, nums);

    vector<int> res;
    for(int i=0;i<k;++i){
        res.push_back(nums[n-i-1]);
    }

    return res;
}
