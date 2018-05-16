
#ifndef TELECOMMUNICATIONTARIFF_H
#define TELECOMMUNICATIONTARIFF_H

template <class T> 
class TelecommunicationTariff
{
    private:

        T numberOfTxtMessages, numberOfMinutes;
        double txtMessagePrice, minutePrice, basicFee;

    public:
        TelecommunicationTariff(){}
        TelecommunicationTariff(T numberOfTxtMessages =-1, T numberOfMinutes =-1,
                                double txtMessagePrice = 0, double minutePrice = 0, double basicFee = 0)
                                
                                 : numberOfTxtMessages(numberOfTxtMessages),numberOfMinutes(numberOfMinutes),
                                  txtMessagePrice(txtMessagePrice), minutePrice(minutePrice), basicFee(basicFee) {}

T getNumberOfTxtMessages(){ return numberOfTxtMessages; }
void setNumberOfTxtMessages(T numberOfTxtMessages){ this -> numberOfTxtMessages = numberOfTxtMessages; }
T getNumberOfMinutes(){ return numberOfMinutes; }
void setNumberOfMinutes(T numberOfMinutes){ this -> numberOfMinutes = numberOfMinutes; }
double getTxtMessagePrice(){ return txtMessagePrice; }
void setTxtMessagePrice(double txtMessagePrice){ this -> txtMessagePrice = txtMessagePrice; }
double getMinutePrice(){ return minutePrice; }
void setMinutePrice(double minutePrice){ this -> minutePrice = minutePrice; }
double getBasicFee(){ return basicFee; }
void setBasicFee(double basicFee){ this -> basicFee = basicFee; }

~TelecommunicationTariff(){}

};

#endif // TELECOMMUNICATIONTARIFF_H
