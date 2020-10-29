#include <afxwin.h> 
#include <iostream>

int main()
{
	using namespace std;
	CString str = _T("Hello, World!");
	cout << "Hello, World!" << endl;
	wcout << (LPCTSTR)str << endl;
	return 0;
}