#include <iostream>
#define n 4
using namespace std;
void Show(double arr[][n]);
void Show(double arr[n]);
void MakeMatrix(double A[][n], double M[][n], double N[]);
void reverseMatrix(double D[n][n], double N[n]);
void JacobyMethod(double M[n][n],double N[n],double x1[n],double x2[n], double b[n],int iter);
int main() {
	double L[n][n] = {}, M[n][n] = {}, D[n] = {}, N[n] = {}, LU[n][n]{};
	double A[n][n] = {{4,-1, - 0.2,2},{-1,5,0,-2},{0.2,1,10,-1},{0,-2,-1,4}};
	double b[n] = { 30,0,-10,5 };
	double x1[n] = {};
	double x2[n] = {};
	cout << "Ax = b" << endl;
	Show(A);
	Show(b);
	cout << "N = D^-1" << endl;
	reverseMatrix(A, N);
	MakeMatrix(A, M, N);
	Show(N);
	cout << "M:"<<endl;
	Show(M);
	cout << "Output:" << endl;
	JacobyMethod(M,N,x1,x2,b,5);	
	Show(x2);

	system("pause");
}
void Show(double  arr[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}
void Show(double  arr[n]) {
	for (int i = 0; i < n; i++) 
		cout << arr[i] << endl;

	cout << endl;
}
void MakeMatrix(double A[][n], double M[n][n], double N[]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				M[i][j] = 0;
			else 
				M[i][j] = -(A[i][j] * N[i]);
		}	
	}
}
void reverseMatrix(double A[n][n], double N[n]){
	for (int i = 0; i<n; i++)
		N[i] = 1 / A[i][i];
}
void JacobyMethod(double M[n][n], double N[n], double x1[n], double x2[n], double b[n],int iter) {

	for (int k = 0; k<iter; k++) {
		for (int i = 0; i<n; i++) {
			x2[i] = N[i] * b[i];
			for (int j = 0; j<n; j++)
				x2[i] += M[i][j] * x1[j];
		}
		for (int i = 0; i<n; i++)
			x1[i] = x2[i];
	}

}

