//#include <afxwin.h> 
#include "Test.h"

int main(int argc, char* argv[])
{
	auto starttime = clock();
	Test::test_MyBinarySearchTree();
	auto runtime = static_cast<double>(clock() - starttime) / CLOCKS_PER_SEC;
	std::cout << "\nRun time = " << runtime * 1000.0 << " ms. " << std::endl;
	system("pause");
}



