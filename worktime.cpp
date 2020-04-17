#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAX_HOURS=24,MAX_MINS=60;
int counter[MAX_HOURS+3][MAX_MINS+3][MAX_MINS+3];

void digits(int num, int& mask){
    if(num<10){
        if(!(mask & 1)){
            mask |= 1;
        }
    }
    while(num>0){
        int digit=num%10;
        if(!(mask & (1<<digit))){
            mask |= (1<<digit);
        }
        num/=10;
    }
}

bool is_lucky(int hours, int mins, int secs){
    int mask=0;
    digits(hours,mask);
    digits(mins,mask);
    digits(secs,mask);
    bool check=true;
    for(int i=0;i<10;++i){
        bool curr=(mask & (1<<i));
        if((i<6 and !curr) or (i>5 and curr)){
            check=false;
            break;
        }
    }
    return check;
}

int prev_time(int hours, int mins, int secs){
    if(hours==0 and mins==0 and secs==0){
        return 0;
    }
    if(secs==0){
        secs=59;
        if(mins==0){
            mins=59;
            --hours;
        }else{
            --mins;
        }
    }else{
        --secs;
    }
    return counter[hours][mins][secs];
}

int res(string curr_time, bool is_start){
    int curr[3]={0,0,0},ind=0;
    for(char sign : curr_time){
        if(sign==':'){
            ++ind;
        }else{
            curr[ind]=10*curr[ind]+sign-'0';
        }
    }
    return (is_start ? prev_time(curr[0],curr[1],curr[2]) : counter[curr[0]][curr[1]][curr[2]]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int hours=0;hours<24;++hours){
        for(int mins=0;mins<60;++mins){
            for(int secs=0;secs<60;++secs){
                counter[hours][mins][secs]=prev_time(hours,mins,secs)+is_lucky(hours,mins,secs);
            }
        }
    }


    int n,m;
    cin>>n>>m;
    int best_worker=-1,max_nums=-1;
    for(int i=0;i<n;++i){
        int curr=0;
        for(int i2=0;i2<m;++i2){
            string start_time,end_time;
            cin>>start_time>>end_time;
            curr+=res(end_time,false)-res(start_time,true);
        }
        if(curr>max_nums){
            max_nums=curr;
            best_worker=i+1;
        }
    }
    cout<<best_worker<<" "<<max_nums<<endl;
return 0;
}