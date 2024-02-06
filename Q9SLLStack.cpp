/*
9. Write a menu driven program in C or C++ to implement a stack using single linked list and
perform the following operations.
    (a) isEmpty() is to check whether the stack is empty or not.
    (b) push() is to insert an item in the stack.
    (c) pop() is to delete an item from the stack.
    (d) display() is to show the entire stack.
*/

#include"mySLL.h"
using namespace std;

class SLLStack{
    private:
        Node* top;
        MySLL sll;
    public:
        SLLStack(){
            sll = MySLL();
            top = NULL;
        }
        bool isEmpty(){
            if (top == NULL){
                return true;
            }
            else{
                return false;
            }
        }
        void push(int item){
            top = sll.insertEnd(item);
            cout << "\nPushed "<<item<<" onto the stack.\n";
        }
        void pop(){
            top = sll.delEnd();
        }
        void display(){
            sll.display();
        }
        int peek(){
            if (top == NULL){
                return NULL;
            }
            return top->value;
        }
};
int main(){
    SLLStack myStack1 = SLLStack();

    cout << "\nOperations on the stack: \n\t- 0.Exit\n\t- 1.Is the Stack empty?\n\t- 2.Get top element of stack.\n\t- 3.Push Item to stack.\n\t- 4.Pop item from stack.\n\t- 5.Display current elements in stack.\n\nPlease enter your choice: ";
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
                if (myStack1.isEmpty()){
                    cout << "\nYes the stack is empty.\n";
                }
                else{
                    cout << "\nNo the stack is not empty.\n";
                }
                break;
            case 2:
                item = myStack1.peek();
                if (item != NULL){
                    cout << "\nThe top element of the stack is: "<<item;
                }
                else{
                    cout << "\nThe Stack is empty. So no element at top.\n";
                }
                break;
            case 3:
                cout << "\nPlease enter the element you want to push to the stack. It must be integer.\n";
                cin >> item;
                myStack1.push(item);
                break;
            case 4:
                myStack1.pop();
                break;
            case 5:
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