#include <iostream>

using namespace std;

class TreeChunk {
public:
    TreeChunk *left;
    TreeChunk *right;
    int data;

    TreeChunk() {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    TreeChunk *root;

    BST() {
        root = NULL;
    }

    //1. Add new values to the tree
    void add(int x) {
        if (root == NULL) {
            //empty tree
            root = new TreeChunk;
            root->data = x;
            cout << "You added the value: " << x << " to your tree" << endl;
            return;
        }

        TreeChunk *slow, *fast;
        slow = fast = root;

        while (fast != NULL) {
            if (x < fast->data) {
                slow = fast;
                fast = fast->left;
            } else if (x > fast->data) {
                slow = fast;
                fast = fast->right;
            } else {
                cout << "We do not allow duplicates";
                return;
            }

        }

        if (x < slow->data) {
            slow->left = new TreeChunk;
            slow->left->data = x;
        } else {
            slow->right = new TreeChunk;
            slow->right->data = x;
        }

        cout << "Added " << x << endl;

    }

    //2. Search for a value
    bool search(int key, TreeChunk *start) {
        //anchor value
        if (start == NULL) {
            cout << "Could not find the value: " << key << " that you are looking for" << endl;
            return false;
        }

            //recursive step
        else {
            if (key == start->data) {
                cout << "Success the value: " << key << " was found! Hooray!" << endl;
                return true;
            } else if (key < start->data) {
                search(key, start->left);
            } else {
                search(key, start->right);
            }
        }
    }

    //3. Display the contents of the tree
    void preorder(TreeChunk *start) {
        if (start == NULL) {
            return;
        } else {
            //root, left, right
            cout << start->data << endl;
            preorder(start->left);
            preorder(start->right);
        }
    }

    void postorder(TreeChunk *start) {
        if (start == NULL) {
            return;
        } else {
            //left, right, root
            postorder(start->left);
            postorder(start->right);
            cout << start->data << endl;
        }
    }

    void inorder(TreeChunk *start) {
        if (start == NULL) {
            return;
        } else {
            //left, root, right
            inorder(start->left);
            cout << start->data << endl;
            inorder(start->right);
        }
    }

    //4. Deleting values from the tree
    void deleteNode(int key) {
        //empty tree test:
        if (root == NULL) {
            cout << "Tree is empty. Nothing to delete. Try adding something";
            return;
        }
        //step1: Search and find that node
        TreeChunk *slow, *fast = root;
        while (fast != NULL && fast->data != key) {
            //keep going left or right
            if (key < fast->data) {
                slow = fast;
                fast = fast->left;
            } else {
                slow = fast;
                fast = fast->right;
            }
        }
        if (fast == NULL) {
            cout << "This node does not exist in this tree for " << key << endl;
            return;
        }
        //step 2: Begin to classify the case for delete (1,2,3)
        cout << "Found the node, now trying to classify the type of delete" << endl;
        if (fast->right == NULL && fast->left == NULL) {
            cout << "Looks like a Case-I delete for " << key << endl;
            if (slow->right == fast) {
                slow->right = NULL;
                cout << "About to delete: " << fast->data << endl;
                delete fast;
            } else {
                slow->left = NULL;
                cout << "About to delete: " << fast->data << endl;
                delete fast;
            }
        } else if ((fast->right == NULL && fast->left != NULL) || (fast->right != NULL && fast->left == NULL)) {
            cout << "Case II delete for " << key << endl;
            if (fast->left != NULL) {
                if (slow->left == fast) {
                    //fast is to the left of slow, and the lone child is to the left of fast
                    slow->left = fast->left;
                    cout << "About to delete: " << fast->data << endl;
                    delete fast;
                } else if (slow->right == fast) {
                    //fast is to the right of, and lone child is to the left of fast
                    cout << "About to delete: " << fast->data << endl;
                    delete fast;
                }
            }
            if (fast->right != NULL) {
                if (slow->left == fast) {
                    //fast is to left of slow, and the lone child is to the right of fast
                    slow->left = fast->right;
                    cout << "About to delete: " << fast->data << endl;
                    delete fast;
                } else if (slow->right == fast) {
                    //fast is to the right of slow, and the lone is to the right of fast
                    slow->right = fast->right;
                    cout << "About to delete: " << fast->data << endl;
                    delete fast;
                }
            }
        } else {
            cout << "Case III delete for " << key << endl;
            TreeChunk *min;
            int temp;
            min = fast->right;
            while (min->left != nullptr) {
                min = min->left;
            }
            temp = min->data;
            deleteNode(temp);
            fast->data = temp;
        }
        //step 3: proceed to delete
    }

};

int main() {
    BST myTree;
    while (true) {
        int choice, value;
        cout << " Press 1 to add a node" << endl;
        cout << " Press 2 to search for a node" << endl;
        cout << " Press 3 to print in preorder" << endl;
        cout << " Press 4 to print in postorder" << endl;
        cout << " Press 5 to print inorder" << endl;
        cout << " Press 6 to delete" << endl;
        cout << "Press anything else to quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Type a number to add to your beautiful tree" << endl;
                cin >> value;
                myTree.add(value);
                break;
            case 2:
                cout << "What number do you want to search for?" << endl;
                cin >> value;
                myTree.search(value, myTree.root);
                break;
            case 3:
                myTree.preorder(myTree.root);
                break;
            case 4:
                myTree.postorder(myTree.root);
                break;
            case 5:
                myTree.inorder(myTree.root);
                break;
            case 6:
                cout << "Type a number you want deleted off your tree " << endl;
                cin >> value;
                myTree.deleteNode(value);
                break;
            default:
                cout << "Ba Bye!" << endl;
                exit(0);
        }
    }

//BST myTree;
//    myTree.add(30);
//    myTree.add(15);
//    myTree.add(60);
//    myTree.add( 7);
//    myTree.add(22);
//    myTree.add(17);
//    myTree.add(27);
//    myTree.add(45);
//    myTree.add(75);
//    myTree.add(80);
//    myTree.search(23, myTree.root);
//    cout << "-------------------------------------" << endl;
//    myTree.preorder(myTree.root);
//    cout << "-------------------------------------" << endl;
//    myTree.postorder(myTree.root);
//    cout << "-------------------------------------" << endl;
//    myTree.inorder(myTree.root);
//    cout << "-------------------------------------" << endl;
//    myTree.deleteNode(17);
//    myTree.deleteNode(75);
//    myTree.deleteNode(15);
//    myTree.deleteNode(99999999);
//    myTree.preorder(myTree.root);

}
