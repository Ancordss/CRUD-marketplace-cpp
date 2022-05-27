#pragma once
#include <string>
#include "time.h"
#include "Compra.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<iostream>

using namespace std;

void reloj();

void M_compras();
void crearcomprobante();
void leerBoleto();

/*---------incluye compra-------*/
void crearCompra();
void leerCompra();
void actualizarCompra();
void borrarCompra();


void M_compras() {
    do
    {
        int switch_on = 0;
        cout << "para agregar una Nueva compra ingrese 1: " << endl;
        cout << "para leer la tabla ingresa 2: " << endl;
        cout << "para actualizar la tabla ingresa 3" << endl;
        cout << "para borrar de la tabla ingresa 4 " << endl;
		cout << "para leer un boleto ingresa 5" << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearcomprobante(); break;

        case 2: leerCompra(); break;

        case 3: actualizarCompra(); break;

        case 4: borrarCompra(); break;

        case 5: leerBoleto(); break;


        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);

}

void crearCompra() {
    system("cls");
    string no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom;
    getline(cin, no_orden_compra);
    cout << "numero de orden de compra: " << no_orden_compra;
    getline(cin, no_orden_compra);
    cout << "ingrese el id del proveedor: " << endl;
    getline(cin, idproveedor);
    cout << "ingrese la fecha de la orden de compra: " << endl;
    getline(cin, fecha_orden);
    cout << "ingrese la fecha de ingreso de la orden de compra: " << endl;
    getline(cin, fechaingreso);

    Compra c = Compra(no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom);
    c.crear();
    c.leer();
    system("pause");
    system("cls");
}




void leerCompra()
{
    system("cls");
    string no_oreden_compra, idproveedor, fecha_orden, fechaingreso, varcom;
    cout << "------------TABLA COMPRAS-----------" << endl;
    Compra c = Compra(no_oreden_compra, idproveedor, fecha_orden, fechaingreso, varcom);
    c.leer();
    system("pause");
    system("cls");
}

void actualizarCompra()
{
    system("cls");
    string no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom;
    getline(cin, varcom);
    cout << "ingrese el id de la compra que desea actualizar: " << endl;
    getline(cin, varcom);
    cout << " ********" << endl;
    getline(cin, no_orden_compra);
    cout << "ingrese el numero de orden de compra: " << endl;
    getline(cin, no_orden_compra);
    cout << "ingrese el id del proveedor: " << endl;
    getline(cin, idproveedor);
    cout << "ingrese la fecha de la orden de compra: " << endl;
    getline(cin, fecha_orden);
    cout << "ingrese la fecha de ingreso de la orden de compra: " << endl;
    getline(cin, fechaingreso);

    Compra c = Compra(no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom);
    c.actualizar();
    c.leer();
    system("pause");
    system("cls");
}

void borrarCompra()
{
    system("cls");
    string no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom;
    getline(cin, varcom);
    cout << "ingrese el id de la compra que desea borrar: " << endl;
    getline(cin, varcom);
    Compra c = Compra(no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom);
    c.borrar();
    c.leer();
    system("pause");
    system("cls");
}

void crearcomprobante() {
    char continuar = 's';
    char fax = 's';
    do {
        system("cls");
        /*time_t t = time(NULL);
        tm* tPtr = localtime(&t);*/
        char cont = 's';
        int no_orden_compra;
        string  idproveedor, fecha_orden, fechaingreso, varcom;
        string  idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;

        int num, c;
        srand(time(NULL));

        for (c = 1; c <= 10; c++)
        {
            num = 1 + rand() % (501 - 1);
        }
        no_orden_compra = num;
        num = no_orden_compra;
        string no_ord = to_string(no_orden_compra);
        cout << "+---------------------------+" << endl;
        cout << " No. Orden de Compra: " << no_ord << endl; // numero de orden de compra aleatorio 
        cout << "+---------------------------+" << endl;

        getline(cin, idproveedor);
        cout << "+---------------------------+" << endl;
        cout << " Id Proveedor:   " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; getline(cin, idproveedor);

        Compra co = Compra(no_ord, idproveedor, fecha_orden, fechaingreso, varcom);
        co.crear();
        co.leer();

        cout << "+---------------------------+" << endl;
        cout << "Ingrese el id de la compra para comprobar " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; getline(cin, idCompra);
        do {
            cout << "+---------------------------+" << endl;
            cout << " Id Producto: " << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, idProducto);
            cout << "+---------------------------+" << endl;
            cout << " Cantidad: " << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, canitdad);
            cout << "+---------------------------+" << endl;
            cout << " Precio Costo Unitario: " << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, precio_costo_unitario);

            Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
            cd.crear();
            cd.leer();
            cout << "+---------------------------+" << endl;
            cout << " Desea ingresar otro producto? (s/n): " << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; cin >> cont;
            cin.ignore();

        } while (cont == 's');
        Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
        cd.leer();
        cout << '\n';
        cout << "+---------------------------+" << endl;
        cout << "|desea imprimir la factura (s/n)" << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; cin >> fax;
        cin.ignore();
        do {
            system("cls");
            Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
            cd.leer2();
            fclose(stdout);
            fflush(stdout);
            //imp();
            system("start C:\\tools\\imp\\imp.exe");
            freopen("CON", "w", stdout);
            cout << "+--------------------------------+" << endl;
            cout << "| impresion realizada con exito! |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| para regresar presiona (n)     |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "-->"; cin >> fax;
        } while (fax == 's');
        cout << "+---------------------------+" << endl;
        cout << "realizar otra compra? s/n" << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; cin >> continuar;
        cin.ignore();
    } while (continuar == 's');
}

void leerBoleto() {
    string  idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;
    cout << "------------TABLA COMPRAS-----------" << endl;
    cout << "------------------------------------" << endl;
	
	Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
	cd.leer();
}