/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#include "Client.h"
Client::Client(std::string name = "", std::string surname = "", int number = 0, int nSentMessages = 0, int nCalledMinutes = 0,
                double bill = 0, TelecommunicationTariff<int> *tariff = NULL, int day = 1, int month = 1, int year = 2000, double* callRegister = NULL) : m_name(name), m_surname(surname), m_number(number),
                m_nSentMessages(nSentMessages), m_nCalledMinutes(nCalledMinutes), m_bill(bill), m_tariff(tariff), m_contractDate(day, month, year), m_callRegister(callRegister)
{
}
void Client::setName(std::string name){ m_name = name; }
std::string Client::getName(){ return m_name; }
void Client::setSurname(std::string surname){ m_surname = surname; }
std::string Client::getSurname(){ return m_surname; }
void Client::setNumber(int number){ m_number = number; }
int Client::getNumber(){ return m_number; }
void Client::setNSentMessages(int nSentMessages){ m_nSentMessages = nSentMessages; }
int Client::getNSentMessages(){ return m_nSentMessages; }
void Client::setNCalledMinutes(int nCalledMinutes){ m_nCalledMinutes = nCalledMinutes; }
int Client::getNCalledMinutes(){ return m_nCalledMinutes; }
void Client::computeBill()
{
    int exceededSms, exceededMins;
    exceededSms = (m_nSentMessages > m_tariff->getNumberOfTxtMessages()) ? m_nSentMessages - m_tariff->getNumberOfTxtMessages() : 0;
    exceededMins = (m_nCalledMinutes> m_tariff->getNumberOfMinutes()) ? m_nCalledMinutes - m_tariff->getNumberOfMinutes() : 0;
     m_bill = exceededSms * m_tariff->getTxtMessagePrice()
               + exceededMins * m_tariff->getMinutePrice()
               + m_tariff->getBasicFee();
}
double Client::getBill(){ return m_bill; }
void Client::setTelecommunicationTariff(TelecommunicationTariff<int>* tariff){ m_tariff = tariff; }
TelecommunicationTariff<int>* Client::getpTelecomunicationTariff(){ return m_tariff; }
int Client::getDay(){ return m_contractDate.getDay();}
int Client::getMonth(){ return m_contractDate.getMonth();}
int Client::getYear(){ return m_contractDate.getYear();}

double* Client::getCallRegisterPointer(){ return m_callRegister; }
void Client::printCallRegister()
{
    int iter = 0;
    while(m_callRegister[iter] != 0)
    {
        std::cout << m_callRegister[iter] << std::endl;
        iter++;
    }
}

std::ostream& operator<< (std::ostream &out, Client &client)
{
    out << client.getName() << "\t" << client.getSurname() << "\t" <<  client.getNumber() << "\t" <<  client.getNSentMessages() << "\t" <<  client.getNCalledMinutes() << "\t" <<
     client.getBill() << "\t" << client.getDay() << "\t" << client.getMonth() << "\t" << client.getYear() << std::endl;
    return out;
}

Client::~Client()
{
}
