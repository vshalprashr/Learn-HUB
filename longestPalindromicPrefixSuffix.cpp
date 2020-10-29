#include <iostream>
#include <algorithm>
using namespace std;

string longestpp(string s){
	// cout << s << endl;
	int n = s.length();
	string revs = s;
	reverse(revs.begin(), revs.end());

	s += "$"+revs;
	// cout << 1 << endl;
	int arr[s.length()] = {0};
	for(int i=0,j=1 ; j<n && i<n ; j++){
		if(s[i]==s[j]){
			arr[j] = ++i;
		}
		else if(arr[i]==0){
			arr[j] = 0;
			i = 0;
		}
		else{
			i = arr[i]-1;
			j--;
		}
	}
	// cout << 2 << endl;
	for(int j=0, i=n+1 ; i<=2*n ; i++){
		if(s[i]==s[j]){
			arr[i] = ++j;
		}
		else if(arr[j]==0){
			arr[i] = 0;
			j = 0;
		}
		else{
			j = arr[j]-1;
			i--;
		}
	}
	// cout << 3 << endl;
	// for(int i=0 ; i<=2*n ; i++)
	// 	cout << arr[i] << " ";
	return s.substr(0,arr[2*n]);
}

string longestps(string s){
	reverse(s.begin(), s.end());
	return longestpp(s);
}

int main(int argc, char const *argv[])
{
	string str;	cin >> str;
	cout << "input done" << endl;
	string lpp = longestpp(str);
	cout << lpp << endl;
	string lps = longestps(str);
	cout << lps << endl;

	lps += lpp;
	

	return 0;
}