#include <iostream>
#include "list.h"
#include <assert.h>

using namespace std;


int main()
{
    struct node *head = NULL, *tail = NULL;
    push_front(&head, &tail, 10);
    assert(head->val == 10);
    push_front(&head, &tail, 20);
    assert(head->val == 20);
    push_front(&head, &tail, 30);
    assert(head->val == 30);
    push_back(&head, &tail, 40);
    assert(tail->val == 40);
    push_back(&head, &tail, 50);
    assert(tail->val == 50);
    push_back(&head, &tail, 60);
    assert(tail->val == 60);
    print_list(head);
    struct node *current = head->next->next->next;
    insert_before(&head, &tail, current, 11);
    print_list(head);
    insert_before(&head, &tail, NULL, 21);
    print_list(head);
    current = create_elem(31);
    insert_before(&head, &tail, current, 41);
    print_list(head);
    return 0;
}

