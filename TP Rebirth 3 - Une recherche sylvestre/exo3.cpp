#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct BinarySearchTree : public BinaryTree
{    
    Node* left;
    Node* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this->left=NULL;
        this->right=NULL;
        this->value=value;
    }

    void insertNumber(int value)
    {
        // create a new node and insert it in right or left child
        if (value < this->value){
            if (this->left == nullptr) {
                this->left = createNode(value);
            }
            else {
                this->left->insertNumber(value);
            }
        }
        else{
            if (this->right == nullptr) {
                this->right = createNode(value);
            }
            else {
                this->right->insertNumber(value);
            }
        }
    }



    uint height() const {
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        uint GOCHE=0;
        uint DROATE=0;
        if (this->left == nullptr && this->right == nullptr) {
            return 1;
        }
        else {
            if (this->left != nullptr) {
                GOCHE = 1 + this->left->height();
            }
            if (this->left != nullptr) {
                DROATE = 1 + this->left->height();
            }
        }

        if (DROATE < GOCHE) {
            return GOCHE;
        }
        return DROATE;

    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        uint COMPTEUR_EXTREME=1;

        if (this->left != nullptr) {
            COMPTEUR_EXTREME = COMPTEUR_EXTREME + this->left->nodesCount();
        }
        if (this->right != nullptr) {
            COMPTEUR_EXTREME = COMPTEUR_EXTREME + this->right->nodesCount();
        }
        return COMPTEUR_EXTREME;
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if (this->left == nullptr && this->right == nullptr) {
            return true;
        }
        return false;
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree

        if (this-> isLeaf()) {
            leaves[leavesCount] = this;
            leavesCount ++;
        }

        if (this->left != nullptr) {
            this->left->allLeaves(leaves, leavesCount);
        }
        if (this->right != nullptr) {
            this->right->allLeaves(leaves, leavesCount);
        }

	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel


        if (this->left != nullptr) {
            this->left->inorderTravel(nodes, nodesCount);
        }

        nodes[nodesCount] = this;
        nodesCount ++;

        if (this->right != nullptr) {
            this->right->inorderTravel(nodes, nodesCount);
        }
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel

        nodes[nodesCount] = this;
        nodesCount++;

        if (this->left != nullptr) {
            this->left->preorderTravel(nodes, nodesCount);
        }

        if (this->right != nullptr) {
            this->right->preorderTravel(nodes, nodesCount);
        }
    }


	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel

        if(this->left != nullptr) {
            this->left->postorderTravel(nodes, nodesCount);
        }

        if (this->right != nullptr) {
            this->right->postorderTravel(nodes, nodesCount);
        }

        nodes[nodesCount] = this;
        nodesCount++;

	}

	Node* find(int value) {
        // find the node containing value
        if (this->value == value) {
            return (Node*)this;
        }
        else if (this->value > value && this->left != nullptr) {
                return(this->left->find(value));
        }
        else if (this->value < value && this->right != nullptr) {
                return(this->right->find(value));
        }

        return nullptr;

	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    BinarySearchTree(int value) : BinaryTree(value) {initNode(value);}
    ~BinarySearchTree() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new BinarySearchTree(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<BinarySearchTree>();
	w->show();

	return a.exec();
}
