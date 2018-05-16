
#include "Operator.h"
Operator::Operator() { this->allBills =0; this->budget =0;}
Operator::Operator(double allBills = 0) : allBills(allBills) {
	setBudget(0);
}
void Operator::printBudget() {
    std::cout << "\nOperator has a budget of " << budget << std::endl;
}
void Operator::setBudget(double budget) {
    
    try {
	 if(budget < 0) throw -1;
	 this->budget = budget;
    
   }catch(int e) {
	std::cout << "budget cannot be lower that zero - changed to zero\n";
	setBudget(0);
	}
}
void Operator::setAllBills(double allBills) {
	
    try {
	 if(allBills < 0) throw -1;
	 this->allBills = allBills;
    }catch(int e) {
	std::cout << "all bills cannot be lower that zero - changed to zero\n";
	setAllBills(0);
	}
}
double Operator::getAllBills() {
	return allBills;
}
double Operator::getBudget() {
    return budget;
}
int Operator::getVecSize() {
	return clientList.size();
}
void Operator::addClient(Client &client){
    
        clientList.push_back(client);
}
void Operator::removeClient(int listId){   
  
    try {
	
	if(getVecSize() == 0 && listId ==0) throw -1;

	clientList.erase(clientList.begin() + listId);
    } catch(int i) {
	std::cout<<"Tried to remove client from an empty vector\n";
    }
     
    
}
bool Operator::sumAllBills(){
    
    try {
        
        if(clientList.size()==0) throw -1;
        
        for(std::vector<Client>::iterator it = clientList.begin(); it != clientList.end(); ++it)
        {
             it -> computeBill();
             if(it->getBill() == -1) throw -2;
             allBills += it->getBill();
        }
    } catch(int e) {
        if(e == -2) {
            std::cout << "Cannot sum bills of unexisting customers\n";    
        }
	if(e == -1) {
	   std::cout << "Customer vec is empty\n";
	}
        allBills = -1;	
        return false;
    }
    return true;
    
}
void Operator::printAllBills() {
    
    std::cout << "All Bills equals " << allBills << std::endl;
}
void Operator::printBalanceMessage(double difference) {
    
    std::cout << "Operator balance is ";
    if(difference < 0) {
        std::cout << "negative\n"; return;    
    }
    if(difference >0) {
        std::cout << "positive\n"; return;  
    }
    if(difference == 0) {
        std::cout << "zero!\n"; return;    
    }
}
void Operator::printBalance()
{
   try {
        if(allBills == -1) throw -1;     
        
        double difference = budget - allBills;
        printBudget();
        printAllBills();
        printBalanceMessage(difference);
        
   } catch(int e) {
        if(e==-1)
          return;
   }
   
}
bool Operator::printClientListHeaders() {
    
    try {
        if(clientList.size() ==0) throw -1;
        
        std::cout << "Name\t" << "Surname\t" << "\tnumber\t" << "nSms\t" << "nMins\t" <<
         "Bill\t" << "Date\t" << std::endl;
        
    } catch( int e) {
        std::cout << "Clients undefined. \n";
	return false;
    }    
    return true;
}
void Operator::printClientList()
{   
    if(!printClientListHeaders()) {
	return;
    }
    for(std::vector<Client>::iterator it = clientList.begin(); it != clientList.end(); ++it)
    {
        std::cout << *it;
    }
}
void Operator::removeAllClients() {
    
    int i = clientList.size();
    while(i--) {
       clientList.erase(clientList.begin() + i);     
	if(i==0) break;
    }
    
}
Client Operator::getClientAt(int listId)
{

    try {

	if(listId < 0) throw -2;
	if(listId >= clientList.size()) throw -1;
	

	return clientList[listId];

    } catch(int e) {

	Client client("","",0,0,0,0,NULL,NULL,NULL);
	if(e==-1) {
	   std::cout << "Vector is empty!\n";	  
	}
	if(e==-2) {
	   std::cout << "Index cannot be lower than zero!\n";	   
	}
	return client;
    }
}
Operator::~Operator()
{
   for(std::vector<Client>::iterator it = clientList.begin(); it != clientList.end(); ++it)
    {
        delete [] it ->getCallRegisterPointer();
    }
}
