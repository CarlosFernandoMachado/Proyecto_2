#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	string a;
	a += "H";
	a += "O";
	a += "L";
	a += "A";
	cout << a << "\n";
	a = "";
	cout << a << "\n";
	return 0;
}
