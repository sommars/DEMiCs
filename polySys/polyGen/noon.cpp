#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[]){

  int i, j, k, counter, ** array;
  int dim;

  

  if(argc == 2){

    dim = atoi(argv[1]);

  }else{

    cout << "Usage: " <<  argv[0] << " " << "dimension" << endl;
    exit(0);

  }



  array = new int* [dim];
  for(i = 0; i < dim; i++) array[i] = new int [dim - 1];


  for(i = 0; i < dim; i++){
    for(j = 0; j < dim - 1; j++){

      array[i][j] = 0;

    }
  }




  cout << "Dim =  " <<  dim << "\n";
  cout << "Support =  " <<  dim << "\n\n";

  cout << "Elem =  ";
  for(i = 0; i < dim; i++) cout << dim + 1 << " ";
  cout << "\n";
  
  cout << "Type =  ";
  for(i = 0; i < dim; i++) cout << 1 << " ";

  cout << "\n\n";

  
  for(j = 0; j < dim - 1; j++){
    for(i = 0; i < dim - 1; i++){
   
      if(i == j) array[j][i] = 2;

    }
  }
  
  
  for(k = 0; k < dim; k++){
    for(j = 0; j < dim; j++){

      counter = 0;

      for(i = 0; i < dim; i++){

	if(i == k) cout << 1 << " ";
	else{
	
	  cout << array[j][counter] << " ";
	  counter++;

	}
      }
      cout << "\n";
    }
    
    for(j = 0; j < dim; j++) cout << 0 << " ";
    
    cout << "\n\n";
  }





  for(i = 0; i < dim; i++) delete [] array[i];
  delete [] array;

  return (EXIT_SUCCESS);


}

