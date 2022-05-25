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
    system("cls");
    /*time_t t = time(NULL);
    tm* tPtr = localtime(&t);*/
    char cont = 's';
    int nofactura;
    int serie = 1;
    string fechaF, idcl, idemp, fechaI;
    string cant, pre_uni, idV, idP, v;

    nofactura = +1;
    string noF = to_string(nofactura);
    cout << "nofactura: "  << noF << endl; // automatico

    string sr = to_string(serie);
    cout << "serie:" <<sr << endl; //automatico

    //cout << " fecha de ingreso "<< (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<" : "<< (tPtr->tm_sec) <<""<< endl;


    getline(cin, idcl);
    cout << "id del cliente: " << endl;
    getline(cin, idcl);
    cout << "id del empleado: " << endl;
    getline(cin, idemp);

    Venta u = Venta(noF, sr, fechaF, idcl, idemp, fechaI, v);
    u.crear();
    u.leeru();

    cout << "id de la venta: ";
    getline(cin, idV);
    do {
        cout << "id del producto: " << endl;
        getline(cin, idP);
        cout << "cantidad: " << endl;
        getline(cin, cant);
        cout << "precio_unitario" << endl;
        getline(cin, pre_uni);

        venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
        a.crear();
        cout << "agregar mas ? s/n";
        cin >> cont;
        cin.ignore();
    } while (cont == 's');
    nofactura = nofactura + 1;

    venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
    a.leer();


}