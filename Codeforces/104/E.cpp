#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

struct tree_data {
    int counter4,counter7,length1,length2;
    tree_data(){
        counter4=0;
        counter7=0;
        length1=1;
        length2=1;
    }
};

const int MAXN=1e6+3;
tree_data tree[4*MAXN];
bool lazy[4*MAXN];
char digits[MAXN];

tree_data combine(tree_data child1, tree_data child2){
    tree_data res;
    res.counter4=child1.counter4+child2.counter4;
    res.counter7=child1.counter7+child2.counter7;
    res.length1=max(child1.counter4+child2.counter7,
                max(child1.counter4+child2.length1,child1.length1+child2.counter7));
    res.length2=max(child1.counter7+child2.counter4,
                max(child1.counter7+child2.length2,child1.length2+child2.counter4));
    return res;
}

void build_tree(int ind, int tl, int tr){
    if(tl==tr){
        if(digits[tl]=='4'){
            ++tree[ind].counter4;
        }else{
            ++tree[ind].counter7;
        }
    }else{
        int mid=(tl+tr)/2;
        build_tree(2*ind,tl,mid);
        build_tree(2*ind+1,mid+1,tr);
        tree[ind]=combine(tree[2*ind],tree[2*ind+1]);
    }
}

void swap_digits(int ind){
    swap(tree[ind].counter4,tree[ind].counter7);
    swap(tree[ind].length1,tree[ind].length2);
}

void push(int ind){
    swap_digits(2*ind);
    lazy[2*ind]=!lazy[2*ind];
    swap_digits(2*ind+1);
    lazy[2*ind+1]=!lazy[2*ind+1];
    lazy[ind]=false;
}

void update_range(int ind, int tl, int tr, int l, int r){
    if(l>tr or r<tl or l>r){
        return;
    }
    if(l==tl and r==tr){
        swap_digits(ind);
        lazy[ind]=!lazy[ind];
    }else{
        if(lazy[ind] and tl!=tr){
            push(ind);
        }else{
            lazy[ind]=false;
        }
        int mid=(tl+tr)/2;
        update_range(2*ind,tl,mid,l,min(mid,r));
        update_range(2*ind+1,mid+1,tr,max(mid+1,l),r);
        tree[ind]=combine(tree[2*ind],tree[2*ind+1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m>>digits;
    
    build_tree(1,0,n-1);
    while(m--){
        string type;
        cin>>type;
        if(type=="count"){
            cout<<tree[1].length1<<endl;
        }else{
            int l,r;
            cin>>l>>r;
            --l;
            --r;
            update_range(1,0,n-1,l,r);
        }
    }
return 0;
}
