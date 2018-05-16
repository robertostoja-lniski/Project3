
#include <algorithm>
#include <cmath>
#include "Client.h"
Client::Client(std::string name = "", std::string surname = "", int number = 0,
               int SentMessages = 0, int CalledMinutes = 0, double bill = 0,
               TelecommunicationTariff<int> *tariff = NULL, 
               ContractDateBase* callDate = NULL, double* callRegister = NULL) 
                
                : name(name), surname(surname), number(number),
                sentMessages(SentMessages), calledMinutes(CalledMinutes),
                bill(bill), tariff(tariff), callDate(callDate),
                callRegister(callRegister) {} 

void Client::setName(std::string name){ this->name = name; }
std::string Client::getName(){ return name; }
void Client::setSurname(std::string surname){ this->surname = surname; }
std::string Client::getSurname(){ return surname; }
void Client::setNumber(int number){ this->number = number; }
int Client::getNumber(){ return number; }
void Client::setSentMessages(int sentMessages){ this->sentMessages = sentMessages; }
int Client::getSentMessages(){ return sentMessages; }
void Client::setCalledMinutes(int calledMinutes){ this->calledMinutes = calledMinutes; }
int Client::getCalledMinutes(){ return calledMinutes; }
void Client::computeBill()
{
    try {
    
        int exceededSms, exceededMins;
        if(tariff->getNumberOfMinutes()==-1) throw -1;
        if(tariff->getNumberOfTxtMessages()==-1) throw -2;
        
        exceededSms = std::max(sentMessages - tariff->getNumberOfTxtMessages(), 0);
        exceededMins = std::max(calledMinutes - tariff->getNumberOfMinutes() , 0);
        
        bill = exceededSms * tariff->getTxtMessagePrice()
               + exceededMins * tariff->getMinutePrice()
               + tariff->getBasicFee();
    } catch (int e) {
        if(e==-1)  {
            std::cout << "Tariff not defined - missing number of msgs\n";
            bill =-1;
        }
        if(e==-2) {
            std::cout << "Tariff not defined - missing number of minutes\n"; 
            bill =-1;
        } 
    }
        
}

double Client::getBill(){ 
    
    try {
        if(bill==-1) throw -1;
        
        return bill;
        
    } catch (int e) {
        return -1;
    }
}
void Client::setTelecommunicationTariff(TelecommunicationTariff<int>* tariff){ tariff = tariff; }
TelecommunicationTariff<int>* Client::getTelecomunicationTariffPointer(){ return tariff; }
ContractDateBase* Client::getDatePtr(){ return callDate;}

double* Client::getCallRegisterPointer(){ return callRegister; }

std::ostream& operator<< (std::ostream &out, Client &client)
{
    try {
        if(&client == NULL) throw -1;
        out << client.getName() << "\t" << client.getSurname() << "\t\t" <<  client.getNumber() << "\t"
        << client.getSentMessages() << "\t" <<  client.getCalledMinutes() << "\t"
        << client.getBill() << "\t" << *client.getDatePtr() << std::endl;
        
    } catch (int e) {
        std::cout << "Tried to print null pointer customer\n";         
    }
    return out;
}

Client::~Client(){}
