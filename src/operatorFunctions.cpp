/*
Autor : Michal Kurzynka, 271194
Prowadzacy: Wiktor Kusmirek
Numer zadania 2
*/
#include "operatorFunctions.h"
int readDataToClass(Operator &telecomunicationOperator, TelecommunicationTariff<int> *pTariff)
{
    std::string fNameClient, fNameCallReg;
    std::cout << "Enter Client data file name" << std::endl;
    getline(std::cin, fNameClient);
    std::string h_name;
    std::string h_surname;
    int h_number;
    int h_nSms;
    int h_nMin;
    double h_bill;
    int h_day;
    int h_month;
    int h_year;
    std::string h_callRegisterName;
    double callTime;


    std::ifstream my_input_file_client;
    std::ifstream my_input_file_callRegister;

    int iter(0);

    my_input_file_client.open(fNameClient.c_str(), std::fstream::in);
    if(my_input_file_client.fail())
    {
        std::cout << "Unable to open Client data file" << std::endl;
        return 1;
    }
    while(my_input_file_client >> h_name >> h_surname >> h_number >> h_nSms >> h_nMin >> h_bill >> h_day >> h_month >> h_year >> h_callRegisterName)
    {
        my_input_file_callRegister.open(h_callRegisterName.c_str(), std::fstream::in);
        if(my_input_file_callRegister.fail())
        {
            std::cout << "Unable to open call register data file no." << iter << std::endl;
            return 2;
        }
        double * callRegisterTab = new double[100];
        int iterCall(0);

        while(my_input_file_callRegister >> callTime)
        {
            callRegisterTab[iterCall] = callTime;
            iterCall++;
        }

        Client client(h_name, h_surname, h_number, h_nSms, h_nMin, h_bill, pTariff, h_day, h_month, h_year, callRegisterTab);
        telecomunicationOperator.addClient(client);
        ++iter;
        my_input_file_callRegister.close();

    }
    my_input_file_client.close();
    return 0;
}
void readOperatorsBudgetFromStdIn(double &opBudget)
{
    std::cout << "Enter Tel Operator Budget" << std::endl;
    std::cin >> opBudget;
    std::cin.clear();
    std::cin.ignore(200, '\n');
}
