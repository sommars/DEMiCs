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

	outData1(xDim);
	outData2(xDim);

	return 0;
}

void  outData1(int xDim){

	int num, i;

	cout << "Dim = " << xDim << "\n";
	cout << "Support = " << xDim << "\n\n";

	cout << "Elem = ";
	
	for(i = 0; i < xDim; i++){

	  cout << xDim + 1 << " ";

	}
	cout << endl;

	
	cout << "Type = ";
	
	for(i = 0; i < xDim; i++){

	  cout << 1 << " ";

	}

	cout << endl << endl;
}

void  outData2(int xDim){

        int i, j, k;
	int** sup;

	for(i = 0; i < xDim - 1; i++) cout << "0 ";
	cout << "1 \n";

	for(i = 0; i < xDim - 1; i++){

	  for(j = 0; j < xDim - 1; j++){

	    if(i == j) cout << "1 ";
	    else cout << "0 ";

	  }
	  cout << "1 \n";
	}


	for(i = 0; i < xDim; i++) cout << "0 ";
	cout << "\n\n";


	sup = new int* [xDim + 1];
	for(i = 0; i < xDim + 1; i++) sup[i] = new int [xDim + 1];


	for(i = 0; i < xDim + 1; i++){
	  for(j = 0; j < xDim + 1; j++){

	    sup[i][j] = 0;

	  }
	}
	


	for(k = 0; k < xDim - 1; k++){

	  for(i = 0; i < xDim; i++){

	    if(i == k) sup[0][i] = 1;
	    else sup[0][i] = 0;

	  }


	  for(i = 0; i < xDim - 1; i++){
	    for(j = 0; j < xDim - 1; j++){

	      if(i == j){

		if(j == k) sup[i + 1][j] = 2;
		else sup[i + 1][j] = 1;
	      
	      }else{

		if(j == k) sup[i + 1][j] = 1;
		else sup[i + 1][j] = 0;

	      }
	    }

	    sup[i + 1][j + 1] = 0;

	  }


	  for(j = 0; j < xDim + 1; j++){

	    for(i = 0; i < xDim; i++){

	      cout << sup[j][i] << " ";

	    }
	    cout << "\n";

	  }
	  cout << "\n";

	}


	for(i = 0; i < xDim + 1; i++){
	  
	  delete [] sup[i];
	  sup[i] = NULL;

	}

	delete [] sup;
	sup = NULL;

}

