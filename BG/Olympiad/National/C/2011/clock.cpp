#include<iostream>
#include<iomanip>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int hours,mins;
    char c;
    cin>>hours>>c>>mins;
    
    double large=(double)mins/60.0;
    double small=(double)(60*hours+mins)/720.0;
    cout<<fixed<<setprecision(3)<<min(abs(large-small),1.0-abs(large-small))*360.0<<endl;
return 0;
}