#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
83. Remove Duplicates from Sorted List  QuestionEditorial Solution  My Submissions

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (NULL == head) return NULL;
		ListNode* start = new ListNode(head->val);
		ListNode* end = start;
		ListNode* index = head->next;
		while (index){
			if (index->val != end->val){
				ListNode* tmp = new ListNode(index->val);
				end->next = tmp;
				end = end->next;
			}
			index = index->next;
		}
		return start;

	}
};

int main(){
	return 0;
}