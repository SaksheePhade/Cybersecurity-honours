#include<bits/stdc++.h>
#include"merge-sort.h"
using namespace std;

void TapeFill(int m,vector<int>program){
    vector<int>*tapePtr= new vector<int>[m];    //tapePtr vector pointing to m vectors
    vector<float>avg(m,0);                      //storing avg values 
    float totAvg=0;
    int i=0,maxSize;
    cout<<"\nEnter max capacity of tapes\n";      //max capacity input
    cin>>maxSize;
    vector<int>sizes(m,maxSize);                //intialize sizes 
        for(int j=0;j<program.size();j++){
        if(sizes[i]>=program[j])                //check if size greater than length 
        {   tapePtr[i].push_back(program[j]);   //if less push in tapePtr
            sizes[i]-=program[j];
            i=(i+1)%m;
        }else{                                  //else not filled
            cout<<"\nNot filled\n";
            for(int k=j;k<program.size();k++){
                cout<<program[k]<<"\t";
            }
            break;
        }
        
        }
        
        
        for(int j=0;j<m;j++){
        cout<<"\nTape"<<j+1<<"\t";
            avg[j]=*tapePtr[j].begin();                 //calculate mrt and print the values
            cout<<avg[j]<<"\t";
        for(auto it=tapePtr[j].begin()+1;it!=tapePtr[j].end();it++)
        {   avg[j]+=*it+*(it-1);
            cout<<*it<<"\t";
        }
        avg[j]/=tapePtr[j].size();
        cout<<"Average-"<<avg[j];
        totAvg+=avg[j];

    }
    totAvg=totAvg/m;
    cout<<"\nAverage Total\t"<<totAvg<<"\n";

}

int main(){

    int m,n;
    cout<<"\nEnter no. of tapes";           //user input for tapes and program count
    cin>>m;
    cout<<"\nEnter no. of programs";        
    cin>>n;
    vector<int>program(n,0);
    for(int i=0;i<n;i++){
        cout<<"\nEnter length of program "<<i+1<<"-";       //input program lengths
        cin>>program[i];
        while(program[i]<0){
            cout<<"\nEnter +ve length";
            cin>>program[i];
        }
    }
    mergeSort(program,0,n-1);                           //sorting program array
    cout<<"\nSorted array\n";
    for(auto it:program){

        cout<<it<<"\t";
    }

    TapeFill(m,program);                            //TapeFill function
}


/***
 * 
 * OUTPUT
 * 
Enter no. of tapes 3

Enter no. of programs 8

Enter length of program 1-34

Enter length of program 2--8

Enter +ve length 8

Enter length of program 3-56

Enter length of program 4-36

Enter length of program 5-88

Enter length of program 6-90

Enter length of program 7-28

Enter length of program 8-53

Sorted array
8       28      34      36      53      56      88      90
Enter max capacity of tapes
100

Not filled
88      90
Tape1   8       36      Average-26
Tape2   28      53      Average-54.5
Tape3   34      56      Average-62
Average Total   47.5
 * 
 * 
 * 
 * 
 * ***/