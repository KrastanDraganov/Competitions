#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <sys/time.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;
const double MAX_TIME = 4.0; // SET THIS
const double SWITCH_TIME = 0.75 * MAX_TIME;

uint32_t seed_ = 123456789; inline uint32_t nextInt(int m) { return m * (1./(1L<<32)) * (seed_ = 1664525 * seed_ + 1013904223); }
double START_TIME, CUR_TIME;
double getTime()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}
void setTime()
{
    START_TIME = getTime();
}
double getElapsed()
{
    CUR_TIME = getTime();
    return CUR_TIME - START_TIME;
}


ifstream fin ("path.in");
ofstream fout ("path.out");

int N, M, L;
int board[MAXN][MAXN];
bool seen[MAXN][MAXN];
pair <int, int> successor[MAXN][MAXN];

int ord[4];
int xc[4] = {-1, 1, 0, 0};
int yc[4] = {0, 0, -1, 1};

vector <pair <int, int> > ans;
int dep[MAXN][MAXN];
pair <int, int> mprev[MAXN][MAXN];

void flood (int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M || seen[x][y]) return;
    seen[x][y] = true;

    int px = mprev[x][y].first, py = mprev[x][y].second;
    if (px != -1 && successor[px][py].first != -1)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + xc[ord[i]];
            int ny = y + yc[ord[i]];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !seen[nx][ny])
            {
                if (successor[px][py] == make_pair (nx, ny) || successor[nx][ny] == make_pair (px, py))
                {
                    dep[nx][ny] = dep[x][y] + 1;
                    mprev[nx][ny] = make_pair (x, y);
                    flood (nx, ny);
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + xc[ord[i]];
        int ny = y + yc[ord[i]];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !seen[nx][ny])
        {
            dep[nx][ny] = dep[x][y] + 1;
            mprev[nx][ny] = make_pair (x, y);
            flood (nx, ny);
        }
    }
}

int LIS (vector <int> v)
{
    vector <int> res;
    for (int x : v)
    {
        if (!res.size() || x > res.back())
        {
            res.push_back(x);
            continue;
        }

        int lo = 0, hi = res.size() - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (res[mid] >= x)
                hi = mid;
            else
                lo = mid + 1;
        }
        res[lo] = x;
    }
    return res.size();
    
    /*set <int> s;
    for (int x : v)
    {
        auto it = s.lower_bound(x);
        if (it == s.end())
            s.insert(x);
        else
        {
            s.erase(it);
            s.insert(x);
        }
    }
    return s.size();*/
}

ll get_score (vector <pair <int, int> > cand)
{
    vector <int> v;
    for (pair <int, int> p : cand)
    {
        v.push_back(board[p.first][p.second]);
    }
    ll a = LIS (v);
    reverse (v.begin(), v.end());
    ll b = LIS (v);
    return a * b;
}

void ggs()
{
    cout << get_score (ans) << "\n";
    fout << ans.size() << "\n";
    for (pair <int, int> p : ans)
    {
        fout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}

vector <pair <int, int> > locs;
vector <pair <int, int> > splocs;

int main()
{
    setTime();
    srand(time(NULL));
    fin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            fin >> board[i][j];
            seen[i][j] = false;
            if (board[i][j] == -1)
                seen[i][j] = true;
            else
                locs.push_back(make_pair (i, j));
            if (board[i][j] == 1)
                splocs.push_back(make_pair (i, j));
            successor[i][j] = make_pair (-1, -1);
        }
    fin >> L;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            for (int k = i - 2; k <= i + 2; k++)
                for (int l = j - 2; l <= j + 2; l++)
                    if (k >= 0 && k < N && l >= 0 && l < M)
                        if (board[k][l] == board[i][j] + 1)
                            if (abs (i - k) + abs (l - j) == 2)
                                successor[i][j] = make_pair (k, l);
        }


    int mm = 0;
    int run = 0;
    int NRUNS = 1;
    if (N <= 100 && M <= 100)
        NRUNS = 20;
    if (N <= 20 && M <= 20)
        NRUNS = 200;

    bool spswap = false;
    while (true)
    {
        if (run % NRUNS == 0)
        {
            double dtime = getElapsed();
            if (dtime > MAX_TIME) break;
            if (dtime > SWITCH_TIME && !spswap)
            {
                spswap = true;
                if (splocs.size())
                    locs = splocs;
            }
        }

        for (int i = 0; i < 4; i++)
            ord[i] = i;
        for (int i = 0; i < 4; i++)
            swap (ord[i], ord[rand() % (i + 1)]);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                seen[i][j] = (board[i][j] == -1);
                dep[i][j] = 0;
                mprev[i][j] = make_pair (-1, -1);
            }

        int choice = rand() % locs.size();
        //if (locs[choice].first >= N/10 && locs[choice].second >= N/10 && locs[choice].first <= 9 * N / 10 && locs[choice].second <= 9 * N / 10)
        //    continue;
        flood (locs[choice].first, locs[choice].second);

        int xloc = -1, yloc = -1, bval = -1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (dep[i][j] > bval)
                {
                    bval = dep[i][j];
                    xloc = i;
                    yloc = j;
                }
        //cout << bval << "\n";
        vector <pair <int, int> > v;
        while (xloc != -1)
        {
            v.push_back(make_pair (xloc, yloc));
            pair <int, int> p = mprev[xloc][yloc];
            xloc = p.first;
            yloc = p.second;
        }
        mm = max (mm, (int) v.size());
        if (v.size() > L)
        {
            for (int test = 0; test < 5; test++)
            {
                int cloc = rand() % (v.size() - L + 1);
                if (test == 0) cloc = v.size() - L;

                vector <pair <int, int> > chop;
                for (int i = cloc; i < cloc + L; i++)
                    chop.push_back(v[i]);
                if (get_score (chop) > get_score(ans))
                    ans = chop;
            }
        }
        else
        {
            if (get_score (v) > get_score (ans))
                ans = v;
        }
        run++;
    }

    cout << run << " runs!\n";

    //cout << mm << "\n";
    ggs();
}