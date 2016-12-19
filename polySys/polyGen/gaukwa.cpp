#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[]){

  int i, j, k;
  int dim;
  
  if(argc != 2){

    cout << "Usage: " <<  argv[0] << " " << "dimension" << endl;
    exit(EXIT_FAILURE);

  }else dim = atoi(argv[1]);


  cout << "Dim =  " << 2 * dim << "\n";
  cout << "Support =  " << 2 * dim << "\n\n";


  cout << "Elem =  ";
  for(i = 0; i < 2 * dim; i++) cout << dim + 1 << " ";
  cout << "\n";

  cout << "Type =  ";
  for(i = 0; i < 2 * dim; i++) cout <<  1 << " ";

  cout << "\n\n";

  ////////////////////////////////////////////////////////

  cout << "\n";


  for(k = 0; k < 2 * dim; k++){
    for(j = 0; j < dim; j++){

      for(i = 0; i < 2 * dim; i++){

	if(i == j) cout << 1 << " ";
	else if(i == j + dim) cout << k << " ";
	else cout << 0 << " ";
      		 
      }
      cout << "\n";
    }

    for(i = 0; i < 2 * dim; i++) cout << 0 << " ";
    cout << "\n\n";

  }


  cout << "\n";

  return (EXIT_SUCCESS);


}
