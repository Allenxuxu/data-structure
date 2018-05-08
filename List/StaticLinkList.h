#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include "LinkList.h"
namespace XXLib
{
    template<typename T, int N>
    class StaticLinkList : public LinkList<T>
    {
    protected:
        typedef  typename LinkList<T>::Node Node;
        struct SNode: public Node
        {
            void* operator new(size_t size, void* loc)
            {
                (void)size;
                return loc;
            }
        };

        unsigned char m_space[sizeof(SNode) * N];
        int m_used[N];

        SNode* create()
        {
            SNode* ret = NULL;
            for(int i=0; i<N; i++)
            {
                if( !m_used[i])
                {
                    ret = reinterpret_cast<SNode*>(m_space) + i;
                    ret = new(ret)SNode();  //此处只是为了让SNode调用构造函数
                    m_used[i] = 1;
                    break;
                }
            }
            return ret;
        }

        void destroy(Node *pn)
        {
            SNode* space = reinterpret_cast<SNode*>(m_space);
            SNode* psn = dynamic_cast<SNode*>(pn);
            for(int i=0; i<N; i++)
            {
                if(psn == (space + i))
                {
                    m_used[i] = 0;
                    psn->~SNode();
                    break;
                }
            }
        }

    public:
        StaticLinkList()
        {
            for(int i=0; i<N; i++)
            {
                m_used[i] = 0;
            }
        }

        int capacity()
        {
            return N;
        }

        ~StaticLinkList()
        {
            this->clear();              //  调用父类的clear(), 由于析构函数不存在多态（调用析构函数时虚函数表已经销毁），
        }                               //  所以 clear() 调用的destroy() 是子类的。
    };                                  //  总结： 析构函数不存在多态，只会调用当前类的成员函数。

}


#endif // STATICLINKLIST_H
