// 0 points - Code is not finished

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int BASE = 1e9;

struct LongNumber {
    int num_size;
    vector<int> digits;

    LongNumber() {
        num_size = 0;
        digits.clear();
    }

    LongNumber(int64_t num) {
        int curr_size = 0;
        
        num_size = 1;
        digits.push_back(0);

        while (num > 0) {
            ++curr_size;

            if (curr_size > 9) {
                curr_size = 1;
                ++num_size;
                digits.push_back(0);
            }

            digits.back() *= 10;
            digits.back() += (num % 10);

            num /= 10;
        }
    }

    LongNumber operator+(const LongNumber& other) {
        int bonus = 0;

        for (int i = 0; i < max(num_size, other.num_size) or bonus > 0; ++i) {
            if (i == num_size) {
                ++num_size;
                digits.push_back(0);
            }

            int sum = bonus;

            if (i < num_size) {
                su
            }

            if (sum >= BASE) {
                bonus = 1;
                sum -= BASE;
            }

            digits[i] = sum;
            ++i;
        }
    }

    LongNumber fast_mul(const LongNumber& other, int counter) {

    }

    LongNumber operator*(const LongNumber& other) {
        
    }
};

int solve(int a, int b, int k) {
    int64_t num = a;
    for (int i = 2; i <= b; ++i) {
        num *= a;
    }

    int res = 0;
    while (k > 0) {
        res = num % 10;
        num /= 10;
        --k;
    }

    return res;
}

LongNumber fast_pow(LongNumber num, int degree) {
    if (degree == 1) {
        return num;
    }
    
    if (degree % 2 == 1) {
        return num * fast_pow(num, degree - 1);
    }

    LongNumber half = fast_pow(num, degree / 2);
    return half * half;
}

int solve2(int a, int b, int k) {
    LongNumber num(a);

    num = fast_pow(num, b);

    int ind = 0;
    while (k > 9) {
        k -= 9;
        ++ind;
    }

    int res = 0;
    while (k > 0) {
        res = num.digits[ind] % 10;
        num.digits[ind] /= 10;
        --k;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test) {
        int a, b, k;
        cin >> a >> b >> k;

        cout << solve(a, b, k) << endl;
    }

return 0;
}