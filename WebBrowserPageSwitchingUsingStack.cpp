/*To facilitate thorough net surfing, any web browser has back and forward buttons that allow the
user to move backward and forward through a series of web pages. To allow the user to move both
forward and backward two stacks are employed. When the user presses the back button, the link to
the current web page is stored on a separate stack for the forward button. As the user moves
backward through a series of previous pages, the link to each page is moved in turn from the back
to the forward stack.
When the user presses the forward button, the action is the reverse of the back button. Now the
item from the forward stack is popped and becomes the current web page. The previous web page
is pushed on the back stack. Simulate the functioning of these buttons using array implementation
of Stack. Also, provide options for displaying the contents of both stacks whenever required.*/ 

//Code:

#include<iostream>
#include<conio.h>
#include<String>
using namespace std;
class Stack
{ public:
int SIZE;
string *arr;
string data;
int pos;
public:
Stack(int size);
bool isEmpty();
bool isFull();
void push(string str);
string pop();
};
Stack :: Stack(int asize)
{
SIZE = asize;
arr = new string[asize];
pos = -1;
}
bool Stack::isEmpty()
{
if(pos == -1)
return true;
return false;
}
bool Stack::isFull()
{
if(pos == SIZE-1)
return true;
return false;
}
void Stack::push(string str)
{
if(isFull())
{
cout<<"Stack is Empty";
return;
}
pos += 1;
arr[pos] = str;
}
string Stack::pop()
{
if(isEmpty())
{
cout<<"Stack is Full";
getch();
return "0";
}
string val;
val = arr[pos];
pos -= 1;
return val;
}
void prev(Stack *prevData,Stack *forwardData)
{
string val = prevData->pop();
forwardData->push(val);
cout<<val<<endl;
}
void forward(Stack *prevData,Stack *forwardData)
{
string val = forwardData->pop();
if(val[0] == '0')
return;
prevData->push(val);
cout<<forwardData->arr[forwardData->pos]<<endl;
}
void display(Stack *prevData,Stack *forwardData)
{
int len = prevData->pos;
cout<<"Previous Stack ";
for(int i = len;i>=0;i--)
cout<<" "<<prevData->arr[i];
cout<<endl;
len = forwardData->pos;
cout<<"Forward Stack ";
for(int i = len;i>=0;i--)
cout<<" "<<forwardData->arr[i];
cout<<endl;
}
int main()
{
int arrSize;
cout<<"Enter Size = ";
cin>>arrSize;
Stack prevData(arrSize);
Stack forwardData(arrSize);
while(1)
{
cout<<"MENU :"<<endl;
cout<<"1. PUSH PREVIOUS STACK"<<endl;
cout<<"2. PUSH FORWARD STACK"<<endl;
cout<<"3. PREVIOUS DATA"<<endl;
cout<<"4. FORWARD DATA"<<endl;
cout<<"5. DISPLAY BOTH STACK"<<endl;
cout<<"6. Exit"<<endl;
int op;
cout<<"Enter Option Number = ";
cin>>op;
int ex = 0;
if(op == 1)
{
string data;
cout<<"Enter Data = ";
cin>>data;
prevData.push(data);
}
else if(op == 2)
{
string data;
cout<<"Enter Data = ";
cin>>data;
forwardData.push(data);
}
else if(op == 3)
{
prev(&prevData,&forwardData);getch();
}
else if(op == 4)
{
forward(&prevData,&forwardData);getch();
}
else if(op == 5)
{
display(&prevData,&forwardData);
}
else if (op == 6)
break;
else
{
cout<<"Wrong Option Selected";getch();
}
}
return 1;
}