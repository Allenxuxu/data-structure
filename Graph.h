#ifndef GRAPH_H
#define GRAPH_H

#include "Object.h"
#include "SharedPointer.h"
#include "Array.h"
#include "DynamicArray.h"
#include "LinkQueue.h"
#include "LinkStack.h"

namespace XXLib
{
template <typename E >
struct Edge : public Object
{
    int b;
    int e;
    E data;

    Edge(int i=-1, int j=-1) :b(i),e(j)
    { }

    Edge(int i, int j,const E& value) : b(i),e(j),data(value)
    { }

    bool operator ==(const Edge<E>& obj)
    {
        return ( (b == obj.b) && (e == obj.e) );
    }

    bool operator !=(const Edge<E>& obj)
    {
        return !operator ==(obj);
    }
};


template < typename V, typename E >
class Graph : public Object
{
protected:
    template <typename T>
    DynamicArray<T>* toArray(LinkQueue<T>& queue)
    {
        DynamicArray<T>* ret = new DynamicArray<T>(queue.length());

        if( ret != NULL)
        {
            for(int i =0; i< ret->length(); i++, queue.remove() )
            {
                ret->set(i,queue.front());
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughtMemoryException, "No memory to create ret object ...");
        }
        return ret;
    }

public:
    virtual V getVertex(int i) =0;
    virtual bool getVertex(int i, V& value) =0;
    virtual bool setVertex(int i,const V& value) =0;
    virtual SharedPointer< Array<int> > getAdjacent(int i) =0;
    virtual E getEdge(int i, int j) =0;
    virtual bool getEdge(int i, int j, E& value) =0;
    virtual bool setEdge(int i, int j, const E& value) =0;
    virtual bool removeEdge(int i, int j) =0;
    virtual int vCount() =0;
    virtual int eCount() =0;
    virtual int OD(int i) =0;
    virtual int ID(int i) =0;
    virtual int TD(int i)
    {
        return OD(i) + ID(i);
    }

    virtual bool isAdjacent(int i, int j) =0;

    bool asUndirected()
    {
        bool ret = true;

        for(int i=0; i<vCount(); i++)
        {
            for(int j=0; j<vCount(); j++)
            {
                if( isAdjacent(i,j) )
                {
                    ret = ret && isAdjacent(j,i) && (getEdge(i, j) == getEdge(j, i));
                }
            }
        }
        return ret;
    }

    SharedPointer< Array<int> > BFS(int i)
    {
        DynamicArray<int>* ret = NULL;

        if( (0<=i) && (i<vCount()) )
        {
            LinkQueue<int> queue;
            LinkQueue<int> r;
            DynamicArray<bool> visited(vCount());

            for(int i=0; i< visited.length(); i++)
            {
                visited.set(i,false);
            }

            queue.add(i);

            while(queue.length() > 0)
            {
                int v = queue.front();
                queue.remove();

                if( !visited[v] )
                {
                    SharedPointer<Array<int>> aj = getAdjacent(v);
                    for(int i=0; i< aj->length(); i++)
                    {
                        queue.add((*aj)[i]);
                    }

                    r.add(v);
                    visited[v] = true;
                }
            }

            ret = toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid ...");
        }

        return ret;
    }

    SharedPointer< Array<int> > DFS(int i)
    {
        DynamicArray<int>* ret = NULL;

        if( (0<=i) && (i<vCount()) )
        {
            LinkStack<int> stack;
            LinkQueue<int> r;
            DynamicArray<int> visited(vCount());

            for(int i=0; i<visited.length(); i++)
            {
                visited[i] = false;
            }

            stack.push(i);

            while( stack.size() > 0 )
            {
                int v = stack.top();
                stack.pop();
                if( !visited[v] )
                {
                    SharedPointer<Array<int> > aj = getAdjacent(v);
                    for(int i=0; i<aj->length(); i++)
                    {
                        stack.push((*aj)[i]);
                    }

                    r.add(v);
                    visited[v] = true;
                }
            }

            ret =  toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid ...");
        }
        return ret;
    }

    SharedPointer<Array<int> > dijkstra(int i, int j, const E& LIMIT)
    {
        LinkQueue<int> ret;

        if( (0<=i) && (i<vCount()) && (0<=j) && (j<vCount()) )
        {
            DynamicArray<E> dist( vCount() );
            DynamicArray<int> path( vCount() );
            DynamicArray<bool> mark( vCount() );

            for( int k=0; k<vCount(); k++)
            {
                mark[k] = false;
                path[k] = -1;
                dist[k] = isAdjacent(i,k) ? (path[k] =i, getEdge(i, k) ) : LIMIT;
            }
            
            mark[i] = true;
            for(int k=0; k<vCount(); k++)
            {
                E m = LIMIT;
                int u = -1;

                for(int w=0; w<vCount(); w++)
                {
                    if( !mark[w]  &&  (dist[w] < m) )
                    {
                        m = dist[w];
                        u = w;
                    }
                }

                if( u == -1 )
                {
                    break;
                }

                mark[u] = true;

                for( int w=0; w<vCount(); w++)
                {
                    if( !mark[w] && isAdjacent(u,w) && (dist[u] + getEdge(u,w) < dist[w]) )
                    {
                        dist[w] = dist[u] + getEdge(u,w);
                        path[w] = u;
                    }
                }
            }

            LinkStack<int> s;
            s.push(j);
            for(int k=path[j]; k!=-1; k=path[k] )
            {
                s.push(k);
            }

            while( s.size() > 0)
            {
                ret.add(s.top());
                s.pop();
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index <i, j> is invalid ...");
        }

        if( ret.length() < 2)
        {
            THROW_EXCEPTION(ArithmeticException, "There is no path from i to j ...");
        }

        return toArray(ret);
    }
};

}

#endif // GRAPH_H
