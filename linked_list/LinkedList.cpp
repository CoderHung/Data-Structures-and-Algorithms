#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        insertAtIndex(getSize(), val);
    }

    void insertAtIndex(int index, int val) {
        Node* newNode = new Node(val);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Index out of bounds\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (!head || index < 0) return;

        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Index out of bounds\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    vector<int> findIndices(int val) {
        vector<int> indices;
        Node* temp = head;
        int idx = 0;
        while (temp) {
            if (temp->data == val) {
                indices.push_back(idx);
            }
            temp = temp->next;
            ++idx;
        }
        return indices;
    }

    int getSize() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            temp = temp->next;
            ++count;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Test the updated LinkedList
int main() {
    LinkedList list;

    // Insert at end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.insertAtEnd(50);
    cout << "Initial list:\n";
    list.display(); // 10 -> 20 -> 30 -> 20 -> 50 -> NULL

    // Insert at index
    cout << "Insert 99 at index 2:\n";
    list.insertAtIndex(2, 99);
    list.display(); // 10 -> 20 -> 99 -> 30 -> 20 -> 50 -> NULL

    // Delete at index
    cout << "Delete at index 3:\n";
    list.deleteAtIndex(3);
    list.display(); // 10 -> 20 -> 99 -> 20 -> 50 -> NULL

    // Find indices of value
    cout << "Find indices of value 20:\n";
    vector<int> indices = list.findIndices(20);
    for (int i : indices) {
        cout << i << " ";
    }
    cout << "\n"; // should print: 1 3
    /*
    Initial list:
    10 -> 20 -> 30 -> 20 -> 50 -> NULL
    Insert 99 at index 2:
    10 -> 20 -> 99 -> 30 -> 20 -> 50 -> NULL
    Delete at index 3:
    10 -> 20 -> 99 -> 20 -> 50 -> NULL
    Find indices of value 20:
    1 3
    */
    return 0;
}
