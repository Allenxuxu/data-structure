#ifndef TREE_H
#define TREE_H
#include "Object.h"
#include "SharedPointer.h"

namespace  XXLib
{
template <typename T>
class TreeNode : public Object
{
protected:
    bool m_flag;
    TreeNode(const TreeNode<T>&);
    TreeNode<T>& operator = (const TreeNode<T>&);

    void* operator new(size_t size) throw()
    {
        return Object:: operator new(size);
    }
public:
    T value;
    TreeNode<T>* parent;

    TreeNode()  : m_flag(false), parent(NULL)
    {}

    bool flag()
    {
        return m_flag;
    }

    virtual ~TreeNode() = 0;
};

template< typename T >
TreeNode<T>::~TreeNode()
{

}

template < typename T>
class Tree : public Object
{
protected:
    TreeNode<T>* m_root;

    Tree(const Tree<T>&);
    Tree& operator =(const Tree<T>&);
public:
    Tree() : m_root(NULL)
    {}
    virtual bool insert(TreeNode<T> * node) = 0;
    virtual bool insert(const T& value, TreeNode<T>* parent) = 0;
    virtual SharedPointer<Tree<T> > remove(const T& value) = 0;
    virtual SharedPointer<Tree<T> > remove(TreeNode<T>* node) = 0;
    virtual TreeNode<T>* find(const T& value) const  =0;
    virtual TreeNode<T>* find(TreeNode<T>* node) const =0;
    virtual TreeNode<T>* root() const = 0;
    virtual int degree() const =0;
    virtual int count() const =0;
    virtual int height() const=0;
    virtual void clear() =0;
};

}

#endif // TREE_H
