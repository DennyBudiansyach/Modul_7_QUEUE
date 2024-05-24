#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
    return front == nullptr;
}
void enqueue(string nama, string nim) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->nim = nim;
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
            cout << count <<". "<< current->nama << " (" << current->nim << ")"<< "\n";
            current = current->next;
        }
        cout << endl;
    } else {
        cout << "(kosong)" << endl;
    }
}

int main() {
    enqueue("Andi", "2311102222");
    enqueue("Maya", "2311102199");
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
