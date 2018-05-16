#ifndef SENIOROPERATOR_H_INCLUDED
#define SENIOROPERATOR_H_INCLUDED
#include "Operator.h"
class SeniorOperator : public Operator{
	
    private:
    	
        double bonus;
        
    public:
        SeniorOperator();
        SeniorOperator(double bonus, double allBills);
        
        void setBonus(double bonus);
        double getBonus();
        
        void printBalance();
        void printBalanceMessage(double);
        void printBudget();

        ~SeniorOperator();
};


#endif // SENIOROPERATOR_H_INCLUDED
