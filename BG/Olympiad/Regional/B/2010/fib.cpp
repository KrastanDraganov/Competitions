#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MOD=100;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    Matrix compatible({{0, 1},
                       {1, 1}});
    compatible=fast_pow(compatible, n);

    Matrix res({{0, 1}});
    res=res*compatible;

    if(res.values[0][0]<10){
        cout<<0;
    }
    cout<<res.values[0][0]<<endl;
return 0;
}