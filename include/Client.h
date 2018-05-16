
#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <string>
#include <iostream>
#include "TelecommunicationTariff.h"
#include "contractDate.h"

class Client
{
    private:
       std::string name, surname;
       int number, sentMessages, calledMinutes;
       double bill;
       TelecommunicationTariff<int>* tariff;
       ContractDateBase* callDate;
       double* callRegister;

    public:
        Client(std::string , std::string , int , int , 
               int , double , TelecommunicationTariff<int> *, 
               ContractDateBase* , double*);
        void setName(std::string );
        std::string getName();
        void setSurname(std::string );
        std::string getSurname();
        void setNumber(int);
        int getNumber();
        void setSentMessages(int);
        int getSentMessages();
        void setCalledMinutes(int);
        int getCalledMinutes();
        void computeBill();
        double getBill();
        void setTelecommunicationTariff(TelecommunicationTariff<int>* );
        TelecommunicationTariff<int>* getTelecomunicationTariffPointer();
        ContractDateBase* getDatePtr();
        double* getCallRegisterPointer();
        void printCallRegister();

        ~Client();
};
std::ostream& operator<< (std::ostream &out, Client &client);
#endif // CLIENT_H
