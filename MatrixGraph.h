#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "Graph.h"
#include "Exception.h"
#include "DynamicArray.h"

namespace XXLib
{
template <int N, typename V, typename E>
class MatrixGraph : public Graph<V,E>
{
protected:
    V* m_vertexes[N];
    E* m_edges[N][N];
    int m_eCount;
public:
    MatrixGraph()
    {
        for(int i=0; i<vCount(); i++)
        {
            m_vertexes[i] = NULL;

            for(int j=0; j<vCount(); j++)
            {
                m_edges[i][j] = NULL;
            }
        }
        m_eCount = 0;
    }

    V getVertex(int i)
    {
        V ret;
        if( !getVertex(i,ret) )
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid ...");
        }
        return ret;
    }

    bool getVertex(int i, V& value)
    {
        bool ret = ( (0<=i ) && ( i<vCount() ) );
        if( ret )
        {
            if( m_vertexes[i] != NULL )
            {
                value = *(m_vertexes[i]);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException,"No value assigned to this vertex ...");
            }
        }
        return ret;
    }

    bool setVertex(int i,const V& value)
    {
        bool ret = ( (0<=i ) && ( i<vCount() ) );
        if( ret )
        {
            if( m_vertexes[i] == NULL)
            {
                V* data = new V(value);
                if ( data == NULL)
                {
                    THROW_EXCEPTION(NoEnoughtMemoryException, "No memory to store new vertex value ...");
                }
                else
                {
                    m_vertexes[i] = data;
                }
            }
            else
            {
                *(m_vertexes[i]) = value;
            }
        }
        return ret;
    }

    SharedPointer< Array<int> > getAdjacent(int i)
    {
        DynamicArray<int>* ret = NULL;
        if( (0<=i) && (i<vCount()))
        {
            int n = 0;
            for(int j=0; j<vCount();j++)
            {
                if(m_edges[i][j] != NULL)
                {
                    ++n;
                }
            }

            if( n>0 )
            {
                ret = new DynamicArray<int>(n);
                if( ret != NULL)
                {
                    for(int j=0, k=0; j<vCount(); j++)
                    {
                        if( m_edges[i][j] != NULL)
                        {
                            ret->set(k++,j);
                        }
                    }
                }
                else
                {
                    THROW_EXCEPTION(InvalidParameterException,"Index i is invalid ...");
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"");
        }
        return ret;
    }

    E getEdge(int i, int j)
    {
        E ret;
        if( !getEdge(i,j,ret) )
        {
            THROW_EXCEPTION(InvalidParameterException,"Index <i,j> is invalid ...");
        }
        return ret;
    }

    bool getEdge(int i, int j, E& value)
    {
        bool ret = ( (0<=i) && (i<vCount()) && (0<=j) && (j<vCount() ));
        if( ret )
        {
            if( m_edges[i] != NULL)
            {
                value = *(m_edges[i][j]);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException,"No value assigned to this vertex ...");
            }
        }
        return ret;
    }

    bool setEdge(int i, int j, const E& value)
    {
         bool ret = ( (0<=i) && (i<vCount()) && (0<=j) && (j<vCount() ));
         if( ret )
         {
             if(  m_edges[i][j] == NULL)
             {
                 E* ne = new E(value);
                 if( ne != NULL)
                 {
                     m_edges[i][j] = ne;
                     ++m_eCount;
                 }
                 else
                 {
                     THROW_EXCEPTION(NoEnoughtMemoryException,"");
                 }
             }
             else
             {
                *(m_edges[i][j]) = value;
             }
         }

         return ret;
    }

    bool removeEdge(int i, int j)
    {
        bool ret = ( (0<=i) && (i<vCount()) && (0<=j) && (j<vCount() ));
        if( ret &&  m_edges[i][j] != NULL )
        {
                E* toDel = m_edges[i][j];
                m_edges[i][j] = NULL;
                m_eCount--;
                delete toDel;
        }
        return ret;
    }

    int vCount()
    {
        return N;
    }

    int eCount()
    {
        return m_eCount;
    }

    int OD(int i)
    {
        int ret = 0;
        if( (0<=i) && (i<vCount()) )
        {
            for(int j=0; j< vCount(); j++)
            {
                if( m_edges[i][j] != NULL)
                {
                    ++ret;
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"Index i is invalid ...");
        }
    }

    int ID(int i)
    {
        int ret = 0;
        if( (0<=i) && (i<vCount()) )
        {
            for(int j=0; j< vCount(); j++)
            {
                if( m_edges[j][i] != NULL)
                {
                    ++ret;
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"Index i is invalid ...");
        }
    }

    bool isAdjacent(int i, int j)
    {
        return ( 0 <= i ) && ( i < vCount() ) && (0 <= j ) && ( j < vCount() ) && ( m_edges[i][j] != NULL ) ;
    }

    ~MatrixGraph()
    {
        for( int i=0; i<vCount(); i++)
        {
            for(int j=0; j<vCount(); j++)
            {
                delete m_edges[i][j];
            }
            delete m_vertexes[i];
        }
    }
};
}

#endif // MATRIXGRAPH_H
