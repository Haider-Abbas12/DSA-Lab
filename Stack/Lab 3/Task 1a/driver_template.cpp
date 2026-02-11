#include <iostream> 
#include "stack.cpp" 
using namespace std;

int main() {

Stack<int> IntStack(10); 
Stack<float> FloatStack(5); 
Stack<char> CharStack(8);
int intData; 
float floatVal; 
char charVal;

cout << "Testing Integer Stack:"<< endl; 
for (int i= 1; i <= 5; i++) 
{
    IntStack.Push(i * 10);
    cout << "Pushed: "<< i * 10 << endl;
}

cout << "\nPopping from Integer Stack:"<< endl; 
while (!IntStack.IsEmpty()) 
{
    IntStack.Pop(intData);
    cout << "Popped: "<< intData << endl;
}

// Test float stack
cout << "\nTesting Float Stack:"<< endl; 
FloatStack.Push(3.1415927); 
FloatStack.Push(2.7182818);
cout << "Popping from Float Stack:"<< endl; 
FloatStack.Pop(floatVal);
cout << "Popped: "<< floatVal << endl; 
FloatStack.Pop(floatVal);
cout << "Popped: "<< floatVal << endl;
// Test character stack (string reversal example)
cout << "\nTesting Character Stack (String Reversal):"<< endl; 
char str[] = "STACK";
cout << "Original string: "<< str << endl;
// Push characters onto stack
for (int i= 0; str[i] != '\0'; i++) 
{
    CharStack.Push(str[i]);
}

// Pop characters to reverse string cout << "Reversed string: ";
while (!CharStack.IsEmpty()) 
{  
    CharStack.Pop(charVal); 
    cout << charVal;
}
cout <<	endl;
return 0;
}