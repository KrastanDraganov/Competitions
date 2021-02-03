#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MOD=1e9+7;
const long long MOD2=1ll*MOD*MOD;

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

    Matrix(int _rows, int _cols){
        rows=_rows;
        cols=_cols;
        values.resize(rows, vector<int>(cols, 0));
    }

    Matrix(vector<vector<int>> _values){
        values=_values;
        rows=(int)values.size();
        cols=(rows==0 ? 0 : (int)values[0].size());
    }

    Matrix operator*(const Matrix& mul){
        Matrix res(rows, mul.cols);

        for(int i=0;i<res.rows;++i){
            for(int j=0;j<res.cols;++j){
                long long curr=0;
                for(int k=0;k<cols;++k){
                    add_mod2(curr, 1ll*values[i][k]*mul.values[k][j]);
                }
                res.values[i][j]=curr%MOD;
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

Matrix fast_pow(Matrix matrix, int degree){
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Matrix compatible(26, 26);
    for(int i=0;i<26;++i){
        for(int j=0;j<26;++j){
            cin>>compatible.values[i][j];
        }
    }

    int tests;
    cin>>tests;

    while(tests--){
        char c;
        int len;
        cin>>c>>len;

        int target=c-'a';

        Matrix dp(1, 26);
        for(int i=0;i<dp.cols;++i){
            dp.values[0][i]=1;
        }
        dp=dp*fast_pow(compatible, len-1);
        
        cout<<dp.values[0][target]<<endl;
    }
return 0;
}