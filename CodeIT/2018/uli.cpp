#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> el;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("subtasks.in", "r", stdin);
    freopen("subtasks.out", "w", stdout);
    int br;
    cin >> br;
    int d;
    for(int i = 0; i < br; ++i){
        int input;
        cin >> input;
        if(i == 0) d = input;
        else d = __gcd(d, input);
        el.push_back(input);
    }
    int sum = 0;
    for(int i = 0; i < el.size(); ++i){
        sum += el[i] / d;
    }
    cout << sum << endl;
    return 0;
}