/*
2. Write a menu driven program in C/C++ to implement a Stack using array and perform the
following operations.
    (a) isFull() function to check whether the Stack is full or not.
    (b) isEmpty() function to check whether the Stack is empty or not.
    (c) peek() function to read the stack top element without deleting it.
    (d) push(item) function to insert an element item in the Stack.
    (e) pop() function to read and remove an element from the Stack.
    (f) display() function to display the entire stack.
*/
#include<iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int maxSize;
        int top;
    public:
        Stack(int maxSize):maxSize(maxSize){
            arr = new int[maxSize];
            top = -1;
            cout << "Stack Created.\n\n";
        }
        bool isFull(){
            if (top == maxSize - 1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isEmpty(){
            if (top == -1){
                return true;
            }
            else{
                return false;
            }
        }
        void peek(){
            if (!(isEmpty())){
                cout << "The top element in the stack is: " << arr[top];
            }
            else{
                cout << "\nThe Stack is currently empty.\n";
            }
        }
        void push(int item){
            if (!(isFull())){
                arr[++top] = item;
                cout << "\nPush Operation successfull.\n";
            }
            else{
                cout << "\nStack is already full. Push operation failed.\n";
            }
        }
        void pop(){
            if (!(isEmpty())){
                cout << "\nElement " << arr[top--] << " removed from the stack.\n";
            }
            else{
                cout << "\nThe Stack is already empty. Pop operation failed.\n";
            }
        }
        void display(){
            cout << "\nThere are " << maxSize-top-1 << " out of " << maxSize << " spaces left in the stack.\n";
            cout << "\nThe elements currently in the stack are: ";
            if (!(isEmpty())){
                for (int i = 0; i <= top; i++){
                    cout << arr[i] << "  ";
                }
            }
            else{
                cout << "None, since all spaces are empty.\n" ;
            }
        }
};

int main(){
    int maxSize;
    cout << "\nPlease enter the maximum size of your stack: ";
    cin >> maxSize;
    Stack myStack1 = Stack(maxSize);

    cout << "\nOperations on the stack: \n\t- 0.Exit\n\t- 1.Is the Stack full?\n\t- 2.Is the Stack empty?\n\t- 3.Get top element of stack.\n\t- 4.Push Item to stack.\n\t- 5.Pop item from stack.\n\t- 6.Display current elements in stack.\n\nPlease enter your choice: ";
    int ch;
    int item;

    cin >> ch;
    while (ch)
    {
        switch (ch)
        {
            case 0:
                break;
            case 1:
                if (myStack1.isFull()){
                    cout << "\nYes, the stack is full.\n";
                }
                else{
                    cout << "\nBhot jagah hai.\n";
                }
                break;
            case 2:
                if (myStack1.isEmpty()){
                    cout << "\nHa bhai pura khaali hai.\n";
                }
                else{
                    cout << "\nNahi bhai bhir hai yahan.\n";
                }
                break;
            case 3:
                myStack1.peek();
                break;
            case 4:
                cout << "\nPlease enter the element you want to push to the stack. It must be integer.\n";
                cin >> item;
                myStack1.push(item);
                break;
            case 5:
                myStack1.pop();
                break;
            case 6:
                myStack1.display();
                break;
            default:
                cout << "\nWrong input. Please select only 1 of the given operation codes 0-6.\n";
                break;
        }
        cout << "\nPlease enter your next choice of operation: ";
        cin >> ch;
    }
    cout << "\nAll stack operations done and program execution complete. Thank you.\n";
    return 0;
}