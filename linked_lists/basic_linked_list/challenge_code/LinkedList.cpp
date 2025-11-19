#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) {
    Node* cur = source.head;
    while(cur != nullptr) {
        insertBack(cur->data);
        cur = cur->next;
    }
}


LinkedList& LinkedList::operator=(const LinkedList& source) {
    clear();
    Node* cur = source.head;
    while(cur != nullptr) {
        insertBack(cur->data);
        cur = cur->next;
    }
    return *this;
}


void LinkedList::clear() {
    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }
    // head is nullptr when loop exits

    tail = nullptr;
}


void LinkedList::insertFront(const int& data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) { // empty list
        tail = newNode;
    }
}


void LinkedList::insertBack(const int& data) {
    Node* newNode = new Node(data); // newNode->next is set to nullptr in its constructor
    if (tail == nullptr) { // empty list
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


void LinkedList::insertAfter(const int& valueToInsert, const int& valueToLookFor) {
    Node* cur = head;
    while(cur != nullptr) {
        if(cur->data == valueToLookFor) {
            Node* newNode = new Node(valueToInsert);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        cur = cur->next;
    }
}


void LinkedList::remove(const int& value) {
    // check if empty list
    if(head == nullptr) {
        return;
    }

     // check case that list only has 1 element
    if(head == tail) {
        if(head->data == value) {
            delete head;
            head = tail = nullptr;
        }
        return;
    }

    // check case that head matches
    if(head->data == value) {
        Node* removeNode = head;
        head = head->next;
        delete removeNode;
        return;
    }

    // check if next element matches, if so remove it
    // make sure to update tail if you remove the last item
    Node* cur = head;
    while(cur->next != nullptr) {
        if(cur->next->data == value) {
            Node* removeNode = cur->next;
            cur->next = cur->next->next;
            delete removeNode;
            if (cur->next == nullptr) {
                tail = cur;
            }
            return;
        } else {
            cur = cur->next;
        }
    }
}


void LinkedList::print(std::ostream& os) const {
    Node* cur = head;
    if (cur == nullptr) {
        os << "Empty List!";
    }
    while (cur != nullptr) {
        os << cur->data << " ";
        cur = cur->next;
    }
    os << std::endl;
}


std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
    ll.print(os);
    return os;
}


bool LinkedList::contains(const int& value) const {
    Node* cur = head;
    while(cur != nullptr) {
        if(cur->data == value) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}


unsigned int LinkedList::count(int value) const {
    unsigned int cnt = 0;
    Node* cur = head;
    while(cur != nullptr) {
        if(cur->data == value) {
            cnt++;
        }
        cur = cur->next;
    }
    return cnt;
}


void LinkedList::multiply(int value) {
    Node* cur = head;
    while(cur != nullptr) {
        cur->data = cur->data * value;
        cur = cur->next;
    }
}


void LinkedList::getEvens(LinkedList& newList) const {
    newList.clear();
    Node* cur = head;
    while(cur != nullptr) {
        if(cur->data % 2 == 0) {
            newList.insertBack(cur->data);
        }
        cur = cur->next;
    }
}


int LinkedList::popFront() {
    // if list is empty, return 0
    if(empty()) {
        return 0;
    }

    // get first value, advance head
    Node* cur = head;
    int result = cur->data;
    head = cur->next;
    // if list is now empty (only had 1 element before), set tail to nullptr
    if(empty()) {
        tail = nullptr;
    }
    delete cur; // no memory leaks!
    return result;
}


int LinkedList::popBack() {
    if(empty()) {
        return 0;
    }

    // get last value
    int result = tail->data;

    // if only 1 element, clear list
    if(head == tail) {
        clear();
        return result;
    }

    // find node right before tail so can set it as the new tail
    Node* cur = head;
    while(cur->next != tail) {
        cur = cur->next;
    }
    delete tail;
    cur->next = nullptr;
    tail = cur;
    return result;
}


void LinkedList::removeDuplicates() {
    // cannot have duplicates if list is empty or only has 1 item
    if(empty() || head == tail) { 
        return;
    }

    // keep a list of items seen so far
    LinkedList seen;
    seen.insertBack(head->data);

    Node* prev = head;
    Node* cur = prev->next;
    
    while(cur != nullptr) {
        if (seen.contains(cur->data)) {
            // if seen, remove cur and advance it to the next item
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else {
            // if not seen, add to list and advance both prev and cur
            seen.insertBack(cur->data);
            prev = cur;
            cur = cur->next;
        }
    }
}
