#include <iostream>
#include<string>
using namespace std;

#define MAX 100 

class Stack {
private:
    int arr[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    // Push operation
    void push(int x) {
        if (topIndex >= MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    // Pop operation
    int pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    // Top operation
    int top() {
        if (topIndex < 0) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // Peep operation: returns element at position from top
    int peep(int position) {
        int index = topIndex - position + 1;
        if (index < 0 || index > topIndex) {
            cout << "Invalid position!" << endl;
            return -1;
        }
        return arr[index];
    }

};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    cout << "Peep 2nd element from top: " << s.peep(2) << endl;

    cout << "Popped: " << s.pop() << endl;
  
  return 0;
}
