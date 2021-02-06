#include "list.h"

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
        if (iter == before)
        {
            (*head) = inserted_elem;
            inserted_elem->next = iter;
        }
        else
        {
            while (iter->next != before and iter->next != NULL)
            {
                iter = iter->next;
            }
            inserted_elem->next = iter->next;
            iter->next = inserted_elem;
            if (*tail == iter)
            {
                (*tail) = inserted_elem;
            }
        }
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
void free_list(struct node **head, struct node **tail)
{
    if (*head == NULL)
    {
        return;
    }
    else
    {
        if (*head == *tail)
        {
            delete *head;
        }
        else
        {
            struct node *left = (*head), *right = left->next;
            while (right != NULL)
            {
                delete left;
                left = right;
                right = right->next;
            }
            delete left;
        }
        *head = NULL;
        *tail = NULL;
    }
}
