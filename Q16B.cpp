/*
Write a program to find the factorial of a number using tail recursion.
*/
#include <iostream>
using namespace std;

int fact_tail(int curr_val, int curr_term, int find_term){
    if (curr_term == find_term){
        return curr_val;
    }
    return fact_tail(curr_val*(++curr_term),curr_term,find_term);
}

int main(){
    int n;
    cout << "\nPlease enter the positive integer for which the value of the Factorial is required: ";
    cin >> n;

    cout << "\nThe factorial of " << n << " is: ";
    int val = fact_tail(1,0,n);
    cout << val << "\n";
}