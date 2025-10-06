#include <iostream>
using namespace std;

// Node tunggal buat SLL
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node() {
        delete next;
    }
};

// Class Singly Linked List
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    ~SinglyLinkedList() {
        delete head;
    }

    // Traversal - tampilkan isi linked list
    void traverse() {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }

        Node* current = head;
        cout << "Isi Linked List: ";
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Insertion - tambah di awal
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insertion - tambah di akhir
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next)
            current = current->next;

        current->next = newNode;
    }

    // Insertion - tambah di posisi tertentu (1 = paling awal)
    void insertAtPosition(int data, int pos) {
        if (pos <= 1) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* current = head;
        int index = 1;

        while (current && index < pos - 1) {
            current = current->next;
            index++;
        }

        if (!current) {
            cout << "Posisi di luar jangkauan, node ditaruh di akhir." << endl;
            insertAtEnd(data);
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Deletion - hapus dari awal
    void deleteFromBeginning() {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    // Deletion - hapus dari akhir
    void deleteFromEnd() {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next && current->next->next)
            current = current->next;

        delete current->next;
        current->next = nullptr;
    }

    // Deletion - hapus dari posisi tertentu
    void deleteFromPosition(int pos) {
        if (pos <= 1) {
            deleteFromBeginning();
            return;
        }

        Node* current = head;
        int index = 1;

        while (current && index < pos - 1) {
            current = current->next;
            index++;
        }

        if (!current || !current->next) {
            cout << "Posisi di luar jangkauan." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        temp->next = nullptr;
        delete temp;
    }

    // Searching - cari nilai di list
    void search(int key) {
        Node* current = head;
        int pos = 1;

        while (current) {
            if (current->data == key) {
                cout << "Data " << key << " ditemukan di posisi ke-" << pos << endl;
                return;
            }
            current = current->next;
            pos++;
        }

        cout << "Data " << key << " tidak ditemukan." << endl;
    }

    // Updating - ubah nilai pada posisi tertentu
    void update(int pos, int newData) {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }

        Node* current = head;
        int index = 1;

        while (current && index < pos) {
            current = current->next;
            index++;
        }

        if (!current) {
            cout << "Posisi di luar jangkauan." << endl;
            return;
        }

        current->data = newData;
    }

    // Reversal - balik urutan linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

int main() {
    SinglyLinkedList list;

    cout << "=== INSERTION ===" << endl;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(15, 2);
    list.traverse();

    // cout << "\n=== DELETION ===" << endl;
    // list.deleteFromBeginning();
    // list.deleteFromEnd();
    // list.deleteFromPosition(2);
    // list.traverse();

    cout << "\n=== SEARCHING ===" << endl;
    list.insertAtEnd(25);
    list.insertAtEnd(35);
    list.traverse();
    list.search(25);
    list.search(99);

    // cout << "\n=== UPDATING ===" << endl;
    // list.update(2, 50);
    // list.traverse();

    // cout << "\n=== REVERSAL ===" << endl;
    // list.reverse();
    // list.traverse();

    return 0;
}
