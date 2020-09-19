#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

struct Movie {
    int from,to;

    Movie(){
        from=to=-1;
    }

    Movie(int _from, int _to){
        from=_from;
        to=_to;
    }

    bool operator<(const Movie comp) const {
        if(to==comp.to){
            return from<comp.from;
        }
        return to<comp.to;
    }
};

const int MAXN=2e5+3;
Movie movies[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        int from,to;
        cin>>from>>to;
        movies[i]=Movie(from,to);
    }
    sort(movies,movies+n);

    int res=0,last_movie=-1;
    for(int i=0;i<n;++i){
        if(movies[i].from>=last_movie){
            ++res;
            last_movie=movies[i].to;
        }
    }

    cout<<res<<endl;
return 0;
}