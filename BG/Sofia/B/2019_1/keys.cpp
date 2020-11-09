#include<iostream>

#define endl '\n'

using namespace std;

const int MOD=1e9+7;

struct TrieNode {
    int word_endings,passing_words;
    TrieNode* children[26];
    
    TrieNode(){
        word_endings=passing_words=0;
        for(int i=0;i<26;++i){
            children[i]=nullptr;
        }
    }
};

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int add_word(string key, TrieNode* root){
    int same_prefix=0;
    TrieNode* curr_node=root;

    for(int i=0;i<(int)key.size();++i){
        int letter=key[i]-'a';

        add_mod(curr_node->passing_words, 1);
        add_mod(same_prefix, curr_node->word_endings);
        
        if(!curr_node->children[letter]){
            curr_node->children[letter]=new TrieNode();
        }
        curr_node=curr_node->children[letter];
    }

    add_mod(same_prefix, curr_node->word_endings);
    add_mod(same_prefix, curr_node->passing_words);

    add_mod(curr_node->word_endings, 1);

    return same_prefix;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TrieNode* root=new TrieNode();
    
    string key;
    int res=0;
    while(cin>>key){
        add_mod(res, add_word(key, root));
    }

    cout<<res<<endl;
return 0;
}