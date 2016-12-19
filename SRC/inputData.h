#ifndef __INPUTDATA_H
#define __INPUTDATA_H

#include "global.h"

class dataSet {
	public:
		dataSet();
		~dataSet();
		int Dim, supN, termSumNum;
		int termMax, typeMax;
		int* termSet, * termStart, * type;
		double* support;
		double* coef;
		char* outFile;
		
		void support_in(int rowIdx, int colIdx, double elem) {
			support[colIdx + Dim * rowIdx] = elem;
		};
		double support_out(int rowIdx, int colIdx){
			return (support[colIdx + Dim * rowIdx]);
		};
		
		void getInputFile(char* inputFile);

		void info_pre();
		void info_support();
};

#endif
