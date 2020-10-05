#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'
 
using namespace std;
 
const int MAXN=2e5+3;
int salaries[MAXN],fenwick[4*MAXN];
vector<int> compressed;
 
struct Query {
    char type;
    int l,r;
 
    Query(){
        type='0';
        l=r=-1;
    }
 
    Query(char _type, int _l, int _r){
        type=_type;
        l=_l;
        r=_r;
        compressed.push_back(r);
        if(type=='?'){
            compressed.push_back(l-1);
            compressed.push_back(l);
        }
    }
} queries[MAXN];

int compress(int num){
    auto it=upper_bound(compressed.begin(), compressed.end(), num);
    return (int) (it-compressed.begin());
}

void add_val(int ind, int val){
    ind=compress(ind);
    while(ind<4*MAXN){
        fenwick[ind]+=val;
        ind += (ind & (-ind));
    }
}
 
int sum(int ind){
    int res=0;
    
    ind=compress(ind);
    while(ind>0){
        res+=fenwick[ind];
        ind -= (ind & (-ind));
    }
    
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,q;
    cin>>n>>q;
 
    for(int i=0;i<n;++i){
        cin>>salaries[i];
        compressed.push_back(salaries[i]);
    }
    for(int i=0;i<q;++i){
        char type;
        int l,r;
        cin>>type>>l>>r;
        queries[i]=Query(type,l,r);
    }
    
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    for(int i=0;i<n;++i){
        add_val(salaries[i], 1);
    }
    
    for(int i=0;i<q;++i){
        if(queries[i].type=='!'){
            int employee=queries[i].l-1;
            int new_salary=queries[i].r;
            
            add_val(salaries[employee], -1);
            add_val(new_salary, 1);
            salaries[employee]=new_salary;
        }else{
            cout<<sum(queries[i].r)-sum(queries[i].l-1)<<endl;
        }
    }
return 0;
}
