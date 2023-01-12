#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;

struct node
{
    int data;
    node* next;
};
// 1.
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

// 2.
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
// 3.
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
// 4.
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
// 5.
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
// 6.
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
// 7.
// #################################################################################

struct node* reverse_list(struct node* &head)
{
    if(head == NULL ||head->next != NULL)
    {
        return head;
    }

    struct node* prev = NULL;
    struct node* curr = head;
    struct node* forward = NULL;
    
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// 8.
// #################################################################################

bool isloop(struct node* &head)
{
    if(head == NULL)
    {
        return false;
    }
    map<struct node *,bool>visited;
    struct node* temp = head;
    while (temp != NULL )
    {
        if(visited[temp] == true)
        {
            cout<<"present on:"<<temp->data;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
    
}

// 9.
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
// 10.
// #################################################################################

struct node* remove_duplicate_from_sorted(struct node* &head)
{
    if(head == NULL)
    {
        return head;
    }
    else
    {
        struct node* temp = head;
        while (temp != NULL)
        {
            if(temp->next != NULL && temp->data == temp->next->data )
            {
                struct node* node_to_delete = temp->next;
                temp->next =temp->next->next;
                free(node_to_delete);

            }
            else
            {
                temp = temp->next;
            }
            
        }
        
    }

    return head;
}
// 11.
// #################################################################################

struct node* solve(struct node* &head1,struct node* head2)
{
    struct node* curr1 = head1;
    struct node* next1  = curr1->next;
    struct node* curr2 = head2;
    struct node* next2 = curr2->next;
    while(next1 != NULL && curr2 != NULL)
    {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            
            curr1->next= curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL)
            {
                curr1->next = curr2;
                return head1;
            }

        }
    }

    return head1;
}
struct node* merge_two_sorted(struct node* &head1,struct node* &head2)
{
    if(head1 == NULL)
    {
        return head2;
    }

    if(head2 == NULL)
    {
        return head1;
    }

    if(head1->data <= head2->data)
    {
        return solve(head1,head2);
    }
    else
    {
        return solve(head2,head1);
    }

}

// #################################################################################



// #################################################################################
int main()
{
    struct node *head = NULL;
    struct node *head2 = NULL;//working properly
    // append(head2,12);//working properly
    // append(head2,2);// working properly
    append(head,4);// working properly
    append(head,2);// working properly
    append(head,3);// working properly
    append(head,4);// working properly
    append(head,3);// working properly
    // append(head,13);// working properly
    // insert_as_first(head,21);  // working properly
    // delete_at_last(head); // working properly
    // print_list(head); // working properly
    cout<<endl;
    // middle_element(head); // working properly
    // cout<<iscircular(head); //working properly
    // cout<<(isloop(head));
    // struct node * tempp = remove_duplicate_from_sorted(head);
    // print_list(tempp);
    // struct node* temppp = merge_two_sorted(head,head2);
    // print_list(temppp);

    
    







































}