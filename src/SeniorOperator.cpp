/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/

#include "SeniorOperator.h"
SeniorOperator::SeniorOperator(){}
SeniorOperator::~SeniorOperator(){}
SeniorOperator::SeniorOperator(double bonus = 0, double allBills = 0) 
					: Operator(allBills) {
						this -> bonus = bonus;
					}
void SeniorOperator::printBudget() {
    
    try {
        if(bonus < 0) throw -1;
        std::cout << "\nSenior operator has a budget of " << budget*(1+bonus/100) 
			  << " with " << bonus << "%." << std::endl;
    } catch (int i) {
        std::cout << "\nSenior operator cannot have negative bonus\n";
        std::cout << "Bonus changed to zero.";
        setBonus(0);
        printBudget();
    }
    
}

void SeniorOperator::setBonus(double bonus) {
    this->bonus = bonus;
}

void SeniorOperator::printBalanceMessage(double difference) {
    
    std::cout << "Senior operator balance is ";
    if(difference < 0) {
        std::cout << "negative\n"; return;    
    }
    if(difference >=0) {
        std::cout << "positive\n"; return;  
    }

}
void SeniorOperator::printBalance()
{
   
   try {
        if(allBills == -1) throw -1;     
        
        double difference = budget*(1+bonus/100) - allBills;
        printBudget();
        printAllBills();
        printBalanceMessage(difference);
        
   } catch(int e) {
        if(e==-1)
          return;
   }
}

