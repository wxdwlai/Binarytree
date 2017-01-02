#ifndef BINTREENODE_H
#define BINTREENODE_H
template<class T>
struct BinTreeNode
{
    T data;
    BinTreeNode<T> *leftChild;
    BinTreeNode<T> *rightChild;
    BinTreeNode();
    BinTreeNode(const T &d,BinTreeNode<T> *lChild = NULL,BinTreeNode<T> *rChild = NULL);
};
#endif // BINTREENODE_H
template<class T>
BinTreeNode<T>::BinTreeNode()
{
    leftChild = NULL;
    rightChild = NULL;
}
template<class T>
BinTreeNode<T>::BinTreeNode(const T &d,BinTreeNode<T> *lChild,BinTreeNode<T> *rChild)
{
    data = d;
    leftChild = lChild;
    rightChild = rChild;
}
