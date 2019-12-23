#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

char days[7][12] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

int x, y;
int beg, en, day;
int cnt[7];

int found(char start[]) {
    for(int i=0; i<7; i++) if(0 == strcmp(days[i], start)) return i;
    return -1;
    }

void precalc() {
     for(; beg<en; beg++, day = (day + 1) % 7) cnt[day]++; 
     }

bool check(int mask) {
     int t = 0;
     
     for(int i=0; i<7; i++)
     if(mask & (1 << i)) t += cnt[i];
     
     return (x <= t && t <= y);
     }

void print(bool cmd) {
     if(cmd) printf("5\nAccepted\n");
     else printf("0\nWrong answer\n");
     }

int out_n;
int sol_n;
char out_days[7][12];
bool f;

int main(int argc, char *argv[]) {
    FILE *win;
    FILE *wout;
    FILE *wsol;
    
    win = fopen(argv[1], "r");
    wout = fopen(argv[2], "r");
    wsol = fopen(argv[3], "r");
    
    if(wout == NULL) {
            printf("0\nCannot open out file\n");
            return 0;
            }
    
    char s[12];
    
    fscanf(win, "%s", &s);
    day = (found(s) + 1) % 7;
    
    beg = 16;
    fscanf(win, "%d", &en);
    fscanf(win, "%s", &s);
    if(s[0] == 'O') en += 30; //dobavyane na dnite ot Septemvri
    else if(s[0] == 'N') en += 30 + 31; //dobavyane na dnite ot Septemvri i Oktomvri
    else if(s[0] == 'D') en += 30 + 31 + 30; //dobavyane na dnite ot Septemvri, Oktomvri i Noemvri
    
    precalc();
    
    fscanf(win, "%d%d", &x, &y);
    
    fscanf(wout, "%d", &out_n);
    fscanf(wsol, "%d", &sol_n);
    
    f = 1;
    if(out_n < 0 || out_n > 7) f = 0;
    else if(out_n == 0) {
         if(sol_n != 0) f = 0;
         }
    else {
         int t, prevt;
         int mask = 0;
         char prev[12];
         
         fscanf(wout, "%s", &s);
         if(-1 == (t = found(s))) f = 0; 
         else mask |= (1 << t), strcpy(prev, s), prevt = t;
         
         
         if(f) {
               for(int i=1; i<out_n; i++) 
               {
               fscanf(wout, "%s", &s);
               if(-1 == (t = found(s))) { f = 0; break; }
               if(t <= prevt) { f = 0; break; }
               
               mask |= (1 << t);
               strcpy(prev, s);
               prevt = t;
               }
               
               if(f) f = check(mask);
               }
         }
         
    print(f);
    return 0;
    }
