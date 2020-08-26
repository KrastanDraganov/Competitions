//Only 60/100 points;

#include<iostream>
#include<string>
#include<stack>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=(1<<10)+3;
bool repaired[MAXN];

int value(char letter){ 
    switch(letter){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return -1;
	} 
}

int priority(string sign){
	if(sign=="*" or sign=="/"){
		return 2;
	}else if(sign=="+" or sign=="-"){
		return 1;
	}else{
		return 0;
	}
}

vector<string> repair(vector<string> rpn, int ind, int limit){
	stack<int> signs;
	for(int i=ind;i<rpn.size() and (rpn[i][0]<'0' or rpn[i][0]>'9');++i){
		if(rpn[i]=="+" or rpn[i]=="-"){
			signs.push(i);
		}
		repaired[i]=true;
	}
	bool change=false;
	while(!signs.empty()){
		int curr=signs.top();
		signs.pop();
		if(signs.size()>=limit){
			continue;
		}
		if(change){
			rpn[curr]=(rpn[curr]=="+" ? "-" : "+");
		}
		if(rpn[curr]=="-"){
			change=!change;
		}
	}
	return rpn;
}

vector<string> to_rpn(string expression){
	vector<string> res;
	stack<string> yards;
	int num=0;
	for(int i=0;i<expression.size();++i){
		string curr(1,expression[i]);
		if(value(expression[i])!=-1){
			double num=0;
			while(i<expression.size() and value(expression[i])!=-1){
				double curr_value=value(expression[i]);
				if(i<expression.size()-1){
					double next_value=value(expression[i+1]);
					if(next_value>curr_value){
						num+=next_value-curr_value;
						++i;
					}else{
						num+=curr_value;
					}
				}else{
					num+=curr_value;
				}
				++i;
			}
			--i;
			res.push_back(to_string(num));
		}else if(curr==")"){
			while(yards.top()!="("){
				res.push_back(yards.top());
				yards.pop();
			}
			yards.pop();
		}else if(curr=="("){
			yards.push("(");
		}else{
			while(!yards.empty() and priority(yards.top())>priority(curr)){
				res.push_back(yards.top());
				yards.pop();
			}
			yards.push(curr);
		}
	}
	while(!yards.empty()){
		res.push_back(yards.top());
		yards.pop();
	}
	return res;
}

double calc_res(vector<string> rpn){
	stack<double> res;
	for(int i=0;i<rpn.size();++i){
		string curr=rpn[i];
		cout<<curr<<" "<<(res.empty() ? -1 : res.top())<<endl;
		if(curr[0]>='0' and curr[0]<='9'){
			double num=0;
			for(int i=0;i<curr.size() and curr[i]>='0' and curr[i]<='9';++i){
				num=10*num+curr[i]-'0';
			}
			res.push(num);
		}else{
			if(!repaired[i]){
				rpn=repair(rpn,i,res.size());
				curr=rpn[i];
			}
			double num1,num2;
			if(!res.empty()){
				num1=res.top();
				res.pop();
			}else{
				num1=0;
			}
			if(!res.empty()){
				num2=res.top();
				res.pop();
			}else{
				if(curr=="-"){
					num2=2*num1;
				}else{
					num2=0;
				}
			}
			if(curr=="+"){
				num2+=num1;
			}else if(curr=="-"){
				num2-=num1;
			}else if(curr=="*"){
				num2*=num1;
			}else{
				num2/=num1;
			}
			res.push(num2);
		}
	}
	return res.top();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string expression;
	cin>>expression;
	
	vector<string> rpn=to_rpn(expression);
	cout<<calc_res(rpn)<<endl;
return 0;
}