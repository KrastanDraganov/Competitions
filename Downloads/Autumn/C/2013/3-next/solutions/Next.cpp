/*
ID: espr1t
LANG: C++
TASK: Next
KEYWORDS: Easy, Greedy
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 9876543210LL;

bool checkRest(const vector <int>& digits, int howMany, int forbidden) {
    int dig = 10;
    for (int i = (int)digits.size() - howMany; i < (int)digits.size(); i++) {
        dig--;
        while (dig >= 0 && (forbidden & (1 << dig)))
            dig--;
        if (dig < 0) return false;
        if (digits[i] < dig) return true;
        if (digits[i] > dig) return false;
        forbidden |= (1 << dig);
    }
    return false;
}

long long nextNumber(long long start) {
    if (start >= 9876543210LL)
        return -1;
    if (start == 0)
        return 1;
    
    vector <int> digits;
    for (long long tmp = start; tmp > 0; tmp /= 10)
        digits.push_back(tmp % 10);
    reverse(digits.begin(), digits.end());
    
    // Some numbers (for example 9876(...)) need one more digit.
    // If that is the case, we return 10234(...).
    if (!checkRest(digits, (int)digits.size(), 0)) {
        long long ret = 10;
        for (int i = 2; ret <= start; i++)
            ret = ret * 10 + i;
        return ret;
    }
    
    int mask = 0;
    for (int i = 0; i < (int)digits.size(); i++) {
        bool changeDigit = false;
        // We should change the current digit in the following two cases:

        // 1) The digit is already used.
        if (mask & (1 << digits[i]))
            changeDigit = true;
        // 2) It is impossible to create a larger number with the rest of the digits.
        if (!checkRest(digits, (int)digits.size() - i - 1, mask | (1 << digits[i])))
            changeDigit = true;

        if (changeDigit) {
            // Increase current digit and re-order the rest greedily.
            digits[i]++;
            while (mask & (1 << digits[i]))
                digits[i]++;
            mask |= (1 << digits[i]);
            for (int c = i + 1; c < (int)digits.size(); c++) {
                digits[c] = 0;
                while (mask & (1 << digits[c]))
                    digits[c]++;
                mask |= (1 << digits[c]);
            }
            long long ret = 0;
            for (int c = 0; c < (int)digits.size(); c++)
                ret = ret * 10 + digits[c];
            return ret;
        }
        else mask |= (1 << digits[i]);
    }
    // This should (in theory) never happen.
    return -1;
}

int main(void) {
//    freopen("Next.in", "rt", stdin);
//    freopen("Next.out", "wt", stdout);
    int numTests;
    fscanf(stdin, "%d", &numTests);
    for (int test = 0; test < numTests; test++) {
        long long num;
        fscanf(stdin, "%lld", &num);
        fprintf(stdout, "%lld\n", nextNumber(num));
    }
    return 0;
}
