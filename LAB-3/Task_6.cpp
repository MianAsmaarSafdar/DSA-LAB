#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int d)
  {
      data=d;
      next=NULL;
  }
};
class List{
  private:
  Node* head;
  public:
  List()
  {
      head=NULL;
  }
  void CreateNode(int val)
  {
      Node* newNode=new Node(val);
      if(head==NULL)
      {
          head=newNode;
          return;
      }
      else
      {
          newNode->next=head;
          head=newNode;
      }
  }
  void Display()
  {
      Node* temp=head;
      while(temp!=NULL)
      {
          cout<<temp->data<<" ";
          temp=temp->next;
      }
  }
};
int main()
{
    List ll;
    ll.CreateNode(1);
    ll.CreateNode(2);
    ll.CreateNode(3);
    ll.CreateNode(4);
    ll.Display();
    
        return 0;
}