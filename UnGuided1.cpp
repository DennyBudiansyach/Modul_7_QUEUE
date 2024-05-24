#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
    return (front == nullptr);
}
void enqueue(string nama) {
    Node* newNode = new Node;
    newNode->data = nama;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
    }
}
int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}
void viewQueue() {
    if (!isEmpty()) {
        Node* current = front;
        cout << "Data antrian teller: \n";
        int count = 0;
        while (current != nullptr) {
            count++;
            cout << count <<". "<< current->data << "\n";
            current = current->next;
        }
        cout << endl;
    } else {
        cout << "(kosong)" << endl;
    }
}

int main()
{
    enqueue("Andi");
    enqueue("Maya");
    cout << "Jumlah antrian = " << countQueue() << endl;
    viewQueue();
    dequeue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    viewQueue();
    clearQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    viewQueue();
    return 0;
}