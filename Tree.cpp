#include <iostream>
#include <queue>
#include<stack>
using namespace std;
 
class BinaryTree {
    private:
    class Node {
 
        public:
        int data;
        Node *left;
        Node *right;
 
        Node(int d, Node *left, Node *right) {
            data = d;
            this->left = left;
            this->right = right;
        }
 
        void insert(int d) {
            queue<Node*> *helperQ = new queue<Node*>();
            helperQ->push(this);
            while(!helperQ->empty()) {
                Node* onQueue = helperQ->front();
                helperQ->pop();
                if (onQueue->left == nullptr) {
                    onQueue->left = new Node(d, nullptr, nullptr);
                    break;
                }
                if (onQueue->right == nullptr) {
                    onQueue->right = new Node(d, nullptr, nullptr);
                    break;
                }
                helperQ->push(onQueue->left);
                helperQ->push(onQueue->right);
            }
        }
    };
    Node *root;
 
    struct NodeRange {
        Node* node;
        int max;
        int min;
        NodeRange(Node* n, int max, int min) {
            node = n;
            this->max = max;
            this->min = min;
        }
    };

    public:
    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data, nullptr, nullptr);
        }
    }
 
    void __printPreOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root;
        __printPreOrder(root->left);
        __printPreOrder(root->right);
    }
 
    void printPreOrder() {
        if (root == nullptr) {
            return;
        }
        __printPreOrder(root);
    }

    int __findHeight(Node *root) {
        if(root == nullptr) {
            return -1;
        } else {
            int leftHeight = __findHeight(root->left);
            int rightHeight = __findHeight(root->right);
            return max(leftHeight, rightHeight)+1 ;
        }
    }

    int findHeight() {
        return __findHeight(root);
    }

    bool __isBalanced(Node* root) {
        if (root == nullptr) {
            return true;
        } else {
            int leftHeight = __findHeight(root->left);
            int rightHeight = __findHeight(root->right);
            if (abs(leftHeight - rightHeight) <= 1) {
                bool isLeftPartOfTreeBalanced = __isBalanced(root->left);
                bool isRightPartOfTreeBalanced = __isBalanced(root->right);
                return isLeftPartOfTreeBalanced && isRightPartOfTreeBalanced;
            } else {
                return false;
            }
        }
    }

//with Recurrsion
    bool __isBst(int max, int min, Node* r) {
        if (r == nullptr) {
            return true;
        }
        if (r->data>min && r->data<max) {
           bool isLeftBST =  __isBst(r->data, min, r->left);
           bool isRightBST = __isBst(r->data, max, r->right);
           return isLeftBST && isRightBST;
        }
        return false;
    }
// Recurrsive approach
    bool isBst() {
        if (root == nullptr) {
            return true;
        }

        __isBst(INT_MAX, INT_MIN, root);
    }

    //Iterative Sol
    bool isBSTI() {
        if(root == nullptr) {
            return true;
        }
        stack<NodeRange> stack;
        stack.push(NodeRange(root, INT_MAX, INT_MIN));
        while(!stack.empty()) {
            NodeRange current = stack.top();
            stack.pop();

            Node* n = current.node;
            int max = current.max;
            int min = current.min;

            if(n->data > max || n->data < min) {
                return false;
            }
            if(n->right != nullptr) {
                stack.push(NodeRange(n->right, max, n->data));
            }
            if(n->left != nullptr) {
                stack.push(NodeRange(n->left, n->data, min));
            }
        }
        return true;
    }

    pair<int, bool> __isBalancedI(Node *r) {
        if (r == nullptr) {
            return {-1, true}; 
        } else {
            auto left = __isBalancedI(r->left);
            if(!left.second) {
                return {-1, false};
            } 
            auto right = __isBalancedI(r->right);
            if(!right.second) {
                return {-1, false};
            } 

            bool isBalanced = abs(left.first-right.first)<=1;
            int height = max(left.first, right.first)+1;
        }
    }

    bool isBalanced() {
        return __isBalancedI(root).second;
    }
};
 
int main() {
 
    BinaryTree *bt = new BinaryTree();
    //level by level insertion
    bt->insert(10);
    bt->insert(11);
    bt->insert(12);
    bt->insert(13);
    bt->insert(14);
    bt->insert(15);
    bt->insert(16);
    bt->insert(17);

 
    bt->printPreOrder();

    cout << "height of the tree is" << bt->findHeight() << endl;
    cout << "is Tree Balanced? " << bt->isBalanced() << endl;
}