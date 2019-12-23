#include <iostream>
#include <cstring>
#include <stdlib.h>     /* atoi */

#define MAXINSTR 120

using namespace std;

typedef struct {
    int cop;      // Instruction Code
    int op1;      // Operand 1
    bool op1type; // OP1 type: true - register; false - numeric
    int op2;      // Operand 2
    bool op2type; // OP2 type: true - register; false - numeric
} cmd;

char *cmds[]={(char *)"MOV", (char *)"ADD", (char *)"SUB",  (char *)"MUL", (char *)"DIV",
              (char *)"MOD", (char *)"IFEQ",(char *)"IFNEQ",(char *)"IFG", (char *)"IFL",
              (char *)"IFGE",(char *)"IFLE",(char *)"ENDIF",(char *)"CALL",(char *)"RET", NULL};
int ipn = 0;
int rc;
cmd pgm[MAXINSTR];
char buff[256];
int ncmds, startvalue;
int CmdParse(char *p)
    {
     int i;
     char *pch;
     pch = strtok (p," \n");
     if(pch!=NULL)
       {
        for(i=0; cmds[i]; i++)
           if(strcmp(cmds[i], pch) == 0)
             {
              pgm[ipn].cop = i;
              if(i>=0 && i<=11)
                {
                 pch = strtok (NULL, ",");
                 if(pch[0] == 'R'){pch++; pgm[ipn].op1 = atoi(pch); pgm[ipn].op1type = true;}
                 else {pgm[ipn].op1 = atoi(pch); pgm[ipn].op1type = false;}
                 pch = strtok (NULL, " \n");
                 if(pch[0] == 'R'){pch++; pgm[ipn].op2 = atoi(pch); pgm[ipn].op2type = true;}
                 else {pgm[ipn].op2 = atoi(pch); pgm[ipn].op2type = false;}
                }
              if(i>=13 && i<=14)
                {
                 pch = strtok (NULL, " \n");
                 if(pch[0] == 'R'){pch++; pgm[ipn].op1 = atoi(pch); pgm[ipn].op1type = true;}
                 else { pgm[ipn].op1 = atoi(pch); pgm[ipn].op1type = false;}
                }
            }
        ipn++;
        return i;
       }
     return -1;
    }
void ReadPgm()
     {
      int i;
       for(i=0; i<ncmds+1; i++)
          {
           std::cin.getline (buff,256);
           CmdParse(buff);
          }
     }
int Execute(int sv)
     {
      int ip = 0;
      int R[10];
      int a, b;
      for(ip=0; ip<10; ip++)R[ip]=0;
      ip = 0;
      R[0] = rc = sv;
      do
        {
         switch(pgm[ip].cop)
               {
                case 0://MOV
                       if(pgm[ip].op2type)
                         R[pgm[ip].op1] = R[pgm[ip].op2];
                       else
                         R[pgm[ip].op1] = pgm[ip].op2;
                       ip++;
                       break;
                case 1://ADD
                       if(pgm[ip].op2type)
                         R[pgm[ip].op1] += R[pgm[ip].op2];
                       else
                         R[pgm[ip].op1] += pgm[ip].op2;
                       if(R[pgm[ip].op1] > 999) R[pgm[ip].op1] = R[pgm[ip].op1] % 999-1;
                       ip++;
                       break;
                case 2://SUB
                       if(pgm[ip].op2type)
                         R[pgm[ip].op1] -= R[pgm[ip].op2];
                       else
                         R[pgm[ip].op1] -= pgm[ip].op2;
                       if(R[pgm[ip].op1] < 0) R[pgm[ip].op1] = 999 + R[pgm[ip].op1]+1;
                       ip++;
                       break;
                case 3://MUL
                       if(pgm[ip].op2type)
                         R[pgm[ip].op1] *= R[pgm[ip].op2];
                       else
                         R[pgm[ip].op1] *= pgm[ip].op2;
                       if(R[pgm[ip].op1] > 999) R[pgm[ip].op1] = R[pgm[ip].op1] % 999-1;
                       ip++;
                       break;
                case 4://DIV
                       if(pgm[ip].op2type) b = R[pgm[ip].op2];
                       else b = pgm[ip].op2;
                       if(b != 0)
                         R[pgm[ip].op1] /= b;
                       else
                         R[pgm[ip].op1] = 0;
                       ip++;
                       break;
                case 5://MOD
                       if(pgm[ip].op2type) b = R[pgm[ip].op2];
                       else b = pgm[ip].op2;
                       if(b != 0)
                         R[pgm[ip].op1] %= b;
                       else
                         R[pgm[ip].op1] = 0;
                       ip++;
                       break;

                case 6://IFEQ
                       if(pgm[ip].op1type)a = R[pgm[ip].op1]; else a = pgm[ip].op1;
                       if(pgm[ip].op2type)b = R[pgm[ip].op2]; else b = pgm[ip].op2;
                       if(a == b)ip++;
                       else
                         {
                          ip++;
                          while(pgm[ip].cop != 12) ip++;
                         }
                       break;
                case 7://IFNEQ
                       if(pgm[ip].op1type)a = R[pgm[ip].op1]; else a = pgm[ip].op1;
                       if(pgm[ip].op2type)b = R[pgm[ip].op2]; else b = pgm[ip].op2;
                       if(a != b)ip++;
                       else
                         {
                          ip++;
                          while(pgm[ip].cop != 12) ip++;
                         }
                       break;
                case 8://IFG
                       if(pgm[ip].op1type)a = R[pgm[ip].op1]; else a = pgm[ip].op1;
                       if(pgm[ip].op2type)b = R[pgm[ip].op2]; else b = pgm[ip].op2;
                       if(a > b)ip++;
                       else
                         {
                          ip++;
                          while(pgm[ip].cop != 12) ip++;
                         }
                       break;
                case 9://IFL
                       if(pgm[ip].op1type)a = R[pgm[ip].op1]; else a = pgm[ip].op1;
                       if(pgm[ip].op2type)b = R[pgm[ip].op2]; else b = pgm[ip].op2;
                       if(a < b)ip++;
                       else
                         {
                          ip++;
                          while(pgm[ip].cop != 12) ip++;
                         }
                       break;
                case 10://IFGE
                       if(pgm[ip].op1type)a = R[pgm[ip].op1]; else a = pgm[ip].op1;
                       if(pgm[ip].op2type)b = R[pgm[ip].op2]; else b = pgm[ip].op2;
                       if(a >= b)ip++;
                       else
                         {
                          ip++;
                          while(pgm[ip].cop != 12) ip++;
                         }
                       break;
                case 11://IFLE
                       if(pgm[ip].op1type)a = R[pgm[ip].op1]; else a = pgm[ip].op1;
                       if(pgm[ip].op2type)b = R[pgm[ip].op2]; else b = pgm[ip].op2;
                       if(a <= b)ip++;
                       else
                         {
                          ip++;
                          while(pgm[ip].cop != 12) ip++;
                         }
                       break;
                case 12://ENDIF
                       ip++;
                       break;
                case 13://CALL
                       if(pgm[ip].op1type)a = R[pgm[ip].op1]; else a = pgm[ip].op1;
                       if(a == rc) return -1;
                       R[9] = Execute(a);
                       if(R[9] == -1)return -1;
                       rc = a;
                       ip++;
                       break;
                case 14://RET
                       if(pgm[ip].op1type)a = R[pgm[ip].op1]; else a = pgm[ip].op1;
                       ip++;
                       return a;
               }
         if(ip >= ncmds) break;
        }
      while(1);
      return 0;
     }

int main()
   {
    int retval;
    std::cin>>ncmds>>startvalue;
    rc = startvalue;
    //std::cout<<ncmds<<" Start Value:"<<startvalue<<endl;
    ReadPgm();
    retval = Execute(startvalue);
    if(retval>=0)
       std::cout<<retval<< endl;
    else cout<<"*" << endl;
    return 0;
   }
