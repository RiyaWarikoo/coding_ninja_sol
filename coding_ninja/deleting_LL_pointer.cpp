#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to delete a node at a specified position
Node* deleteNode(Node* head, int pos) {
    if (head == nullptr) {
        return head;  // If the list is empty, return null
    }

    if (pos == 0) {
        Node* temp = head;    // Save the head node to delete
        head = head->next;    // Move the head to the next node
        delete temp;          // Delete the old head
        return head;
    }

    Node* current = head;
    Node* previous = nullptr;
    int index = 0;

    // Traverse to the node at the specified position
    while (current != nullptr && index < pos) {
        previous = current;
        current = current->next;
        index++;
    }

    // If the position is beyond the end of the list, return the head
    if (current == nullptr) {
        return head;
    }

    // Adjust the pointers to bypass the node to be deleted
    previous->next = current->next;
    delete current;  // Delete the node

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to add a node at the end of the linked list
Node* append(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Main function to demonstrate the usage
int main() {
    Node* head = nullptr;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);

    std::cout << "Original list: ";
    printList(head);

    // Delete node at position 2 (0-based index)
    head = deleteNode(head, 2);

    std::cout << "List after deleting node at position 2: ";
    printList(head);

    // Delete node at position 0 (head node)
    head = deleteNode(head, 0);

    std::cout << "List after deleting node at position 0: ";
    printList(head);

    // Delete node at position 10 (beyond list length)
    head = deleteNode(head, 10);

    std::cout << "List after attempting to delete node at position 10: ";
    printList(head);

    // Clean up remaining nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
