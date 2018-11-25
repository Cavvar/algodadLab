#include <utility>

#include <utility>

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Helper {
    int key;
    int pointValue;
};

struct Node {
    int key;
    Node *parent;
};

class GeneralTree {
public:

    GeneralTree(Node *root, list<Helper *> edgeList) {
        this->root = root;

        this->edgeList = move(edgeList);
        tree.push_back(root);
    }

    void organizeTree() {
        for (int index = 0; index < tree.size(); index++) {
            for (Helper *edges: edgeList) {
                if (tree.at(static_cast<unsigned int>(index))->key == edges->key) {
                    Node *child = new Node();
                    child->key = edges->pointValue;
                    child->parent = tree.at(static_cast<unsigned int>(index));
                    tree.push_back(child);
                }
            }
        }
    }

    void preOrder() {
        int id = 1;
        for (Node *element: tree) {
            if (element == root) {
                cout << "ID: " << id << " Key: " << element->key << " This is the root" << endl;
            } else {
                cout << "ID: " << id << " Key: " << element->key << " Parent: " << element->parent->key << endl;
            }

            id++;
        }
    }

    int count() {
        return tree.size();
    }

    int height(){
        int amountOfDifferentParents = 0;
        int currentParent = tree.front()->key;
        for (Node *element: tree) {
            if(element == root){
                amountOfDifferentParents = 1;
            }else{
                if(element->parent->key != currentParent){
                    currentParent = element->parent->key;
                    amountOfDifferentParents++;
                }
            }
        }
        return amountOfDifferentParents;
    }

private:
    Node *root;
    list<Helper *> edgeList;
    vector<Node *> tree;

};

int determineRoot(list<Helper *> edge_list) {
    int root = 0;

    vector<int> pointValues;
    vector<int> keyValues;
    for (Helper *element: edge_list) {
        pointValues.push_back(element->pointValue);
        keyValues.push_back(element->key);
    }

    bool foundRoot = false;
    int index = 0;
    while (!foundRoot) {
        root = keyValues.at(static_cast<unsigned int>(index));
        if (find(pointValues.begin(), pointValues.end(), root) == pointValues.end()) {
            foundRoot = true;
        }
        index++;
    }

    return root;
}

int main(int argc, char *argv[]) {
    int arraySize = argc - 1;
    list<Helper *> edge_list;

    for (int index = 0; index < arraySize; index = index + 2) {
        auto *current = new Helper();
        current->key = atoi(argv[index + 1]);
        current->pointValue = atoi(argv[index + 2]);
        edge_list.push_back(current);
    }

    Node *root = new Node();
    root->key = determineRoot(edge_list);
    GeneralTree gt(root, edge_list);
    gt.organizeTree();
    gt.preOrder();
    cout << "Count: " << gt.count() << endl;
    cout << "Height: " << gt.height() << endl;

    return 0;
}



