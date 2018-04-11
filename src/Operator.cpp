/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#include "Operator.h"

Operator::Operator()
{
}
Operator::Operator(double allBills = 0) : m_allBills(allBills)
{

}

void Operator::addClient(Client &client)
{
    m_clientList.push_back(client);
}
void Operator::removeClient(int listId)
{
    m_clientList.erase(m_clientList.begin() + listId);
}
void Operator::sumAllBills()
{
    for(std::vector<Client>::iterator it = m_clientList.begin(); it != m_clientList.end(); ++it)
    {
        it -> computeBill();
        m_allBills += it->getBill();
    }
}
std::string Operator::checkBalance(int operatorCapital)
{
   if(operatorCapital < static_cast<int>(m_allBills)) return "Operator balance is negative";
   else if(operatorCapital == static_cast<int>(m_allBills)) return "Operator balanace is zero";
   else return "Operator balance is positive";
}
std::string Operator::checkBalance(double operatorCapital)
{
   if(operatorCapital < (m_allBills)) return "Operator balance is negative";
   else if(operatorCapital == (m_allBills)) return "Operator balanace is zero";
   else return "Operator balance is positive";
}
void Operator::printClientList()
{
    std::cout << "Name\t" << "Surname\t" << "Phone number\t" << "nSms\t" << "nMins\t" <<
         "Acc balance\t" << "Day\t" << "Month\t" << "Year\t" << std::endl;
    for(std::vector<Client>::iterator it = m_clientList.begin(); it != m_clientList.end(); ++it)
    {

        std::cout << *it;
    }
}
Client Operator::getClient(int listId)
{
    return m_clientList[listId];
}
Operator::~Operator()
{
   for(std::vector<Client>::iterator it = m_clientList.begin(); it != m_clientList.end(); ++it)
    {
        delete [] it ->getCallRegisterPointer();
    }
}
