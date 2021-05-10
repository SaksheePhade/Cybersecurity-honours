//ASSIGNMENT 2
//SAKSHEE PHADE
//33243


#include<iostream>
using namespace std;

int answer1[2], answer2[2], answer[2]; //0 is min, 1 is max
static int pass=0;
 
int *getMinMax(int arr[], int low, int high)
{     
    int mid;
    cout << endl;
    cout << "\n\tPASS : " << pass++;
    //cout << "\n\tLOW : " << low << "\tHIGH : " << high << endl;
    cout << "\n\t[";
    for(int i=low; i<high+1; i++)
    	cout << arr[i] << ", ";
    cout << "]";
    // If there is only one element 
    if (low == high)
    {
       	answer1[0] = arr[low];
        answer1[1] = arr[low];     

       cout << "\n\tMIN MAX : " << answer1[0] << " " << answer1[1] << endl;
        return answer1;
    } 
     
    // If there are two elements 
    if (high == low + 1)
    { 
        if (arr[low] > arr[high]) 
        {
            answer2[1] = arr[low];
            answer2[0] = arr[high];
            //cout << "\n\tTWO ELEMENTS : " << answer[0] << " " << answer[1] << endl;
        } 
        else
        {
            answer2[1] = arr[high];
            answer2[0] = arr[low];
            //cout << "\n\tTWO ELEMENTS : " << answer[0] << " " << answer[1] << endl;
        } 
        cout << "\n\tMIN MAX : " << answer2[0] << " " << answer2[1] << endl;
        return answer2;
    }
     
    // If there are more than 2 elements 
    mid = (low + high) / 2; 

    int *leftAnswer = getMinMax(arr, low, mid);
    int *rightAnswer = getMinMax(arr, mid + 1, high); 
    

    cout << "\n\tLEFT LIST JOINING : " << *(leftAnswer+0) << " " << leftAnswer[1] << endl;
	
    cout << "\n\tRIGHT LIST JOINING : " << rightAnswer[0] << " " << rightAnswer[1] << endl;
     
    // Compare minimums of two parts
    if (*(leftAnswer+0) < *(rightAnswer+0))
        answer[0] = *(leftAnswer+0);
    else
        answer[0] = *(rightAnswer+0);     
     
    // Compare maximums of two parts
    if (*(leftAnswer+1) > *(rightAnswer+1))
        answer[1] = *(leftAnswer+1);
    else
        answer[1] = *(rightAnswer+1);     

    cout << "\n\tMIN MAX : " << answer[0] << " " << answer[1] << endl;
     
    return answer;
}
 
int main()
{
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int arr_size = 6;
    int answer[2];
    int *ptr = getMinMax(arr, 0, arr_size - 1);
                              
    cout << "\n\tMinimum element is " << *(ptr+0) << endl;
    cout << "\n\tMaximum element is " << *(ptr+1) << endl;
          
    return 0;
}
/*

        OUTPUT

sakshee@sakshee-Vostro-3580:~/TE Sem 2/DAA$ ./a.out


    PASS : 0
    [1000, 11, 445, 1, 330, 3000, ]

    PASS : 1
    [1000, 11, 445, ]

    PASS : 2
    [1000, 11, ]
    MIN MAX : 11 1000


    PASS : 3
    [445, ]
    MIN MAX : 445 445

    LEFT LIST JOINING : 11 1000

    RIGHT LIST JOINING : 445 445

    MIN MAX : 11 1000


    PASS : 4
    [1, 330, 3000, ]

    PASS : 5
    [1, 330, ]
    MIN MAX : 1 330


    PASS : 6
    [3000, ]
    MIN MAX : 3000 3000

    LEFT LIST JOINING : 1 330

    RIGHT LIST JOINING : 3000 3000

    MIN MAX : 1 3000

    LEFT LIST JOINING : 1 3000

    RIGHT LIST JOINING : 1 3000

    MIN MAX : 1 3000

    Minimum element is 1

    Maximum element is 3000
sakshee@sakshee-Vostro-3580:~/TE Sem 2/DAA$ B



*/