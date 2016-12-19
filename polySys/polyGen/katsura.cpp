#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;



void  outData1(int xDim);
void  outData2(int xDim);


int main (int argc, char* argv[]){

	int xDim;

	if (argc == 2){

	  xDim = atoi(argv[1]);

	}else{

	  cout << "Usage: " <<  argv[0] << " " << "dimension" << endl;
	  exit(0);


	}

	/* output problem data */
	outData1(xDim+1);
	outData2(xDim+1);
	

	return 0;
}

void  outData1(int xDim){

	int num, i;

	cout << "Dim = " << xDim << "\n";
	cout << "Support = " << xDim << "\n\n";

	cout << "Elem = ";

	num = xDim+1;
	cout << num << " ";
	num++;
	cout << num << " ";
	num--;
	for (i = xDim/2-1;i > 0; i--){
		cout << num << " " << num << " ";
		num--;
	}

	if((xDim % 2) != 0){
		cout << num << " ";
	}
	cout << endl;

	cout << "Type = ";
	for (i = 0;i < xDim; i++) cout << "1 ";
	cout << endl << endl;

}


void  outData2(int xDim){

	int i, j, k, num,num2;
	int ***auxInd;

	auxInd = new int **[xDim];
	for (i = 0;i < xDim;i++ ){
		if(i!=0){
			num2 = xDim + 2 - i/2;
			auxInd[i] = new int *[num2];
		}else{
			num2 = xDim + 1 - i/2;
			auxInd[i] = new int *[num2];		
		}

		for(j = 0;j < num2;j++){
			auxInd[i][j] = new int [xDim];
			for(k = 0;k < xDim;k++){
				auxInd[i][j][k] = 0;
			}
		} 
	}

	//c1
	for (j = 0; j < xDim; j++){
		auxInd[0][j+1][xDim-1-j]++;
	}

	// after c2 
	for(i = 1;i < xDim;i++){	
		auxInd[i][0][i-1] = 1;
		num = xDim+1-i;
 		for (j = 0; j < num; j++){
			auxInd[i][j+1][xDim-i-j]++;
			auxInd[i][j+1][xDim-1-j]++;
		}
		num2 = xDim  - i/2;
		for(j=num;j<num2;j++){
			auxInd[i][j+1][j-xDim+i]++;
			auxInd[i][j+1][xDim-1-j]++;
		}
	}

	// print
	for (i = 0;i < xDim;i++){
		if(i!=0){
			num2 = xDim + 2 - i/2;
		}else{
			num2 = xDim + 1 - i/2;
		}

		for(j = 0;j < num2;j++){

			for(k = 0;k < xDim;k++){
				cout << auxInd[i][j][k] << " ";
			}
			cout << endl;
			delete [] auxInd[i][j];
		}
		cout << endl;
		delete [] auxInd[i];
	}

	delete [] auxInd;


}

