/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#ifndef CONTRACTDATE_H
#define CONTRACTDATE_H
#include <string>
#include <iostream>
template<class T>
class ContractDate;

template<class T>
std::ostream& operator<< (std::ostream &out, const ContractDate<T> &contractDate);

template<class T>
class ContractDate
{
    private:
        int m_day;
        int m_month;
        int m_year;
    public:
        ContractDate(){}
        ContractDate(int day = 1, int month = 1, int year = 2000) : m_day(day), m_month(month), m_year(year)
        {
        }
        void setDay(int day){ m_day = day; }
        int getDay(){ return m_day; }
        void setMonth(int month){ m_month = month; }
        int getMonth(){ return m_month; }
        void setYear(int year){ m_year = year; }
        int getYear(){ return m_year; }
        friend std::ostream& operator<< <>(std::ostream &out, const ContractDate &contractDate);
        ~ContractDate() {}
};
template<typename T>
std::ostream& operator<< (std::ostream &out, const ContractDate<T> &contractDate)
{
    out << contractDate.m_day << "-" <<  contractDate.m_month << "-" << contractDate.m_year << std::endl;
    return out;
}

template<>
class ContractDate<std::string>
{
    private:
        std::string m_day;
        std::string m_month;
        int m_year;
    public:
        ContractDate(){};
        ContractDate(std::string day = "monday", std::string month = "January", int year = 2000)
        : m_day(day), m_month(month), m_year(year)
        {
        }
        friend std::ostream& operator<< <>(std::ostream &out, const ContractDate &contractDate);
        void setDay(int day){ m_day = day; }
        std::string getDay(){ return m_day; }
        void setMonth(int month){ m_month = month; }
        std::string getMonth(){ return m_month; }
        void setYear(int year){ m_year = year; }
        int getYear(){ return m_year; }
        ~ContractDate(){}
};
#endif // CONTRACTDATE_H
