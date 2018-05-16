
#ifndef CONTRACTDATE_H
#define CONTRACTDATE_H
#include "contractDateBase.h"
template<typename T>
class ContractDate : public ContractDateBase {
        
    private:
        T month;
    public:
        ContractDate(){}
        ContractDate(int day, T month, int year)
                 : ContractDateBase( day, year ) {
                        this -> month = month; 
                 }
                        
        void setMonth(T);
        T getMonth();
        
        void printContractDate(std::ostream& stream) const;
        
};
template<typename T>
void ContractDate<T>::setMonth(T month) {
        this -> month = month;
}
template<typename T>
T ContractDate<T>::getMonth() {
        return month;
}
template<typename T>
void ContractDate<T>::printContractDate(std::ostream& stream) const {
        stream << day << " \t" << month << " \t" << year; 
}

#endif // CONTRACTDATE_H
