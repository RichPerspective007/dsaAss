/*
4. Write a menu driven program in C or C++ to implement a Circular Queue using array and
perform the following operations.
    (a) isFull() function to check whether the Circular Queue is full or not.
    (b) isEmpty() function to check whether the Circular Queue is empty or not.
    (c) insert(item) function to insert an element item in the Circular Queue.
    (d) delete() function to read and remove an element from the Circular Queue.
    (e) display() function to display the entire Circular Queue.
*/

#include<iostream>
using namespace std;

class MyQueue{
    private:
        int* arr;
        int front;
        int rear;
        int maxSize;
    public:
        MyQueue(int maxSize):maxSize(maxSize){
            arr = new int[maxSize];
            front = -1;
            rear = -1;
        }
        bool isFull(){
            if ((rear + 1)%maxSize == front){
                return true;
            }
            return false;
        }
        bool isEmpty(){
            if (front == -1){
                return true;
            }
            return false;
        }
        void insert(int item){
            if (!(isFull())){
                if (rear == maxSize-1){
                    rear = -1;
                }
                arr[++rear] = item;
                if (front == -1){
                    front++;
                }
                cout << "\nInsert operation successful.\n";
            }
            else{
                cout << "\nQueue is already full. Insert operation failed.\n";
            }
            cout << "\nFront = " << front << "\nRear = " << rear << "\n";
        }
        void del(){
            int tbd = arr[front];
            if (isEmpty()){
                cout << "\nThe queue is empty. Delete operation failed.\n";
                return;
            }
            else if (front==rear && !(isEmpty())){
                front = -1;
                rear = -1;
            }
            else if (front == maxSize - 1)
            {
                front = 0;
            }
            else{
                front++;
            }
            cout << "\nRemoved " << tbd << " from the queue.\n";
            cout << "\nFront = " << front << "\nRear = " << rear << "\n";
            
        }
        void display(){
            if (isEmpty()){
                cout << "\nThe queue has no items to display.\n";
            }
            else{
                cout << "\nThe items in the queue are:  ";
                if (rear >= front){
                    for(int i = front; i <= rear; i++){
                        cout << arr[i] << "  ";
                    }
                }
                else{
                    for(int i = front; i<maxSize; i++){
                        cout << arr[i] << "  ";
                    }
                    for(int i = 0; i<=rear; i++){
                        cout << arr[i] << "  ";
                    }
                }
            }
        }
};

int main(){
    int maxSize;
    cout << "\nPlease enter the maximum size of your Queue: ";
    cin >> maxSize;
    MyQueue myQueue1 = MyQueue(maxSize);

    cout << "\nOperations on the queue: \n\t- 0. Exit\n\t- 1. Is the Queue full?\n\t- 2. Is the Queue empty?\n\t- 3. Insert into Queue.\n\t- 4. Delete from queue.\n\t- 5. Display current elements in the queue.\n\nPlease enter your choice: ";
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
                if (myQueue1.isFull()){
                    cout << "\nYes, the Queue is full.\n";
                }
                else{
                    cout << "\nBhot jagah hai.\n";
                }
                break;
            case 2:
                if (myQueue1.isEmpty()){
                    cout << "\nHa bhai pura khaali hai.\n";
                }
                else{
                    cout << "\nNahi bhai bhir hai yahan.\n";
                }
                break;
            case 3:
                cout << "\nPlease enter the element you want to insert into the queue. It must be integer.\n";
                cin >> item;
                myQueue1.insert(item);
                break;
            case 4:
                myQueue1.del();
                break;
            case 5:
                myQueue1.display();
                break;
            default:
                cout << "\nWrong input. Please select only 1 of the given operation codes 0-5.\n";
                break;
        }
        cout << "\nPlease enter your next choice of operation: ";
        cin >> ch;
    }
    cout << "\nAll queue operations done and program execution complete. Thank you.\n";
    return 0;
}