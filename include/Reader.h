
#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED
#include <string>
#include <fstream>
#include <vector>
#include "TelecommunicationTariff.h"
#include "Operator.h"
#include "contractDateBase.h"
class Reader {
	
	public :
	    Reader() {};
	    void printHelloMessage();
		int readDataToClass(Operator &telecomunicationOperator, TelecommunicationTariff<int> *pTariff) throw();
		void readOperatorsBudgetFromStdIn(Operator &operatorReference );
		bool isNum(std::string);
		int toInteger(std::string);
		/// creates date pointer
		template <typename T>
		ContractDateBase* createDatePointer(int, T ,int);
};

template <typename T>
ContractDateBase* Reader::createDatePointer(int day, T month, int year) {
    
        ContractDate<T>* datePointer = new ContractDate<T>(day, month, year);
        return datePointer;
}
#endif // READER_H_INCLUDED
