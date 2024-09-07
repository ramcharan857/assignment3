#include <iostream>
#include <vector> // Include necessary header for vector
using namespace std;

class Node {
public:
    int i;     // Row index
    int j;     // Column index
    int data;  // Value
    Node *next;
};

void next_node(Node **node, int i, int j, int x) {
    Node *tmp = *node;
    Node *newNode;
    // If the node is null, directly create and assign Node to it
    if (tmp == NULL) {
        tmp = new Node();
        tmp->i = i;
        tmp->j = j;
        tmp->data = x;
        tmp->next = NULL;
        *node = tmp;
    } else {
        // If the node is not null
        // Finding the last node and appending a new node to it
        while (tmp->next != NULL)
            tmp = tmp->next;

        newNode = new Node();
        newNode->i = i;
        newNode->j = j;
        newNode->data = x;
        newNode->next = NULL;
        tmp->next = newNode;
    }
}

Node* convertLinkedList(int n, int m, vector<vector<int>> sparseMatrix) {
    Node *head = NULL;
    for (int i = 0; i < n; i++) {  // Use n instead of hard-coded value 4
        for (int j = 0; j < m; j++) {  // Use m instead of hard-coded value 5
            if (sparseMatrix[i][j] != 0)
                next_node(&head, i, j, sparseMatrix[i][j]);
        }
    }
    return head;
}

void printLinkedList(Node *start) {
    Node *ptr = start;
    cout << "Row:    ";
    while (ptr != NULL) {
        cout << ptr->i << " ";
        ptr = ptr->next;
    }
    cout << endl;

    cout << "Column: ";
    ptr = start;
    while (ptr != NULL) {
        cout << ptr->j << " ";
        ptr = ptr->next;
    }
    cout << endl;

    cout << "Value:  ";
    ptr = start;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> sparseMatrix =
    {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    Node *head = convertLinkedList(4, 5, sparseMatrix);
    printLinkedList(head);
    return 0;
}
