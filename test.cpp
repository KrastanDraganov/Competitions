/*
ID: espr1t
TASK: crypto
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 404
#define NUM_DIGITS 16
#define BASE 1000000000
using namespace std;
FILE *in; FILE *out;
struct Long
{
	int len;
	int digits[NUM_DIGITS];
	
	Long()
	{
		len = 1;
		memset(digits, 0, sizeof(digits));
	}
	
	Long(long long num)
	{
		len = 0;
		memset(digits, 0, sizeof(digits));

		while (num)
		{
			digits[len++] = num % BASE;
			num /= BASE;
		}
		if (len == 0) len++;
	}
	
	Long(const Long& right)
	{
		len = right.len;
		for (int i = 0; i < NUM_DIGITS; i++)
			digits[i] = right.digits[i];
	}
	
	void operator -= (const Long& right)
	{
		for (int i = len - 1; i >= 0; i--)
			digits[i] -= right.digits[i];
		for (int i = 0; i < len; i++)
			if (digits[i] < 0) {digits[i] += BASE; digits[i + 1]--;}
		while (len > 1 && digits[len - 1] == 0) len--;
	}
	
	void operator += (const Long& right)
	{
		len = max(len, right.len);
		int carry = 0;
		for (int i = 0; i < len; i++)
		{
			carry += digits[i] + right.digits[i];
			if (carry >= BASE) {digits[i] = carry - BASE; carry = 1;}
			else {digits[i] = carry; carry = 0;}
		}
		if (carry) digits[len++] = carry;
	}
	
	int parity() {return digits[0] & 1;}
	void divideByTwo()
	{
		for (int i = 0; i < len; i++)
		{
			digits[i] >>= 1;
			if (i < len - 1) if (digits[i + 1] & 1) digits[i] += (BASE >> 1);
		}
		while (len > 1 && digits[len - 1] == 0) len--;
	}
	
	bool notZero()
	{
		return len > 1 || digits[0] != 0;
	}
	
	void print()
	{
		fprintf(out, "%d", digits[len - 1]);
		for (int i = len - 2; i >= 0; i--)
			fprintf(out, "%09d", digits[i]);
	}
};


int k;
int a[MAX], lena;
int b[MAX], lenb;
Long leftIdx, rightIdx;
char vis[MAX][MAX][2][2];
Long dyn[MAX][MAX][2][2];

Long recurse(int idx, int ones, int flag1, int flag2)
{
	if (ones >= k) return 0;
	if (idx < 0) return 1;
	if (vis[idx][ones][flag1][flag2])
		return dyn[idx][ones][flag1][flag2];
	
	Long ans = 0;
	// Set this position to 0
	if (flag1 || a[idx] == 0)
		ans += recurse(idx - 1, 0, flag1, flag2 || b[idx] > 0);
		
	// Set this position to 1
	if (flag2 || b[idx] == 1)
		ans += recurse(idx - 1, ones + 1, flag1 || a[idx] < 1, flag2);
	
	vis[idx][ones][flag1][flag2] = 1;	
	return dyn[idx][ones][flag1][flag2] = ans;
}

Long eval()
{
	memset(a, 0, sizeof(a)); lena = 0;
	memset(b, 0, sizeof(b)); lenb = 0;
	
	Long ans = rightIdx; ans -= leftIdx; ans += 1;
	while (leftIdx.notZero()) {a[lena++] = leftIdx.parity(); leftIdx.divideByTwo();}
	while (rightIdx.notZero()) {b[lenb++] = rightIdx.parity(); rightIdx.divideByTwo();}
	if (k > lenb) return 0;
	memset(vis, 0, sizeof(vis));
	ans -= recurse(lenb - 1, 0, 0, 0);
	return ans;
}


Long parseLong()
{
	char temp[128];
	fscanf(in, "%s", temp);
	
	Long ret; ret.len = 0;
	int idx = 0, mul[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	for (int i = (int)strlen(temp) - 1; i >= 0; i--)
	{
		ret.digits[ret.len] += (int)(temp[i] - 48) * mul[idx++];
		if (idx >= 9) {idx = 0; ret.len++;}
	}
	if (idx != 0) ret.len++;
	return ret;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("crypto.in", "rt"); out = fopen("crypto.out", "wt");
	
	fscanf(in, "%d", &k);
	leftIdx = parseLong(); rightIdx = parseLong();
	
	Long ans = eval();
	ans.print(); fprintf(out, "\n");
	return 0;
}