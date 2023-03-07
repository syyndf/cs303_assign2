#include <iostream>

using namespace std;

template <typename Item_Type> class SingleLinkedList {
private:
    struct Node { 
        Item_Type item;
        Node* next;
        Node(const Item_Type& item, Node* next = nullptr)
            : item(item), next(next) {}
    };
public:

    
    SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}
    
    ~SingleLinkedList(){
    while (!empty()) {
        pop_front();
    }
}
    Node* head;       
    Node* tail;       
    size_t num_items; 
    void push_front(const Item_Type& item);

    void push_back(const Item_Type& item);

    void pop_front();

    void pop_back();

    Item_Type front() const;

    Item_Type back() const;

    bool empty() const;

    void insert(size_t index, const Item_Type& item);

    bool remove(size_t index);

    size_t find(const Item_Type& item) const;
    size_t size() const; 
};
