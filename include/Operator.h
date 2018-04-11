/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#ifndef OPERATOR_H
#define OPERATOR_H
#include <vector>
#include "Client.h"


class Operator
{
    private:
        std::vector <Client> m_clientList;
        double m_allBills;

    public:
        Operator();
        Operator(double allBills);
        void addClient(Client &client);
        void removeClient(int listId);
        std::string checkBalance(int operatorCapital);
        std::string checkBalance(double operatorCapital);
        void sumAllBills();
        void printClientList();
        Client getClient(int listID);


        virtual ~Operator();
};

#endif // OPERATOR_H
