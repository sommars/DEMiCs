#include "global.h"
#include "inputData.h"
#include "mvc.h"

//------------------------------------------------------------------------------
void getInputPara(int argc, char** argv, int& seedNum, 
									int& output, char** inputFileName){
  int length, flag;
  flag = 0;

	if(argc == 2) {
		seedNum = 1;
		output = 0;
		*inputFileName = argv[1];
	}
	
	if(argc > 2 && argc < 5 && argv[1][0] == '-'){
		length = strlen(argv[1]);
		if(argc == 3 && length == 2 && argv[1][0] == '-' && argv[1][1] == 'c') {
			seedNum = 1;
			output = 1;
			*inputFileName = argv[2];
		} else if (argc == 4 && length == 2 && argv[1][0] == '-' && argv[1][1] == 's'){
				seedNum = atoi(argv[3]);
				output = 0;
				*inputFileName = argv[2];
		} else if (argc == 4 && length == 3 && argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == 's'){
			seedNum = atoi(argv[3]);
			output = 1;
			*inputFileName = argv[2];
		} else 
			flag = 1;
	} else {
		if(argc == 2) {
			seedNum = 1;
			output = 0;
			*inputFileName = argv[1];
		} else 
			flag = 1;
	}

	if(flag) {
		cerr <<"-----" << endl;
		cerr <<"Usage" << endl;
		cerr <<"-----" << endl << endl;
		cerr << argv[0] << " [option] input_file [seed_number]" << endl << endl << endl;
		cerr << "------" << endl;
		cerr << "Option" << endl;
		cerr << "------" << endl << endl;
		cerr << "default : " <<  argv[0] << " input_file" << endl << endl;
		cerr << "-c : Output information about mixed cells in a terminal" << endl ;
		cerr << "    " << argv[0] << " -c input_file" << endl << endl;
		cerr << "-s : Designate a seed number" << endl ;
		cerr << "    " << argv[0] << " -s input_file seed_number" << endl << endl;
		cerr << "-cs : Output information about mixed cells in a terminal, ";
		cerr << "and set a seed number" << endl ;
		cerr << "    " << argv[0] << " -cs input_file seed_number" << endl;
		exit(EXIT_FAILURE);
	}
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]){
	int seedNum, output;
	char* inputFileName;

	dataSet Data;
	mvc MV_Comp;

	double cpuTime_start, cpuTime_end;
	struct tms cpuTime;

	getInputPara(argc, argv, seedNum, output, &inputFileName);

	times(&cpuTime);
	cpuTime_start = (double) cpuTime.tms_utime;

	Data.getInputFile(inputFileName);

	MV_Comp.allocateAndIni(Data, seedNum, output);

	MV_Comp.Enum();

	times(&cpuTime);
	cpuTime_end = (double) cpuTime.tms_utime;
	cout << fixed;
	MV_Comp.info_final();
	MV_Comp.info_cpuTime(cpuTime_start, cpuTime_end);
	return (EXIT_SUCCESS);
}
