#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		if (str.empty())break;
		cout << "me:" << str << endl;
	}
	cout << "I Love you,My wife!" << endl;
	return 0;
}
