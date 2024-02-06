/*
11. Write a menu driven program in C or C++ to implement a priority queue using single linked
list and perform the following operations.
    (a) isEmpty() is to check whether the queue is empty or not.
    (b) insert() is to insert an item in the queue.
    (c) del() is to delete an item from the queue.
    (d) display() is to show the entire queue.
*/

#include "mySLL.h"
using namespace std;

class PriorityQ{
    private:
        MySLL sll;
    public:
        PriorityQ(){
            sll = MySLL();
        }
        bool isEmpty(){
            if (sll.head == NULL){
                return true;
            }
            return false;
        }

        void insert(int x, int p){
            sll.insertByPriority(x,p);
        }

        void del(){
            sll.delBeg();
        }

        void display(){
            sll.display();
        }
};

int main(){
    PriorityQ PQ = PriorityQ();
    cout << "\nPriority Queue initialised. Operations on it are:\n\t  - 0. Exit\n\t  - 1. Is the Queue empty?\n\t  - 2. Insert value by priority.\n\t  - 3. Delete element of highest priority\n\t  - 4. Display queue elements from highest to lowest priority.\n\nPlease choose an operation: ";
    int ch,item,p;
    cin >> ch;

    while (ch)
    {
        switch (ch)
        {
        case 0:
            break;
        
        case 1:
            if (PQ.isEmpty()){
                cout << "\nYes the priority queue is empty.\n";
            }
            else{
                cout << "\nThe priority queue is not empty.\n";
            }
            break;
        
        case 2:
            cout << "\nInsert the item you want to insert (integer).\n";
            cin >> item;
            cout << "\nEnter the priority of the item. (integer)\n";
            cin >> p;
            PQ.insert(item,p);
            break;
        
        case 3:
            PQ.del();
            break;
        
        case 4:
            cout << "\nThe values in the queue are: ";
            PQ.display();
            break;
        
        default:
            cout << "\nWrong input. Please select only 1 of the given operation codes 0-4.\n";
            break;
        }
        cout << "\nPlease enter your next choice of operation: ";
        cin >> ch;
    }
    cout << "\nAll priority queue operations done and program execution complete. Thank you.\n";
    return 0;
}