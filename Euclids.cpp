//ASSIGNMENT 1
//33243 TE 10 SAKSHEE

# include <iostream>
using namespace std;

//Euclids algorithm
int GCD(int n, int m) {

	int r;
	int a=n, b=m;
	if(n<0) n = m + n;

	while(m>0) {
		cout << "\n\t" << n << " = " << m << "(" << n/m << ")" << " + " << n%m;
		
		r = n%m;
		n = m;
		m = r;
	}

	cout << "\n\t";

	return n;

}

//Multiplicative inverse
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}


int main()
{
	int n, m;

	cout << "\n\tENTER NUM 1 : ";
	cin >> n;
	cout << "\n\tENTER NUM 2 : ";
	cin >> m;

	cout << "\n\tGCD of (" << n << ", " << m << ") is : " << GCD(n, m) << endl;

	cout << "\n\tMULTIPLICATIVE INVERSE : " << modInverse(n, m) << endl;
	return 0;
}

//		OUTPUT

/*
sakshee@sakshee-Vostro-3580:~/Cybersecurity$ g++ Euclids.cpp
sakshee@sakshee-Vostro-3580:~/Cybersecurity$ ./a.out

	ENTER NUM 1 : 3

	ENTER NUM 2 : 11

	GCD of (3, 11) is : 
	3 = 11(0) + 3
	11 = 3(3) + 2
	3 = 2(1) + 1
	2 = 1(2) + 0
	1

	MULTIPLICATIVE INVERSE : 4
sakshee@sakshee-Vostro-3580:~/Cybersecurity$ 


*/
