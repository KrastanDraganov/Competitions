#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define endl '\n'

using namespace std;

int calc_wins(vector<int>& a, vector<int>& b){
    return min(a[0], b[1])+min(a[1], b[2])+min(a[2], b[0]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    // rock, scissors, paper
    vector<int> a(3),b(3);
    for(int i=0;i<3;++i){
        cin>>a[i];
    }
    for(int i=0;i<3;++i){
        cin>>b[i];
    }

    vector<pair<int, int>> no_win_turns({{0, 0}, {0, 2}, {1, 0}, {1, 1}, {2, 1}, {2, 2}});
    sort(no_win_turns.begin(), no_win_turns.end());

    int max_wins=calc_wins(a, b);
    int min_wins=1e9;
    do{
        vector<int> curr_a=a,curr_b=b;
        for(pair<int, int> pos : no_win_turns){
            int rounds=min(curr_a[pos.first], curr_b[pos.second]);
            curr_a[pos.first]-=rounds;
            curr_b[pos.second]-=rounds;
        }
        min_wins=min(min_wins, calc_wins(curr_a, curr_b));
    } while(next_permutation(no_win_turns.begin(), no_win_turns.end()));

    cout<<min_wins<<" "<<max_wins<<endl;
return 0;
}