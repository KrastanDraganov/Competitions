/*
#include<bits/stdc++.h>
using namespace std;
string s[10001],ss,sss;
int n,m,k,mins,ans,maxbr,ans3;
string ans2;
string nexter(string x,string y){
for(int i=0;i<max(x.size(),y.size());i++){
    if(i<min(x.size(),y.size())){
        if(x[i]>y[i])return y;
        else if(x[i]<y[i])return x;
    }else{
        if(x.size()<y.size())return x;
        else return y;
    }
}
return x;
}
bool li[10001];
int broi(string x){
int pos=0,kk=maxbr;
for(int i=0;i<n;i++){
    if(!li[i]){
        pos=0;
        for(int f=0;f<s[i].size();f++){
            if(s[i][f]==x[pos])pos++;
        }
        if(pos!=x.size())kk--;
        if(kk<ans)return 0;
    }
}
return kk;
}
void perm(string ss,int k,int last){
if(k==0){
    if(broi(sss)==ans){
        if(ans==3){
        }
        ans2=nexter(ans2,sss);
        ans3++;
    }else  if(broi(sss)>ans){
        ans2=sss;
        ans3=1;
        ans=broi(sss);
    }
}else{
    for(int i=last;i<ss.size();i++){
        sss.push_back(ss[i]);
        perm(ss,k-1,i+1);
        sss.pop_back();
    }
}
}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m>>k;
for(int i=0;i<n;i++){
    cin>>s[i];
}
mins=1000000;
maxbr=n;
for(int i=0;i<n;i++){
    if(s[i].size()<k){
        li[i]=true;
        maxbr--;
    }else{
        if(s[i].size()<mins){
            mins=s[i].size();
            ss=s[i];
        }
    }
}
for(int i=0;i<n;i++){
    if(!li[i]){
       perm(s[i],k,0);
    }
    maxbr--;
    li[i]=true;
}
cout<<ans<<endl;
cout<<ans2<<endl;
cout<<ans3<<endl;
return 0;
}
5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
string s[10001];
int br[26][10001];
char ans2;
int ans3;
int main(){
cin>>n>>m>>k;
if(k==1){
for(int i=0;i<n;i++){
    cin>>s[i];
    for(int f=0;f<s[i].size();f++){
        br[s[i][f]-'a'][i]++;
    }
}
int br2,br3;
for(int i=0;i<26;i++){
        br2=0;br3=0;
    for(int f=0;f<n;f++){
        if(br[i][f]>0)br3++;
    }
    if(br3>ans){
        ans=br3;
        ans2=i+'a';
        ans3=1;
    }else if(br3==ans){
        ans3++;
    }
}
cout<<ans<<endl<<ans2<<endl<<ans3<<endl;
}else if(k==2){
string ans22;
for(int i=0;i<n;i++){
    cin>>s[i];
}
for(int i=0;i<26;i++){
    for(int f=0;f<26;f++){
       int k=i+'a';
       bool li=false;
       int br2=0;
       for(int p=0;p<n;p++){
           for(int pp=0;pp<s[p].size();pp++){
              if(s[p][pp]==k){
                 if(k==i+'a' and !li){li=true;k=f+'a';}
                 else if(li)
                 {br2++;
                 break;
                 }
              }
           }
       }
       if(br2>ans){
          ans=br2;
          ans22="";
          ans22.push_back(i+'a');
          ans22.push_back(f+'a');
          ans3=1;
       }else if(br2==ans){
          ans3++;
       }
    }
}
cout<<ans<<endl<<ans22<<endl<<ans3<<endl;
}else if(k==3){
string ans222;
for(int i=0;i<n;i++){
    cin>>s[i];
}
for(int i=0;i<26;i++){
    for(int f=0;f<26;f++){
       for(int ii=0;ii<26;ii++){
       char k=i+'a';
       bool li=false,li2=false;
       int br2=0;
       for(int p=0;p<n;p++){
           for(int pp=0;pp<s[p].size();pp++){
              if(s[p][pp]==k){
                 if(k==i+'a' and !li){li=true;k=f+'a';}
                 else if(k==f+'a' and !li2 and li){li2=true;k=ii+'a';}
                 else if(li2)
                 {br2++;
                 break;
                 }
              }
           }
       }
       if(br2>ans){
          ans=br2;
          ans222="";
          ans222.push_back(i+'a');
          ans222.push_back(f+'a');
          ans222.push_back(ii+'a');
          ans3=1;
       }else if(br2==ans){
          ans3++;
       }
       }
    }
}
cout<<ans<<endl<<ans222<<endl<<ans3<<endl;
}else{
cout<<1/0;
}
return 0;
}
