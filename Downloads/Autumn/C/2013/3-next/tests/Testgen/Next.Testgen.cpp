#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const long long INF = 9876543210LL;

vector <long long> nums;

long long nextNumberDummy(long long start) {
    for (long long candidate = start + 1; candidate <= INF; candidate++) {
        int mask = (1 << (candidate % 10));
        for (int tmp = candidate / 10; tmp > 0; tmp /= 10) {
            if (mask & (1 << (tmp % 10))) {
                mask = -1;
                break;
            }
            mask |= (1 << (tmp % 10));
        }
        if (mask != -1)
            return candidate;
    }
    return -1;
}

int cnt = 0;

long long nnRecurse(long long num, int mask, long long limit) {
    cnt++;
    if (num > limit)
        return num;
    long long ans = INF;
    for (int dig = !num; dig < 10; dig++) if (!(mask & (1 << dig)))
        ans = std::min(ans, nnRecurse(num * 10 + dig, mask | (1 << dig), limit));
    return ans;
}

long long nextNumberRecurse(long long start) {
    return start >= INF ? -1 : nnRecurse(0, 0, start);
}


bool checkRest(const vector <int>& digits, int howMany, int forbidden) {
    int dig = 10;
    for (int i = (int)digits.size() - howMany; i < (int)digits.size(); i++) {
        dig--;
        while (dig >= 0 && (forbidden & (1 << dig)))
            dig--;
        if (dig < 0) return false;
        if (digits[i] < dig) return true;
        if (digits[i] > dig) return false;
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

string toString(long long num) {
    if (num == 0)
        return "0";
    string sign = "";
    if (num < 0)
        sign = "-", num = -num;
    
    string ret;
    while (num)
        ret += (num % 10 + '0'), num /= 10;
    reverse(ret.begin(), ret.end());
    return sign + ret;
}

long long random40() {
    long long ret = 0;
    for (int i = 0; i < 4; i++) {
        ret <<= 10;
        ret |= (rand() & (((1 << 10) - 1) << 4));
    }
    return ret;
}

void randomTest(int size, long long limit) {
    for (int i = 0; i < size; i++) {
        nums.push_back(random40() % (limit + 1));
    }
}

long long slowTest(long long limit) {
    vector < pair <unsigned, long long> > v;
    for (int iter = 0; iter < 1000; iter++) {
        long long num = random40() % (limit + 1);
        unsigned timer = clock();
        long long res = nextNumberDummy(num);
        v.push_back(make_pair(clock() - timer, num));
    }
    sort(v.rbegin(), v.rend());
    nums.push_back(v[0].second);
}

void sampleInput() {
    nums.push_back(42);
    nums.push_back(10);
    nums.push_back(424242424242LL);
    nums.push_back(426661337);
}

void handTest1() {
    nums.push_back(0);
    nums.push_back(9);
    nums.push_back(987);
    nums.push_back(666);
    nums.push_back(100);
    nums.push_back(42);
    nums.push_back(321);
    nums.push_back(16);
}

void handTest2() {
    nums.push_back(0);
    nums.push_back(1000000);
    nums.push_back(987654);
    nums.push_back(989796);
    nums.push_back(424242);
    nums.push_back(12345);
    nums.push_back(102030);
    nums.push_back(789666);
    nums.push_back(567890);
    
    // Relatively large gaps
    nums.push_back(987654);
    nums.push_back(109876);
    nums.push_back(879654);
    nums.push_back(219876);
    nums.push_back(769854);

    // Randoms
    while ((int)nums.size() < 100) {
        nums.push_back(slowTest(1000000));
    }
}

void handTest3() {
    nums.push_back(1234567890LL);
    nums.push_back(9876543210LL);
    nums.push_back(1357924680LL);
    nums.push_back(2468013579LL);
    nums.push_back(1928374650LL);
    nums.push_back(1029384756LL);
    nums.push_back(9876543201LL);
    nums.push_back(8976543210LL);
    nums.push_back(9876501234LL);
    nums.push_back(5432106789LL);
    nums.push_back(5432109876LL);
    nums.push_back(1111111111LL);
    nums.push_back(2222222222LL);
    nums.push_back(3333333333LL);
    nums.push_back(4444444444LL);
    nums.push_back(5555555555LL);
    nums.push_back(6666666666LL);
    nums.push_back(7777777777LL);
    nums.push_back(8888888888LL);
    nums.push_back(9999999999LL);
    nums.push_back(10000000000LL);
    nums.push_back(100000000000LL);
    nums.push_back(1000000000000LL);
    
    // Largest answer;
    nums.push_back(1098765432LL);
    nums.push_back(8796543210LL);
    nums.push_back(2198765430LL);
}

int main(void) {
    srand(42);
    FILE* in = stdin; FILE* out = stdout;
    
    int numTests = 10;
    for (int test = 0; test <= numTests; test++) {
        fprintf(stderr, "Currently generating testcase %d...\n", test);
        nums.clear();
        if (test == 0) sampleInput();
        else if (test == 1) handTest1();
        else if (test == 2) randomTest(10, 1000);
        else if (test == 3) randomTest(100, 10000);
        else if (test == 4) randomTest(100, 1000000);
        else if (test == 5) handTest2();
        else if (test == 6) randomTest(15, 1000000000);
        else if (test == 7) randomTest(30, 500000000);
        else if (test == 8) randomTest(50, 10000000000LL);
        else if (test == 9) randomTest(100, 10000000000LL);
        else if (test == 10) handTest3();
        
        // Test times
        unsigned sTime = clock();
        vector <long long> ans1;
        for (int i = 0; i < (int)nums.size(); i++)
            ans1.push_back(nextNumberDummy(nums[i]));
        fprintf(stderr, "  >> Dummy execution time: %.3lf sec.\n",
            (double)(clock() - sTime) / CLOCKS_PER_SEC);
        
        sTime = clock();
        vector <long long> ans2;
        for (int i = 0; i < (int)nums.size(); i++)
            ans2.push_back(nextNumberRecurse(nums[i]));
        fprintf(stderr, "  >> Recurse execution time: %.3lf sec.\n",
            (double)(clock() - sTime) / CLOCKS_PER_SEC);
        
        sTime = clock();
        vector <long long> ans3;
        for (int i = 0; i < (int)nums.size(); i++)
            ans3.push_back(nextNumber(nums[i]));
        fprintf(stderr, "  >> Author's execution time: %.3lf sec.\n",
            (double)(clock() - sTime) / CLOCKS_PER_SEC);
        
        for (int i = 0; i < (int)nums.size(); i++) {
            if (ans1[i] != ans2[i]) {
                fprintf(stderr, "ERROR: Dummy different than Recursion (%s vs %s)\n",
                    toString(ans1[i]).c_str(), toString(ans2[i]).c_str());
                system("pause");
            }
            if (ans1[i] != ans3[i]) {
                fprintf(stderr, "ERROR: Dummy different than Author's on number %s (%s vs %s)\n",
                    toString(nums[i]).c_str(), toString(ans1[i]).c_str(), toString(ans3[i]).c_str());
                system("pause");
            }
        }
        
        char inpFile[32];
        sprintf(inpFile, "next.%02d.in", test);
        FILE* inp = fopen(inpFile, "wt");
        fprintf(inp, "%d\n", (int)nums.size());
        for (int i = 0; i < (int)nums.size(); i++)
            fprintf(inp, "%s\n", toString(nums[i]).c_str());
        fclose(inp);
        
        char solFile[32];
        sprintf(solFile, "next.%02d.sol", test);
        FILE* sol = fopen(solFile, "wt");
        for (int i = 0; i < (int)nums.size(); i++)
            fprintf(sol, "%s\n", toString(nextNumber(nums[i])).c_str());
        fclose(sol);
    }

    /*
    long long best = 1, with = 0, num = 1, last = 0;
    while (num <= 9876543210LL) {
        last = num;
        num = nextNumber(num);
        if (best < num - last)
            best = num - last, with = last;
    }
    fprintf(stderr, "%lld %lld\n", best, with);
    */

    return 0;
}
