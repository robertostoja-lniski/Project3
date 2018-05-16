
#include <sstream>
#include <fstream>
#include "Reader.h"
#include "contractDate.h"
#include "contractDateBase.h"
int Reader::toInteger(std::string month) {
    
    try {
        
        if(month.size()==2) throw -1;
        
        if(month.size() == 1)
            return month[0]-48;
        else
          return (month[0]-48)*10 + month[1]- 48;
          
    } catch(int e) {
        std::cout << "Reader.toInteger(string) has received illegal argument\n";
        return e;
    }
    
}
bool Reader::isNum(std::string month) {
    
    try {
        if(month.size()==0) throw -1;
        
        if(month.size() > 2)
              return false;
        if(month.size() == 2) {
           if(!isdigit(month[0]) || !isdigit(month[1])) 
                return false;    
          }
        if(month.size()==1) {
             if(!isdigit(month[0]))
                  return false;    
           }
    return true;
    } catch(int e) {
        std::cout << "Reader.isNUm(string) has received illegal argument\n";
        return false;
    }
   
}
void Reader::printHelloMessage() {
    std::cout << "Hello\n";
}
int Reader::readDataToClass(Operator &teleOperator, TelecommunicationTariff<int> *tariffPointer) throw()
{
    std::string clientFileName , callRegisterFileName;
    std::string name, surname, callRegisterName;
    int number, nSms, nMin, day, year, iter= 0;
    std::string month;
    double bill, callTime;
    
    try {
        std::ifstream infile("..//resource//Data.txt");
        std::string line;

        if(!infile.good()) throw -1;
        
        while (std::getline(infile, line))
        {
            std::istringstream iss(line);

            iss >> name >> surname >> number 
            >> nSms >> nMin >> bill >> day 
            >> month >> year >> callTime ;
            
            if(!iss) throw -2;
            
            double * callRegisterTab = new double[100];
        
            callRegisterTab[0] = callTime;
            ContractDateBase* ptr = createDatePointer(day, month, year);
            Client client(name, surname, number, nSms, nMin, bill, tariffPointer, ptr, callRegisterTab);
            //std::cout << *ptr;
            teleOperator.addClient(client);
    
            ++iter;
        }
        infile.close();
    } catch(int e) {
        if(e==-1)
            std::cout << "In Reader.readFile was an error - wrong file path";
        if(e==-2) {
            std::cout << "In Reader.readFile was an error - bad data format in file\n";
            std::cout << "change to: string, string, int, int, int, double, int, int or string, int, int\n";
            teleOperator.removeAllClients();
            return 1;
        }
        return 1;
    } catch (std::bad_alloc& e1) {
        std::cout<< "In Reader.readFile couldn't create call register Tab\n";
    }
    return 0;
}

void Reader::readOperatorsBudgetFromStdIn(Operator &operatorReference)
{
    try {
        double opBudget;
        std::cout << "Enter Tel Operator Budget" << std::endl;
        std::cin >> opBudget;
        
        if(!std::cin) throw -1;
        
        operatorReference.setBudget(opBudget);
        
    } catch(int e) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Wrong type given, type a numeric value";
        readOperatorsBudgetFromStdIn(operatorReference);
    }
    
}
