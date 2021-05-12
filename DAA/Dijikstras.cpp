/*
33243 Sakshee Phade
*/
# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Graph {
	int N;
	int cost[20][20];
	bool set[20];
	int dist[20], parent[20];
	int source;
	public :
		void create();
		void display();
		void Dijikstras();
		int minDistance();
		void printPath(int);
};

int Graph :: minDistance() {
	int i, min=9999, minIndex=0;
	for(i=0; i<N; i++) {
		if(set[i]==false && dist[i] <= min) {
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void Graph :: create() {
	int i,j;
	char ch='n';
	cout << "\n\tEnter number of nodes : ";
	cin >> N;
	cout << "\n\tEnter the source vertex : ";
	cin >> source;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			cost[i][j] = 0;
			
			
	do {
		cout << "\nEnter edge : ";
		cin >> i >> j;
		cout << "\nEnter the distance between " << i << " and " << j << " : ";
		cin >> cost[i][j];
		cost[j][i] = cost[i][j];
		cout << "\nDo you want to enter edge again(y/n) ? " ;
		cin >> ch;
	}while(ch=='y' || ch=='Y');
	
}

void Graph :: display() {
	int i,j;
	cout << "\n\tGRAPH NODES :- ";
	for(i=0; i<N; i++) cout << " " << i;
	cout << "\t=============================================================" << endl;
	cout << "\n\tGRAPH IN ADJACENCY MATRIX REPRESENTATION :- " << endl;
	cout << "\t=============================================================" << endl;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			cout << "\t" << cost[i][j];
		}
		cout << endl;
	}
	cout << "\t=============================================================" << endl;
}

void Graph :: printPath(int j) {       
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  
    printPath(parent[j]); 
    printf(" -> %d ", j); 
} 

void Graph :: Dijikstras() {
	int i,j,u,v;
	//dist[0] = 0;//source is 1st vertex
	for(i=1; i<N; i++) dist[i] = 9999;
	dist[source] = 0;
	parent[0] = -1;
	
	for(i=0; i<N-1; i++) {
		u = minDistance();
		set[u] = true;
		
		for(v=0; v<N; v++) {
			if (!set[v] && cost[u][v]
                && dist[u] + cost[u][v] < dist[v]) {
                	parent[v] = u;
                	dist[v] = dist[u] + cost[u][v];
				}  
		}
	}
	cout << "\t=============================================================" << endl;
	cout << "\n\tVERTEX\t\tSHORTEST DISTANCE FROM SOURCE\tPATH" << endl;
	cout << "\t=============================================================" << endl;
	for(i=0; i<N; i++) {
		cout << "\t" << source << " -> " << i << "\t\t" << dist[i] << "\t" << source  ;
		printPath(i);
		cout << endl; 
	}
	cout << "\t=============================================================" << endl;
	
		
}


int main() {
	Graph G;
	G.create();
	G.display();
	G.Dijikstras();
	return 0;
}

/*

        Enter number of nodes : 9

        Enter the source vertex : 0

Enter edge : 0 7

Enter the distance between 0 and 7 : 8

Do you want to enter edge again(y/n) ? y

Enter edge : 0 1

Enter the distance between 0 and 1 : 4

Do you want to enter edge again(y/n) ? y

Enter edge : 1 7

Enter the distance between 1 and 7 : 11

Do you want to enter edge again(y/n) ? y

Enter edge : 1 2

Enter the distance between 1 and 2 : 8

Do you want to enter edge again(y/n) ? y

Enter edge : 7 8

Enter the distance between 7 and 8 : 7

Do you want to enter edge again(y/n) ? y

Enter edge : 7 6

Enter the distance between 7 and 6 : 1

Do you want to enter edge again(y/n) ? y

Enter edge : 2 8

Enter the distance between 2 and 8 : 2

Do you want to enter edge again(y/n) ? y

Enter edge : 8 6

Enter the distance between 8 and 6 : 6

Do you want to enter edge again(y/n) ? y

Enter edge : 2 3

Enter the distance between 2 and 3 : 7

Do you want to enter edge again(y/n) ? y

Enter edge : 2 5

Enter the distance between 2 and 5 : 4

Do you want to enter edge again(y/n) ? y

Enter edge : 6 5

Enter the distance between 6 and 5 : 2

Do you want to enter edge again(y/n) ? y

Enter edge : 3 5

Enter the distance between 3 and 5 : 14

Do you want to enter edge again(y/n) ? y

Enter edge : 3 4

Enter the distance between 3 and 4 : 9

Do you want to enter edge again(y/n) ? y

Enter edge : 5 4

Enter the distance between 5 and 4 : 10

Do you want to enter edge again(y/n) ? n

        GRAPH NODES :-  0 1 2 3 4 5 6 7 8       
		=============================================================

        GRAPH IN ADJACENCY MATRIX REPRESENTATION :-
        =============================================================
        0       4       0       0       0       0       0       8       0
        4       0       8       0       0       0       0       11      0
        0       8       0       7       0       4       0       0       2
        0       0       7       0       9       14      0       0       0
        0       0       0       9       0       10      0       0       0
        0       0       4       14      10      0       2       0       0
        0       0       0       0       0       2       0       1       6
        8       11      0       0       0       0       1       0       7
        0       0       2       0       0       0       6       7       0
        =============================================================
        =============================================================

        VERTEX          SHORTEST DISTANCE FROM SOURCE   PATH
        =============================================================
        0 -> 0          0       0
        0 -> 1          4       0 -> 1
        0 -> 2          12      0 -> 1  -> 2
        0 -> 3          19      0 -> 1  -> 2  -> 3
        0 -> 4          26      0 -> 1  -> 2  -> 5  -> 4
        0 -> 5          16      0 -> 1  -> 2  -> 5
        0 -> 6          9    	0 -> 7  -> 6
        0 -> 7          8       0 -> 7
        0 -> 8          14      0 -> 1  -> 2  -> 8
        =============================================================

--------------------------------
Process exited after 130.5 seconds with return value 0
Press any key to continue . . .
*/
