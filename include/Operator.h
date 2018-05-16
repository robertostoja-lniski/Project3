
#ifndef OPERATOR_H
#define OPERATOR_H
#include <vector>
#include "Client.h"
class Operator
{
    protected:
        std::vector < Client > clientList;
        double allBills;
        double budget;

    public:
        Operator();
        Operator(double allBills);
	void setAllBills(double allBills);
	double getAllBills();
        void setBudget(double budget);
        double getBudget();
        void addClient(Client &client);
        void removeClient(int listId);
        void removeAllClients();
        void printAllBills();
        bool printClientListHeaders();
        bool sumAllBills();
	int getVecSize();
        void printClientList();
        Client getClientAt(int listID);
        
        virtual void printBalance();
        virtual void printBalanceMessage(double);
        virtual void printBudget();
        ~Operator();
};

#endif // OPERATOR_H

