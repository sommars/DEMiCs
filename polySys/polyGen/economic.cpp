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
	


	outData1(xDim);
	outData2(xDim);

	return 0;
}

void  outData1(int xDim){


	int	i;

	cout << "Dim = " << xDim << endl;
	cout << "Support = " << xDim << endl << endl;


	cout << "Elem = ";
	cout << xDim << " ";

	for (i = 0; i < xDim-2; i++){

	  cout <<i + 2 << " ";

	}

	cout << xDim << " ";
	cout << endl;


	cout << "Type = ";
	for (i = 0; i < xDim; i++){

	  cout << 1 << " ";

	}


	cout << endl << endl;
}


void  outData2(int xDim){	


	int	i, j, k;


	for(k=0;k<xDim;k++){

	  cout << 0 << " ";		

	}


	cout << endl;


	for(j=0;j<xDim-1;j++){


	  for (k = 0; k < j; k++){

	    cout << 0 << " ";

	  }

	  cout << 1 << " ";

	  for (k = j+1; k < xDim; k++){

	    cout << 0 << " ";

	  }

	  cout << endl;

	}


	cout << endl;




	for (i = xDim - 2; i >= 0; i--){

	  for (k = 0; k < xDim; k++){

	    cout << 0 << " ";

	  }

	  cout << endl;


	  for (k = 0; k < i; k++){

	    cout << 0 << " ";

	  }
	  
	  cout << 1 << " ";

	  for (k = i+1; k < xDim-1; k++){
	    
	    cout << 0 << " ";

	  }

	  cout << 1 << " ";
	  cout << endl;

		
	  for (j = 1; j < xDim-i-1; j++){
	    
	    for (k = 0; k < j-1; k++){

	      cout << 0 << " ";

	    }

	    cout << 1 << " ";

	    for (k = j; k < i+j; k++){

	      cout << 0 << " ";

	    }

	    cout << 1 << " ";

	    for (k = i+j+1; k < xDim-1; k++){

	      cout << 0 << " ";
	    
	    }

	    cout << 1 << " ";
	    cout << endl;

	  }


	  cout << endl;	

	}


}

