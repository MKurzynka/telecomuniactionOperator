/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#ifndef OPERATORFUNCTIONS_H_INCLUDED
#define OPERATORFUNCTIONS_H_INCLUDED
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "TelecommunicationTariff.h"
#include "Operator.h"

int readDataToClass(Operator &telecomunicationOperator, TelecommunicationTariff<int> *pTariff);
void readOperatorsBudgetFromStdIn(double &opBudget);
void readOperatorsBudgetFromStdIn(int &opBudget);

#endif // OPERATORFUNCTIONS_H_INCLUDED
