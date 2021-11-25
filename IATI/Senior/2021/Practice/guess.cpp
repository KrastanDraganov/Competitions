#include <iostream>

#include "guess.h"

using namespace std;

void guess() {
    int64_t l = 1, r = 1e18;

    while (l <= r) {
        int64_t mid = (l + r) / 2;
        int guess_result = quest(mid);

        if (guess_result == 0) {
            res(mid);
            return;
        }

        if (guess_result == 1) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}