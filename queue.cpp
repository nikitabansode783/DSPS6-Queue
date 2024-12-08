/* Nikita Bansode, Roll no.:10, DSPS Assignment no.:6, 26-9-24 */
#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int q[10];

public:
    Queue() : front(-1), rear(-1), size(10) {}

    void enqueue() {
        int ele;
        cout << "Enter the element: ";
        cin >> ele;

        if (rear == size - 1) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) front = 0;
            q[++rear] = ele;
            cout << "Enqueued: " << ele << endl;
        }
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Dequeued: " << q[front] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void check() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else if (rear == size - 1) {
            cout << "Queue is full" << endl;
        } else {
            cout << "Queue has elements" << endl;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << q[i] << " ";
            }
            cout << endl;
        }
    }

    void peak() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << q[front] << endl;
        }
    }
};

int main() {
    Queue q;
    int ch;

    do {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue\n3. Check\n4. Peak\n5. Display\n6. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.check();
                break;
            case 4:
                q.peak();
                break;
            case 5:
                q.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (ch != 6);

    return 0;
}
