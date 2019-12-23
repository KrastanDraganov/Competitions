#include <stdio.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include <cstring>

#define NO	      0
#define YES	      1
#define MAXOP    25
#define MAXDATA  50
#define MAXTXTLN 64	 /* Maximum length of text */

#define EFORMAT   2
#define EDIALC	  3
#define OKEY	  0

/*-----------------------------------------------------*/
/* Types of data received from scanner() 		       */
/*-----------------------------------------------------*/
#define ENDSTR	 0   /* End of arithmetic expression   */
#define NUMM	 1   /* Number 			               */
#define IDENTIF  2   /* Identifier of variable         */
#define SFUNC	 3   /* Standard function 	           */
#define SEP	     6   /* Separator +,-,*,/,(,),^,=,,    */
#define FTEXT	 7   /* Text string 		           */
#define SCANERR  8   /* Wrong lexical unit             */
#define BEGSTR	 9   /* Start of arithmetic expression */
#define LBRACE	10   /* Left parenthesis 		       */
#define RBRACE	11   /* Right parenthesis 		       */
#define TEXTVAR 14   /* Variable of type TEXT 	       */
/*-----------------------------------------------------*/

int gcalc(char *);
int fcerror(int );
int scanner(char *, char *, float *);
int setvar(char *, int *);
int popop();
int setstr(char *, int *);
int exsfun(char *);
int valsep(char , int *);
int stdfunc(char *, int );
int issep(char , char *);
void linepack(char *, char *);

int settvar(char *, char *, int *);

 typedef struct {
		         char vname[9];
		         float vval;
		        } var;

 typedef struct {
		         char sname[9];
		         char  sval[65];
		        } str;

 struct  opstack {
		          char opcode;
		          int prior;
		         }opst[MAXOP];


 var   *vtab = NULL;
 str   *stab;
 float *dstack;

 int vl=-1;	       /* Number of Variables */
 int sl=-1;	       /* Number of strings   */
 int lbn=-1;       /* Number of labels    */
 int dp;	       /* Index in the data stack */

int ftrue;	       /* Receives the value of the logical expression 1-true; 0-false */
int errdeli=0;	   /* Flag for removal Identifier on error */

 int op;	       /* Index in the stack of operations */

 int ires;	       /* In which row of the table will stored the result */

 struct separ {
	           char sepkey;
	           int  prior;
	          } sep[]  = {
			  'e',5, /* predicate minus */
			  '+',5,
			  '-',5,
			  '*',6,
			  '/',6,
			  '^',7,
			  '(',1,
			  ')',1,
			  ',',1,
			  '<',4, /* <  */
			  '?',4, /* <= */
			  '=',4, /* =  */
			  '#',4, /* != */
			  '$',4, /* >= */
			  '>',4, /* >  */
			  '!',3, /* !  */
			  '|',3, /* || */
			  '&',2, /* && */
			  '_',1
			 };

 char txt5[80];

 int maxvar=50, maxstr=50;
 char textbuf[256];
 int endflag=0;
 int iii;

float pmp(float par)
{
    return par/2.0;
}

/* --------------------------------------------------------------------*/
/* Function to reset the variables involved in formulas and programs.  */
/* --------------------------------------------------------------------*/
int fclrm()
{
 vl=sl=-1;
 return 0;
}

int gcalc(char *s)
{
 float numval;
 char identif[9];
 char sch[256];
 int pos;	   /* In which row of the table is stored identifier? */
 int code;
 int tprior;
 int pred;
 int i;

 errdeli = 0;	    /* On error - blocking the elimination of the changes.  */
 ires = 0;
/* Ignore all spaces and replace the two-character separators with one-character */
 linepack(sch, s);
 code = scanner(&sch[0],&identif[0],&numval);
 if(code != IDENTIF)
   {
    /* The expression must start with identifier and = */
    if((code==SEP)&&(identif[0]=='='))
      {
       ires=-1; 	    /* If the expression starts with = commit */
       goto begstmt;	/* the calculated value of the compute_flt */
      }
    else return(EFORMAT);
   }
 errdeli = setvar(&identif[0],&ires);  /* errdeli = 1 if this variable is new */
 if ((scanner(&sch[0],&identif[0],&numval) != SEP) || (identif[0] != '='))
							   return(EFORMAT);

begstmt:
 pred = BEGSTR;   /* Beginning of a sentence */
 op = 0;	  /* A pointer to the stack of operations */
 opst[op].opcode = '_';
 opst[op].prior  = 0;

 dp = -1;    /*  Pointer to the stack data	*/

 do
   {
    code=scanner(&sch[0],&identif[0],&numval);

    /* Parsing the expression */
    /*==============================*/
    if((code == NUMM) || (code == IDENTIF) || (code == SFUNC))
       {  /* Variable, number, function */
	    if((pred != BEGSTR) && (pred != SEP) && (pred != LBRACE))
	      {
	       return(EFORMAT);
	      }
	    if(code == SFUNC)
	      pred=LBRACE;
	    else
	      pred = NUMM;
       }
     else
       {
	    if(code == SEP)
	      { /* Separator */
	       if(identif[0] == '(')
	         {
	          if((pred != BEGSTR) && (pred != SEP) && (pred != LBRACE))
		        {
		         return(EFORMAT);
                }
	          pred = LBRACE;
	         }
	       else
		     {
		      if(identif[0] == ')')
		        {
		         if((pred != RBRACE) && (pred != NUMM))
		           {
		            return(EFORMAT);
		           }
		         pred = RBRACE;
		        }
              else
		        {
		         if((pred != BEGSTR) && (pred != NUMM) &&
			        (pred != RBRACE) && !(pred == LBRACE))
			       {
			        return(EFORMAT);
			       }
		         /* Starting minus */
		         /* ================ */
		         if((pred == BEGSTR) || (pred == LBRACE))
			       {
			        switch( identif[0] )
				       {
				        case '-':
					             identif[0] = 'e';
					             break;
				        /* '+','*','/','^'*/
				        default:
					            return(EFORMAT);
				       }
			       }
		         pred = SEP;
		        }
             }
	      } /* End of SEP */
	    else
	      {
	       if(code == FTEXT)
	         {
	          pred=NUMM;
	         }
	       else
	         {
	          if(code == ENDSTR)
		        {
		         /* Beginning of a sentence = end of expression */
		         if((pred == BEGSTR) && (ires==-1))
		           {
		            /* Display menu of variables */
		            /* == just the symbol = ! ==================== */
		           }
		         if((pred == SEP) || (pred == LBRACE) || (pred == BEGSTR))
		            return(EFORMAT);
		         pred = ENDSTR;
		        }
	          else
		        {
		         if(code < TEXTVAR) return(EDIALC); /* Wrong lexical unit */
		        }
	         }
	      }
       }

    switch(code)
          {
	       case ENDSTR:
		               while(opst[op].opcode != '_')
			                if(popop() != 0) return(1);
		               /* Processing results */
                       if(ires==-1)
		                 {
			              ftrue = (dstack[dp] == 1.0) ? YES : NO;
		                 }
		               else
			             vtab[ires].vval = dstack[dp];
		                 return(-1);
	        case NUMM:
		               dstack[++dp] = numval;
		               if(dp > MAXDATA) return(EFORMAT);
		               break;
	        case IDENTIF:
		               if((setvar(&identif[0],&pos)) != 0)
		                 {errdeli=1; return(EDIALC);}
		                /* The new right variable is found on the left */
		               if((errdeli==1) && (pos==vl)) return(EDIALC);
		                 dstack[++dp] = vtab[pos].vval;
		               if(dp > MAXDATA) return(EFORMAT);
		               break;
	        case TEXTVAR:
		               {int ktv1,ktv2;
		                char sgn;
                        setstr(identif,&ktv1);
		                code=scanner(&sch[0],&identif[0],&numval);
		                if((identif[0] != '=') && (identif[0] != '#')) return(EFORMAT);
		                sgn = identif[0];
		                code=scanner(&sch[0],&identif[0],&numval);
		                if(code == TEXTVAR)
			              {
			               setstr(identif,&ktv2);
			               if(strcmp(stab[ktv1].sval,stab[ktv2].sval))
			                 {
			                  if(sgn == '=') dstack[++dp] = 0.0;
			                  if(sgn == '#') dstack[++dp] = 1.0;
			                 }
			               else
			                 {
			                  if(sgn == '=') dstack[++dp] = 1.0;
			                  if(sgn == '#') dstack[++dp] = 0.0;
                             }
			               pred = NUMM;
			               break;
                          }
		                 if(code == FTEXT)
			               {
			                if(strcmp(stab[ktv1].sval,textbuf))
			                  {
			                   if(sgn == '=') dstack[++dp] = 0.0;
			                   if(sgn == '#') dstack[++dp] = 1.0;
			                  }
			                else
			                  {
			                   if(sgn == '=') dstack[++dp] = 1.0;
			                   if(sgn == '#') dstack[++dp] = 0.0;
                              }
			               }
		                 else
			               return(EFORMAT);
		                 pred = NUMM;
		                 break;}
            case FTEXT:
		                 strcpy(txt5,textbuf);
		                 dstack[++dp] = 9999;
		                 break;
	        case SFUNC:
		                 opst[++op].opcode = 'f'; /* Looking for ) of a function */
		                 opst[op].prior = 1;
                         break;
	        case SEP:
		                 if(identif[0] == '(')
			               {
			                opst[++op].opcode = '(';
			                opst[op].prior = 1;
			               }
		                 else
                           {
			                if(identif[0] == ')')
			                  {
			                   while((opst[op].opcode != '(') &&
				                     (opst[op].opcode != 'f') &&
				                     (op > 0))
				                    if(popop() != 0) return(1);
			                  if(op <= 0) return(EFORMAT);
			                    else
				                  {
				                   /* Release (, f from the stack */
				                   if(opst[op].opcode != '(')
				                     {
				                      if(exsfun(&sch[0]) == NO) return(EFORMAT);
				                     }
				                  op--;
				                  }
			                  }
			                else
			                  {
			                   if(valsep(identif[0],&tprior) != 0 )  return(EDIALC);
			                   for(i=op; i>=0;i--)
				                  {
				                   if(tprior <= opst[i].prior)
				                     {
				                      if(popop() != 0) return(1);
				                     }
				                   else
				                     {
					                  op=i+1;
					                  opst[op].opcode = identif[0];
                                      opst[op].prior = tprior;
					                  break;
                                     }
				                  }
			                  }
			               }
		                   break;
	        case SCANERR:
		                   break;
	        default:
		                   fcerror(code);
                           break;
	     }
   }
while (code != ENDSTR);
return 0;
}  /* end of gcalc */

int setvar(char *ident, int *pos)
{
 int i = 0;
 while ((ident[i] != ' ') && (ident[i] != 0) && (i < 8)) i++;
 ident[i] = 0;
 for (i=0;i<=vl;i++)
     {
      if(strcmp(vtab[i].vname,ident) == 0)
	{
	 *pos = i;
	 return(0);
	}
     }
*pos = ++vl;
if (vl > maxvar) return(EDIALC);
strcpy(vtab[vl].vname,ident);
return(1);
} /* end of module setvar  */


int setstr(char *ident, int *pos)
{
 int i = 0;
 while ((ident[i] != ' ') && (ident[i] != 0) && (i < 8)) i++;
 ident[i] = 0;
 for (i=0;i<=sl;i++)
     {
      if(strcmp(stab[i].sname,ident) == 0)
	{
	 *pos = i;
	 return(0);
	}
     }
*pos = ++sl;
if (sl > maxstr) return(EDIALC);
strcpy(stab[sl].sname,ident);
return(1);
} /* end of module setstr  */

int valsep(char tsep, int *tpr)
{
 int i=0;
 while(sep[i].sepkey != '_')
      {
       if(sep[i].sepkey == tsep)
	     {
	      *tpr = sep[i].prior;
	      return(0);
	     }
       i++;
      }
 return(1);
} /* end of valsep */

int popop()
{
 if(((opst[op].opcode == 'e') && (dp<0)) ||
    ((opst[op].opcode != 'e') && (dp<1))) return EDIALC;
 switch (opst[op].opcode)
	{
	 case 'e':
		  dstack[dp] = -dstack[dp];
		  dp++;
		  break;
	 case '+':
		  dstack[dp-1] = dstack[dp-1] + dstack[dp];
		  break;
	 case '-':
		  dstack[dp-1] = dstack[dp-1] - dstack[dp];
		  break;
	 case '*':
		  dstack[dp-1] = dstack[dp-1] * dstack[dp];
		  break;
	 case '/':
		  dstack[dp-1] = dstack[dp-1] / dstack[dp];
		  break;
	 case '^':
		  dstack[dp-1] = pow((double)dstack[dp-1] ,(double)dstack[dp]);
		  break;
	 case '!':
		  dstack[dp] = (dstack[dp]==0.0) ? 1.0 : 0.0;
		  dp++;
		  break;
	 case '|':
		  dstack[dp-1] = (dstack[dp-1] || dstack[dp]) ? YES : NO;
		  break;
	 case '&':
		  dstack[dp-1] = dstack[dp-1]*dstack[dp];
		  break;
	 case '>':
		  dstack[dp-1] = (dstack[dp-1] > dstack[dp]) ? YES : NO;
		  break;
	 case '<':
		  dstack[dp-1] = (dstack[dp-1] < dstack[dp]) ? YES : NO;
		  break;
	 case '=':
		  dstack[dp-1] = (dstack[dp-1] == dstack[dp]) ? YES : NO;
		  break;
	 case '#':
		  dstack[dp-1] = (dstack[dp-1] != dstack[dp]) ? YES : NO;
		  break;
	 case '?':
		  dstack[dp-1] = (dstack[dp-1] <= dstack[dp]) ? YES : NO;
		  break;
	 case '$':
		  dstack[dp-1] = (dstack[dp-1] >= dstack[dp]) ? YES : NO;
		  break;
	 default:
		  return(1);
	}
 dp--;
 op--;
 return(0);
}

int scanner(char *sch, char *identif, float *value)
{
static int i=0;  /* Index in the input line */
int j=0;
int k;
int typeident=ENDSTR;
//float pot;
/* Reset after an error */
if(sch[0]=='#') {i = 0; return(0);}

/* Skipping spaces! */
while (isspace(sch[i])) i++;
/* Upper or lower case letters -> identifier */
if(isalpha(sch[i]))
  {
   if(j==0) typeident = IDENTIF;
   do
    {
     identif[j++] = sch[i++];
     if ( j >= 8 ) break;	     /* Identifier length exceeds */
    }
   while(isalnum(sch[i]));
   identif[j] = '\0';
   while (isspace(sch[i])) i++;
   /* Is it name of text variable */
   if(setstr(identif,&k) == 0)
     {
      typeident = TEXTVAR;
      return (typeident);
     }
   else sl--;
   /* Is it a function name? */
   if(sch[i] == '(')
     {
      i++;
      /* stdfunc() Assigned functions number into dstack */
      /* We are looking for sequence number of a function from number 0 */
      if(stdfunc(identif,0) == YES)
	    {
	     typeident = SFUNC;
	     return(typeident);
	    }
     }
   return (typeident);
  }
/* Is it text? */
if(sch[i] == '"')
  {
   i++;
   typeident = FTEXT;
   /* Loading text in textbuf  */
   j=0;
   do
     {
      textbuf[j++] = sch[i++];
      if ( j >= MAXTXTLN ) return(SCANERR);  /* Надхвърля дължина на буфер */
     }
   while(sch[i] != '"');
   textbuf[j] = '\0';
   i++;
   if(typeident != FTEXT)
     { while ((isspace(sch[i])) || (sch[i] == ',')) i++; }
  }
/* Is it digit? */
if((isdigit(sch[i])) || (sch[i]=='.'))
  {
   *value = (float )atof(&sch[i]);
   /* To move the pointer to the end of the number */
   while (isdigit(sch[i])||(sch[i]=='.')) i++;
   while (isspace(sch[i])) i++;
   if((sch[i]=='e')||(sch[i]=='E'))
     {
      i++;
      while (isspace(sch[i])) i++;
      if((sch[i]=='+')||(sch[i]=='-')) i++;
      while (isdigit(sch[i])) i++;
     }
   typeident = NUMM;
   return (typeident);
  }
/* Is it separator? */
if(issep(sch[i],(char *)"+-*/^()=,<>#?$|&!"))
  {
   typeident = SEP;
   identif[j++] = sch[i++];
   identif[j++] = '\0';
   return(typeident);
  }
/* Whether it is the end of the string or comment */
if((sch[i]=='\0') || (sch[i]=='%'))
  {
   typeident = ENDSTR;
   i = 0;
   return(typeident);
  }
 /* Error! */
 typeident = SCANERR;
 i++;
 return(typeident);
}


int exsfun(char *sch)
{
 int i;

 if(opst[op].opcode == 'f')
    i = dstack[dp-1];

 switch (i)
   {
	case 0:
	       dstack[dp-1] = exp((double)dstack[dp]);
	       break;
	case 1:
	       dstack[dp-1] = log((double)dstack[dp]);
	       break;
	case 2:
	       dstack[dp-1] = log10((double)dstack[dp]);
	       break;
	case 3:
	       dstack[dp-1] = sqrt((double)dstack[dp]);
	       break;
	case 4:
	       dstack[dp-1] = sin((double)dstack[dp]);
	       break;
	case 5:
	       dstack[dp-1] = cos((double)dstack[dp]);
	       break;
	case 6:
	       dstack[dp-1] = tan((double)dstack[dp]);
	       break;
	case 7:
	       if ( tan((double)dstack[dp]) == 0.0 ) dstack[dp-1] = FLT_MAX;
	       else dstack[dp-1] = 1.0/tan((double)dstack[dp]);
	       break;
	case 8:
	       dstack[dp-1] = asin((double)dstack[dp]);
	       break;
	case 9:
	       dstack[dp-1] = acos((double)dstack[dp]);
	       break;
	case 10:
	       dstack[dp-1] = atan((double)dstack[dp]);
	       break;
	case 11:   /* abs function */
	       dstack[dp-1] = (dstack[dp] < 0.0) ? -dstack[dp] : dstack[dp];
	       break;
	case 12:   /* pmp function */
           dstack[dp-1] = pmp(dstack[dp]);
           break;
	default:
		   return(NO);
   }
 dp--;
 return(YES);
}

int fcerror(int msgnum)
{
 static char *msg[] = {
		(char *)"ERR 0: Unknown error!",
        (char *)"ERR 1: Wrong left part!",
        (char *)"ERR 2: Too many variables!",
		(char *)"ERR 3: Missing symbol =",
		(char *)"ERR 4: Data Stack Overflow!",
		(char *)"ERR 5: New variable on the right side!",
		(char *)"ERR 6: Syntax error!",
		(char *)"ERR 7: Incorrect lexical unit!",
		(char *)"ERR 8: Semantic error!",
		(char *)"ERR 9: Insufficient data!",
		(char *)"ERR 10: Incorrect or unknown standard function!"
		      };
 float dummypar = 0.0;
 char seps[]="#\0";

 scanner( seps, seps, &dummypar);
 if (msgnum < 0) return -1;
 if (errdeli != 0) vl--;   /* On error-must be removed variable */
 printf("\n%s",msg[msgnum]);
 return 0;
}
/* Whether it is a standard function? Look up in the table */
int stdfunc(char *ident, int pos)
{
 static char *sfun[] = {
               (char *)"exp",
		       (char *)"log",
		       (char *)"log10",
		       (char *)"sqrt",
		       (char *)"sin",
		       (char *)"cos",
		       (char *)"tan",
		       (char *)"cot",
		       (char *)"asin",
		       (char *)"acos",
		       (char *)"atan",
		       (char *)"abs",
		       (char *)"pmp",
		       NULL
		      };

 int i;
 for (i=pos; sfun[i]; i++) //  i<MAXFUNC;
     {
      if(strcmp(sfun[i],&ident[0]) == 0)
	    {
	     dstack[++dp] = i;
         /* Do not exceed MAXDATA */
	     return(YES);
        }
     }
 return(NO);
}

/* Search a separator in a string */
int issep(char ch, char *sep_str)
{
 char *s;
 for (s=sep_str; *s != 0; s++)
     if(*s == ch) return(YES);
 return(NO);
}
int settvar(char *ident, char *value, int *pos)
{
 int i = 0;

 for (i=0;i<=sl;i++)
     {
      if(strcmp(stab[i].sname,ident) == 0)
	    {
	     *pos = i;
	     return(0);
	    }
     }
*pos = ++sl;
if (sl > maxvar) return(EDIALC);
strcpy(stab[sl].sname,ident);
strcpy(stab[sl].sval,value);
return(1);
} /* end of module settvar  */

/* Skipping spaces and replace the two-character separators with one-character */
void linepack(char *t, char *inp)
{
 char *p;
 int j;
 for(j = 0, p = inp; *p; p++)
    if(*p != ' ') t[j++] = *p;
 t[j] = 0;
 j = 0; p = t;
  do{
     if((strncmp(&t[j], "<=",2) == 0)||(strncmp(&t[j], "=<",2) == 0))
       { *p = '?'; p++; j += 2; }
     else{
          if((strncmp(&t[j], ">=",2) == 0)|| (strncmp(&t[j], "=>",2) == 0))
            { *p = '$'; p++; j += 2; }
          else{
               if(strncmp(&t[j], "!=",2) == 0)
                 { *p = '#'; p++; j += 2; }
               else{
                    if(strncmp(&t[j], "||",2) == 0)
                      { *p = '|'; p++; j += 2; }
                    else{
                         if(strncmp(&t[j], "&&",2) == 0)
                           { *p = '&'; p++; j += 2; }
                         else
                           { *p = t[j]; p++; j++; }
                        }
                   }
              }
         }
    }
 while(t[j]);
 *p = 0;
}

/* Function to calculate the formulas! */
/* ----------------------------------- */
int main()
{
    //int i;
    char buff[1024];
/* Taking memory for variables and labels  */
if ( vtab == NULL)
   {
    vtab = (var *)calloc(maxvar, sizeof(var));
    stab = (str *)calloc(maxstr, sizeof(str));
    dstack=(float *)calloc(MAXDATA, sizeof(float));
   }

//      textbuf[0]='a';
//      textbuf[1]='=';
//      scanf("%s",&textbuf[2]);
while(true){
      scanf("%s",textbuf);
      strcpy(buff,"a=");
      strcat(buff, textbuf);
      strcpy(textbuf, buff);
      //if(strcmp(textbuf, "end")==0)break;
      fcerror(gcalc(textbuf));
      if(ires>=0)
         printf("%d\n",(int )vtab[ires].vval);
      break;
}
   return 0;
}
/* End of File */
