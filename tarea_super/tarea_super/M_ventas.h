#pragma once
#include <string>
#include "Venta.h"
#include "time.h"
#include <iostream>
using namespace std;

void reloj();

void menu_Venta();
void crearfactura();

void crear_venta();
void leer_venta();
void actualizar_venta();
void borrar_venta();

void menu_Venta() {
    do
    {
        int switch_on = 0;
        cout << "para realizar Nueva Venta ingresa 1" << endl;
        cout << "para leer la tabla ingresa 2" << endl;
        cout << "para actualizar la tabla ingresa 3" << endl;
        cout << "para borrar de la tabla ingresa 4 " << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); crearfactura(); break;

        case 2: system("cls"); leer_venta(); break;

        case 3: system("cls"); actualizar_venta(); break;

        case 4: system("cls"); borrar_venta(); break;


        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);



}


void crear_venta() {

    system("cls");
    string noF, sr, fechaF, idcl, idemp, fechaI, v;
    getline(cin, noF);
    cout << "no de factura: ";
    getline(cin, noF);
    cout << "ingrese serie de las facturas: ";
    getline(cin, sr);
    cout << "fecha de la factura: ";
    getline(cin, fechaF);
    cout << "id del cliente ";
    getline(cin, idcl);
    cout << "id del empleado : ";
    getline(cin, idemp);


    Venta u = Venta(noF, sr, fechaF, idcl, idemp, fechaI, v);
    u.crear();


}

void leer_venta() {
    string noF, sr, fechaF, idcl, idemp, fechaI, v;
    cout << "--------------TABLA Venta----------------------------" << endl;
    Venta u = Venta(noF, sr, fechaF, idcl, idemp, fechaI, v);
    u.leer();

}

void actualizar_venta() {
    system("cls");
    string noF, sr, fechaF, idcl, idemp, fechaI, v;
    getline(cin, noF);
    cout << "no de factura: ";
    getline(cin, noF);
    cout << "ingrese serie de las facturas: ";
    getline(cin, sr);
    cout << "fecha de la factura: ";
    getline(cin, fechaF);
    cout << "id del cliente ";
    getline(cin, idcl);
    cout << "id del empleado : ";
    getline(cin, idemp);


    Venta u = Venta(noF, sr, fechaF, idcl, idemp, fechaI, v);
    u.actualizar();

}


void borrar_venta() {
    string noF, sr, fechaF, idcl, idemp, fechaI, v;
    getline(cin, v);
    cout << "ingrese id de la venta a eliminar: ";
    getline(cin, v);

    Venta u = Venta(noF, sr, fechaF, idcl, idemp, fechaI, v);
    u.borrar();



}

void crearfactura() {
    int nofactura = 0;
    char continuar = 's';
    do {
        system("cls");
        /*time_t t = time(NULL);
        tm* tPtr = localtime(&t);*/
        char cont = 's';
        int c;
        int serie = 1;
        string fechaF, idcl, idemp, fechaI;
        string cant, pre_uni, idV, idP, v;
        getline(cin, idcl);
        nofactura++;
        string noF = to_string(nofactura);
        cout << "nofactura: " << noF << endl; // automatico

        string sr = to_string(serie);
        cout << "serie:" << sr << endl; //automatico

        //cout << " fecha de ingreso "<< (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<" : "<< (tPtr->tm_sec) <<""<< endl;

        
        
        cout << "+---------------------------+" << endl;
        cout << "|ingrese id del cliente: " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; getline(cin, idcl);
        cout << "+---------------------------+" << endl;
        cout << "|ingrese id del empleado: " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->";  getline(cin, idemp);

        Venta u = Venta(noF, sr, fechaF, idcl, idemp, fechaI, v);
        u.crear();
        u.leeru();

        cout << "+---------------------------+" << endl;
        cout << "ingrese el id de la venta: " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; getline(cin, idV);
        do {
            cout << "+---------------------------+" << endl;
            cout << "ingrese el id del producto: " << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, idP);
            cout << "+---------------------------+" << endl;
            cout << "ingrese la cantidad: " << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, cant);
            cout << "+---------------------------+" << endl;
            cout << "ingrese precio_unitario: " << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, pre_uni);

            venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
            a.crear();
            cout << "+---------------------------+" << endl;
            cout << "agregar mas productos ? s/n";
            cout << "+---------------------------+" << endl;
            cout << "-->"; cin >> cont;
            cin.ignore();
        } while (cont == 's');
        nofactura = nofactura + 1;

        venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
        a.leer();
        cout << "+---------------------------+" << endl;
        cout << "realizar otra venta? (s/n)" << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; cin >> continuar;
        cin.ignore();
    } while (continuar== 's');

}