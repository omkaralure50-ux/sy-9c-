#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    // Insert a node into BST
    void insert(Node *&temp, int value)
    {
        if (temp == NULL)
        {
            temp = new Node;
            temp->data = value;
            temp->left = NULL;
            temp->right = NULL;
            return;
        }

        if (value < temp->data)
            insert(temp->left, value);
        else
            insert(temp->right, value);
    }

    // Non-recursive Inorder Traversal
    void inorder()
    {
        stack<Node *> s;
        Node *temp = root;

        while (temp != NULL || !s.empty())
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();

            cout << temp->data << " ";

            temp = temp->right;
        }
    }

    // Non-recursive Preorder Traversal
    void preorder()
    {
        if (root == NULL)
            return;

        stack<Node *> s;
        s.push(root);

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();

            cout << temp->data << " ";

            // Push right first
            if (temp->right != NULL)
                s.push(temp->right);

            // Push left second
            if (temp->left != NULL)
                s.push(temp->left);
        }
    }

    // Non-recursive Postorder Traversal
    void postorder()
    {
        if (root == NULL)
            return;

        stack<Node *> s1, s2;

        s1.push(root);

        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();

            s2.push(temp);

            if (temp->left != NULL)
                s1.push(temp->left);

            if (temp->right != NULL)
                s1.push(temp->right);
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();

            cout << temp->data << " ";
        }
    }

    // Count total number of nodes
    int countNodes(Node *temp)
    {
        if (temp == NULL)
            return 0;

        return 1 + countNodes(temp->left) + countNodes(temp->right);
    }

    // Find smallest value
    int findMin()
    {
        Node *temp = root;

        while (temp->left != NULL)
            temp = temp->left;

        return temp->data;
    }

    // Find largest value
    int findMax()
    {
        Node *temp = root;

        while (temp->right != NULL)
            temp = temp->right;

        return temp->data;
    }

    // Find height of tree
    int height(Node *temp)
    {
        if (temp == NULL)
            return 0;

        int leftHeight = height(temp->left);
        int rightHeight = height(temp->right);

        return 1 + max(leftHeight, rightHeight);
    }

    // Display tree statistics
    void statistics()
    {
        if (root == NULL)
        {
            cout << "\nTree is empty!";
            return;
        }

        cout << "\n===== Tree Statistics =====";
        cout << "\nTotal Nodes : " << countNodes(root);
        cout << "\nSmallest    : " << findMin();
        cout << "\nLargest     : " << findMax();
        cout << "\nHeight      : " << height(root);
        cout << "\n===========================";
    }
};

int main()
{
    BST tree;
    int choice, value;

    do
    {
        cout << "\n\n===== Binary Search Tree Menu =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Tree Statistics";       // Novel feature
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(tree.root, value);
            cout << "Node inserted successfully!";
            break;

        case 2:
            cout << "Inorder traversal: ";
            tree.inorder();
            break;

        case 3:
            cout << "Preorder traversal: ";
            tree.preorder();
            break;

        case 4:
            cout << "Postorder traversal: ";
            tree.postorder();
            break;

        case 5:
            tree.statistics();
            break;

        case 6:
            cout << "\nProgram Exited.";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}