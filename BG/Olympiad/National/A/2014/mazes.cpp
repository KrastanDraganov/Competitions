#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MOD=1234567;
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

Matrix fast_pow(Matrix& matrix, long long degree){
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin>>n>>m;
    n-=2;
    
    int k=(1<<n);
    Matrix compatible(k, k);
    for(int profile1=0;profile1<k;++profile1){
        for(int coloring=0;coloring<k;++coloring){
            int profile2=(profile1 & coloring);
            
            for(int i=1;i<n;++i){
                if(is_set(i, coloring) and !is_set(i, profile2) and is_set(i-1, profile2)){
                    profile2 |= (1<<i);
                }
            }
            for(int i=n-2;i>=0;--i){
                if(is_set(i, coloring) and !is_set(i, profile2) and is_set(i+1, profile2)){
                    profile2 |= (1<<i);
                }
            }
            
            ++compatible.values[profile1][profile2];
        }
    }

    Matrix dp=fast_pow(compatible, m-1);
    
    int res=0;
    for(int i=1;i<dp.rows;++i){
        for(int i2=1;i2<dp.cols;++i2){
            add_mod(res, dp.values[i][i2]);
        }
    }

    cout<<res<<endl;
return 0;
}