#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int width = (n + 4) / 2;

    for (int i = 0; i < width; ++i)
    {
        cout << "_";
    }
    cout << "^";
    for (int i = 0; i < width; ++i)
    {
        cout << "_";
    }
    cout << endl;

    for (int i = 0; i < width - 1; ++i)
    {
        cout << "_";
    }
    cout << "/|\\";
    for (int i = 0; i < width - 1; ++i)
    {
        cout << "_";
    }
    cout << endl;

    for (int dots = 0; dots <= (n / 2); ++dots)
    {
        for (int i = 0; i < width - 2 - dots; ++i)
        {
            cout << "_";
        }
        
        cout << "/";
        for (int i = 0; i < dots; ++i)
        {
            cout << ".";
        }
        cout << "|||";
        for (int i = 0; i < dots; ++i)
        {
            cout << ".";
        }
        cout << "\\";

        for (int i = 0; i < width - 2 - dots; ++i)
        {
            cout << "_";
        }

        cout << endl;
    }

    cout << "_/";
    for (int i = 0; i < (n / 2) - 1; ++i)
    {
        cout << ".";
    }
    cout << "|||";
    for (int i = 0; i < (n / 2) - 1; ++i)
    {
        cout << ".";
    }
    cout << "\\_" << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < width - 1; ++j)
        {
            cout << "_";
        }
        cout << "|||";
        for (int j = 0; j < width - 1; ++j)
        {
            cout << "_";
        }
        cout << endl;
    }

    for (int i = 0; i < width - 1; ++i)
    {
        cout << "_";
    }
    cout << "~~~";
    for (int i = 0; i < width - 1; ++i)
    {
        cout << "_";
    }
    cout << endl;

    for (int dots = 0; dots < (n / 2); ++dots)
    {
        for (int i = 0; i < width - 2 - dots; ++i)
        {
            cout << "_";
        }

        cout << "//";
        for (int i = 0; i < dots; ++i)
        {
            cout << ".";
        }
        cout << "!";
        for (int i = 0; i < dots; ++i)
        {
            cout << ".";
        }
        cout << "\\\\";


        for (int i = 0; i < width - 2 - dots; ++i)
        {
            cout << "_";
        }

        cout << endl;
    }

    return 0;
}