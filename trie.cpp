#include<iostream>
#include<vector>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAX_WORDS=2003,MAXN=103;
string dictionary[MAX_WORDS],input;
int dp[MAXN],parent[MAXN];

struct Node {
    int word;
    Node* children[26];
    Node(){
        word=-1;
        for(int i=0;i<26;++i){
            children[i]=nullptr;
        }
    }
};

void add_word(int word, int ind, Node* curr){
    if(ind==dictionary[word].size()){
        curr->word=word;
        return;
    }
    int diff=dictionary[word][ind]-'a';
    if(curr->children[diff]==nullptr){
        curr->children[diff]=new Node;
    }
    add_word(word,ind+1,curr->children[diff]);
}

void search_word(int start_ind, int ind, Node* curr){
    if(curr->word!=-1){
        int end_ind=start_ind+dictionary[curr->word].size()-1;
        //cout<<end_ind<<" "<<dp[end_ind]<<" "<<dp[end_ind+1]<<endl;
        if(end_ind==input.size()-1){
            if(dp[start_ind]>1){
                dp[start_ind]=1;
                parent[start_ind]=input.size();
            }
        }else if(dp[end_ind+1]>-1){
            if(dp[end_ind+1]+1<dp[start_ind]){
                dp[start_ind]=dp[end_ind+1]+1;
                parent[start_ind]=end_ind+1;
            }
        }
    }
    if(ind==input.size()){
        return;
    }
    int diff=input[ind]-'a';
    if(curr->children[diff]!=nullptr){
        search_word(start_ind,ind+1,curr->children[diff]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>input>>n;
    Node* trie=new Node;
    for(int i=0;i<n;++i){
        cin>>dictionary[i];
        add_word(i,0,trie);
    }
    for(int i=0;i<MAXN;++i){
        dp[i]=1e8;
    }
    for(int i=input.size()-1;i>=0;--i){
        search_word(i,i,trie);
    }
    cout<<dp[0]<<endl;
    int pos=0;
    while(pos<input.size()){
        for(int i=pos;i<parent[pos];++i){
            cout<<input[i];
        }
        cout<<" ";
        pos=parent[pos];
    }
    cout<<endl;
return 0;
}