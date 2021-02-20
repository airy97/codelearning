#include <afxwin.h> 
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	ListNode *head = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	head->next = n2;
	n2->next = n3;

	vector<int> vet;
	while (head != NULL)
	{
		vet.push_back(head->val);
		head = head->next;
	}
	vector<int> res;
	for (int i = 0; i < vet.size(); ++i)
	{
		res.push_back(vet.at(vet.size() - i - 1));
	}

	return 0;
}