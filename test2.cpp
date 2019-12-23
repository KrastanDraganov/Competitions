#include <iostream> 
#include <vector> 
using namespace std;
// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    bool j=false;
    if(r==3 and key==79) j=true;
	while (r - l > 1) { 
		int m = l + (r - l) / 2; 
		if (v[m] >= key) {
            if(j) cout<<"r ";
			r = m; 
        }else{
            if(j) cout<<"l ";
			l = m;
        } 
        if(j) cout<<"bs "<<m<<" "<<l<<" "<<r<<" "<<v[mid]<<endl;
	} 

	return r; 
} 

int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
	if (v.size() == 0) 
		return 0; 

	std::vector<int> tail(v.size(), 0); 
	int length = 1; // always points empty slot in tail 

	tail[0] = v[0]; 
	for (size_t i = 1; i < v.size(); i++) { 

		// new smallest value 
		if (v[i] < tail[0]){
			tail[0] = v[i]; 
            cout<<"a ";
		// v[i] extends largest subsequence 
        }else if (v[i] > tail[length - 1]){ 
			tail[length++] = v[i]; 
            cout<<"b ";
		// v[i] will become end candidate of an existing 
		// subsequence or Throw away larger elements in all 
		// LIS, to make room for upcoming grater elements 
		// than v[i] (and also, v[i] would have already 
		// appeared in one of LIS, identify the location 
		// and replace it) 
        }else{
            int new_ind=CeilIndex(tail, -1, length - 1, v[i]);
            cout<<"c "<<new_ind<<" "<<length-1<<" "<<v[i]<<" ";
			tail[new_ind] = v[i];
        } 
        cout<<length<<endl;
	} 

	return length; 
} 

int main() 
{ 
    vector<int>v;
	int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
	cout << LongestIncreasingSubsequenceLength(v) << '\n'; 
	return 0; 
} 
