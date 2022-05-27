#pragma once
#include <string>
#include "Venta.h"
#include "time.h"
#include <iostream>
#include "impresion.h"
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;



int nofactura = 0;
void reloj();
void imprimir(string cant, string pre_uni, string idV, string idP, string v);
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
    
    char continuar = 's';
    do {
        system("cls");
        /*time_t t = time(NULL);
        tm* tPtr = localtime(&t);*/
        char cont = 's';
        char fax = 's';
        int c;
        int serie = 1;
        string fechaF, idcl, idemp, fechaI;
        string cant, pre_uni, idV, idP, v;
        getline(cin, idcl);
        nofactura++;
        string noF = to_string(nofactura);
        cout << "+---------------+" << endl;
        cout << "nofactura: " << noF << endl; // automatico
        cout << "+---------------+" << endl;
        string sr = to_string(serie);
        cout << "+---------------+" << endl;
        cout << "serie:" << sr << endl; //automatico
        cout << "+---------------+" << endl;
        //cout << " fecha de ingreso "<< (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<" : "<< (tPtr->tm_sec) <<""<< endl;

        
        
        cout << "+---------------------------+" << endl;
        cout << "|ingrese id del cliente: " << endl; //esto tiene que ser por nit
        cout << "+---------------------------+" << endl;
        cout << "-->"; getline(cin, idcl);
        cout << "+---------------------------+" << endl;
        cout << "|ingrese id del empleado: " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->";  getline(cin, idemp);

        Venta u = Venta(noF, sr, fechaF, idcl, idemp, fechaI, v);
        u.crear();
        u.leeru();
        // esto se tiene que pasar automatico
        cout << "+---------------------------+" << endl;
        cout << "ingrese el id de la venta: " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; getline(cin, idV);
        do {
            cout << "+---------------------------+" << endl;
            cout << "ingrese el id del producto: " << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, idP);               //tiene que mostrar el producto que se ingresa
            cout << "+---------------------------+" << endl;
            cout << "ingrese la cantidad: " << endl; 
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, cant);
            cout << "+---------------------------+" << endl;
            cout << "ingrese precio_unitario: " << endl; // precio unitario tiene que agarrarse del que ya esta ingresado
            cout << "+---------------------------+" << endl;
            cout << "-->"; getline(cin, pre_uni);

            venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
            a.crear();
            cout << "+---------------------------+" << endl;
            cout << "agregar mas productos ? s/n" << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; cin >> cont;
            cin.ignore();
        } while (cont == 's');
        nofactura = nofactura + 1;
        venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
        a.leer();
        cout << '\n';
        cout << "+---------------------------+" << endl;
        cout << "|desea imprimir la factura (s/n)"<< endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; cin >> fax;
        cin.ignore();
        do{
            system("cls");
            venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v); 
            a.leerI();
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
        cout << "realizar otra venta? (s/n)" << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; cin >> continuar;
        cin.ignore();
    } while (continuar== 's');
    nofactura = nofactura;

}
/*
void imprimir(string cant, string pre_uni, string idV, string idP, string v) {
   freopen("texto.txt", "w", stdout);
    venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
    a.leer();
    fflush(stdout);
    fclose(stdout);

   //Reassign "stderr" to "freopen.out":
    //stream = freopen("texto.txt", "w", stderr); // C4996
    // Note: freopen is deprecated; consider using freopen_s instead

    if (stream == NULL)
        fprintf(stdout, "error on freopen\n");
    else
    {
        fprintf(stdout, "successfully reassigned\n"); fflush(stdout);
        fprintf(stream, "This will go to the file 'freopen.out'\n");
        fclose(stream);
    }
    system("type freopen.out");
   
} */