//timetable - Elena Dimitrova
#include <iostream>
#include <cstdio>

using namespace std;

char start[12];
char days[7][12] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

int x, y;
int beg, en, day;
int cnt[7];

int find() {
    if(start[0] == 'M') return 0; //Monday
    if(start[2] == 'e') return 1; //Tuesday
    if(start[0] == 'W') return 2; //Wednesday
    if(start[0] == 'T') return 3; //Thursday
    if(start[0] == 'F') return 4; //Friday
    if(start[1] == 'a') return 5; //Saturday
    return 6; //Sunday
    }

int weeks;

void precalc() {
     weeks = (en - beg) / 7; //broi celi sedmici
     for(int i=0; i<7; i++) cnt[i] = weeks;

     beg += weeks * 7; //parviyat den ot poslednata sedmica
     for(; beg<en; beg++, day = (day + 1) % 7) cnt[day]++; //prebroyavane na dnite ot poslednata sedmica
     }

int br;

bool check(int mask) {
     int t = 0;

     br = 0;
     for(int i=0; i<7; i++)
     if(mask & (1 << i)) br++, t += cnt[i];

     return (x <= t && t <= y);
     }

void print(int mask) {
     printf("%d\n", br);
     for(int i=0; i<7; i++)
     if(mask & (1 << i)) printf("%s\n", days[i]);
     }

int main() {
    scanf("%s", &start);
    day = (find() + 1) % 7;

    beg = 16;
    scanf("%d", &en);
    scanf("%s", &start);
    if(start[0] == 'O') en += 30; //dobavyane na dnite ot September
    else if(start[0] == 'N') en += 30 + 31; //dobavyane na dnite ot September i October
    else if(start[0] == 'D') en += 30 + 31 + 30; //dobavyane na dnite ot September, October i November

    precalc();

    scanf("%d%d", &x, &y);

    for(int i=1; i<128; i++)
    if(check(i)) {
             print(i);
             return 0;
             }

    printf("0\n");
    return 0;
   }
