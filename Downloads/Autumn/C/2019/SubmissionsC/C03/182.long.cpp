#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 10001;
string s[MAXN];
int br[32];
bool used[32];
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    if(k==1)
    {
        for(int i=0; i<n; i++)
        {
            memset(used, 0, sizeof(used));
            cin >> s[i];
            int len = s[i].size();
            for(int j=0; j<len; j++)
            {
                int k = (int)(s[i][j]-'a'+1);
                if(!used[k])
                {
                    used[k] = true;
                    br[k]++;
                }
            }
        }
        int max1 = -1, cnt = 0;
        char c;
        for(int i=1; i<=m; i++)
        {
            if(br[i] > max1)
            {
                max1 = br[k];
                c = (char)(k+'a'-1);
                cnt = 1;
            }
            else if(br[i] == max1)
            {
                cnt++;
            }
        }
        cout << max1 << endl;
        cout << c << endl;
        cout << cnt << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}
