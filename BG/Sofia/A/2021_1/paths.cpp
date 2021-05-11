// Not solved - wrong answer, 0 points

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

struct Matrix {
    int limit;
    int rows, cols;
    vector<vector<int>> values;

    Matrix(int _rows, int _cols, int _limit) {
        limit = _limit;
        rows = _rows;
        cols = _cols;
        values.resize(rows, vector<int>(cols, 0));
    }

    Matrix(vector<vector<int>> _values, int _limit) {
        values = _values;
        rows = (int) values.size();
        cols = (rows == 0 ? 0 : (int) values[0].size());
        limit = _limit;
    }

    Matrix operator*(const Matrix& mul) {
        Matrix res(rows, mul.cols, limit);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < mul.cols; ++j) {
                int64_t curr = 0;
                for (int k = 0; k < cols; ++k) {
                    curr += 1ll * values[i][k] * mul.values[k][j];

                    if (curr > limit) {
                        curr = limit + 1;
                        break;
                    }
                }

                res.values[i][j] = curr;
            }
        }

        return res;
    }
};

Matrix identity_matrix(int n, int limit) {
    Matrix res(n, n, limit);
    for (int i = 0; i < n; ++i) {
        res.values[i][i] = 1;
    }

    return res;
}

Matrix fast_pow(Matrix matrix, int degree) {
    Matrix res = identity_matrix(matrix.rows, matrix.limit);

    while (degree > 0) {
        if (degree & 1) {
            res = res * matrix;
            --degree;
        } else {
            matrix = matrix * matrix;
            degree /= 2;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    Matrix graph(n + 1, n + 1, k);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        graph.values[from][to] = 1;
    }

    ++graph.values[n - 1][n];
    ++graph.values[n][n];

    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;

        Matrix curr = fast_pow(graph, mid);
        if (curr.values[0][n - 1] + curr.values[0][n] >= k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << r + 1 << endl;
return 0;
}