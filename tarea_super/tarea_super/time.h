#pragma once
#include <ctime>
#include <iostream>
#include <string>
using namespace std;



void time() {
    system("cls");
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    cout << "\n\n mostrando el tiempo y fecha de hoy :\n";
    cout << "----------------------------------------\n";
    cout << " segundos = " << (tPtr->tm_sec) << endl;
    cout << " minutos = " << (tPtr->tm_min) << endl;
    cout << " horas = " << (tPtr->tm_hour) << endl;
    cout << " dia del mes = " << (tPtr->tm_mday) << endl;
    cout << " mes del anio = " << (tPtr->tm_mon) + 1 << endl;
    cout << " anio = " << (tPtr->tm_year) + 1900 << endl;
    cout << " semana = " << (tPtr->tm_wday) << endl;
    cout << " dia del anio = " << (tPtr->tm_yday) << endl;
    cout << endl;
    cout << endl;


    cout << " fecha actual: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << " hora actual: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << ":" << (tPtr->tm_sec) << endl;
    cout << endl;
    system("pause");

}

void reloj() {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    std::cout << "hora: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << ":" << (tPtr->tm_sec) << endl;
    
}