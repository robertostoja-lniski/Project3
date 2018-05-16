
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Reader.h"
#include "Operator.h"
#include "SeniorOperator.h"
using namespace std;

int main()
{
    
    Reader reader;
    reader.printHelloMessage();
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    reader.readOperatorsBudgetFromStdIn(teleOperator);
    try {
    	reader.readDataToClass(teleOperator, &economicTariff);
    } catch(...) {
    	cout << "Could not read file\n";
    	return 1; 
    }
        
    teleOperator.sumAllBills();
    teleOperator.printClientList();
	teleOperator.printBalance();
	
	SeniorOperator seniorOperator(40.0, 0);
	seniorOperator.Operator::setBudget(teleOperator.getBudget());
	//reader.readOperatorsBudgetFromStdIn(seniorOperator);
	try {
    	reader.readDataToClass(seniorOperator, &economicTariff);
    } catch(...) {
    	cout << "Could not read file\n";
    	return 1; 
    }
	seniorOperator.Operator::sumAllBills();
	seniorOperator.Operator::printClientList();
	seniorOperator.printBalance();

   

    return 0;
}
