/*
TASK:rebus
LANG:C++
*/

#include <iostream>
#include <string>

using namespace std;

int cnt (int a);

int main() {
    // reading input data in string eq
    string eq;
    cin>>eq;
	for (int a = 0; a < 10; a++) //generating all posible values for character  A 
    	for (int b = 0; b < 10; b++) //generating all posible values for character  B
        	for (int c = 0; c < 10; c++) //generating all posible values for character  C
            {
				if (a == b || a == c || b == c) continue; //incorrect case - with two diferrent characters is present one digit 
				int Num1 = 0, Num2 = 0, Num3 = 0, br = 0;
				// in A generates first number
				// in B generates second number
				// in C generates third number
				// num indicate what number must be generate
					for (int i = 0; i < eq.length(); i++) //replace characters with digits
                    {
						if (eq[i] == '+' || eq[i] == '=') //one number is ended
                        {
							br++;
							continue;
                        }
						// chacter establish a connection with digit 
                        int p = 0;
						if (eq[i] == 'A') p = a;
						if (eq[i] == 'B') p = b;
						if (eq[i] == 'C') p = c;
			            //generate number
						if (br == 0) Num1 = Num1*10 + p;
						if (br == 1) Num2 = Num2*10 + p;
						if (br == 2) Num3 = Num3*10 + p;
					}
				if (Num1+Num2 == Num3) // verification expresion
                   if (cnt(Num1)+cnt(Num2)+cnt(Num3)+2==eq.length()) //verification useless zero
                      {
                      cout<<Num1<<'+'<<Num2<<'='<<Num3<<endl;
				      return 0;
				      }
                    
            }
    cout <<"No answer.\n";
	return 0;
}

int cnt (int a)
{
    int brc=0;
    do {
        brc++;
        a/=10;
        } while (a);
    return brc;
}
