// 13-03-2025
// Merge K linked lists (using minHeaps)

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

#include <queue>

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap: smallest element at the top
    }
};



Node* mergeKLists(vector<Node*> &listArray)
    
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    int k = listArray.size();
    if (k == 0)  
        return NULL;  

    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }     

    Node* head = NULL;
    Node* tail = NULL;

    while (!minHeap.empty()) {
        Node* tmp = minHeap.top();
        minHeap.pop();

        if (tmp->next != NULL) {
            minHeap.push(tmp->next);
        } 

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
    }

    return head;
}