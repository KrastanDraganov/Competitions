#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    int top_left = 0, down_right = n - 1;
    while (top_left <= down_right) {
        
        swap(matrix[top_left][top_left], matrix[top_left][down_right]);
        for (int i = top_left + 1; i < down_right; ++i) {
            swap(matrix[top_left][i], matrix[i][down_right]);
        }
        
        swap(matrix[top_left][top_left], matrix[down_right][down_right]);
        for (int i = top_left + 1, j = down_right - 1; i < down_right; ++i, --j) {
            swap(matrix[top_left][i], matrix[down_right][j]);
        }
        
        swap(matrix[top_left][top_left], matrix[down_right][top_left]);
        for (int i = top_left + 1, j = down_right - 1; i < down_right; ++i, --j) {
            swap(matrix[top_left][i], matrix[j][top_left]);
        }
        
        ++top_left;
        --down_right;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}