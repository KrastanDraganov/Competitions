//Task: sync
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;

const unsigned MAXN = 33, MAXK = 66;

int main() {
    // prevaritelno iz4islqwane C[n][k]
    
    long long C[MAXN + 1][MAXK + 1];
    
    C[0][0] = 1;
    for (unsigned j = 1; j <= MAXK; j++) 
        C[0][j] = 0;
    
    for (unsigned i = 1; i <= MAXN; i++) {
        C[i][0] = 1;
        for (unsigned j = 1; j <= MAXK; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    
    unsigned n, a, b;
    cin >> n >> a >> b;
    
   long long ans = 0;
      
    for (unsigned x = 3; x <= min(n - 2, a); x++)
        ans += C[a][x] * C[b][n - x];
    
    cout << ans << endl;
    return 0;
}

