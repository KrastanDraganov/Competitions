#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

#define endl '\n'

using namespace std;

string mult(string s, int num){
    string ans="";
    int add=0;
    
    for(int i=s.size()-1;i>=0;--i){
        int curr=(s[i]-'0')*num+add;
        ans+=(curr%10)+'0';
        add=curr/10;
    }
    
    if(add>0){
        string s_add=to_string(add);
        reverse(s_add.begin(),s_add.end());
        ans+=s_add;
    }
    reverse(ans.begin(),ans.end());
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    cin>>n>>k;
    
    vector<int> nums1,nums2;
    for(int i=n;i>(n-k);--i){
        nums1.push_back(i);
        nums2.push_back(i+k-n);
    }
    
    for(int i=0;i<nums1.size();++i){
        for(int i2=0;i2<nums2.size();++i2){
            int gd=__gcd(nums1[i],nums2[i2]);
            nums1[i]/=gd;
            nums2[i2]/=gd;
        }
    }
    
    string res="1";
    for(int i=0;i<nums1.size();++i){
        res=mult(res,nums1[i]);
    }
    
    int counter=0;
    for(int i=0;i<res.size();++i){
        if(res[i]=='0'){
            ++counter;
        }
    }
    cout<<counter<<endl;
return 0;
}