#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int types[MAXN],colors[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>types[i];
        }
        types[n]=types[0];

        bool are_equal=true;
        for(int i=0;i<n;++i){
            if(types[i]!=types[i+1]){
                are_equal=false;
                break;
            }
        }
        if(are_equal){
            cout<<1<<endl;
            for(int i=0;i<n;++i){
                cout<<1<<" ";
            }
            cout<<endl;
            continue;
        }

        bool is_two=(n%2==0);
        int ind=-1;
        if(!is_two){
            for(int i=0;i<n;++i){
                if(types[i]==types[i+1]){
                    ind=i;
                    is_two=true;
                    break;
                }
            }
        }
        if(is_two){
            ++ind;
            for(int i=0;i<n;++i){
                colors[(ind+i)%n]=1+(i%2);
            }
            cout<<2<<endl;
            for(int i=0;i<n;++i){
                cout<<colors[i]<<" ";
            }
            cout<<endl;
            continue;
        }

        cout<<3<<endl;
        for(int i=0;i<n-1;++i){
            cout<<1+(i%2)<<" ";
        }
        cout<<3<<endl;
    }
return 0;
}