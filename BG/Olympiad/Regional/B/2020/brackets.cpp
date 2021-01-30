#include<iostream>
#include<string>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

// Return values - {which types of signs are in a group of brackets, index of the closing bracket}
// Mask for the types of signs:
// 00(0) - there are no signs or the brackets are not removed
// 01(1) - there is only '*' and '/'
// 10(2) - there is only '+' and '-'
// 11(3) - there are from ('*', '/') and ('+', '-')
pair<int, int> remove_brackets(int ind, int n, string& expression, vector<bool>& removed){
    int first_sign=ind-1;
    ++ind;

    int mask=0;
    while(ind<n and expression[ind]!=')'){
        if(expression[ind]=='('){
            pair<int, int> curr=remove_brackets(ind, n, expression, removed);
            mask |= curr.first;
            ind=curr.second;
            continue;
        }

        if(expression[ind]=='+' or expression[ind]=='-'){
            if(mask==1 or mask==3){
                mask=3;
            }else{
                mask=2;
            }
        }

        if(expression[ind]=='*' or expression[ind]=='/'){
            if(mask==2 or mask==3){
                mask=3;
            }else{
                mask=1;
            }
        }

        ++ind;
    }
    ++ind;

    if((expression[first_sign]=='(' and expression[ind]!='*' and expression[ind]!='/')
        or (expression[first_sign]=='+' and expression[ind]!='*' and expression[ind]!='/')
        or (expression[first_sign]=='$' and expression[ind]!='*' and expression[ind]!='/')
        or (expression[first_sign]=='-' and (mask==0 or mask==1))
        or (expression[first_sign]!='/' and (mask==0 or mask==1) and expression[ind]=='/')
        or (expression[first_sign]!='/' and (mask==0 or mask==1) and (expression[first_sign]=='*' or expression[ind]=='*')))
    {
        removed[first_sign+1]=removed[ind-1]=true; 
    }else{
        mask=0;
    }

    return {mask, ind};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string expression;
    cin>>expression;
    expression="$"+expression+"$";

    int n=(int)expression.size();
    vector<bool> removed(n, false);
    removed[0]=removed[n-1]=true;

    int ind=0;
    while(ind<n){
        if(expression[ind]!='('){
            ++ind;
            continue;
        }
        ind=remove_brackets(ind, n, expression, removed).second;
    }

    for(int i=0;i<n;++i){
        if(!removed[i]){
            cout<<expression[i];
        }
    }
    cout<<endl;
return 0;
}