#include "SingleLinkedList.h"
using namespace std;


template <typename Item_Type> SingleLinkedList<Item_Type>::~SingleLinkedList();



template <typename Item_Type>
SingleLinkedList<Item_Type>::SingleLinkedList();



template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_front(const Item_Type& item) {
    head = new Node(item, head);
    if (num_items == 0) {
        tail = head;
    }
    num_items += 1;
}

//==============================================//

// creates a new node and includes the item from the list's end.//
template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_back(const Item_Type& item) {
    if (empty()) {
        push_front(item);
    }
    else {
        tail->next = new Node(item);
        tail = tail->next;
        num_items += 1;
    }
}

// this takes away the node from the back of the list //
template <typename Item_Type> void SingleLinkedList<Item_Type>::pop_back() {
    if (empty()) {
        throw out_of_range("Empty list");
    }
    if (num_items == 1) {
        pop_front();
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
        num_items -= 1;
    }
}


// this takes away the first node from the list//
template <typename Item_Type> void SingleLinkedList<Item_Type>::pop_front() {
    if (empty()) {
        throw out_of_range("Empty list");
    }
    Node* old_head = head;
    head = head->next;
    delete old_head;
    --num_items;
    if (empty()) {
        tail = nullptr;
    }
}

//================================================//

// this brings back the item to the front of the list//
template <typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::front() const {
    if (empty()) {
        throw out_of_range("Empty list");
    }
    return head->item;
}

// Returns the item at the back of the list
template <typename Item_Type>
Item_Type SingleLinkedList<Item_Type>::back() const {
    if (empty()) {
        throw out_of_range("Empty list");
    }
    return tail->item;
}


//===================================================//



// Inserts a new node with the item at position index
template <typename Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);
    }
    else if (index >= num_items) {
        push_back(item);
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        current->next = new Node(item, current->next);
        num_items += 1;
    }
}

// If the list is empty, the result is true.//
template <typename Item_Type> bool SingleLinkedList<Item_Type>::empty() const {
    return num_items == 0;
}
//==================================================//






template <typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) const {
    size_t index = 0;
    for (Node* current = head; current != nullptr;
        current = current->next, index += 1) {
        if (current->item == item) {
            return index;
        }
    }
    return num_items;
}

// gives the list's item count back.//
template <typename Item_Type> size_t SingleLinkedList<Item_Type>::size() const {
    return num_items;
}


//============================================//

// the node at location index is removed.
template <typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {
    if (empty() || index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        num_items -= 1;
        if (current->next == nullptr) {
            tail = current;
        }
    }
    return true;
}

template class SingleLinkedList<int>;

