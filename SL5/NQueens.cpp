# include <iostream>
using namespace std;

//positions is 2D array of positions of queen

bool isSafe(int positions[][10], int row, int col, int size) {

	int i;
	
	for(i=0; i<size; i++)//check if queen is present in that row
		if(row==positions[i][0]) return false; 
	
	for(i=0; i<size; i++) //check if queen is present in that col
		if(col==positions[i][1]) return false;

}

void NQueens(int size) {

	int chessBoard[10][10];
	int i, j;
	
}


int main() {

	int size;
	cout << "\n\tENTER CHESS BOARD SIZE : ";
	cin >> size;
	
}