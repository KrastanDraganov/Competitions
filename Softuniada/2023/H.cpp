#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

#define endl '\n'

using namespace std;

const int MAXN = 1e3 + 3;

int proton_sequence[MAXN][MAXN];
int electron_to_proton[MAXN][MAXN];

pair<int, int> chosen_electron[MAXN];
int which_proton_chose_me[MAXN];

void find_new_electron(int proton, int n);
bool can_change(int new_proton, int electron, int index, int n);

int main()
{
    int n;
    cin >> n;

    cin.ignore();

    for (int proton = 0; proton < n; ++proton)
    {
        string s;
        getline(cin, s);

        stringstream input(s);
        
        int electron;
        int i = 0;

        unordered_set<int> all_electrons;

        while (input >> electron)
        {
            proton_sequence[proton][i++] = electron;
            all_electrons.insert(electron);
        }

        for (int j = 0; j < n; ++j)
        {
            if (!all_electrons.count(j))
            {
                proton_sequence[proton][i++] = j;
            }
        }
    }

    for (int electron = 0; electron < n; ++electron)
    {
        string s;
        getline(cin, s);

        stringstream input(s);
        int proton;

        for (int score = n; input >> proton; --score)
        {
            electron_to_proton[electron][proton] = score;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        which_proton_chose_me[i] = -1;
        chosen_electron[i] = {-1, -1};
    }

    for (int proton = 0; proton < n; ++proton)
    {
        find_new_electron(proton, n);
    }

    for (int proton = 0; proton < n; ++proton)
    {
        cout << proton << " <-> " << chosen_electron[proton].first << endl;
    }

    return 0;
}

void find_new_electron(int proton, int n)
{
    for (int i = chosen_electron[proton].second + 1; i < n; ++i)
    {
        int electron = proton_sequence[proton][i];

        if (can_change(proton, electron, i, n))
        {
            return;
        }
    }
}

bool can_change(int new_proton, int electron, int index, int n)
{
    int old_proton = which_proton_chose_me[electron];

    if (old_proton > - 1 and electron_to_proton[electron][new_proton] <= electron_to_proton[electron][old_proton])
    {
        return false;
    }

    which_proton_chose_me[electron] = new_proton;
    chosen_electron[new_proton] = {electron, index};

    find_new_electron(old_proton, n);

    return true;
}