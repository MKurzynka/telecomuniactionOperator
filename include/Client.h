/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include "TelecommunicationTariff.h"
#include "contractDate.h"

class Client

{
    private:
       std::string m_name;
       std::string m_surname;
       int m_number;
       int m_nSentMessages;
       int m_nCalledMinutes;
       double m_bill;
       TelecommunicationTariff<int>* m_tariff;
       ContractDate<int> m_contractDate;
       double* m_callRegister;

    public:
        Client(std::string name, std::string surname, int number, int nSentMessages, int nCalledMinutes,
                double bill, TelecommunicationTariff<int> *tariff, int day, int month, int year, double* callRegister);
        void setName(std::string name);
        std::string getName();
        void setSurname(std::string surname);
        std::string getSurname();
        void setNumber(int number);
        int getNumber();
        void setNSentMessages(int nSentMessages);
        int getNSentMessages();
        void setNCalledMinutes(int nCalledMinutes);
        int getNCalledMinutes();
        void computeBill();
        double getBill();
        void setTelecommunicationTariff(TelecommunicationTariff<int>* Tariff);
        TelecommunicationTariff<int>* getpTelecomunicationTariff();
        int getDay();
        int getMonth();
        int getYear();
        double* getCallRegisterPointer();
        void printCallRegister();

        ~Client();
};
std::ostream& operator<< (std::ostream &out, Client &client);
#endif // CLIENT_H
