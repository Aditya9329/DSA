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

int count_nodes(struct node * head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

void middle_element(struct node* head){
    int list_length = count_nodes(head);
    int middle = list_length /2;
    int i = 0;
    while(i != middle)
    {
        head = head->next;
        i++;
    }
    cout<<"middle-element = "<<head->data;

}

// #################################################################################

bool iscircular(struct node * head)
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        struct  node * temp = head->next;
        while (temp !=NULL && temp!=head)
        {
            temp = temp->next;
        }
        if(temp == head)
        {
            return true;
        }
        else
        {
            return false;
        }
        
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
    append(head,10);// working properly
    append(head,11);// working properly
    append(head,20);// working properly
    append(head,30);// working properly
    append(head,35);// working properly
    insert_as_first(head,21);  // working properly
    // delete_at_last(head); // working properly
    // print_list(head); // working properly
    cout<<endl;
    // middle_element(head); // working properly
    // cout<<iscircular(head); //working properly

}