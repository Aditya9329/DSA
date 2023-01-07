#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    node* next;
};
// #################################################################################
void append(struct node* &head,int data)
{
    struct node *n =(struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if(head == NULL)
    {
        head = n;
    }
    else
    {
        struct node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

// #################################################################################
void insert_as_first(struct node* &head,int data)
{
    struct node* n =(struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;

    if(head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

// #################################################################################
void delete_at_last(struct node * &head)
{
    if(head == NULL)
    {
        cout<<"list is empty";
    }
    else
    {
        struct node * first = head;
        struct node * second = NULL;
        // struct node * temp = head;
        while (first->next != NULL)
        {
            second = first;
            first = first->next;
        }
        second->next = NULL;
        free(first);
        
    }
}

// #################################################################################
void print_list(struct node* head)
{
    if(head == NULL)
    {
        cout<<"list is empty";
    }
    else
    {
        struct  node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

// #################################################################################

int main()
{
    struct node *head = NULL;
    append(head,10);
    append(head,11);
    append(head,20);
    append(head,30);
    insert_as_first(head,21);
    delete_at_last(head);
    print_list(head);
}