# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Graph {
	int N;
	int dist[4][4] = {
		{0, 2, 9, 10},
		{1, 0, 6, 4},
		{15, 7, 0, 8},
		{6, 3, 12, 0}
	};
	int dp_table[16][4];
	int all_visited;
	vector<int> cities;
	public :
		Graph() {

			all_visited = (1<<4) - 1;

			for(int i=0; i<(1<<4); i++) 
				for(int j=0; j<4; j++) 
					dp_table[i][j] = -1;
		}

		void create();
		void display();
		int g(int mask, int position);
		
};

int Graph :: g(int mask, int position) {
	//Base Case Set = {}

	cout << "\n\tMask : " << mask;
	cout << "\n\tAll visited: " << all_visited;

	if(mask==all_visited)
		return dist[position][0]; // last city to source

	if(dp_table[mask][position]!=-1)
		return dp_table[mask][position];

	int mincost = 99999;

	for(int curr_city=0; curr_city<4; curr_city++) {
		//check for unvisited city
		if(mask&(1<<curr_city)==0) {// if city is unvisited
			int cost = dist[position][curr_city] + g(mask | (1<<curr_city), curr_city); // bitwise OR function updates mask value
			int mincost = min(mincost, cost);

			cout << "\n\tMincost : " << mincost;

			cities.push_back(mincost);
		}	

	}

	dp_table[mask][position] = mincost;	
}

void Graph :: display() {
	int i,j;
	
	cout << "\n\t============================================" << endl;
	cout << "\n\tGRAPH IN ADJACENCY MATRIX REPRESENTATION :- " << endl;
	cout << "\t==============================================" << endl;
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			cout << "\t" << dist[i][j];
		}
		cout << endl;
	}
	cout << "\t==============================================" << endl;

	cout << "\n\tCITIES :- " ;
	for(i=0; i<cities.size(); i++) {
		cout << "\t" << cities[i];
	}

	cout << endl;

}


int main() {
	Graph G;
	G.g(0, 0);
	G.display();
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
