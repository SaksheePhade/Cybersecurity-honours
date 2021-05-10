#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <cstring>
using namespace std;

//prototypes
vector<string> isInstruction(string);
bool isLiteral(string);
bool isSymbol(string);
bool isConstant(string);

vector<string> hashTable[30];
int LC=-1;
int hashTableSize=30;

string SymbolTable[100][100];
int SymTab=0;
string LiteralTable[100][100];
int LitTab=0;


int hashFunc(string str, int collision) {
	int i, sum=0;
	for(i=0; i<str.size(); i++) {
		sum=sum+str[i];
		sum=sum%hashTableSize;
	}
	return collision?sum+1:sum;
}

void displayVect(vector<string> vect) {
	int i;
	for(i=0; i<vect.size(); i++) {
		cout << vect[i];
	}
}

vector<string> isInstruction(string str) {

	vector<string> v;
	//in MOT hashtable 1 gives opcode and 3 gives type
	if(hashTable[hashFunc(str, 0)].at(0)==str) return hashTable[hashFunc(str, 0)];
	else return v;
}

string getType(string str) {

	if(str=="AREG") return "(r, 01)";
	else if(str=="BREG") return "(r, 02)";
	else if(str=="CREG") return "(r, 03)";
	else if(str=="DREG") return "(r, 04)";
	else if(str=="LT") return "(cc, 01)";
	else if(str=="LE") return "(cc, 02)";
	else if(str=="GT") return "(cc, 03)";
	else if(str=="GE") return "(cc, 04)";
	else if(str=="EQ") return "(cc, 05)";
	else if(str=="NE") return "(cc, 06)";
	else if(str=="ANY") return "(cc, 07)";
	else if(isConstant(str)) return "(C, " + str + ")";
	else if(isLiteral(str)) {

		for(int i=0; i<LitTab; i++) {
			if(LiteralTable[i][1]==str) {
				return "(L, " +  to_string(i) + ")";
			}
		}


		LiteralTable[LitTab][0] = to_string(LitTab);
		LiteralTable[LitTab][1] = str;
		return "(L, " +  to_string(LitTab++) + ")";
	}
	else {

		for(int i=0; i<SymTab; i++) {
			if(SymbolTable[i][1]==str) {
				return "(S, " +  to_string(i) + ")";
			}
		}

		SymbolTable[SymTab][0] = to_string(SymTab);
		SymbolTable[SymTab][1] = str;
		return "(S, " +  to_string(SymTab++) + ")"; 
	}
}

bool isConstant(string str) {
	return isdigit(str[0]);
}

bool isStart(string str) {
	return str=="START";
}

bool isLiteral(string str) {
	if(str.find("'") != string::npos)
		return true;
	else return false;	
}

void createHashTable(string arr[100][100], int rows) {
	int collision, i, j;
	string Instruction;
	
		for(i=0; i<rows+1; i++) {
			collision=0;
			for(j=0; j<5; j++) {
				if(j==0) Instruction = arr[i][j];
				else {
					
					if(j==1 && hashTable[hashFunc(Instruction, collision)].at(0)!="-") collision=1;//checks if there is collision by checking - at 0th element
																									 //of hashTable
					if(hashTable[hashFunc(Instruction, collision)].at(0)=="-") {//checks if field is empty
					  	hashTable[hashFunc(Instruction, collision)].pop_back();//remove dash -
					  	hashTable[hashFunc(Instruction, collision)].push_back(Instruction);//replace it with instruction first	
					}
					
					hashTable[hashFunc(Instruction, collision)].push_back(arr[i][j]);//then push the actual operand
				}
			}
		}
		
}



void displayMat(string arr[100][100], int rows, int cols) {
	int i, j;
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}
} 



int main()
{
	int rows, rowsInpFile, cols, j, k, i, collision;
	string arr[100][100]; //this 2d array will store every token
	string Instruction;
	string answerTable[100][100];
	//vector<string> hashTable[30];

    

    for(i=0; i<hashTableSize; i++) {
    	hashTable[i].push_back("-");
    	//hashTable[i][0] = "-";
    }//initialize hashTable

	fstream file;

	file.open("mot_table.txt", ios::in);
	
	if(file.is_open()){ //tokenization part             
	           
		string temp, temp2;
		i = 0;
		rows=1;
		while(getline(file, temp, '\n')) {
		    j=0; k=0;
		  /*  char str[100];
		    cout << "\n\ttemp : " << temp;

		    for(int s=0; temp[s]!='\0'; s++) {
		    	str[s] = temp[s];
		    	cout << str[s] << " " ;
		    }

		    char *token = strtok(str, " ");
		    while (token) {
		    	arr[rows-1][k++] = token;
		        if(token) { 
		        	cout << token << endl;
		        	token = strtok(NULL," ");
		        }
		    }*/

		    
		    while(temp[j]!='\0') {

		    	if(temp[j]==' ' || temp[j+1]=='\0') {
		    		if(temp[j+1]=='\0') temp2.push_back(temp[j]);
		    		arr[rows-1][k++] = temp2;//use strtok here
		    		temp2.clear();
		    	}else {
		    		temp2.push_back(temp[j]);
		    	}
		    	j++;
		    }
		    rows++;
		}

		cout << endl;
		cout << "\n\t=====================================" << endl;
		cout << "\t\tMOT TABLE" << endl;
		cout << "\t=====================================" << endl;
		displayMat(arr, rows, 5);
		cout << "\t=====================================" << endl;
		createHashTable(arr, rows);
		file.close();
	}
	
	/*cout << "\n\t\tHASH TABLE" << endl;
	for(i=0; i<hashTableSize; i++) {
		//cout << "\n\tHash " << i << " : ";
		//displayVect(hashTable[i]);
		if(hashTable[i].at(0)!="-" && hashTable[i].at(0)!=" ") {
			for(j=0;j<hashTable[i].size(); j++) {
				//if(hashTable[i].at(0)!="-" || hashTable[i].at(0)!=" ")
				cout << "\t" << hashTable[i].at(j);
			}
			cout << endl;
		}
		
	}*/

	cout << endl;

	string filename;

	cout << "\n\tENTER FILENAME : ";
	cin >> filename;

	file.open(filename, ios::in);

	if(file.is_open()) {

		string temp, temp2, Loc_counter;
		i = 0;
		rowsInpFile=1;
		while(getline(file, temp, '\n')) {
		    j=0; k=1;
		   	bool start=false;

		   	cout << "\n\t" << temp << endl;
		   	temp2.clear();
		    while(temp[j]!='\0') {

		    	if(temp[j]==' ' || temp[j+1]=='\0') {

		    		if(temp[j+1]=='\0') 
		    			temp2.push_back(temp[j]);

		    			if(start) {
		    				Loc_counter.push_back(temp[j]);
		    				LC = stoi(Loc_counter);
							//answerTable[rowsInpFile-1][0] = to_string(LC++);
							answerTable[0][0] = "-"; //first LC location is leftt blank
							answerTable[0][1] = "(" + isInstruction("START").at(3) + ", " + isInstruction("START").at(1) + ")";
							answerTable[0][2] = "-"; //ther is only one operand so leave this blank
							answerTable[0][3] = "(C, " + to_string(LC) + ")";
							//LC++;
							//displayMat(answerTable, 1, 4);
							LC--;
    						start = false;
		    			}else if(LC!=-1) {

		    				answerTable[rowsInpFile][0] = to_string(LC);

		    				if(isInstruction(temp2).empty()) {
		    					
		    					answerTable[rowsInpFile][k++] = getType(temp2);
		    					
		    				}else { // if its a mnemonic instruction
		    					answerTable[rowsInpFile][k++] = "(" + isInstruction(temp2).at(3) + ", " + isInstruction(temp2).at(1) + ")";
		    				}
		    			}



		    		
					if(temp2=="START") {
						start=true;
					}
		    		//arr[rows-1][k++] = temp2;
		    		temp2.clear();
		    	}else {
		    
		    		if(start) Loc_counter.push_back(temp[j]);
		    		temp2.push_back(temp[j]);
		    	}
		    	j++;
		    }
		    LC++;
		    rowsInpFile++;
		}
	}

	cout << "\n\t=====================================";
	cout << "\n\t\tRESULT";
	cout << "\n\t=====================================" << endl;
	displayMat(answerTable, rowsInpFile, 4);
	cout << "\n\t=====================================" << endl;

	cout << "\n\t\tSYMBOL TABLE";
	cout << "\n\t=====================================" << endl;
	displayMat(SymbolTable, SymTab, 2);
	cout << "\n\t=====================================" << endl;
	
	cout << "\n\t\tLITERAL TABLE";
	cout << "\n\t=====================================" << endl;
	displayMat(LiteralTable, LitTab, 2);
	cout << "\n\t=====================================" << endl;
	

	file.close();

}