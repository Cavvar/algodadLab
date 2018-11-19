#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

class BinarySearchTree {
public:
    BinarySearchTree() = default;

    bool isEmpty(Node *root) {
        if (root == nullptr) {
            return true;
        }
        return false;
    }

    void insert(Node *currentNode, int newKey) {
        if (isEmpty(currentNode)) {
            currentNode->key = newKey;
        } else {
            if (currentNode->key == newKey) {
                // do nothing
            } else if (currentNode->key < newKey) {
                if (currentNode->right == nullptr) {
                    currentNode->right = newNode(newKey);
                } else {
                    insert(currentNode->right, newKey);
                }
            } else {
                if (currentNode->left == nullptr) {
                    currentNode->left = newNode(newKey);
                } else {
                    insert(currentNode->left, newKey);
                }
            }
        }
    }

    bool doesKeyExistInTree(Node *currentNode, int key) {
        bool result;
        if (isEmpty(currentNode)) {
            return false;
        }
        if (currentNode->key == key) {
            result = true;
        } else if (currentNode->key > key) {
            if (currentNode->left == nullptr) {
                result = false;
            } else {
                return doesKeyExistInTree(currentNode->left, key);
            }
        } else {
            if (currentNode->right == nullptr) {
                result = false;
            } else {
                return doesKeyExistInTree(currentNode->right, key);
            }
        }
        return result;
    }

    int getMin(Node *currentNode) {
        if (isEmpty(currentNode)) {
            cout << "The Tree is Empty" << endl;
        } else if (currentNode->left == nullptr) {
            return currentNode->key;
        } else {
            return getMin(currentNode->left);
        }
    }

    int getMax(Node *currentNode) {
        if (isEmpty(currentNode)) {
            cout << "The Tree is Empty" << endl;
        } else if (currentNode->right == nullptr) {
            return currentNode->key;
        } else {
            return getMax(currentNode->right);
        }
    }

    void printTheNodesOrNone(Node *currentNode) {
        if (currentNode != nullptr) {
            if (currentNode->key % 5 == 0) {
                multipleOfFiveCount = multipleOfFiveCount + 1;
                if(currentNode->left != nullptr){
                    cout << currentNode->left->key << endl;
                }
                if(currentNode->right != nullptr){
                    cout << currentNode->right->key << endl;
                }
            }
            printTheNodesOrNone(currentNode->left);
            printTheNodesOrNone(currentNode->right);
        }
    }

    int getMultipleOfFiveCount(){
        return  multipleOfFiveCount;
    }

private:
    int multipleOfFiveCount;

    Node *newNode(int key) {
        Node *newNode = new Node();
        newNode->key = key;
        newNode->right = newNode->left = nullptr;
        return newNode;
    }
};

int main(int argc, char* argv[]) {
    Node *root = new Node();
    root->left = root->right = nullptr;
    BinarySearchTree bst;

    int arraySize = argc - 1;
    for (int index = 0; index < arraySize; index++) {
        if(index == 0){
            root->key = atoi(argv[index + 1]);
        }else{
            bst.insert(root, atoi(argv[index + 1]));
        }
    }

    bst.printTheNodesOrNone(root);
    if(bst.getMultipleOfFiveCount() == 0){
        cout << "None" << endl;
    }
    return 0;
}