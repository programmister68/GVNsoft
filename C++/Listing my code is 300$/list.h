#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node *create_elem(int elem);
void push_front(struct node **head, struct node **tail, int elem);
void push_back(struct node **head, struct node **tail, int elem);
void insert_before(struct node **head, struct node **tail,
                   struct node *before, int elem);
void print_list(struct node *head);
void free_list(struct node **head, struct node **tail);

#endif // LIB_H_INCLUDED
