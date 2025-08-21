#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};



    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*> pq;

     
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next) pq.push(curr->next);
        }

        return dummy.next;
    }

ListNode* createList(vector<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<ListNode*> lists;
    lists.push_back(createList({1,4,5}));
    lists.push_back(createList({1,3,4}));
    lists.push_back(createList({2,6})); 
    
    ListNode* merged = mergeKLists(lists);
    printList(merged);  
    return 0;
}
