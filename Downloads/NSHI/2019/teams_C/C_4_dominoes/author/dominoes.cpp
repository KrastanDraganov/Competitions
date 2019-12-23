//Task: dominoes
//Author: Kinka Kirilova-Lupanova
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector> 
#include<map>

using namespace std;

typedef pair<int, int> pi;

int n;
bool cmp(pi a, pi b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int main()
{
    scanf("%d", &n);
    vector<pi> a(n);
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d%d", &a[i].first, &a[i].second);        
    }
    sort(a.begin(), a.end(), cmp);
    map<int, int> ans;
    int answer = 0;
    for (int i = 0; i < n; ++i) 
    {
        ans[a[i].second] = max(ans[a[i].second], ans[a[i].first] + 1);
        answer = max(answer, ans[a[i].second]);
    }
    printf("%d", answer);
    cout<<endl;
    return 0;
}




