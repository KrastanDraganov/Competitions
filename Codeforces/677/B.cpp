#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int n;
        cin>>n;

        int res=0,prev_book=-1;
        for(int i=0;i<n;++i){
            bool curr_book;
            cin>>curr_book;
            
            if(!curr_book){
                continue;
            }

            if(prev_book!=-1){
                res+=(i-prev_book-1);
            }
            prev_book=i;
        }

        cout<<res<<endl;
    }
return 0;
}