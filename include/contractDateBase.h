
#ifndef CONTRACTDATEBASE_H
#define CONTRACTDATEBASE_H
#include <string>
#include <iostream>

class ContractDateBase {
    protected:
        int day,year;
    public:
        ContractDateBase(){}
        ContractDateBase(int day = 1, int year = 2000) : day(day), year(year) {}
        void setDay(int day){ day = day; }
        int getDay(){ return day; }
        void setYear(int year){ year = year; }
        int getYear(){ return year; }
        
        virtual void printContractDate(std::ostream& stream) const = 0;
       		 friend std::ostream& operator<< (std::ostream &stream, const ContractDateBase& c)
					{
    					c.printContractDate(stream);
   						return stream;
					}
        ~ContractDateBase() {}
};

#endif // CONTRACTDATE_H
