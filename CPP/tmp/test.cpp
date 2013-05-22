#include <iostream> 
using namespace std;

int count(const string& s, char c);

int main(){
	string str;
	char c;	
	int co ; 

	std :: cout << "Enter a string: \n";
	std :: cin >> str;
	std :: cout << "Enter a char: \n";
	std :: cin >> c;
	co  = count(str,c);
	std :: cout << "Counter: " << co << '\n';

}

int count(const string& s, char c){

	int n = 0;
	string :: const_iterator i = find(s.begin(),s.end(),c);
	while(i!=s.end()){
		++n;
		i = find(i+1,s.end(),c);
	}
	return n;
}
