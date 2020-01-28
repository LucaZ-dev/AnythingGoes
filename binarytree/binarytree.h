#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <iomanip>      // std::setw

using namespace std;

class binarytree
{
    binarytree();

    struct tree
    {
     int iData;
     tree* left;
     tree* right;

     tree(int i) : iData(i), left(nullptr), right(nullptr) {
     }
    };

public:
    void add(int i) {
        tree* temp = mRoot;
        if(mRoot == nullptr) {
            cout << "Insert new tree with value " << i << endl;
            mRoot = new tree(i);
            return;
        }

        while(true) {
            if(temp->iData <= i) {
//            while(true) {
                if(temp->right == nullptr) {
                    temp->right = new tree(i);
                    cout << "Insert new tree right with value " << i << endl;
                    return;
                }
                else {
                    temp = temp->right;
                    cout << "Going right" << endl;
                    cout << temp->iData << endl;
            }
//                }
        }
        else if(temp->iData > i) {
//            while(true) {
                if(temp->left == nullptr) {
                    temp->left = new tree(i);
                cout << "Insert new tree left with value " << i << endl;
                return;
                } else {
                    temp = temp->left;
                    cout << "Going left" << endl;
                    cout << temp->iData << endl;
                }
             }
//        }

        }

//        else {
//            cout << "Int already in use, good luck." << endl;
//            return;
//        }

    }

    void print_graphictree(int i) {
        graphictree(mRoot, i);
    }

    void graphictree(tree* p, int indent = 4)
    {
        if(p != nullptr) {
            if(p->right) {
                graphictree(p->right, indent+4);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
            std::cout<< p->iData << "\n ";
            if(p->left) {
                std::cout << std::setw(indent) << ' ' <<" \\\n";
                graphictree(p->left, indent+4);
            }
        }
    }

    void print(tree* tree) {
        if(tree->left != nullptr)
            print(tree->left);
        cout << tree->iData << endl;
        if(tree->right != nullptr)
            print(tree->right);
    }

    tree* mRoot = nullptr;
};



#endif // BINARYTREE_H
