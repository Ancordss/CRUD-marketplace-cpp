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

    system("cls");
    /*time_t t = time(NULL);
    tm* tPtr = localtime(&t);*/
    char cont = 's';
    int no_orden_compra;
    string  idproveedor, fecha_orden, fechaingreso , varcom;
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
	cout <<"*******************************" << endl;
	cout << " No. Orden de Compra: " << no_ord << endl; // numero de orden de compra aleatorio 
    cout << "*******************************" << endl;
	
    getline(cin, idproveedor);
    cout << " Id Proveedor:   ";
	getline(cin, idproveedor);
	
    Compra co = Compra(no_ord, idproveedor, fecha_orden, fechaingreso, varcom);
	co.crear();
	co.leer();

	cout << "Ingrese el id de la compra para comprobar " << endl;
	getline(cin, idCompra);
    do {
		cout << " Id Producto: " << endl;
		getline(cin, idProducto);
		cout << " Cantidad: " << endl;
		getline(cin, canitdad);
		cout << " Precio Costo Unitario: " << endl;
		getline(cin, precio_costo_unitario);
		
		Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
		cd.crear();
        cd.leer();

		cout << " Desea ingresar otro producto? (s/n): " << endl;
		cin >> cont;
        cin.ignore();
		
    } while (cont == 's');
	
	Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
	cd.leer();
	system ("pause");

}

void leerBoleto() {
    string  idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;
    cout << "------------TABLA COMPRAS-----------" << endl;
    cout << "------------------------------------" << endl;
	
	Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
	cd.leer();
}