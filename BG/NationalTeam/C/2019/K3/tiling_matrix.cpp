// Not solved - 92 points, time limit

#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MOD=1e9+7;
const long long MOD2=(long long)MOD*MOD;

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

void add_mod2(long long& x, long long y){
    x+=y;
    if(x>=MOD2){
        x-=MOD2;
    }
}

struct Matrix {
    int rows,cols;
    vector<vector<int>> values;

    Matrix(){
        rows=cols=0;
    }

    Matrix(vector<vector<int>> _values){
        values=_values;
        rows=(int)values.size();
        cols=(rows==0 ? 0 : (int)values[0].size());
    }

    Matrix(int _rows, int _cols){
        rows=_rows;
        cols=_cols;
        values.resize(rows, vector<int>(cols, 0));
    }

    Matrix operator*(const Matrix& mul) const {
        Matrix res(rows, mul.cols);
        
        for(int i=0;i<rows;++i){
            for(int i2=0;i2<mul.cols;++i2){
                long long curr=0;
                for(int i3=0;i3<cols;++i3){
                    add_mod2(curr, 1ll*values[i][i3]*mul.values[i3][i2]);
                }
                res.values[i][i2]=curr%MOD;
            }
        }
        
        return res;
    }
};

Matrix identity_matrix(int n){
    Matrix res(n, n);
    for(int i=0;i<n;++i){
        res.values[i][i]=1;
    }
    return res;
}

Matrix fast_pow(Matrix& matrix, int degree){
    Matrix res=identity_matrix(matrix.rows);
    while(degree>0){
        if(degree & 1){
            res=res*matrix;
            --degree;
        }else{
            matrix=matrix*matrix;
            degree/=2;
        }
    }
    return res;
}

bool is_set(int pos, int mask){
    return (1<<pos) & mask;
}

// Profile values: 0 - empty cell, will be filled with horizontal domino
// 1 - occupied cell with either vertical or horizontal domino
bool is_compatible(int profile1, int profile2, int n){
    int counter=0;
    
    for(int i=0;i<n;++i){
        if(is_set(i, profile1) and is_set(i, profile2)){
            ++counter;
            continue;
        }

        if(counter & 1){
            return false;
        }
        if(!is_set(i, profile1) and !is_set(i, profile2)){
            return false;
        }

        counter=0;
    }
    
    return counter%2==0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    if(n>m){
        swap(n, m);
    }

    int limit=(1<<n);
    Matrix compatible(limit, limit);
    for(int profile1=0;profile1<limit;++profile1){
        for(int profile2=0;profile2<limit;++profile2){
            compatible.values[profile1][profile2]=is_compatible(profile1, profile2, n);
        }
    }

    Matrix dp=fast_pow(compatible, m-1);
    
    int res=0;
    for(int i=0;i<dp.rows;++i){
        if(is_compatible(i, limit-1, n)){
            add_mod(res, dp.values[i][limit-1]);
        }
    }

    cout<<res<<endl;
return 0;
}