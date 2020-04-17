#include<iostream>

#define endl '\n'

using namespace std;

long long is_prime(int num){
    if(num==2){
        return true;
    }else if(num%2==0){
        return false;
    }
    for(long long i=3;i*i<=num;i+=2){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

long long calc_next(int num){
    do{
        ++num;
    }while(!is_prime(num));
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    long long num=2,curr_prime=2,next_prime=3;
    for(int i=1;i<n;++i){
        if(num%next_prime==0){
            curr_prime=next_prime;
            next_prime=calc_next(curr_prime);
        }
        num+=curr_prime;
    }
    cout<<num<<endl;
return 0;
}