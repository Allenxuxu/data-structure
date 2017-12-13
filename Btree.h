#ifndef BTREE_H
#define BTREE_H

#include "tree.h"

namespace XXLib
{
enum BTnodePos
{
    ANY,
    LEFT,
    RIGHT
};


template <typename T>
class BTreeNode : public TreeNode<T>
{
public:
    BTreeNode<T>* m_left;
    BTreeNode<T>* m_right;

    static BTreeNode<T>* NewNode()
    {
        BTreeNode<T>* ret = new BTreeNode();
        if(ret != NULL)
        {
            ret->m_flag = true;
        }
        return ret;
    }
};

template <typename T>
class BTree : public Tree<T>
{
protected:
    BTreeNode<T>* find(BTreeNode<T>* node,T value) const
    {
        BTreeNode<T>* ret = NULL;
        if( node->value == value)
        {
            return node;
        }
        else
        {
            if( node != NULL)
            {
                if( (ret = find(node->m_left,value) ) == NULL)
                {
                    ret = find(node->m_right);
                }
            }
        }
        return ret;
    }

    BTreeNode<T>* find(BTreeNode<T>* node, BTreeNode<T>* obj) const
    {
        BTreeNode<T>* ret =NULL;
        if( node == obj)
        {
            return node;
        }
        else
        {
            if( (ret = find(node->m_left,obj)) == NULL)
            {
                ret = find(node->m_right,obj);
            }
        }
        return ret;
    }

    virtual bool insert(BTreeNode<T>* node, BTreeNode<T>* nodeParent, BTnodePos pos)
    {
        bool ret = true;

        switch (pos)
        {
        case ANY:
            if(nodeParent->m_left == NULL)
            {
                nodeParent->m_left = node;
            }
            else if(nodeParent->m_right == NULL)
            {
                nodeParent->m_right = node;
            }
            else
            {
                ret = false;
            }
            break;

        case LEFT:
            if(nodeParent->m_left == NULL)
            {
                nodeParent->m_left = node;
            }
            else
            {
                ret = false;
            }
            break;

        case RIGHT:
            if(nodeParent->m_right == NULL)
            {
                nodeParent->m_right = node;
            }
            else
            {
                ret = false;
            }
            break;

        default:
            ret =false;
            break;
        }

        return ret;
    }

public:

    bool insert(TreeNode<T> * node)
    {
        return insert(dynamic_cast<BTreeNode<T>*>(node),ANY);
    }

    virtual bool insert(BTreeNode<T>* node,BTnodePos pos)
    {
        bool ret = true;
        if(node != NULL)
        {
            if( this->m_root == NULL)
            {
                node->parent = NULL;
                this->m_root = node;
            }
            else
            {
                BTreeNode<T>* nP = find(node->parent);
                if( nP != NULL)
                {
                    ret = insert(dynamic_cast<BTreeNode<T>*>(node),nP,pos);
                }
                else
                {
                    THROW_EXCEPTION(InvalidParameterException,"Invalid parent tree node ... ");
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"Parameter node can not be NULL");
        }

        return ret;
    }

   bool insert(const T& value, TreeNode<T>* parent)
   {
       return insert(value, parent,ANY);
   }

    virtual bool insert(const T& value, TreeNode<T>* parent, BTnodePos  pos)
    {
        bool ret = true;
        BTreeNode<T>* node = BTreeNode<T>::NewNode();

        if( node != NULL)
        {
            node->value = value;
            node->parent = parent;
            ret = insert(node, pos);

            if( !ret )
            {
                delete node;
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughtMemoryException,"No memory to create new node ... ");
        }
        return ret;
    }

    SharedPointer<Tree<T> > remove(const T& value)
    {

    }

    SharedPointer<Tree<T> > remove(TreeNode<T>* node)
    {

    }

    BTreeNode<T>* find(const T& value) const
    {
        return find(root(), value);
    }
    BTreeNode<T>* find(TreeNode<T>* node) const
    {
        return find(root() , dynamic_cast<BTreeNode<T>*>(node));
    }
    BTreeNode<T>* root() const
    {
        return  dynamic_cast<BTreeNode<T>*>(this->m_root);
    }
    int degree() const
    {

    }
    int count() const
    {

    }
    int height() const
    {

    }
    void clear()
    {

    }
};
}

#endif // BTREE_H
