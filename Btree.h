#ifndef BTREE_H
#define BTREE_H

#include "Tree.h"
#include "Exception.h"
#include "LinkQueue.h"
#include "DynamicArray.h"

namespace XXLib
{
enum BTnodePos
{
    ANY,
    LEFT,
    RIGHT
};

enum BTTraversal
{
    preOrder,
    inOrder,
    postOrder
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
            ret->parent = NULL;
            ret->m_right = NULL;
            ret->m_left = NULL;
            ret->value = 0;
        }
        return ret;
    }
};

template <typename T>
class BTree : public Tree<T>
{
protected:
    LinkQueue<BTreeNode<T>* > m_queue;

    BTreeNode<T>* find(BTreeNode<T>* node,T value) const
    {
        BTreeNode<T>* ret = NULL;
        if( node != NULL)
        {
            if( node->value == value)
            {
                return node;
            }
            else
            {

                if( (ret = find(node->m_left,value) ) == NULL)
                {
                    ret = find(node->m_right,value);
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
            if(node != NULL)
            {
                if( (ret = find(node->m_left,obj)) == NULL)
                {
                    ret = find(node->m_right,obj);
                }
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

    void free(BTreeNode<T>* node)
    {
        if( node != NULL)
        {
            free(node->m_left);
            free(node->m_right);

            if( node->flag())
                delete node;
        }
    }

    void remove(BTreeNode<T>* node,BTree<T>*& ret)
    {
        ret = new BTree<T>();
        if( ret )
        {
            if( root() == node)
            {
                this->m_root = NULL;
            }
            else
            {
                BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);

                if(parent->m_left == node)
                {
                    parent->m_left = NULL;
                }
                else if( parent->m_right == node)
                {
                    parent->m_right = NULL;
                    //                    std::cout << "va: " << parent->m_right->value <<endl;
                }
                node->parent = NULL;
            }
            ret->m_root = node;

        }
        else
        {
            THROW_EXCEPTION(NoEnoughtMemoryException, "... ");
        }
    }

    int count(BTreeNode<T>* node) const
    {
        //        int ret = 0;
        //        if( node == NULL)
        //        {
        //            ret = 0;
        //        }
        //        else
        //        {
        //            ret = count(node->m_left) + count(node->m_right) + 1;
        //        }
        //        return ret;
        return (node==NULL) ? (0) : (count(node->m_left) + count(node->m_right) + 1) ;
    }

    int height(BTreeNode<T>* node) const
    {
        int ret = 0 ;
        if(node != NULL)
        {
            int lh = height(node->m_left);
            int rh = height(node->m_right);

            ret =( (lh < rh)? rh : lh ) + 1;
        }
        return ret;
    }

    int degree(BTreeNode<T>* node) const
    {
        int ret = 0;
        if( node != NULL)
        {
            BTreeNode<T>* child[] = {node->m_left, node->m_right};
            ret = !!child[0] + !!child[1];

            for (int i = 0; i<2; i++)
            {
                if( ret < 2)
                {
                    int d = degree(child[i]);
                    if( d > ret)
                    {
                        ret = d;
                    }
                }
            }
            //            ret  = !!node->m_left + !!node->m_right; //如果 左边节点为空，!!node->m_left = 0
            //            if( ret < 2)
            //            {
            //                int d = degree(node->m_left);
            //                if( d > ret)
            //                {
            //                    ret = d;
            //                }
            //            }

            //            if( ret < 2)
            //            {
            //                int d = degree(node->m_right);
            //                if( d > ret)
            //                {
            //                    ret = d;
            //                }
            //            }
        }
        return ret;
    }

    void preOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
    {
        if( node != NULL)
        {
            queue.add(node);
            preOrderTraversal(node->m_left,queue);
            preOrderTraversal(node->m_right,queue);
        }
    }

    void inOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
    {
        if( node != NULL)
        {

            inOrderTraversal(node->m_left,queue);
            queue.add(node);
            inOrderTraversal(node->m_right,queue);
        }
    }

    void postOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
    {
        if( node != NULL)
        {

            postOrderTraversal(node->m_left,queue);
            postOrderTraversal(node->m_right,queue);
            queue.add(node);
        }
    }

    BTreeNode<T>* clone(BTreeNode<T>* node) const
    {
        BTreeNode<T>* ret =NULL;
        if( node != NULL)
        {
            ret = BTreeNode<T>::NewNode();
            if( ret != NULL)
            {
                ret->value = node->value;
                ret->m_left = clone(node->m_left);
                ret->m_right = clone(node->m_right);

                if( ret->m_left != NULL)
                    ret->m_left->parent = ret;
                if( ret->m_right != NULL)
                    ret->m_right->parent = ret;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughtMemoryException, " ... ");
            }
        }
        return ret;
    }

    bool equal(BTreeNode<T>* lh,BTreeNode<T>* rh)
    {
        if( lh == rh)
        {
            return true;
        }
        else if( (lh != NULL) && (rh != NULL))
        {
            return ((lh->value == rh->value) && equal(lh->m_left,lh->m_right) && equal(rh->m_left,rh->m_right));
        }
        else
        {
            return false;
        }
    }

public:
    bool operator ==(const BTree<T>& obj)
    {
        return equal(root(), obj.root());
    }

    bool operator !=(const BTree<T>& obj)
    {
        return !(*this == obj);
    }

    SharedPointer<BTree<T>> clone() const
    {
        BTree<T>*  ret = new BTree<T>();
        if( ret != NULL)
        {
            ret->m_root = clone(root());
        }
        else
        {
            THROW_EXCEPTION(NoEnoughtMemoryException," ...");
        }
        return ret;
    }

    SharedPointer<Array<T>> tarversal( BTTraversal order)
    {
        DynamicArray<T>* ret=NULL;
        LinkQueue<BTreeNode<T>*> queue;
        switch (order) {
        case preOrder:
            preOrderTraversal(root(),queue);
            break;
        case inOrder:
            inOrderTraversal(root(),queue);
            break;
        case postOrder:
            postOrderTraversal(root(),queue);
            break;
        default:
            THROW_EXCEPTION(InvalidParameterException," order ...");
            break;
        }
        ret = new DynamicArray<T>(queue.length());
        if( ret != NULL)
        {
            for(int i=0; i< ret->length(); i++, queue.remove())
            {
                ret->set(i,queue.front()->value);
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughtMemoryException, " .. ");
        }

        return ret;

    }

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
        BTree<T>* ret = NULL;
        BTreeNode<T>* node = find(value);
        if( node)
        {
            remove(node,ret);
            m_queue.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "..");
        }
        return ret;
    }

    SharedPointer<Tree<T> > remove(TreeNode<T>* node)
    {
        BTree<T>* ret = NULL;
        node = find(node);
        if( node )
        {
            remove(dynamic_cast<BTreeNode<T>*>(node),ret);
            m_queue.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"...");
        }
        return ret;
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
        return degree(root());
    }
    int count() const
    {
        return count(root());
    }
    int height() const
    {
        return height(root());
    }
    void clear()
    {
        free(root());
        m_queue.clear();
        this->m_root = NULL;
    }


    void begin()
    {
        m_queue.clear();
        m_queue.add(root());
    }

    bool end()
    {
        return (m_queue.length() == 0);
    }

    bool next()
    {
        bool ret = !end();
        if( ret)
        {
            BTreeNode<T>* node = m_queue.front();
            m_queue.remove();

            if(node->m_left != NULL)
            {
                m_queue.add(node->m_left);
            }

            if( node->m_right != NULL)
            {
                m_queue.add(node->m_right);
            }
        }
        return ret;
    }

    T  current()
    {
        if( !end())
        {
            return  m_queue.front()->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"No value at current position ... ");
        }
    }
};
}

#endif // BTREE_H
