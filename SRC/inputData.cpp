#include "inputData.h"

//------------------------------------------------------------------------------
dataSet::dataSet() {
	Dim = 0;
	termSumNum = 0;
	termMax = 0;
	typeMax = 0;
	supN = 0;

	support = NULL;
	termSet = NULL;
	termStart = NULL;
	type = NULL;
	coef = NULL;
	outFile = NULL;
}

//------------------------------------------------------------------------------
dataSet::~dataSet() {
	delete [] outFile;
	delete [] support;
	delete [] termStart;
	delete [] termSet;
	delete [] type;
	delete [] coef;
}

//------------------------------------------------------------------------------
void dataSet::getInputFile(char* inputFile) {
	size_t length;
	int rowCounter, colCounter, ccounter, sum, counter;
	counter = 0;
	char ch, str[STRLENGTH], *p;

	length = strlen(inputFile);

	for(size_t i = 0; i < (signed) length; i++){
		if(inputFile[i] == '.') 
			break;
		counter++;
	}

	outFile = new char [length + EXCESS];
	assert(outFile);

	for(size_t i = 0; i < counter; i++) {
		outFile[i] = inputFile[i];
	}

	outFile[counter] = '\0';
	strcat(outFile, ".out");

	ifstream in(inputFile);

	if(!in){
		cout << "Cannot open -- " << inputFile << "\n";
		exit(EXIT_FAILURE);
	}

	colCounter = 0;

	do{
		p = str;
		ch = in.peek();

		if(ch == '#') {
			do {
				ch = in.get();
			} while((ch != '\n') && (!in.eof()));
		} else if(ch == 'D') {
			do {
				ch = in.get();
			} while((ch != '=') && (ch != '\n') && (!in.eof()));
			do {
				ch = in.peek();
				if(isdigit(ch)){
					while(isdigit(*p = in.get())) 
						p++;
					in.putback(*p);
					*p = '\0';
					Dim = atoi(str);
				}
				ch = in.get();
			} while((ch != '\n') && (!in.eof()));
		} else if(ch == 'S') {
			do{
				ch = in.get();
			} while((ch != '=') && (ch != '\n') && (!in.eof()));
			do{
				ch = in.peek();
				if(isdigit(ch)) {
					while(isdigit(*p = in.get())) 
						p++;
					in.putback(*p);
					*p = '\0';
					supN = atoi(str);
					termSet = new int [supN];
					assert(termSet);
					termStart = new int [supN + 1];
					assert(termStart);
					type = new int [supN];
					assert(type);
				}
				ch = in.get();
			}while((ch != '\n') && (!in.eof()));
		}	else if(ch == 'E'){
			do{
				ch = in.get();
			} while((ch != '=') && (ch != '\n') && (!in.eof()));
			termSumNum = 0;
			counter = 0;
			do{
				ch = in.peek();
				if(isdigit(ch)){
					p = str;
					while(isdigit(*p = in.get())) 
						p++;
					in.putback(*p);
					*p = '\0';
					termSet[counter] = atoi(str);
					if(termMax < termSet[counter]) 
						termMax = termSet[counter];
					counter++;
				}
				ch = in.get();
			} while((ch != '\n') && (!in.eof()));
			for(size_t i = 0; i < supN; i++) 
				termSumNum += termSet[i];
			termStart[0] = (sum = 0);
			for(size_t i = 1; i < supN + 1; i++){
				sum += termSet[i - 1];
				termStart[i] = sum;
			}
			support = new double [termSumNum * Dim];
			assert(support);
			memset(support, 0, termSumNum * Dim * sizeof(double));
			coef = new double [2 * termSumNum];
			assert(coef);
		} else if(ch == 'T') {
			do{
				ch = in.get();
			} while((ch != '=') && (ch != '\n') && (!in.eof()));
			counter = 0;
			do{
				ch = in.peek();
				if(isdigit(ch)) {
					p = str;
					while(isdigit(*p = in.get())) 
						p++;
					in.putback(*p);
					*p = '\0';
					type[counter] = atoi(str);
					if(typeMax < type[counter]){
						typeMax = type[counter];
					}
					counter++;
				}
				ch = in.get();
			} while((ch != '\n') && (!in.eof()));
			cout << "\n";
		} else if(isdigit(ch)) {
				rowCounter = 0;
				colCounter++;
				do{
					ch = in.peek();
					if(isdigit(ch)){
						p = str;
						while(isdigit(*p = in.get())) 
							p++;
						in.putback(*p);
						*p = '\0';
						support_in(colCounter - 1, rowCounter, atoi(str));
						rowCounter++;
					}
					ch = in.get();
				} while((ch != '\n') && (!in.eof()));
		} else in.get();
	} while(!in.eof());

	in.close();

	#if DBG_INFO
		info_pre();
		info_support();
	#endif
}

//------------------------------------------------------------------------------
void dataSet::info_pre(){
	cout << "Dim: " << Dim << endl;
	cout << "Support " << supN << endl << endl;
	cout << "Elem: ";
	for(size_t i = 0; i < supN; i++)
		cout << termSet[i] << " ";
	cout << endl;
	cout << "Type: ";
	for(size_t i = 0; i < supN; i++)
		cout << type[i] << " ";
	cout << endl << endl;
}

//------------------------------------------------------------------------------
void dataSet::info_support(){
	int top, counter;
	top = 0;
	counter = 0;
	
	cout << "Support: " << endl;
	for(size_t k = 0; k < supN; k++){
		for(size_t j = top; j < termSet[k] + top; j++){
			for(size_t i = 0; i < Dim; i++){
				cout << support_out(j, i) << " ";
			}
			cout << endl;
			counter++;
		}
		cout << endl;
		top = counter;
	}
}
