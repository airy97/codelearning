//#include <afxwin.h> 
#include "Test.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
string reverseWords(string s) {
	string ans = "";
	while (s.back() == ' ')
		s.pop_back();
	int i = s.size() - 1;
	int j = i;
	while (i >= 0)
	{
		while (i >= 0 && s[i] != ' ')
			--i;
		ans.append(s.substr(i + 1, j - i) + " ");
		while (i >= 0 && s[i] == ' ')
			--i;
		j = i;
	}

	return ans;
}
int main(int argc, char* argv[])
{
    cout << reverseWords("  hello world!  ") << endl;
    return 0;
}



