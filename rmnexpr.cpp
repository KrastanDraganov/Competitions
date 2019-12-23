#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
double rpn[10005];
string s;
int rpn_size=0;
double roman_to_number(char l){
	switch(l){
		case 'I': return 1; break;
		case 'V': return 2; break;
		case 'X': return 5; break;
		case 'L': return 50; break;
		case 'C': return 100; break;
		case 'D': return 500; break;
		case 'M': return 1000; break;
		default: return 0; break;
	}
}
double sign_encoding(char sign){
	switch(sign){
		case '+': return -1; break;
		case '-': return -2; break;
		case '*': return -3; break;
		case '/': return -4; break;
		case '(': return -5; break;
		case ')': return -6; break;
	}
}
int priority(char sign){
	if(sign=='+' or sign=='-') return 1;
	if(sign=='/' or sign=='*') return 2;
	if(sign=='(') return 0;
}
void to_rpn(){
	stack<char>shunting_yard;
	for(int i=0;i<s.size();i++){
		if(s[i]==')'){
			while(shunting_yard.top()!='('){
				rpn[rpn_size]=sign_encoding(shunting_yard.top());
				rpn_size++;
				shunting_yard.pop();
			}
			shunting_yard.pop();
		}else if(s[i]=='('){
			shunting_yard.push(s[i]);
		}else if(s[i]=='+' or s[i]=='-' or s[i]=='/' or s[i]=='*'){
			while(!shunting_yard.empty() and (priority(shunting_yard.top())>priority(s[i]))){
				rpn[rpn_size]=shunting_yard.top();
				rpn_size++;
				shunting_yard.pop();
			}
			shunting_yard.push(s[i]);
		}else{
			double number=0.0;
			while(i<s.size() and roman_to_number(s[i])>0){
				if(roman_to_number(s[i+1])>roman_to_number(s[i])){
					number+=roman_to_number(s[i+1])-roman_to_number(s[i]);
					i+=2;
				}else{
					number+=roman_to_number(s[i]);
					i++;
				}
			}
			i--;
			rpn[rpn_size]=number;
			rpn_size++;
		}
	}
}
double print_result(){
	stack<double>result;
	for(int i=0;i<rpn_size;i++){
		if(rpn[i]>=0){
			result.push(rpn[i]);
		}else{
			double x=result.top();
			result.pop();
			double y=result.top();
			result.pop();
			if(rpn[i]==-1) result.push(y+x);
			if(rpn[i]==-2) result.push(y-x);
			if(rpn[i]==-3) result.push(y*x);
			if(rpn[i]==-4) result.push(y/x);
		}
	}
	return result.top();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	to_rpn();
	cout<<print_result()<<endl;
return 0;
}
