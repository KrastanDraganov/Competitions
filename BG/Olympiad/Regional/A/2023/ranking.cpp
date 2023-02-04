#include <iostream>
#include <unordered_map>
#include <algorithm>

#define endl '\n'

using namespace std;

const int MAXN = 3e5 + 3;
const int MAXK = 5;

struct Competitior
{
    string name;

    int64_t score;
    array<int, MAXK> subtasks;

    Competitior()
    {
        name = "";
        score = 0ll;
        for (int i = 0; i < MAXK; ++i)
        {
            subtasks[i] = 0;
        }
    }

    Competitior(string _name)
    {
        name = _name;
        score = 0ll;
        for (int i = 0; i < MAXK; ++i)
        {
            subtasks[i] = 0;
        }
    }

    void update_subtask(int i, int points)
    {
        subtasks[i] = max(subtasks[i], points);
    }

    void calculate_score()
    {
        for (int i = 0; i < MAXK; ++i)
        {
            score += 1ll * subtasks[i];
        }
    }

    void print(int k)
    {
        cout << name << " " << score << " ";
        for (int i = 0; i < k; ++i)
        {
            cout << subtasks[i] << " ";
        }
        cout << endl;
    }

    bool operator<(Competitior &comp)
    {
        if (score == comp.score)
        {
            int name_size1 = (int) name.size();
            int name_size2 = (int) comp.name.size();

            for (int i = 0; i < min(name_size1, name_size2); ++i)
            {
                if (name[i] != comp.name[i])
                {
                    return name[i] < comp.name[i];
                }
            }

            return name_size1 < name_size2;
        }

        return score > comp.score;
    }
};

unordered_map<string, int> name_to_id;
Competitior competitors[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        string name;
        cin >> name;

        name_to_id[name] = i;
        competitors[i] = Competitior(name);
    }

    for (int i = 0; i < m; ++i)
    {
        string name;
        cin >> name;

        int id = name_to_id[name];

        for (int j = 0; j < k; ++j)
        {
            int points;
            cin >> points;

            competitors[id].update_subtask(j, points);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        competitors[i].calculate_score();
    }

    sort(competitors, competitors + n);

    for (int i = 0; i < n; ++i)
    {
        competitors[i].print(k);
    }

    return 0;
}