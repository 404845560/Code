#include <iostream>
using namespace std;

/*
141. Linked List Cycle 

Given a linked list, determine if it has a cycle in it.
*/
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {
	 }
 };

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (NULL == head) return false;
		if (NULL == head->next) return false;
		ListNode *t1 = head;
		ListNode *t2 = head->next;
		while (t2){
			if (t2 == t1) return true;
			else{
				t1 = t1->next;
				t2 = t2->next; //t2ÒÆ¶¯Á½²½
				if (t2) t2 = t2->next;
				else break;
			}
		}
		return false;
	}
};
int main(){
	return 0;
}