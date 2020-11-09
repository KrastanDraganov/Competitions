#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

struct Request {
    int l,r,colors;
    
    Request(int _l=-1, int _r=-1, int _colors=0){
        l=_l;
        r=_r;
        colors=_colors;
    }

    bool operator<(const Request& comp){
        if(l==comp.l){
            if(r==comp.r){
                return colors<comp.colors;
            }
            return r<comp.r;
        }
        return l<comp.l;
    }
};

char opposite_color(char color){
    return color=='Y' ? 'G' : 'Y';
}

void add_new_request(int l, int r, vector<Request>& requests, vector<Request>& combined){
    if(l==-1){
        l=r=0;
    }
    Request new_request(l, r, 1);
    combined.push_back(new_request);
    requests.push_back(new_request);
}

string find_arrangement(int n, vector<Request>& requests, vector<Request>& one_color){
    sort(one_color.begin(), one_color.end());

    // Combine one color intervals
    int new_l=-1,new_r=-1;
    vector<Request> combined;

    for(Request curr : one_color){
        if(curr.l<=new_r){
            new_r=max(new_r, curr.r);
            continue;
        }
        add_new_request(new_l, new_r, requests, combined);
        new_l=curr.l;
        new_r=curr.r;
    }
    add_new_request(new_l, new_r, requests, combined);
    
    one_color=combined;

    // Check if interval with two colors is in interval with one color
    sort(requests.begin(), requests.end());
    int prev_l=-1,prev_r=-1;
    
    for(Request curr : requests){
        if(curr.colors==1){
            prev_l=curr.l;
            prev_r=curr.r;
            continue;
        }
        if(curr.l==curr.r or (prev_l<=curr.l and curr.r<=prev_r)){
            return "";
        }
    }

    string res="Y";
    for(int i=1;i<(int)one_color.size();++i){
        for(int i2=one_color[i-1].r+1;i2<=one_color[i].l;++i2){
            res+=opposite_color(res.back());
        }
        for(int i2=one_color[i].l+1;i2<=one_color[i].r;++i2){
            res+=res.back();
        }
    }

    for(int i=one_color.back().r+1;i<n;++i){
        res+=opposite_color(res.back());
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    vector<Request> requests,one_color;
    for(int i=0;i<q;++i){
        int from,to,colors;
        cin>>from>>to>>colors;
        Request curr(from, to, colors);
        if(colors==1){
            one_color.push_back(curr);
        }else{
            requests.push_back(curr);
        }
    }

    string res=find_arrangement(n, requests, one_color);
    if(res.empty()){
        cout<<"0\n";
    }else{
        cout<<"1\n"<<res<<endl;
    }
return 0;
}