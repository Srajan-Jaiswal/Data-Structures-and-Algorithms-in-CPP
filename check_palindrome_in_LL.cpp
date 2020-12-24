#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
class node
{
	string  data;
	node* next;
public:
	node(string d)
	{
		d=data;
		next=NULL;
	}
};
void ins_tail(node* head, string  data)
{
	if(head==NULL)
	{
		return new node(data);
	}
	node* tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
    tail->next= new node(data);
}
bool check_palindrome(node* head)
{
	stack<string> stk;
	node* temp=head;
	stk.push(temp);
	while(temp!=NULL)
	{
		temp=temp->next;
		stk.push(temp->data);
	}
	while(temp!=NULL)
	{
		temp=temp->next;
		string s=stk.top();
		stk.pop(s);
		if(s==temp->data)
		{
			return true;
		}
		else
			return false;
	}
}
// for printing the linked list
void print_LL(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"-->>";
        head=head->next;
	}
}
int main()
{
	node* head=NULL;
	ins_tail(head,"R");
    ins_tail(head,"A");
    ins_tail(head,"D");
    ins_tail(head,"A");
    ins_tail(head,"R");
    print_LL(head);
    return 0;
}

