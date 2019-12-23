#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int n , q;

struct query {
    int u , v , num ;
    int ans;
    query (){}
    query ( int u , int v , int num ){
        this -> u = u;
        this -> v = v;
        this -> num = num;
    }
};

struct edge {
    int v ;
    int  w;
    edge (){}
    edge ( int v , int w ){
        this -> v = v;
        this -> w = w;
    }
};

query qu[200004];
vector<edge> v[5012];
int dist[6000];

void read (){
    int tmp;
    int x , y , z;
    scanf ( "%d%d" , &n , &q );
    for ( int i = 2; i <= n; ++i ){
        scanf ( "%d%d%d" , &x , &y , &z);
        v[x].push_back( edge ( y , z) );
        v[y].push_back( edge ( x , z ));

    }

    for ( int i = 0; i < q; ++i ) {
        scanf ( "%d%d" , &x , &y );
        if ( y < x ) swap ( x , y );
        qu[i].u = x;
        qu[i].v = y;
        qu[i].num = i;
    }
}

bool cmp1 ( query t1 , query t2 ) {
    return t1.u < t2.u;
}

void dfs ( int node ) {
    int sz = v[node].size();
    for ( int i = 0; i < sz; ++i )
        if ( !dist[ v[node][i].v ]  ) {
            dist[ v[node][i].v ] = dist[node] + v[node][i].w;
            dfs ( v[node][i].v );
        }
}

bool cmp2 ( query t1 , query t2 ) {
    return t1.num < t2.num;
}

void solve (){
    sort ( qu , qu+q , cmp1 );
    int cur = -1;
    for ( int i = 0; i < q; ++i ) {
        if ( qu[i].u == cur ) {
            qu[i].ans = dist[qu[i].v]-1;
        } else {
            memset ( dist , 0 , sizeof ( dist ));
            dist[ qu[i].u ] = 1;
            dfs ( qu[i].u );
            qu[i].ans = dist[ qu[i].v ] - 1;
            cur = qu[i].u;
        }
    }

    sort ( qu , qu+q , cmp2 );
    for ( int i = 0; i < q; ++i )
        printf ( "%d\n" , qu[i].ans );
}

int main () {
     read ();
     solve ();
     return 0;
}
