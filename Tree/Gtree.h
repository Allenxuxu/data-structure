#ifndef GTREE_H
#define GTREE_H

#include "Tree.h"
#include "LinkList.h"
#include "LinkQueue.h"
#include "Exception.h"
namespace XXLib
{
template <typename T>
class GTreeNode : public TreeNode<T>
{
public:
    LinkList<GTreeNode<T> *> child;

    static GTreeNode<T>* NewNode()
    {
        GTreeNode<T>* ret = new GTreeNode();
        if(ret != NULL)
        {
            ret->m_flag = true;
        }
        return ret;
    }
};

template <typename T>
class GTree : public Tree<T>
{
protected:
    LinkQueue<GTreeNode<T>*> m_queue;


    GTreeNode<T>* find(GTreeNode<T>* node,const T& value) const
    {
        GTreeNode<T>* ret = NULL;

        if( node!=NULL)
        {
            if( node->value == value)
            {
                return node;
            }
            else
            {
                for( node->child.move(0); !node->child.end() && (ret == NULL); node->child.next())
                {
                    ret = find(node->child.current(),value);
                }
            }
        }
        return ret;
    }

    GTreeNode<T>* find(GTreeNode<T>* node,GTreeNode<T>* obj) const
    {
        GTreeNode<T>* ret = NULL;

        if(node == obj)
        {
            return node;
        }
        else
        {
            if(node != NULL)
            {
                for( node->child.move(0); !node->child.end()  && (ret == NULL) ; node->child.next())
                {
                    ret = find(node->child.current(), obj);
                }
            }
        }

        return ret;
    }

    void treeFree(GTreeNode<T>* node)
    {
        if(node)
        {
            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                treeFree(node->child.current());
            }
            if( node->flag())
            {
                delete node;
            }
        }
    }

    void remove(GTreeNode<T>* node, GTree<T>*& ret)
    {
        ret = new GTree();
        if(ret == NULL)
        {
            THROW_EXCEPTION(NoEnoughtMemoryException,"No enought memory to create new tree ...");
        }
        else
        {
            LinkList<GTreeNode<T>*>& child = dynamic_cast<GTreeNode<T>*>(node->parent)->child;
            child.remove(child.find(node));
            node->parent = NULL;
        }
        ret->m_root = node;
    }

    int count(GTreeNode<T>* node) const
    {
        int ret = 0;
        if( node != NULL)
        {
            ret = 1;
            for( node->child.move(0); !node->child.end(); node->child.next())
            {
                ret += count(node->child.current());
            }
        }
        return ret;
    }

    int height(GTreeNode<T>* node)const
    {
        int ret = 0;
        if (node != NULL)
        {
            for( node->child.move(0); !node->child.end(); node->child.next())
            {
                int h = height(node->child.current());
                if ( h > ret)
                {
                    ret = h;
                }
            }
            ret +=1;
        }

        return ret;
    }

    int degree(GTreeNode<T>* node) const
    {
        int ret = 0;
        if( node != NULL)
        {
            ret = node->child.length();

            for( node->child.move(0); !node->child.end(); node->child.next())
            {
                int len = degree(node->child.current());
                if (ret <len )
                {
                    ret = len;
                }
            }
        }
        return ret;
    }

public:
    GTree()
    {

    }

    bool insert(TreeNode<T> * node)
    {
        bool ret = true;
        if( node != NULL)
        {
            if( this->m_root == NULL)
            {
                node->parent = NULL;
                this->m_root = node;
            }
            else
            {
                GTreeNode<T>* n = find(node->parent);
                if( n != NULL)
                {
                    GTreeNode<T>* p = dynamic_cast<GTreeNode<T>*>(node);
                    if( n->child.find(p) < 0)
                        n->child.push_back(p);
                }
                else
                {
                    THROW_EXCEPTION(InvalidOperationException,"Invalid parent tree node ...");
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"parameter node cannot be NULL ...");
        }
        return ret;
    }

    virtual bool insert(const T& value, TreeNode<T>* parent)
    {
        bool ret = true;
        GTreeNode<T>* node = GTreeNode<T>::NewNode();
        if( node != NULL)
        {
            node->value = value;
            node->parent = parent;
            insert(node);
        }
        else
        {
            THROW_EXCEPTION(NoEnoughtMemoryException,"No memory to create new tree node ...");
        }
        return ret;
    }

    SharedPointer<Tree<T> > remove(const T& value)
    {
        GTree<T>* ret = NULL;

        GTreeNode<T>* node = find(value);
        if( node == NULL)
        {
            THROW_EXCEPTION(InvalidParameterException,"Invalid value to find tree node ...");
        }
        else
        {
            remove(node,ret);
            m_queue.clear();
        }

        return ret;
    }

    SharedPointer<Tree<T> > remove(TreeNode<T>* node)
    {
        GTree<T>* ret = NULL;

        node = find(dynamic_cast<GTreeNode<T>*>(node));
        if( node == NULL)
        {
            THROW_EXCEPTION(InvalidParameterException,"Invalid value to find tree node ...");
        }
        else
        {
            remove(dynamic_cast<GTreeNode<T>*>(node),ret);
            m_queue.clear();
        }

        return ret;
    }

    GTreeNode<T>* find(const T& value) const
    {
        return  find(root(),value);
    }

    GTreeNode<T>* find(TreeNode<T>* node) const
    {
        return find(root(), dynamic_cast<GTreeNode<T>*>(node));
    }

    GTreeNode<T>* root() const
    {
        return dynamic_cast<GTreeNode<T>*> (this->m_root);
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
        return  height(root());
    }


    void clear()
    {
        treeFree(root());
        this->m_root = NULL;

        m_queue.clear();
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
            GTreeNode<T>* node = m_queue.front();
            m_queue.remove();

            for( node->child.move(0); !node->child.end(); node->child.next())
            {
                m_queue.add(node->child.current());
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

#endif // GTREE_H
