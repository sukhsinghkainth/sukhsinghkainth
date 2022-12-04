
#include <iostream>
using namespace std;
struct treenode
{
    int value;
    treenode *left;
    treenode *right;
};
class binarytree
{
private:
    treenode *root;

public:
    binarytree()
    {
        root = nullptr;
    }

    void insert(int d)
    {
        treenode *trav, *parnnt;
        treenode *newnode = new treenode();
        newnode->value = d;
        newnode->left = newnode->right = nullptr;
        if (root == nullptr)

            root = newnode;

        else
        {
            trav = root;
            while (trav != NULL)
            {
                if (d > trav->value)
                {
                    if (trav->right != nullptr)
                        trav = trav->right;

                    else
                    {
                        trav->right = newnode;
                        break;
                    }
                }
                else
                {
                    if (trav->left != nullptr)
                        trav = trav->left;
                    else
                    {
                        trav->left = newnode;
                        break;
                    }
                }
            }
        }
    }
    void printinorder()
    {
        inorder(root);
    }
    void inorder(treenode *temp)
    {
        if (temp)
        {
            inorder(temp->left);
            cout << endl
                 << temp->value << endl;
            inorder(temp->right);
        }
    }
    void printpreorder()
    {
        preorder(root);
    }
    void preorder(treenode *temp)
    {

        if (temp)
        {
            cout << endl
                 << temp->value << endl;
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    void printpostorder()
    {
        postorder(root);
    }
    void postorder(treenode *temp)
    {

        if (temp)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout << endl
                 << temp->value << endl;
        }
    }
};

int main()
{

    binarytree b1;
    int click, click2, v;
    do
    {
        cout << " ----------------BINARY-TREE-------------------" << endl
             << "1 insertion in binary tree" << endl
             << " 2 display" << endl
             << " 3 exit" << endl;
        cin >> click;
        switch (click)
        {
        case 1:
            cout << " enter value to insert in binary tree" << endl;
            cin >> v;
            b1.insert(v);

            break;
        case 2:
            cout << "---------display functions-------" << endl
                 << "1 inorder" << endl
                 << "2 preorder" << endl
                 << "3 postorder" << endl;
            cin >> click2;
            switch (click2)
            {
            case 1:
                b1.printinorder();
                break;
            case 2:
                b1.printpreorder();

                break;
            case 3:
                b1.printpostorder();
                break;
            }
            break;
        case 3:
            exit(1);
            break;
        }

    } while (click != 4 || click2 != 4);

    return 0;
}