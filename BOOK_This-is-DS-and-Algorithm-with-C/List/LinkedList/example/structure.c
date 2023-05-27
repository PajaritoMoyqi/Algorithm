typedef int ElementType;

// method 1

struct Node
{
    ElementType Data; // data
    struct Node* NextNode; // next node
};

struct Node MyNode; // make instance

// method 2

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* NextNode;  
} Node;

Node MyNode; // make instance w/shorter code