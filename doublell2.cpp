#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;
 
class double_llist
{
    public:
        void create_list(int value);
        void display_dlist();
        void reverse();
        double_llist()
        {
            start = NULL;  
        }
};
 
int main()
{
    int choice, element, position;
    double_llist dl;
    cout<<endl<<"********************************";
    cout<<endl<<"Operations on Doubly linked list";
    cout<<endl<<"********************************"<<endl;         
    cout<<"1.Create Node\n2.Display\n3.Reverse\n4.Quit"<<endl;
    cout<<"***********************"<<endl;
    while (1) 
    {
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            dl.create_list(element);
            cout<<endl;
            cout<<"***Doubly Linked List Data***\n";
            dl.display_dlist();
            cout<<"\n****************\n";
            break;
            case 5:
            cout<<"***Doubly Linked List Data***\n";
            dl.display_dlist();
            cout<<endl;
            cout<<"\n****************\n";
            break;
        case 2:
            if (start == NULL)
            {
                cout<<"List empty,nothing to reverse"<<endl;
                break;
            }
            dl.reverse();
            cout<<endl;
            cout<<"***Doubly Linked List Data***\n";
            dl.display_dlist();
            cout<<"\n****************\n";
            break;
        case 3:
            if (start == NULL)
            {
                cout<<"List empty,nothing to reverse"<<endl;
                break;
            }
            dl.reverse();
            cout<<endl;
            cout<<"***Doubly Linked List Data***\n";
            dl.display_dlist();
            cout<<"\n****************\n";
            break;
        case 4:
            cout<<"****************\n";
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
            cout<<"****************\n";
        }
    }
    return 0;
}
void double_llist::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
void double_llist::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
void double_llist::reverse()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    cout<<"List Reversed"<<endl; 
}