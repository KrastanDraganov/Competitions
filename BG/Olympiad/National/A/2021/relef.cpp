// Not solved - wrong answer, 0 points

#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN = 3e5 + 3, INF = 2e9;

int calc_displacement(int peak1, int peak2, vector<int>& heights) {
    return max(heights[peak1], heights[peak2]) - min(heights[peak1], heights[peak2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<bool> is_peak(MAXN, false);
    int n = 1;
    for (int i = 0; i < t; ++i) {
        int peak;
        cin >> peak;
        is_peak[peak - 1] = true;
        n = peak;
    }

    int w;
    cin >> w;

    vector<int> heights(MAXN, INF);
    for (int i = 0; i < w; ++i) {
        int pos, curr_height;
        cin >> pos >> curr_height;
        heights[pos - 1] = curr_height;
    }

    int displacement = 0;
    int last_peak = 0, last_known = INF;
    if (heights[0] != INF) {
        last_known = 0;
    }
    
    bool is_up = true;
    for (int i = 1; i < n; ++i) {
        // cout << (is_up ? "up " : "down ") << i << " " << (is_peak[i] ? "peak " : "not peak ") << heights[i] << " " << last_peak << " " << last_known << " " << displacement << endl;

        if (is_peak[i]) {
            if (heights[i] != INF) {
                if (last_known == INF) {
                    heights[last_peak] = heights[i] + (is_up ? -1 : 1) * (i - last_peak);
                }
                last_known = i;
                displacement = max(displacement, calc_displacement(i, last_peak, heights));
            } else if (last_known == INF) {
                displacement = max(displacement, i - last_peak);
            } else {
                if (is_up) {
                    heights[i] = heights[last_known] + (i - last_known);
                } else {
                    heights[i] = heights[last_known] - (i - last_known);
                }
                
                last_known = INF;
                displacement = max(displacement, calc_displacement(i, last_peak, heights));
            }

            last_peak = i;
            is_up ^= 1;
            continue;
        }

        if (heights[i] == INF) {
            continue;
        }

        if (last_known == INF) {
            if (is_up) {
                heights[last_peak] = heights[i] - (i - last_peak);
            } else {
                heights[last_peak] = heights[i] + (i - last_peak);
            }
        }

        last_known = i;
    }

    cout << displacement << " " << 1948 << endl;
return 0;
}