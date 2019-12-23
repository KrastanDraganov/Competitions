#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
struct Point
{
    long long x, y, z;
    Point(long long _x, long long _y, long long _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    bool operator< (const Point &b)const
    {
        if (x < b.x)    return true;
        if (x > b.x)    return false;
        if (z < b.z) return true;
        if (z > b.z) return false;
        return y < b.y;
    }

};
int n;
vector<Point> pointsUp, pointsDown;
vector<Point> segments;

void FormSegments(vector<Point> points)
{
    if (points.empty())
        return;
    sort(points.begin(), points.end());
    multiset<long long> s;
    long long prevX = points[0].x;
    Point currSeg(prevX, prevX, 0);
    for (int i = 0;  i < points.size(); i++)
    {
        if (!s.empty())
            currSeg.z += (points[i].x - prevX) * (-*s.begin());
        else // There is nothing in the set.. next shall be z
            currSeg.x = points[i].x;
        if (points[i].z == 2)
        {
            multiset<long long>::iterator it = s.lower_bound(points[i].y);
            s.erase(it);
        }
        else
            s.insert(points[i].y);

        if (s.size() == 0)
        {
            currSeg.y = points[i].x;
            segments.push_back(currSeg);
            currSeg.z = 0;
        }
        prevX = points[i].x;
    }
}
void AddPoints(long long x1, long long x2, long long y, vector<Point> &p) // Ys are negative
{
    p.push_back(Point(x1, y, 1)); // opening
    p.push_back(Point(x2, y, 2)); // closing
}
int main ()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long x1, y1, x2, y2; // y1 is useless
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        if (y2 == 0) swap(y1, y2);
        if (x1 > x2) swap(x1, x2);
        AddPoints(x1, x2, -abs(y2), y2 > 0 ? pointsUp : pointsDown);
    }
    long long sum = 0, maxR = -2147483647, mx = 0, cnt = 0, curr = 0;

    FormSegments(pointsUp);
    FormSegments(pointsDown);
    sort(segments.begin(), segments.end());

    //combine the segments and you are ready
    for (int i = 0; i < segments.size(); i++)
    {
        if (segments[i].x >= maxR)
        {
            curr = 0;
            cnt++;
        }
        curr += segments[i].z; // size
        mx = max(curr, mx);
        sum += segments[i].z;
        maxR = max(maxR, segments[i].y);
    }

    printf("%lld\n%lld\n%lld\n", cnt, sum, mx);
    return 0;
}
/*
8
1 0 9 2
3 0 7 4
4 0 8 -2
10 0 14 2
14 0 19 -2
16 0 19 -4
17 0 19 -3
21 0 25 -1


*/
