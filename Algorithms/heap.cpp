#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int heap[MAXN],length;

void heap_push(int num){
    heap[length++]=num;
    int pos=length-1;
    while(pos>1 and heap[pos]>heap[pos/2]){
        swap(heap[pos],heap[pos/2]);
        pos/=2;
    }
}

void heap_pop(){
    heap[1]=heap[length-1];
    --length;
    int pos=1;
    while(pos<length){
        int change=-1;
        if(heap[2*pos]>heap[pos]){
            change=2*pos;
        }
        if(2*pos+1<length and heap[2*pos+1]>heap[2*pos] and heap[2*pos+1]>heap[pos]){
            change=2*pos+1;
        }
        if(change==-1){
            break;
        }
        swap(heap[pos],heap[change]);
        pos=change;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int queries;
    cin>>queries;
    while(queries--){
        int type;
        cin>>type;
        if(type==1){
            int num;
            cin>>num;
            heap_push(num);
        }else if(type==2){
            cout<<heap[1]<<endl;
        }else{
            heap_pop();
        }
    }
return 0;
}