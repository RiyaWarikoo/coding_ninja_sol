#include <iostream>
#include <list>

using namespace std;
void deleteNodeAtPosition(list<int>& lst, int position) {
    if (position < 0 || position >= lst.size()) {
        return; 
    }

    auto it = lst.begin();
    advance(it, position); 
    lst.erase(it); 
}
void printList(const list<int>& lst) {
    for (const int& value : lst) {
        cout << value << " ";
    }
    cout << endl;
}
int main() {
    list<int> myList = {1, 2, 3, 4, 5};
    cout << "Original list: ";
    printList(myList);
    int position;
    cout << "Enter the position to delete: ";
    cin >> position;
    deleteNodeAtPosition(myList, position);
    cout << "List after deletion: ";
    printList(myList);
    return 0;
}