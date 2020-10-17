#include<vector>

#include "cards.h"

using namespace std;

void swapCards(int cards[], int s, int t){
    int total_swaps=0;
    for(int i=0;i<52 and total_swaps<s;++i){
        if(cards[i]!=-1){
            int pos=i;
            vector<int> cycle;
            
            while(cards[pos]!=-1){
                cycle.push_back(pos);
                int curr=pos;
                pos=cards[pos];
                cards[curr]=-1;
            }

            int n=(int) cycle.size();
            if(t<n){
                doSwap(cycle[n/2], i);
                ++total_swaps;
            }
        }
    }
}

void guessCard(int s, int t, int target){
    while(true){
        int i=guess(target);
        target=i;
    }
}