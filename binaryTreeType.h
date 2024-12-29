//Header File Binary Tree
#ifndef H_binaryTree
#define H_binaryTree

//*************************************************************
// Author: D.S. Malik
//
// class binaryTreeType
// This class specifies the basic operations to implement a
// binary tree.
//*************************************************************

#include <iostream>

using namespace std;

     //Definition of the node
template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

   //Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&); 
      //Overload the assignment operator.
    bool isEmpty() const;
      //Returns true if the binary tree is empty;
      //otherwise, returns false.
    int treeHeight() const;
      //Returns the height of the binary tree.
    void destroyTree();
      //Deallocates the memory space occupied by the binary tree.
      //Postcondition: root = NULL;
    binaryTreeType(const binaryTreeType<elemType>& otherTree); 
      //copy constructor
    binaryTreeType();   
      //default constructor
    ~binaryTreeType();   
      //destructor

  void buildExampleTree1();
  void buildExampleTree2();
    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.

    int leafCount() const;
      //Returns the number of leaves in the binary tree.

  int internalNodes() const;
      //Returns the number of internal nodes in the binary tree.

  int singleChild() const;
      //Returns the number of nodes with only one child in the binary tree.

  int twoChildren() const;
      //Returns the number of nodes with two in the binary tree.

    int nodeCount() const;
      //Returns the number of total nodes in the binary tree.

protected:
    binaryTreeNode<elemType> *root;

private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
                  binaryTreeNode<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. The pointer copiedTreeRoot  
      //points to the root of the copied binary tree.
    void destroy(binaryTreeNode<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: p = NULL
    int height(binaryTreeNode<elemType> *p) const;
      //Function to return the height of the binary tree
      //to which p points. 
    int max(int x, int y) const;
      //Returns the larger of x and y.

  void inorder(binaryTreeNode<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  

  int leafCountRec(binaryTreeNode<elemType> *p) const;
      //Function to return the number of leaves in the binary 
      //tree to which p points 	  

  int internalNodesRec(binaryTreeNode<elemType> *p) const;
      //Function to return the number of internal nodes in the binary 
      //tree to which p points 	  

  int singleChildRec(binaryTreeNode<elemType> *p) const;
      //Function to return the number of nodes with only one child in the binary 
      //tree to which p points 	  

  int twoChildrenRec(binaryTreeNode<elemType> *p) const;
      //Function to return the number of nodes with two children in the binary 
      //tree to which p points 	  

  int nodeCountRec(binaryTreeNode<elemType> *p) const;
      //Function to return the number of total nodes in the binary 
      //tree to which p points 	  
};

//Definition of member functions
template <class elemType>
void binaryTreeType<elemType>::buildExampleTree1()
{
    root = new binaryTreeNode<int>;
  root->info = 1;

  root->llink = new binaryTreeNode<int>;
  root->llink->info = 3;
  root->llink->llink = NULL;
  root->llink->rlink = NULL;	

  root->rlink = new binaryTreeNode<int>;
  root->rlink->info = 2;

  root->rlink->llink = new binaryTreeNode<int>;
  root->rlink->llink->info = 5;
  root->rlink->llink->llink = NULL;
  root->rlink->llink->rlink = NULL;

  root->rlink->rlink = new binaryTreeNode<int>;
  root->rlink->rlink->info = 4;
  root->rlink->rlink->llink = NULL;	
  root->rlink->rlink->rlink = NULL;	

  return;
}

template <class elemType>
void binaryTreeType<elemType>::buildExampleTree2()
{
  root = new binaryTreeNode<int>;
  root->info = 8;

  root->llink = new binaryTreeNode<int>;
  root->llink->info = 3;

  root->llink->llink = new binaryTreeNode<int>;
  root->llink->llink->info = 1;
  root->llink->llink->llink = NULL;
  root->llink->llink->rlink = NULL;	

  root->llink->rlink = new binaryTreeNode<int>;
  root->llink->rlink->info = 6;

  root->llink->rlink->llink = new binaryTreeNode<int>;
  root->llink->rlink->llink->info = 4;
  root->llink->rlink->llink->llink = NULL;
  root->llink->rlink->llink->rlink = NULL;	

  root->llink->rlink->rlink = new binaryTreeNode<int>;
  root->llink->rlink->rlink->info = 7;
  root->llink->rlink->rlink->llink = NULL;
  root->llink->rlink->rlink->rlink = NULL;	

  root->rlink = new binaryTreeNode<int>;
  root->rlink->info = 10;
  root->rlink->llink = NULL;

  root->rlink->rlink = new binaryTreeNode<int>;
  root->rlink->rlink->info = 14;
  root->rlink->rlink->rlink = NULL;	

  root->rlink->rlink->llink = new binaryTreeNode<int>;
  root->rlink->rlink->llink->info = 13;
  root->rlink->rlink->llink->llink = NULL;
  root->rlink->rlink->llink->rlink = NULL;	

    return;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        inorder(p->llink);
        cout << p->info << " ";
        inorder(p->rlink);
    }
}

template <class elemType>
int binaryTreeType<elemType>::leafCount() const
{
  return leafCountRec(root);
}

template <class elemType>
int binaryTreeType<elemType>::leafCountRec(binaryTreeNode<elemType> *p) const
{
  if (p == NULL) return 0;
  else if (p->llink == NULL && p->rlink == NULL) return 1;
  else return leafCountRec(p->llink) + leafCountRec(p->rlink);
}

template <class elemType>
int binaryTreeType<elemType>::internalNodes() const
{
  return internalNodesRec(root);
}

template <class elemType>
int binaryTreeType<elemType>::internalNodesRec(binaryTreeNode<elemType> *p) const
{
  // what goes here?
  if(p==NULL)
    return 0;
  else if(p->llink !=NULL && p->rlink !=NULL)
    return 1 + internalNodesRec(p->llink) + internalNodesRec(p->rlink);
  else
    return internalNodesRec(p->llink) + internalNodesRec(p->rlink);
}

template <class elemType>
int binaryTreeType<elemType>::singleChild() const
{
  return singleChildRec(root);
}

template <class elemType>
int binaryTreeType<elemType>::singleChildRec(binaryTreeNode<elemType> *p) const
{
  // what goes here?
  if(p==NULL)
    return 0;
  else if(p->llink==NULL && p->rlink!=NULL)
    return 1 + singleChildRec(p->rlink);
  else if(p->llink!=NULL && p->rlink==NULL)
    return 1 + singleChildRec(p->llink);
  else
    return singleChildRec(p->llink) + singleChildRec(p->rlink);
  return 0;
}

template <class elemType>
int binaryTreeType<elemType>::twoChildren() const
{
  return twoChildrenRec(root);
}

template <class elemType>
int binaryTreeType<elemType>::twoChildrenRec(binaryTreeNode<elemType> *p) const
{

  if(p==NULL)
    return 0;
  else if(p->llink != NULL && p->rlink !=NULL)
    return 1 + twoChildrenRec(p->llink) + twoChildrenRec(p->rlink);
  else 
    return twoChildrenRec(p->llink) + twoChildrenRec(p->rlink);
  return 0;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount() const
{
  return nodeCountRec(root);
}

template <class elemType>
int binaryTreeType<elemType>::nodeCountRec(binaryTreeNode<elemType> *p) const
{
  // what goes here?
  if(p==NULL)
    return 0;
  else
    return 1 + nodeCountRec(p->llink) + nodeCountRec(p->rlink);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = NULL;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
                      (binaryTreeNode<elemType>* &copiedTreeRoot,
                   binaryTreeNode<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new binaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
} //end copyTree

     //Overload the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
           operator=(const binaryTreeType<elemType>& otherTree)
{  
    if (this != &otherTree) //avoid self-copy
    {
        if (root != NULL)  //if the binary tree is not empty, 
                           //destroy the binary tree
            destroy(root);

        if (otherTree.root == NULL) //otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this; 
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

  //copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
              (const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

template <class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}
#endif