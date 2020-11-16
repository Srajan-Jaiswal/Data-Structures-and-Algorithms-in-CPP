#include<iostream>
#include<list>
#include<climits>
using namespace std;
class Graph{
    int V,E;

    struct Edge{
    int v,w;
    int weight;
    };

    list<Edge> edges;
public:
    Graph(int V,int E);
    void addEdge(int s,int d,int w);
    void bellmanFord(int s);
};

Graph::Graph(int V,int E){
this->V= V;
this->E=E;
}

void Graph::addEdge(int s,int d,int wt)
{
    struct Edge e;
    e.v=s;
    e.w=d;
    e.weight=wt;
    edges.push_back(e);
}

void Graph::bellmanFord(int s){
    int dist[V];

    for(int i=0;i<V;i++)
        dist[i]=INT_MAX;
    dist[s]=0;
    list<Edge>::iterator j;
    for(int i=1;i<V;i++){ //Relax ALL edges V-1 times.
        for(j=edges.begin();j!=edges.end();j++){
            int v =  (*j).v;
            int w =  (*j).w;
            int weight = (*j).weight;
            if(dist[v]+ weight < dist[w])
                dist[w]=dist[v]+weight;
        }
    }
    for(j=edges.begin();j!=edges.end();j++){
            int v =  (*j).v;
            int w =  (*j).w;
            int weight = (*j).weight;
            if(dist[v]+ weight < dist[w])
                cout<<"Negative Cycle Exists !"<<endl;
        }
    cout<<"Vertex - Distance from Source"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"  "<<dist[i]<<endl;
    }
}


int main(){

Graph g(5,8);
g.addEdge(0,1,-1);
g.addEdge(0,2,4);
g.addEdge(1,2,3);
g.addEdge(1,3,2);
g.addEdge(1,4,2);
g.addEdge(3,2,5);
g.addEdge(3,1,1);
g.addEdge(4,3,-3);

g.bellmanFord(0);

return 0;
}
