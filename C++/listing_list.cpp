#include <iostream>
#include <assert.h>

using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node *create_elem(int elem)
{
    struct node *returned = new struct node();
    if (returned == NULL)
    {
        return NULL;
    }
    returned->val = elem;
    returned->next = NULL;
    return returned;
};

void push_front(struct node **head, struct node **tail, int elem)
{
    struct node *inserted_elem = create_elem(elem);
    if (inserted_elem == NULL)
        return;
    if (*head == NULL)
    {
        (*head) = inserted_elem;
        (*tail) = inserted_elem;
    }
    else
    {
        inserted_elem->next = (*head);
        (*head) = inserted_elem;
    }
}

void push_back(struct node **head, struct node **tail, int elem)
{
    struct node *inserted_elem = create_elem(elem);
    if (inserted_elem == NULL)
    {
        return;
    }
    if ((*head) == NULL)
    {
        (*head) = inserted_elem;
        (*tail) = inserted_elem;
    }
    else
    {
        (*tail)->next = inserted_elem;
        (*tail) = inserted_elem;
    }
}

void insert_before(struct node **head, struct node **tail,
                   struct node *before, int elem)
{
    struct node *inserted_elem = create_elem(elem);
    if (inserted_elem == NULL)
        return;
    struct node *iter = (*head);
    if (iter == NULL)
    {
        (*head) = inserted_elem;
        (*tail) = inserted_elem;
    }
    else
    {
        while (iter->next != before and iter->next != NULL)
        {
            iter = iter->next;
        }
        inserted_elem->next = iter->next;
        iter->next = inserted_elem;
    }
}

void print_list(struct node *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

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
