#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *oddEvenList(struct ListNode *head){
    struct ListNode *list1, *list2, *walker1, *walker2;

    list2 = list1 = walker1 = walker2 = NULL;
    
    if(!head)return head;
    
    list1 = head;
    list2 = head-> next;
    if(!list2)return head;

    walker1 = list1;
    walker2 = list2;

    while(walker1 && walker2){
        walker1-> next = walker2-> next;
        if(walker1-> next)
            walker1 = walker1-> next;
        else 
            break;

        if(!walker1)break;
        walker2 = walker2-> next = walker1-> next;
    }

    walker1-> next = list2;

    return list1;
}

