/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#ifndef TELECOMMUNICATIONTARIFF_H
#define TELECOMMUNICATIONTARIFF_H

template <class T> 
class TelecommunicationTariff
{
    private:

        T m_numberOfTxtMessages;
        T m_numberOfMinutes;
        double m_txtMessagePrice;
        double m_minutePrice;
        double m_basicFee;


    public:
        TelecommunicationTariff(){}
        TelecommunicationTariff(T numberOfTxtMessages = 0, T numberOfMinutes = 0, double txtMessagePrice = 0,
                                 double minutePrice = 0, double basicFee = 0) : m_numberOfTxtMessages(numberOfTxtMessages),
                                 m_numberOfMinutes(numberOfMinutes), m_txtMessagePrice(txtMessagePrice), m_minutePrice(minutePrice), m_basicFee(basicFee)

{

}

T getNumberOfTxtMessages(){ return m_numberOfTxtMessages; }
void setNumberOfTxtMessages(T numberOfTxtMessages){ m_numberOfTxtMessages = numberOfTxtMessages; }
T getNumberOfMinutes(){ return m_numberOfMinutes; }
void setNumberOfMinutes(T numberOfMinutes){ m_numberOfMinutes = numberOfMinutes; }
double getTxtMessagePrice(){ return m_txtMessagePrice; }
void setTxtMessagePrice(double txtMessagePrice){ m_txtMessagePrice = txtMessagePrice; }
double getMinutePrice(){ return m_minutePrice; }
void setMinutePrice(double minutePrice){ m_minutePrice = minutePrice; }
double getBasicFee(){ return m_basicFee; }
void setBasicFee(double basicFee){ m_basicFee = basicFee; }


~TelecommunicationTariff()
{
}

};

#endif // TELECOMMUNICATIONTARIFF_H
