#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

const int INF = 1e9 + 3;

struct Delivery {
    int time, house;
    
    Delivery() : time(0), house(0) {}
    Delivery(int _time, int _house) : time(_time), house(_house) {}

    bool operator<(const Delivery& comp) {
        if (time == comp.time) {
            return house < comp.house;
        }

        return time < comp.time;
    }
};

int greedy(vector<Delivery>& deliveries, int n) {
    sort(deliveries.begin(), deliveries.end());

    vector<Delivery> trucks;
    trucks.push_back(deliveries[0]);

    for (int i = 1; i < n; ++i) {
        int min_time_diff = INF;
        int ind = -1;

        // cout << "Current Delivery: " << deliveries[i].time << " " << deliveries[i].house << endl;
        // cout << "Available Trucks: ";
        // for (Delivery truck : trucks) {
        //     cout << "(" << truck.time << ", " << truck.house << ") ";
        // }
        // cout << endl;

        for (int j = 0; j < (int) trucks.size(); ++j) {
            int time_diff = deliveries[i].time - trucks[j].time;
            int house_dist = abs(deliveries[i].house - trucks[j].house);

            if (time_diff >= house_dist and time_diff < min_time_diff) {
                min_time_diff = time_diff;
                ind = j;
            }
        }

        if (ind == -1) {
            trucks.push_back(deliveries[i]);
        } else {
            trucks[ind] = deliveries[i];
        }
    }

    return (int) trucks.size();
}

int calc_dp(vector<Delivery>& deliveries, int n) {
    sort(deliveries.begin(), deliveries.end());

    vector<int> dp(n, INF);
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (deliveries[i].time - deliveries[j].time >= abs(deliveries[i].house - deliveries[j].house)) {
                dp[i] = min(dp[i], dp[j]);
            } else {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    int res = dp[0];
    for (int i = 1; i < n; ++i) {
        res = max(res, dp[i]);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Delivery> deliveries(n);
    for (int i = 0; i < n; ++i) {
        cin >> deliveries[i].time >> deliveries[i].house;
    }

    cout << greedy(deliveries, n) << endl;
return 0;
}