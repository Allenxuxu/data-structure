#include <iostream>
#include "SmartPointer.h"
#include "Exception.h"
#include "SeqList.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "StaticLinkList.h"
#include "SharedPointer.h"
#include "CircleList.h"
#include "DualLinkList.h"
#include "DualCircleList.h"
#include"StaticStack.h"
#include "LinkStack.h"
#include "StaticQueue.h"
#include "LinkQueue.h"
#include "XXString.h"
#include <cstring>
#include "Sort.h"
#include <ctime>
#include "Gtree.h"
#include "Btree.h"
#include "Graph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
using namespace std;
using namespace XXLib;

void DFS(Graph<double, int>& graph, int v,Array<int>& visited)
{
    if( (0<=v && (v<=visited.length())))
    {
        cout << v << endl;
        visited[v] =true;

        SharedPointer<Array<int> > aj = graph.getAdjacent(v);
        for(int i=0;i <aj->length(); i++)
        {
            if( !visited[ (*aj)[i] ] )
            {
                DFS(graph,(*aj)[i], visited);
            }
        }
    }
    else
    {

    }
}


void DFS(Graph<double,int>& graph, int v)
{
    DynamicArray<int> visited(graph.vCount());
    for( int i=0; i<visited.length(); i++)
    {
        visited[i] = false;
    }

    DFS(graph, v,visited);
}

void test()
{
    ListGraph<double , int> map(6);

    map.setVertex(0,1);
    map.setVertex(1,2);
    map.setVertex(2,9);
    map.setVertex(3,2);
    map.setVertex(4,2);
    map.setVertex(5,2);
    cout << "----------------------" << endl;
    cout << map.setEdge(0,1,10);
    cout << map.setEdge(1,0,11);
    cout<<  map.setEdge(0,2,11);
    cout<<  map.setEdge(2,0,11);
    cout<< map.setEdge(0,3,10);
    cout<< map.setEdge(3,0,10);
    cout<< map.setEdge(4,1,10);
    cout<< map.setEdge(1,4,10);
    cout<< map.setEdge(4,5,10);
    cout<< map.setEdge(5,4,10);
    cout << endl<< "----------------------" << endl;
    cout <<  map.vCount() << endl;
    cout << map.getEdge(0,1) << endl;
    SharedPointer<Array<int> > p = map.getAdjacent(0);
    int i = -1;
    for( int k=0; k < p->length(); k++)
    {
        cout <<"bool :"<< p->get(k,i)<< endl;
        cout <<i<<endl;
    }
    SharedPointer< Array<int> > sa = map.BFS(0);
    for( int i=0; i < sa->length(); i++)
    {
        cout << "   " << (*sa)[i] <<endl;
    }

    cout <<"55555" << endl;
    DFS(map,0);

}

template< typename V, typename E>
Graph<V,E>& GraphComple()
{
    static ListGraph<V,E> g(5);

    if(
    g.setEdge(0,1,10) &&
    g.setEdge(0,3,30) &&
    g.setEdge(0,4,100) &&

    g.setEdge(1,2,50) &&

    g.setEdge(2,4,10) &&

    g.setEdge(3,2,20) &&
    g.setEdge(3,4,60) )
    {
        cout << "complete ok!" << endl;
    }

    return g;
}

int main(void)
{
    try
    {
    Graph<int,int>& g = GraphComple<int, int>();
    SharedPointer< Array<int> > p =g.dijkstra(0,4,5555);

    for(int i=0; i<p->length(); i++)
    {
        cout << (*p)[i] << " ";
    }
    cout << endl;
    }
    catch( Exception& e )
    {
        cout << e.location() <<" " << e.message() << endl;
    }
}
