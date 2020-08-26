#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
string program[MAXN];

int mod(int num){
    if(num<0 and num!=-6969){
        num+=1000;
    }else if(num>=1000){
        num-=1000;
    }
    return num;
}

int change_val(int num, bool check, int reg[]){
    return (check ? reg[num] : num);
}

bool logicop(string command, int num1, int num2){
    if(command=="IFEQ"){
        return num1==num2;
    }else if(command=="IFNEQ"){
        return num1!=num2;
    }else if(command=="IFG"){
        return num1>num2;
    }else if(command=="IFL"){
        return num1<num2;
    }else if(command=="IFGE"){
        return num1>=num2;
    }else{
        return num1<=num2;
    }
}

int execute(int input, int n, int counter){
    if(counter==10001){
        return -6969;
    }
    
    int reg[11];
    reg[0]=mod(input);
    bool is_if=false;
    
    for(int i=0;i<n;++i){
        string curr="",command="";
        int spaces=0,num[2]={-1,-1};
        bool check=false;
        
        for(char pos : program[i]){
            if(pos==' ' or pos==','){
                if(spaces==0){
                    command=curr;
                }else if(curr[0]=='R'){
                    if(spaces==1){
                        num[0]=curr[1]-'0';
                        check=true;
                    }else{
                        num[1]=reg[curr[1]-'0'];
                    }
                }else{
                    num[spaces-1]=stoi(curr);
                }
                curr="";
                ++spaces;
            }else{
                curr+=pos;
            }
        }
        
        if(is_if and command=="ENDIF"){
            is_if=false;
        }else if(!is_if){
            if(command.substr(0,2)=="IF"){
                num[0]=change_val(num[0],check,reg);
                if(!logicop(command,num[0],num[1])){
                    is_if=true;
                }
            }else if(command=="MOV"){
                reg[num[0]]=num[1];
            }else if(command=="ADD"){
                reg[num[0]]+=num[1];
            }else if(command=="SUB"){
                reg[num[0]]-=num[1];
            }else if(command=="MUL"){
                reg[num[0]]*=num[1];
            }else if(command=="DIV"){
                reg[num[0]]=(num[1]!=0 ? reg[num[0]]/num[1] : 0);
            }else if(command=="MOD"){
                reg[num[0]]=(num[1]!=0 ? reg[num[0]]%num[1] : 0);
            }else if(command=="CALL"){
                num[0]=change_val(num[0],check,reg);
                reg[9]=execute(mod(num[0]),n,counter+1);
                if(reg[9]<0){
                    return -6969;
                }
            }else if(command=="RET"){
                num[0]=change_val(num[0],check,reg);
                return mod(num[0]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,l;
    cin>>n>>l;
    getline(cin,program[0]);
    for(int i=0;i<n;++i){
        getline(cin,program[i]);
        program[i]+=" ";
    }
    
    int res=execute(l,n,1);
    if(res<0){
        cout<<"*\n";
    }else{
        cout<<res<<endl;
    }
return 0;
}