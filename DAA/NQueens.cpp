# include <iostream>
using namespace std;

//positions is 2D array of positions of queen
//first positions are
// -1 -1
// -1 -1
// -1 -1
// -1 -1

//considering size x size chessborad

int positions[10][10];

//returns if its safe for queen to be placed
bool isSafe(int positions[][10], int row, int col, int size) {

	int i, j, k;
	
	for(i=0; i<size; i++)//check if queen is present in that row
		if(row==positions[i][0]) return false; 
	
	for(i=0; i<size; i++) //check if queen is present in that col
		if(col==positions[i][1]) return false;

	for(k=0; k<size && positions[k][0]!=-1; k++) {

		i=0;

		while(row-i>=0 && col-i>=0) {
			if(positions[k][0]==row-i && positions[k][1]==col-i) return false;
			i++;
		}

		while(row+i<size && col-i>=0) { 
			if(positions[k][0]==row+i && positions[k][1]==col-i) return false;
			i++;
		}

		while(row-i>=0 && col+i<size) { 
			if(positions[k][0]==row-i && positions[k][1]==col+i) return false;
			i++;
		}

		while(row+i<size && col+i<size) {
			if(positions[k][0]==row-i && positions[k][1]==col+i) return false;
			i++;
		}

		

		/*
		while(row-i>=0 && row+i<size && col-i>=0 && col+i<size) {
			if(positions[k][0]==row-i && positions[k][1]==col-i) return false; 
			if(positions[k][0]==row+i && positions[k][1]==col-i) return false;
			if(positions[k][0]==row-i && positions[k][1]==col+i) return false;
			if(positions[k][0]==row+i && positions[k][1]==col+i) return false;

			i++;
		}*/

	}

	return true;
	/*
	finding digonal issafe	
		0 1 2 3
	  0 Q + + +
	  1	+ + + +
	  2	+ Q + +
	  3	+ + + +
	
	 01 21

	 10 10 row decr. col decr keep decreading until out of limit
	 12 30 row incr, col decr
	 23 12 row dec, col incr

	*/

}

bool NQueens(int positions[][10], int col, int size) {

	//int positions[10][10] = {{-1, -1},{-1, -1},{-1, -1},{-1, -1}};
	int i, j;

	cout << "\n\tCURRENT COLUMN : " <<  col;

	if(col>=size) return true;
	
	for(i=0; i<size; i++) {
		
		if(isSafe(positions, i, col, size)) {
			positions[i][0] = i;
			positions[i][1] = col;

			cout << "\n\tPOSITIONS(PASSES) : " << endl;
			for(i=0; i<size; i++) {
				cout << positions[i][0] << " " << positions[i][1] << endl;
			}
			if(NQueens(positions, col+1, size))
				return true;
		}
		
	}

	return false;
	
}


int main() {

	int size, i;
	cout << "\n\tENTER CHESS BOARD SIZE : ";
	cin >> size;

	for(i=0; i<size; i++) {
		positions[i][0] = -1;
		positions[i][1] = -1;		
	}

	NQueens(positions, 0, size);
	cout << "\n\tPOSITIONS : " << endl;
	for(i=0; i<size; i++) {
		cout << positions[i][0] << " " << positions[i][1] << endl;
	}
	//cout << "Safe? " << isSafe(positions, 3, 2, 4) << endl;
	
	return 0;
}