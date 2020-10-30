#include<iostream>
#include<vector>

#include "cards.h"

using namespace std;

void swapCards(int cards[], int s, int t){
    int total_swaps=0;
    for(int i=0;i<52 and total_swaps<s;++i){
        int pos=i;
        vector<int> cycle;
        
        while(cards[pos]!=-1){
            cycle.push_back(pos);
            int curr=pos;
            pos=cards[pos];
            cards[curr]=-1;
        }

        int n=(int) cycle.size();
        for(int limit=t;limit<n and total_swaps<s;limit+=t){
            doSwap(cycle[0], cycle[limit]);
            ++total_swaps;
        }
    }
}

void guessCard(int s, int t, int target){
    while(t--){
        int i=guess(target);
        target=i;
    }
}