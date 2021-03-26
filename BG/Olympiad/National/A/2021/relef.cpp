#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int INF = 1e9 + 53;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> peaks(t);
    int n = 1;
    for (int i = 0; i < t; ++i) {
        cin >> peaks[i];
        n = peaks[i];
        --peaks[i];
    }

    int w;
    cin >> w;

    vector<int> heights(n, INF);
    for (int i = 0; i < w; ++i) {
        int pos, curr_height;
        cin >> pos >> curr_height;
        heights[pos - 1] = curr_height;
    }

    vector<int> limit(t);
    int min_boundary = INF, max_boundary = -INF;
    for (int i = 0; i < t; ++i) {
        limit[i] = (i % 2 == 0 ? INF : -INF);

        if (i > 0) {
            for (int j = peaks[i]; j >= peaks[i - 1]; --j) {
                if (heights[j] == INF) {
                    continue;
                }

                if (i % 2 == 0) {
                    limit[i] = min(limit[i], heights[j] - (peaks[i] - j));
                    min_boundary = min(min_boundary, limit[i]);
                } else {
                    limit[i] = max(limit[i], heights[j] + (peaks[i] - j));
                    max_boundary = max(max_boundary, limit[i]);
                }
            }
        }

        if (i < t - 1) {
            for (int j = peaks[i]; j <= peaks[i + 1]; ++j) {
                if (heights[j] == INF) {
                    continue;
                }

                if (i % 2 == 0) {
                    limit[i] = min(limit[i], heights[j] - (j - peaks[i]));
                    min_boundary = min(min_boundary, limit[i]);
                } else {
                    limit[i] = max(limit[i], heights[j] + (j - peaks[i]));
                    max_boundary = max(max_boundary, limit[i]);
                }
            }
        }
    }

    int max_diff = 0;
    for (int i = 1; i < t; ++i) {
        max_diff = max(max_diff, peaks[i] - peaks[i - 1]);
    }

    if (min_boundary >= max_boundary) {
        min_boundary = 0;
        max_boundary = max_diff;
    } else if (max_boundary - min_boundary < max_diff) {
        min_boundary = max_boundary - max_diff;
    }

    long long min_sum = 0;
    for (int i = 0; i < t; i += 2) {
        if (heights[peaks[i]] == INF) {
            heights[peaks[i]] = min_boundary;
        }

        min_sum += 1ll * heights[peaks[i]];
    }

    for (int i = 1; i < t; i += 2) {
        if (heights[peaks[i]] == INF) {
            heights[peaks[i]] = max(limit[i], heights[peaks[i - 1]] + (peaks[i] - peaks[i - 1]));
            
            if (i < t - 1) {
                heights[peaks[i]] = max(heights[peaks[i]], heights[peaks[i + 1]] + (peaks[i + 1] - peaks[i]));
            }
        }

        min_sum += 1ll * heights[peaks[i]];
    }

    cout << max_boundary - min_boundary << " " << min_sum << endl;
return 0;
}