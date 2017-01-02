# Binarytree
The creation of a basic binarytree and what it can do.
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include"BinTreeNode.h"
using namespace std;
template<class T>
class BinaryTree
{
protected:
    BinTreeNode<T> *root;
    ///辅助函数
   /// BinTreeNode<T> *CopyTree(BinTreeNode<T> *t);///复制二叉树t
    void Destroy(BinTreeNode<T> * &r);///删除以r为根的二叉树
   /// void PreOrder(BinTreeNode<T> *r,void (*Visit)(const T &)) const;///先序遍历
    ///void InOrder(BinTreeNode<T> *r,void (*Visit)(const T &)) const;///中序遍历
   /// void PostOrder(BinTreeNode<T> *r,void (*Visit)(const T &)) const;///后序遍历
   // int Hight(const BinTreeNode<T> *r) const;///求以r为根的二叉树的高度
    ///int NodeCount(const BinTreeNode<T> *r) const;///求以r为根的二叉树的节点的个数
    BinTreeNode<T> *Parent(BinTreeNode<T> *r,const BinTreeNode<T> *p) const;///在以r为根的二叉树中求p的双亲
    void ShowHelp(BinTreeNode<T> *p);
public:
    BinaryTree();
    BinaryTree(const T &e);///构造以e为根的二叉树
    virtual ~BinaryTree();
    bool IsEmpty() const;
    BinTreeNode<T> *LeftSibling(const BinTreeNode<T> *p)u const;
    BinTreeNode<T> *RightSibling(const BinTreeNode<T> *p) const;
    void InserLeftChild(BinTreeNode<T> *p,const T &e);
    void InserRightChild(BinTreeNode<T> *p,const T &e);
    BinTreeNode<T> *GetRoot() const;///求二叉树的根

   /* 
    int GetElem(BinTreeNode<T> *p,T &e) const;
    int SetElem(BinTreeNode<T> *p,T &e);
    void InOrder(void (*Visit)(const T &)) const;
    void PreOrder(void (*Visit)(const T &)) const;
    void PostOrder(void (*Visit)(const T &)) const;
    void LevelOrder(void (*Visit)(const T &)) const;///二叉树的层次遍历
    BinTreeNode<T> *LeftChild(const BinTreeNode<T> *p) const;
    BinTreeNode<T> *RightChild(const BinTreeNode<T> *p) const;

    BinTreeNode<T> *Parent(const BinTreeNode<T> *p) const;

    void DeleteL(BinTreeNode<T> *p);
    void DeleteR(BinTreeNode<T> *p);
    int Hight() const;
    BinaryTree(const BinaryTree<T> &t);
    BinaryTree(BinTreeNode<T> *r);///建立以r为根的二叉树
    BinaryTree & operator=(const BinTreeNode<T> &t);///赋值运算符重载
    */
    void Show();
};
#endif // BINARYTREE_H

template<class T>
BinaryTree<T>::BinaryTree()  
{
    root = NULL;
}

template<class T>
BinaryTree<T>::BinaryTree(const T &e)
{
    root = new BinTreeNode<T>;
    root->leftChild = root->rightChild = NULL;
    root->data = e;
}

template<class T>
void BinaryTree<T>::Destroy(BinTreeNode<T> * &r)
{
    if (r != NULL)	{
		Destroy(r->leftChild);
		Destroy(r->rightChild);
		delete r;
		r=NULL;
	}
}
template<class T>
BinaryTree<T>::~BinaryTree()
{
    Destroy(root);
}

template<class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *r,const BinTreeNode<T> *p) const
{
    if(r==NULL) return NULL;
    else if(r->leftChild==p||r->rightChild==NULL)
        return r;
    else{
        BinTreeNode<T> *t;
        t = Parent(r->leftChild,p);
        if(t!=NULL) return t;
        t = Parent(r->rightChild,p);
        if(t!=NULL)
            return t;
        else return NULL;
    }
}

template<class T>
bool BinaryTree<T>::IsEmpty() const
{
    if(root==NULL)
        return true;
    else return false;
}

template<class T>
BinTreeNode<T> *BinaryTree<T>::LeftSibling(const BinTreeNode<T> *p) const
{
    BinTreeNode<T> *pre = new BinTreeNode<T>;
    pre = Parent(root,p);
    if(p==NULL)
        return NULL;
    else if(pre->rightChild==p) return pre->leftChild;
    else return NULL;
}

template<class T>
BinTreeNode<T> *BinaryTree<T>::RightSibling(const BinTreeNode<T> *p) const
{
    BinTreeNode<T> *pre;
    pre = Parent(root,p);
    if(pre==NULL)
        return NULL;
    else if(pre->leftChild==p)
        return pre->rightChild;
    else return NULL;
}

template<class T>
void BinaryTree<T>::InserLeftChild(BinTreeNode<T> *p,const T &e)
{
    if(p==NULL)
        return;
    else{
      BinTreeNode<T> child = new BinTreeNode<T>(e);
      p->leftChild = child;
      if(p->leftChild!=NULL)
        child->leftChild = p->leftChild;
      p->rightChild = child;
      return ;
    }
}

template<class T>
void InserRightChild(BinTreeNode<T> *p,const T &e)
{
    if(p==NULL)
        return ;
    else{
        BinTreeNode<T> child = new BinTreeNode<T>(e);
        if(p->rightChild!=NULL)
            child->rightChild = p->rightChild;
        p->rightChild = child;
        return ;
    }
}

template<class T>
BinTreeNode<T> *BinaryTree<T>::GetRoot() const
{
    
}









template<class T>
void BinaryTree<T>::ShowHelp(BinTreeNode<T> *p)
{
    if(p==NULL) return ;
    cout<<p->data<<endl;
    if(p->leftChild!=NULL)
        ShowHelp(p->leftChild);
    if(p->rightChild!=NULL)
        ShowHelp(p->rightChild);
}
template<class T>
void BinaryTree<T>::Show()
{
   ShowHelp(root);
}
