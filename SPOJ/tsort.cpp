#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int heap[MAXN],len,res[MAXN];

void build_heap(){
    for(int i=2;i<=len;++i){
        for(int pos=i;pos>1 and heap[pos]>heap[pos/2];pos/=2){
            swap(heap[pos],heap[pos/2]);
        }    
    }
}

void remove_max(){
    swap(heap[1],heap[len--]);
    int pos=1;
    while(2*pos<=len){
        int ind=pos,max_val=heap[pos];
        if(heap[2*pos]>max_val){
            ind=2*pos;
            max_val=heap[2*pos];
        }
        if(2*pos+1<=len and heap[2*pos+1]>max_val){
            ind=2*pos+1;
            max_val=heap[2*pos+1];
        }
        if(ind==pos){
            break;
        }
        swap(heap[ind],heap[pos]);
        pos=ind;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    len=n;
    for(int i=1;i<=n;++i){
        cin>>heap[i];
    }

    build_heap();
    for(int i=0;i<n;++i){
        res[n-i-1]=heap[1];
        remove_max();
    }

    for(int i=0;i<n;++i){
        cout<<res[i]<<endl;
    }
return 0;
}