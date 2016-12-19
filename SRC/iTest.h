#ifndef __ITEST_H
#define __ITEST_H

#include "global.h"
#include "inputData.h"

//------------------------------------------------------------------------------
class uData{
	private:
		int nfN;

	public:
		uData();
		~uData();

		uData *next;
		uData *prev;
		uData *fNext;

		int supLab;

		double red;
		double* dir;

		void create(int depth, int Dim);
		void init();

		void getDir(double& val, int idx){
			dir[idx] = val;
		};
		void getRed(double& val, int idx){
			red = val;
		};

		void info_dirRed();
};

//------------------------------------------------------------------------------
class inifData{
	public:
		inifData();
		~inifData();

		uData* head;
		uData* fHead;
		uData* last;

		void create(int length, int depth, int Dim);
		void get_info(dataSet& Data, double* lifting, 
		int* termSet, int* termStart, 
		int depth, int Dim, int supN);

		void info_all_dirRed();
		void info_feasIdx();
		void info_fNext();
		void info_next();
		void info_prev();
};

//------------------------------------------------------------------------------
class iLvData{
	private:
		int rspLen;
		int inifLen;

	public:
		iLvData();
		~iLvData();

		inifData* inif;
		int* rsp;

		void create(int depth, int supN, int Dim, int termMax);

		void getInit(dataSet& Data, double* lifting, int* termSet,
			int* termStart, int Dim, int supN);
			
		void init(int supN, int depth, int* preRsp);

		void info_rsp();
		void info_all_dirRed();
		void info_feasIdx(int depth);
		void info_all_feasIdx();
};

#endif
