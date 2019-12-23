#include<iostream>
#include<cstring>
#include<unordered_map>
#define endl '\n'
using namespace std;
int days_in_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
unordered_map<string,int> code_type;
unordered_map<int,string> decode_type;
bool is_leap(int year){
    return (year%100==0 ? year%400==0 : year%4==0);
}
void init_type(){
    code_type["Monday"]=1;
    code_type["Tuesday"]=2;
    code_type["Wednesday"]=3;
    code_type["Thursday"]=4;
    code_type["Friday"]=5;
    code_type["Saturday"]=6;
    code_type["Sunday"]=7;
    decode_type[1]="Monday";
    decode_type[2]="Tuesday";
    decode_type[3]="Wednesday";
    decode_type[4]="Thursday";
    decode_type[5]="Friday";
    decode_type[6]="Saturday";
    decode_type[7]="Sunday";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int year;
    string type,day;
    cin>>year>>type>>day;
    if(is_leap(year)){
        ++days_in_month[1];
    }
    int all_pages=1,num=code_type[type];
    bool is_weekend=false;
    for(int i=0;i<12;++i){
        for(int i2=1;i2<=days_in_month[i];++i2){
            if(!is_weekend){
                ++all_pages;
            }
            if(num==7){
                num=1;
                is_weekend=false;
            }else{
                if(num==6){
                    is_weekend=true;
                }
                ++num;
            }
        }
    }
    int date,month;
    if(day=="Flip"){
        date=69;
        month=69;
    }else{
        date=10*(day[0]-'0')+(day[1]-'0');
        month=10*(day[3]-'0')+(day[4]-'0');
    }
    if(date==1 and month==1 and all_pages%2==1){
        cout<<"Face: 01.01 "<<type<<endl;
        return 0;
    }
    num=code_type[type];
    is_weekend=(num==7);
    int counter=0,strike=-1;
    for(int i=0;i<12;++i){
        for(int i2=1;i2<=days_in_month[i];++i2){
            if(!is_weekend){
                ++counter;
            }
            if(date==69 and counter==((all_pages/2)+1)){
                cout<<"Face: Flip"<<endl;
                strike=counter+1;
            }else if(strike==counter or date==i2 and month==(i+1)){
                
            }
            is_weekend=(num==6);
            if(num==7){
                num=1;
            }else{
                ++num;
            }
        }
    }
    cout<<all_pages<<endl;
return 0;
}