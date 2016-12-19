
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


void  outData1(int xDim);
void  outData2(int xDim);
void  inputTerm(int* auxInd, int xDim, int constNum, int termNum);

int main (int argc, char* argv[])
{
        int     i, xDim;

        if (argc == 2){

	  xDim = atoi(argv[1]);

	}else{

	  cout << "Usage: " <<  argv[0] << " " << "dimension" << endl;
	  exit(0);
		
	}

        /* output problem data */

	outData1(xDim);
	outData2(xDim);
}

void  outData1(int xDim)
{
	int	i;

	cout << "Dim = " << xDim << "\n";
	cout << "Support = " << xDim << "\n\n";

	cout << "Elem = ";

        cout << "2 ";


	for (i = 0; i < xDim-1; i++) cout << xDim << " ";
	cout << "\n";

	cout << "Type = ";
	for (i = 0; i < xDim; i++) cout << "1 ";

	cout << "\n\n";
}

void  outData2(int xDim)
{	
	int	i, j, k;
	int*	auxInd;

        auxInd = new int [xDim];

        for (k = 0; k < xDim; k++)
                cout << "0 ";
        cout << "\n";

        for (k = 0; k < xDim; k++)
                cout << "1 ";
        cout << "\n\n";

	for (i = 1; i < xDim; i++)
	{

		for (j = 1; j <= xDim; j++)
		{
			inputTerm(auxInd, xDim, xDim-i, j);

			for (k = 0; k < xDim; k++)
				cout << auxInd[k] << " ";
			cout << "\n";
		}

		cout << "\n";
	}

	delete [] auxInd;
}

void  inputTerm(int* auxInd, int xDim, int constNum, int termNum)
{
	int	i;

	for (i = 0; i < xDim; i++)
		auxInd[i] = 0;

	for (i = termNum; i < termNum+constNum; i++)
        {
        	if (i <= xDim)
			auxInd[i-1] = 1;
                else
			auxInd[i%xDim-1] = 1;
	}
}

