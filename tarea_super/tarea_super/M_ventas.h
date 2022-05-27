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
        time_t t = time(NULL);
        tm* tPtr = localtime(&t);
        char cont = 's';
        char fax = 's';
        int c;
        int serie = 1;
        string nt;
        string fechaF, idcl, idemp, fechaI;
        string cant, pre_uni, idP, v;
        getline(cin, idcl);
        

        cout << "+---------------------------+" << endl;
        cout << "|ingrese id del empleado: " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->";  getline(cin, idemp);


        cout << "+---------------------------+" << endl;
        cout << "|ingrese nit del cliente: " << endl; //esto tiene que ser por nit comprobar si existe el nit en la bd
        cout << "+---------------------------+" << endl;
        cout << "-->"; getline(cin, idcl);
        string idV = idcl;
        Nit r = Nit(idcl);
        system("cls");
        r.verificanit();
        cout << " continuar? s/n:"; cin >> continuar;
        if (continuar == 'n') break;
        //cin.ignore();
        nofactura++;
        string noF = to_string(nofactura);
        system("cls");

        cout << " nofactura: " << noF; // automatico
        cout << "                                       Hora: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << " : " << (tPtr->tm_sec) << "" << endl;
        string sr = to_string(serie);
        cout << " serie:" << sr; //automatico

       
        Venta u = Venta(noF, sr, fechaF, idcl, idemp, fechaI, v);
        u.crear();
        u.leerCV();
       // u.leeru();
        // esto se tiene que pasar automatico
      /*  cout << "+---------------------------+" << endl;
        cout << "ingrese el id de la venta: " << endl;
        cout << "+---------------------------+" << endl;
        cout << "-->"; getline(cin, idV);*/
        do {

            getline(cin, idP);

            cout << " ingrese el id del producto: "; getline(cin, idP);   
            cout << " ingrese la cantidad:        "; getline(cin, cant);
            cout << " ingrese precio_unitario:    "; getline(cin, pre_uni);
            venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
            a.crear();
            a.leerVD();


            cout << '\n';
            cout << "agregar mas productos ? s/n "; cin >> cont;
            cin.ignore();
            system("cls");
        } while (cont == 's');
        nofactura = nofactura + 1;
        //cout << "" << endl;
        int segundos = 5;
        for (int i = 0; i <= 10; i++)//21
            cout << "\n";
        cout << "\t\t\t\t CARGANDO... \n";
        for (int i = 0; i <= 79; i++)//7|9
            cout << "";
        for (int i = 0; i <= 79; i++)//79
        {
            cout << char(219);
            Sleep(segundos * 100 / 80);
        }
        cout << "\nCompletado!" << endl;
        venta_detalle a = venta_detalle(cant, pre_uni, idV, idP, v);
        a.leer();

        do{
            cout << '\n';
            cout << "+---------------------------+" << endl;
            cout << "|desea imprimir la factura (s/n)" << endl;
            cout << "+---------------------------+" << endl;
            cout << "-->"; cin >> fax;
            if (fax == 'n') break;
            cin.ignore();
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
        freopen("CON", "w", stdout);
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