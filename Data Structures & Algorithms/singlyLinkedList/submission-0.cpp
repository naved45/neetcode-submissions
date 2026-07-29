#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    void insertTail(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
        } else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) return false;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* cur = head;
        while (cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }
};
