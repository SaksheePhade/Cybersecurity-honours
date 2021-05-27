/*

33243
SAKSHEE PHADE
TE 10
Bellman-ford: Dijikstras but works for -ve edges
*/
# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

# define INT_MAX 99999

struct Edge {
    int src;
    int dest;
    int weight;
};

class Graph {
  int V, E;
  //int cost[20][20];
  //bool set[20];
  int dist[100], parent[100];
  int srcVertex;

  struct Edge* edge;
  public :
    void create();
    void display();
    void BellmanFord();
    void printPath(int);    
};

void Graph :: create() {
  int i,j;
  cout << "\n\tENTER NUMBER OF VERTICES AND EDGES : ";
  cin >> V >> E;
  //vertex validations
  do{
    cout << "\n\tEnter the source vertex : ";
    cin >> srcVertex;

    if(srcVertex<=0 || srcVertex>V) cout << "\n\tINCORRECT VERTEX";  
  }while(srcVertex<=0 || srcVertex>V);
  

  edge = new Edge[E]; //array of edges   
  cout << "\n\t===EDGES===" << endl;
  for(i=0; i<E; i++) {
    
    do{
      cout << "\n\tEnter source : ";
      cin >> edge[i].src;
      if(edge[i].src>V || edge[i].src<=0) cout << "\n\tINCORRECT VERTEX";
    }while(edge[i].src>V || edge[i].src<=0);  

    do{
      cout << "\n\tEnter destination : ";
      cin >> edge[i].dest;
      if(edge[i].dest>V || edge[i].dest<=0) cout << "\n\tINCORRECT VERTEX";
    }while(edge[i].dest>V || edge[i].dest<=0);

    if(edge[i].src==edge[i].dest) { //validation
      cout << "\n\tSOURCE AND DESTINATION CAN'T BE SAME!";
      i--;  
    }
    else {
      cout << "\n\tEnter weight(" << edge[i].src << ", " << edge[i].dest << ") : ";
      cin >> edge[i].weight;
    }
  }    

  
}

void Graph :: display() {
  int i,j;
  cout << "\n\tGRAPH NODES :- ";
  for(i=0; i<V; i++) cout << " " << i+1;
  cout << endl;
  cout << "\t======================================" << endl;
  cout << "\n\tSOURCE\tDESTINATION\tWEIGHT" << endl;
  cout << "\t======================================" << endl;
  for(i=0; i<E; i++) {
    cout << "\t" << edge[i].src+1 << "\t" << edge[i].dest+1 << "\t\t" << edge[i].weight;
    cout << endl;
  }
  cout << "\t======================================" << endl;
}


void Graph :: printPath(int j) {       
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
    if(parent[j]!=INT_MAX) {
      printPath(parent[j]); 
      printf(" -> %d ", j+1);  
    }  
}

void Graph :: BellmanFord() {

  int u, v, weight, i;
  vector<int> path; 

  for (int i = 0; i < V; i++) { //initialization step
      dist[i] = INT_MAX;
      parent[i] = INT_MAX;
  }
  dist[srcVertex] = 0;
  parent[srcVertex] = -1;

  for (int i=0; i<V-1; i++) { //for V-1 times, do
    for (int j=0; j<E; j++) { // for each edge check most optimal soln
            u = edge[j].src;
            v = edge[j].dest;
            weight = edge[j].weight;

            if (dist[u]!=INT_MAX && dist[u]+weight<dist[v]) { //relaxation step
                dist[v]=dist[u]+weight; // update distance if it is lesser than previous
                parent[v] = u;
                path.push_back(v);
                cout << "\n\t===PATH===" << endl;
                cout << "\t";
                for(int p=0; p<path.size(); p++) {
                    cout << " -> " << path[p]+1;   //iterative path
                }
                cout << "\n\t==========" << endl;
                for(int k=0; k<V; k++) {
                  cout << "\t" << k+1 << "\t" << dist[k] << "\t";  
                  printPath(k); //recursive path
                  cout << endl;
                }
            }
            //path.clear();
    }

    path.clear();
  }

    //checking for negative cycle
    for (i = 0; i < E; i++) {
        u = edge[i].src;
        v = edge[i].dest;
        weight = edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "\n\t**NEGATIVE CYCLE**";
            return;
        }
    }

    cout << "\t======================================" << endl;
    cout << "\n\tVERTEX\tDIST FROM SOURCE" << endl;
    cout << "\t======================================" << endl;
    for(i=0; i<V; i++) {
      cout << "\t" << i+1 << "\t" << dist[i] << endl;
    }

}



int main() {
  Graph G;
  G.create();
  G.display();
  G.BellmanFord();
  return 0;
}

/*
sakshee@sakshee-Vostro-3580:~/TE2/DAA$ ./a.out

  ENTER NUMBER OF VERTICES AND EDGES : 5 8

  Enter the source vertex : 0

  ===EDGES===

  Enter source : 0

  Enter destination : 1

  Enter weight(0, 1) : -1

  Enter source : 0

  Enter destination : 2

  Enter weight(0, 2) : 4

  Enter source : 1

  Enter destination : 2

  Enter weight(1, 2) : 3

  Enter source : 1

  Enter destination : 3

  Enter weight(1, 3) : 2

  Enter source : 1

  Enter destination : 4

  Enter weight(1, 4) : 2

  Enter source : 3

  Enter destination : 2

  Enter weight(3, 2) : 5

  Enter source : 3

  Enter destination : 1

  Enter weight(3, 1) : 1

  Enter source : 4

  Enter destination : 3

  Enter weight(4, 3) : -3

  GRAPH NODES :-  1 2 3 4 5
  ======================================

  SOURCE  DESTINATION WEIGHT
  ======================================
  1 2   -1
  1 3   4
  2 3   3
  2 4   2
  2 5   2
  4 3   5
  4 2   1
  5 4   -3
  ======================================

    ===PATH===
   -> 2
  ==========
  1 0 
  2 -1   -> 2 
  3 99999 
  4 99999 
  5 99999 

  ===PATH===
   -> 2 -> 3
  ==========
  1 0 
  2 -1   -> 2 
  3 4  -> 3 
  4 99999 
  5 99999 

  ===PATH===
   -> 2 -> 3 -> 3
  ==========
  1 0 
  2 -1   -> 2 
  3 2  -> 2  -> 3 
  4 99999 
  5 99999 

  ===PATH===
   -> 2 -> 3 -> 3 -> 4
  ==========
  1 0 
  2 -1   -> 2 
  3 2  -> 2  -> 3 
  4 1  -> 2  -> 4 
  5 99999 

  ===PATH===
   -> 2 -> 3 -> 3 -> 4 -> 5
  ==========
  1 0 
  2 -1   -> 2 
  3 2  -> 2  -> 3 
  4 1  -> 2  -> 4 
  5 1  -> 2  -> 5 

  ===PATH===
   -> 2 -> 3 -> 3 -> 4 -> 5 -> 4
  ==========
  1 0 
  2 -1   -> 2 
  3 2  -> 2  -> 3 
  4 -2   -> 2  -> 5  -> 4 
  5 1  -> 2  -> 5 
  ======================================

  VERTEX  DIST FROM SOURCE
  ======================================
  1 0
  2 -1
  3 2
  4 -2
  5 1

sakshee@sakshee-Vostro-3580:~/TE2/DAA$ 

*/