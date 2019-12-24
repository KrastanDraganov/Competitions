#include<iostream>
int main(){
	int num;
	std::cin>>num;
	std::cout<<std::boolalpha<<(bool)(num & 1)<<'\n';
return 0;
}