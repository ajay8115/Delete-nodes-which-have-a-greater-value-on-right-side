// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *pre = NULL;
        Node *cur = head;
        Node *next = head->next;

        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    Node *compute(Node *head)
    {
        head = reverse(head);
        Node *pre = head;
        Node *cur = head->next;

        int maxi = head->data;
        while (cur)
        {
            if (cur->data >= maxi)
            {
                maxi = cur->data;
                pre = pre->next;
                cur = cur->next;
            }
            else
            {
                pre->next = cur->next;
                cur = pre->next;
            }
        }

        return reverse(head);
    }
};