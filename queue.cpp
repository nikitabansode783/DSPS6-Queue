#include <iostream>
using namespace std;

class Queue {
    int front, rear;
    int q[10]; 
    int n;

public:
    Queue(int size) {
        n = size;
        front = rear = -1;
    }

    void enqueue(int ele);
    void dequeue();
    void peak();
    void display();
    bool isFull();
    bool isEmpty();
};

void Queue::enqueue(int ele) {
    if (isFull()) {
        cout << "\nQueue is full.";
        return;
    }
    if (isEmpty()) {
        front = 0; 
    }
    rear++;
    q[rear] = ele;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "\nQueue is empty.";
        return;
    }
    cout << "\nDequeued element: " << q[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void Queue::peak() {
    if (isEmpty()) {
        cout << "\nQueue is empty.";
        return;
    }
    cout << "\nFront element: " << q[front];
}

bool Queue::isFull() {
    return rear == n - 1;
}

bool Queue::isEmpty() {
    return front == -1 || front > rear;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "\nQueue is empty.";
        return;
    }
    cout << "\nElements are: ";
    for (int i = front; i <= rear; i++) {
        cout "\t"<< q[i] << "\t";
    }
}

int main() {
    int n, ch, ele;
    cout << "\nEnter total number of elements: ";
    cin >> n;

    Queue q(n); 
    
    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.IsFull\n4.IsEmpty\n5.Peak\n6.Display\nEnter 0 to exit.\n";
        cout << "\nEnter your choice: ";
        cin >> ch;
        
        switch(ch) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter the element: ";
                    cin >> ele;
                    q.enqueue(ele);
                }
                break;

            case 2: 
                q.dequeue();
                break;

            case 3:
                if (q.isFull()) {
                    cout << "\nQueue is full.";
                } else {
                    cout << "\nQueue is not full.";
                }
                break;

            case 4:
                if (q.isEmpty()) {
                    cout << "\nQueue is empty.";
                } else {
                    cout << "\nQueue is not empty.";
                }
                break;

            case 5:
                q.peak(); 
                break;

            case 6:
                q.display();
                break;

            case 0:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid choice.";
                break;
        }
    } while(ch != 0);

    return 0;
}
