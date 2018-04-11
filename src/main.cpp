/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "contractDate.h"
#include "TelecommunicationTariff.h"
#include "Client.h"
#include "Operator.h"
#include "operatorFunctions.h"
using namespace std;

int main()
{
    double opBudget(0);
    readOperatorsBudgetFromStdIn(opBudget);

    Operator telecomunicationOperator(0);
    TelecommunicationTariff<int> economicTariff(40, 120, 0.1, 0.4, 20);

    if(readDataToClass(telecomunicationOperator, &economicTariff) != 0) return 1;

    telecomunicationOperator.sumAllBills();

    telecomunicationOperator.printClientList();

    cout << "\n" << telecomunicationOperator.checkBalance(opBudget) << endl;
    return 0;
}
