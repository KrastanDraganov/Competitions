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

    vector<int64_t> pascal(n + 1, 1);

    for (int i = 1; i < n; ++i)
    {
        vector<int64_t> new_pascal(n + 1, 1);

        for (int j = 1; j <= i; ++j)
        {
            new_pascal[j] = pascal[j - 1] + pascal[j];
        }

        pascal = new_pascal;
    }

    for (int i = 0; i < n + 1; ++i)
    {
        cout << pascal[i] << " ";
    }
    cout << endl;

    return 0;
}