#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

int main() {
    SingleLinkedList<int> list;
    list.push_back(3);
  
    list.push_back(2);
  
    list.push_front(20);
  
    list.push_front(4);

    cout << "List: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list.front() << " ";
        list.push_back(list.front());
        list.pop_front();
    }
    cout << endl;
    list.insert(9, 40);
    cout << "List add ";
    for (int i = 0; i < list.size(); i++) {
        cout << list.front() << " ";
        list.push_back(list.front());
      
        list.pop_front();
      
    }
    cout << endl;
    bool removed = list.remove(4);
    cout << "Remove number: " << removed << endl;

    cout << "List: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list.front() << " ";
        list.push_back(list.front());
      
        list.pop_front();
    }
    cout << endl;
    cout << "Find(3): " << list.find(3) << endl;
    cout << endl;
    cout << "Delete front and back " << endl;
    list.pop_back();
    list.pop_front();
    cout << "List: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list.front() << " ";
      
        list.push_back(list.front());
        list.pop_front();
    }
    cout << endl;
    cout << "Beginning: " << list.front() << endl;
  
    cout << "Ending: " << list.back() << endl;

    cout << "Testing the size() " << endl;
  
    cout << "Size: " << list.size() << endl;
    return 0;
}
