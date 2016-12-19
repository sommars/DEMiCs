//////////////////////////// probGenerate.cpp ////////////////////////////

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;



void  outData1(int xDim, int height);


int main (int argc, char* argv[])
{

  int i, xDim, height;


  if (argc == 3){

    xDim = atoi(argv[1]);
    height = atoi(argv[2]);

  }else{

    cout << "Usage: " <<  argv[0] << " " << "dimension" 
	 << " "  <<  "#supports" << endl;

    exit(0);

  }

  /* output problem data */

  outData1(xDim, height);

}



void  outData1(int xDim, int height)
{
  

  int i, j, k;

  int zero = 0;
  int one = 1;

  int** eye;


  eye = new int* [xDim];

  for(i = 0; i < xDim; i++){

    eye[i] = new int [xDim];
    memset(eye[i], 0, sizeof(int) * xDim);

  }

  for(i = 0; i < xDim; i++){

    eye[i][i] = 1;

  }



  //////////////////////////////

  cout << "Dim = " << xDim << "\n";
  cout << "Support = " << height << "\n\n";

  cout << "Elem = ";
  for(i = 0; i < height; i++){

    cout << 2 * xDim << " ";

  }
  cout << "\n";

  cout << "Type = ";
  for(i = 0; i < height; i++){

    cout << (double) xDim / (double) height << " ";

  }
  cout << "\n\n";


  ////////////////////////////////////////

  for(k = 0; k < height; k++){

    for(j = 0; j < xDim; j++){

      cout << zero + eye[k][j] << " ";

    }

    cout << "\n";

    for(i = 0; i < xDim - 1; i++){

      for(j = 0; j < xDim; j++){

	if(i == j){
	  
	  cout << one + eye[k][j] << " ";

	}else{

	  cout << zero + eye[k][j] << " ";

	}
      }

      cout << "\n";

    }

    
    ////////////////////////////////////////
    ////////////////////////////////////////



    for(j = 0; j < xDim - 1; j++){

      cout << zero + eye[k][j] << " ";

    }

    cout << one + eye[k][xDim - 1] << " \n";

    for(i = 0; i < xDim - 1; i++){


      for(j = 0; j < xDim - 1; j++){

	if(i == j){

	  cout << one + eye[k][j] << " ";

	}else{

	  cout << zero + eye[k][j] << " ";

	}
      }

      cout << one + eye[k][xDim - 1] << " ";
      cout << "\n";

    }
  
    cout << "\n";

  }


  ////////////////////////////

  if(eye){

    for(i = 0; i < xDim; i++) delete [] eye[i];

    delete [] eye;
    eye = NULL;

  }


}

