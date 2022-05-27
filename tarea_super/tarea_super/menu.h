//para regresar al menu en cada menu agregar un case para regresar al menu principal. [eso lo ve james XD]
// maria colores y menus decoracion
//carlos agregar arduino
//mandar a imprimir factura [james]  
//logo para terminar agregar a la factura.
#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <mysql.h>
#include "Cliente.h"
#include <string>
#include "M_ventas.h"
#include "Producto.h"
#include "Marca.cpp"
#include "Proveedor.h"
#include "M_compras.h"
#include "Producto.h"
#include <windows.h>
using namespace std;

/*menu principal*/
void menuUser();
/*menus segundarios*/
void M_empleado();
void Madmin();


/*submenu admin crear empleado*/
void menu_empleados();
void empleados_crear();
void empleados_borrar();
void empleados_actualizar();
void empleados_leer();
void crear_puesto();
void update_puesto();
void borra_puesto();
void leer_puesto();

/*submenu admin  Producto 3*/
void M_producto();
void subM_Producto();
void crearpro();
void leerpro();
void actualizarpro();
void borrarpro();

/*---------incluye marca-------*/
void M_marca();
void crearmarca();
void leermarca();
void actualizarmarca();
void borrarmarca();

/*---------incluye proveedor-------*/

void M_proveedor();
void crearProd();
void leerProd();
void actualizarProd();
void borrarProd();
 

/*---------MAESTROS-----------------------*/

void M_compras();

/*submenus empleado crear Cliente 1*/
void M_clientes();
void menu_clientes();
void crearC();
void borrarC();
void actualizarC();
void leerC();

void menuUser() { 
       HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) ;
       system("cls");

       
    do
    {
        int switch_on = 0;

        SetConsoleTextAttribute (hConsole, 2);  cout <<  "+-------------------------------------+" << endl;
        SetConsoleTextAttribute (hConsole, 14); cout <<  "|    Selecciona tipo de usuario:      |" << endl;
        SetConsoleTextAttribute (hConsole, 14); cout <<  "|       * Administrador   (1)         |" << endl;
        SetConsoleTextAttribute (hConsole, 14); cout <<  "|       * Empleado        (2)         |" << endl;
        SetConsoleTextAttribute (hConsole, 14); cout <<  "|       para salir presiona 0         |" << endl;
        SetConsoleTextAttribute (hConsole, 2);  cout <<  "+-------------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1:  system("cls"); Madmin(); break;

        case 2: system("cls"); M_empleado();  break;


        case 0: exit(-1); 

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);

}



void Madmin() {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) ;
     system("cls");

    do
    {
        int switch_on = 0;
      
        SetConsoleTextAttribute (hConsole, 1); cout << "+------------------------------------------+" << endl;
        SetConsoleTextAttribute (hConsole, 3); cout << "|      administrar empleados          (1)  |" << endl;
        SetConsoleTextAttribute (hConsole, 3); cout << "|      administrar Producto           (2)  |"<< endl;
        SetConsoleTextAttribute (hConsole, 3); cout << "|      administra proveedores         (3)  |" << endl;
        SetConsoleTextAttribute (hConsole, 3); cout << "|      Realizar comprar a proveedores (4)  |" << endl;
        SetConsoleTextAttribute (hConsole, 3); cout << "|      mostrar opciones de empleados  (5)  |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout <<  "|      regresar                       (6)  |" << endl;
        SetConsoleTextAttribute (hConsole, 3); cout << "|      para salir presiona            (0)  |" << endl;
        SetConsoleTextAttribute (hConsole, 1); cout << "+------------------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); menu_empleados(); break;
        case 2: system("cls"); M_producto(); break;
		case 3: system("cls"); M_proveedor(); break;
        case 4: system("cls"); crearcomprobante(); break; //M_compras(); break;
        case 5: system("cls"); M_empleado(); break;
        case 6: system("cls"); menuUser(); break;

        case 0: exit(-1); break;

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);
}


void M_empleado() {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) ;
     system("cls");
    do
    {
        int switch_on = 0;
        SetConsoleTextAttribute (hConsole, 4);cout << "+----------------------------------+" << endl;
        SetConsoleTextAttribute (hConsole,15);cout << "|     Realizar Venta          (1)  |" << endl;
        SetConsoleTextAttribute (hConsole,15);cout << "|     gestionar Producto      (2)  |" << endl;
        SetConsoleTextAttribute (hConsole,15);cout << "|     registra Cliente        (3)  |" << endl;
        SetConsoleTextAttribute(hConsole, 15);cout << "|     regresar al menu        (4)  |" << endl;
        SetConsoleTextAttribute (hConsole,15);cout << "|     para salir presiona     (0)  |" << endl;
        SetConsoleTextAttribute (hConsole, 4);cout << "+----------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); crearfactura(); break;//menu_Venta(); break;
        case 2: system("cls"); subM_Producto(); break;
        case 3: system("cls"); menu_clientes(); break;
        case 4: system("cls"); menuUser(); break;

        case 0: exit(-1); break;

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);

}


void M_producto() {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) ;
     system("cls");

    do
    {
        SetConsoleTextAttribute(hConsole, 128); cout << "****   selecciona una opcion:   ****" << endl;
        SetConsoleTextAttribute(hConsole, 10); cout << " 1. Producto" << endl;
        SetConsoleTextAttribute(hConsole, 10); cout << " 2. Marca " << endl;
        SetConsoleTextAttribute(hConsole, 10); cout << " 3. regresar " << endl;
        SetConsoleTextAttribute(hConsole, 10); cout << " 4. SALIR " << endl;
        int opcion;
        cout << "-->"; cin >> opcion;
        switch (opcion) {
        case 1:
            system("cls");
            subM_Producto();
            break;

        case 2:
            system("cls");
            M_marca();
            break;
        case 3: Madmin(); break;

        case 0: exit(-1); break;

        }

    } while (1 == 1);
}



void M_clientes() {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) ;
     system("cls");

    do
    {
        int switch_on = 0;
        SetConsoleTextAttribute (hConsole, 1);cout << "+-------------------------------------+" << endl;
        SetConsoleTextAttribute (hConsole, 1);cout << "| para agregar cliente ingrese  (1)   |" << endl;
        SetConsoleTextAttribute(hConsole, 1); cout << "| para agregar empleado ingrese (2)   |" << endl;
        SetConsoleTextAttribute(hConsole, 1); cout << "| para hacer una venta ingrese  (3)   |" << endl;
        SetConsoleTextAttribute (hConsole, 1);cout << "| para salir presiona           (0)   |" << endl;
        SetConsoleTextAttribute (hConsole, 1);cout << "+-------------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); menu_clientes(); break;

        case 2: system("cls"); menu_empleados(); break;

        case 3: system("cls"); menu_Venta(); break;

        case 0: exit(-1); break;

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);

}


void menu_clientes() {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) ;
     system("cls");

    do
    {
        int switch_on = 0;
        SetConsoleTextAttribute(hConsole, 11); cout << "+----------------------------------------------+" << endl;
        SetConsoleTextAttribute(hConsole, 11); cout << "|   para agregar contenido ingresa      (1)    |" << endl;
        SetConsoleTextAttribute(hConsole, 11); cout << "|   para leer la tabla ingresa          (2)    |" << endl;
        SetConsoleTextAttribute(hConsole, 11); cout << "|   para actualizar la tabla ingresa    (3)    |" << endl;
        SetConsoleTextAttribute(hConsole, 11); cout << "|   para borrar de la tabla ingresa     (4)    |" << endl;
        SetConsoleTextAttribute(hConsole, 11); cout << "|   regresar                            (5)    |" << endl;
        SetConsoleTextAttribute(hConsole, 11); cout << "|   para salir presiona                 (0)    |" << endl;
        SetConsoleTextAttribute(hConsole, 11); cout << "+----------------------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); crearC(); break;

        case 2: system("cls"); leerC(); break;

        case 3: system("cls"); actualizarC(); break;

        case 4: system("cls"); borrarC(); break;
        case 5: system("cls"); M_clientes(); break;

        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);


}


void menu_empleados() {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) ;
     system("cls");

    do
    {
        int switch_on = 0;
        SetConsoleTextAttribute(hConsole, 1); cout << "+----------------------------------------------------+" << endl;
        SetConsoleTextAttribute(hConsole, 1); cout << "|    para agregar empleado ingresa              (1)  |" << endl;
        SetConsoleTextAttribute(hConsole, 1); cout << "|    para leer la tabla empleados ingresa       (2)  |" << endl;
        SetConsoleTextAttribute(hConsole, 1); cout << "|    para actualizar un empleado ingresa        (3)  |" << endl;
        SetConsoleTextAttribute(hConsole, 1); cout << "|    para borrar de la tabla empleados ingresa  (4)  |" << endl;
        SetConsoleTextAttribute(hConsole, 1); cout << "+====================================================+" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|    para agregar puesto ingresa                (5)  |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|    para leer la tabla puestos ingresa         (6)  |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|    para actualizar un puesto ingresa          (7)  |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|    para borrar de la tabla puesto ingresa     (8)  |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|    regresar                                   (9)  |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|    para salir presiona                        (0)  |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "+----------------------------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); empleados_crear(); break;

        case 2: system("cls"); empleados_leer(); break;

        case 3: system("cls"); empleados_actualizar(); break;

        case 4: system("cls"); empleados_borrar(); break;
        case 5: system("cls"); crear_puesto(); break;

        case 6: system("cls"); leer_puesto(); break;
        case 7: system("cls"); update_puesto(); break;
        case 8: system("cls"); borra_puesto(); break;
        case 9: system("cls"); Madmin(); break;
        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);




}





void crearC() {
    system("cls");
    string nit;
    string nom, ape, nt, gen, dir, tel, ce, fi, v;
    getline(cin, nom);
    cout << "ingrese nombre: ";
    getline(cin, nom);
    cout << "ingrese apellido: ";
    getline(cin, ape);
    cout << "ingrese nit: ";
    getline(cin, nt);
    cout << "ingrese correo electronico: ";
    getline(cin, ce);
    cout << "ingrese telefono: ";
    getline(cin, tel);
    cout << "ingrese genero: ";
    getline(cin, gen);
    Genero d = Genero(gen);
    d.confgen();



    Nit r = Nit(nt);
    r.verificanit();

    Cliente c = Cliente(nom, ape, nt, gen, dir, tel, ce, fi, v);
    c.crear();
}



void borrarC() {
    string nom, ape, nt, gen, dir, tel, ce, fi, v;
    getline(cin, nom);
    cout << "ingrese id del producto a eliminar: ";
    getline(cin, v);

    Cliente c = Cliente(nom, ape, nt, gen, dir, tel, ce, fi, v);
    c.borrar();
}

void actualizarC() {
    system("cls");
    string nom, ape, nt, gen, dir, tel, ce, fi, v;
    getline(cin, v);
    cout << "ingrese id del carne a actualizar: ";
    getline(cin, v);
    cout << "=================================================" << endl;
    getline(cin, nom);
    cout << "ingrese nombre: ";
    getline(cin, nom);
    cout << "ingrese apellido: ";
    getline(cin, ape);
    cout << "ingrese nit: ";
    getline(cin, nt);
    cout << "ingrese correo electronico: ";
    getline(cin, ce);
    cout << "ingrese telefono: ";
    getline(cin, tel);
    cout << "ingrese genero: ";
    getline(cin, gen);
    Genero d = Genero(gen);
    d.confgen();
 


    Cliente c = Cliente(nom, ape, nt, gen, dir, tel, ce, fi, v);
    c.actualizar();

}

void leerC() {
    string nom, ape, nt, gen, dir, tel, ce, fi, v;
    cout << "--------------TABLA Cliente----------------------------" << endl;
    Cliente c = Cliente(nom, ape, nt, gen, dir, tel, ce, fi, v);
    c.leer();
}
/*************************************************************************************************************************/


void empleados_crear() {
    system("cls");

    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;

    getline(cin, nom);
    cout << "ingrese nombre: ";
    getline(cin, nom);
    cout << "ingrese apellido: ";
    getline(cin, ape);
    cout << "ingrese direccion: ";
    getline(cin, dir);
    cout << "ingrese telefono: ";
    getline(cin, tel);
    cout << "ingrese DPI: ";
    getline(cin, dpi);
    cout << "ingrese genero: ";
    getline(cin, gen);
    Genero d = Genero(gen);
    d.confgen();





    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.crear();
}


void empleados_borrar() {
    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;
    getline(cin, nom);
    cout << "ingrese id del producto a eliminar: ";
    getline(cin, v);

    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.borrar();
}


void empleados_actualizar() {
    system("cls");
    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;
    getline(cin, v);
    cout << "ingrese id del empleado a actualizar: ";
    getline(cin, v);
    cout << "=================================================" << endl;
    getline(cin, nom);
    cout << "ingrese nombre: ";
    getline(cin, nom);
    cout << "ingrese apellido: ";
    getline(cin, ape);
    cout << "ingrese direccion: ";
    getline(cin, dir);
    cout << "ingrese telefono: ";
    getline(cin, tel);
    cout << "ingrese DPI: ";
    getline(cin, dpi);
    cout << "ingrese genero: ";
    getline(cin, gen);
    Genero d = Genero(gen);
    d.confgen();
    cout << "ingrese fecha nacimiento: ";
    getline(cin, fn);
    cout << "ingrese idpuesto: ";
    getline(cin, idpuesto);
    cout << "ingrese la fecha de inicio de labores nueva: ";
    getline(cin, fi);

  

    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.actualizar();

}

void empleados_leer() {
    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;
    cout << "--------------TABLA empleados----------------------------" << endl;
    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.leer();

}

void crear_puesto() {
    system("cls");

    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;

    getline(cin, nom);
    cout << "ingrese puesto: ";
    getline(cin, nom);
    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.crearpuesto();

}

void leer_puesto() {

    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;
    cout << "--------------TABLA puesto----------------------------" << endl;
    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.leerPuesto();
}

void borra_puesto() {
    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;
    getline(cin, nom);
    cout << "ingrese id del puesto a borrar: ";
    getline(cin, v);

    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.borrarPuesto();

}

void update_puesto() {
    system("cls");


    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;
    getline(cin, v);
    cout << "ingrese id del puesto a actualizar: ";
    getline(cin, v);
    cout << "=================================================" << endl;
    getline(cin, nom);
    cout << "ingrese nuevo nombre para el puesto: ";
    getline(cin, nom);
    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.actualizarpuesto();

}
/*-------------------------------------------------------Venta--------------------------------------------------*/




void subM_Producto() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    do
    {
        int switch_on = 0;
        SetConsoleTextAttribute(hConsole, 3); cout << "+----------------------------------------------------------------------------+"<< endl;
        SetConsoleTextAttribute(hConsole, 5); cout << "|          Si desea agregar un Producto presione                  (1)        |" << endl;
        SetConsoleTextAttribute(hConsole, 5); cout << "|          Si desea ver los Producto ingresados presione          (2)        |" << endl;
        SetConsoleTextAttribute(hConsole, 5); cout << "|          Si de sea actulaizar los Producto ingresados presione  (3)        |" << endl;
        SetConsoleTextAttribute(hConsole, 5); cout << "|          Si de sea borrar un producto presione                  (4)        |" << endl;
        SetConsoleTextAttribute(hConsole, 5); cout << "|          regresar                                               (5)        |" << endl;
        SetConsoleTextAttribute(hConsole, 5); cout << "|             -Si desea salir presione                            (0)        |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "+----------------------------------------------------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearpro(); break;

        case 2: leerpro(); break;

        case 3: actualizarpro(); break;
        case 5: M_producto(); break;


        case 4: borrarpro(); break;


        case 0: exit(-1);

        default: cout << "ERROR! NUMERO INVALIDO, POR FAVOR INGRESE OTRO. " << endl;
            break;
        }


    } while (1 == 1);

}

void crearpro() {
    system("cls");
    string prod,idM,Des,Ima,pre_c,pre_v,exi,fe_ing, v;
    getline(cin, prod);
    cout << "Ingrese el producto: " << endl;
    getline(cin, prod);
    cout << "Ingrese el Id de la marca del producto : " << endl;
    getline(cin, idM);
    cout << "Ingrese la Descripcion del producto: " << endl;
    getline(cin, Des);
    cout << "Ingrese la imagen del producto: " << endl;
    getline(cin, Ima);
    cout << "Ingrese el precio de costo del producto: " << endl;
    getline(cin, pre_c);
    cout << "Ingrese el precio de venta del producto: " << endl;
    getline(cin, pre_v);
    cout << "Ingrese la existencia del producto: " << endl;
    getline(cin, exi);


    Producto p = Producto(prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v);
    p.crear();
    p.leer();

}

void leerpro() {
    system("cls");
    string prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v;
    cout << "***LISTA DE Producto INGRESADOS****" << endl;
    cout << "----------------------------------------" << endl;

    Producto p = Producto(prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v);
    p.leer();
}

void actualizarpro() {
    system("cls");
    string prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v;
    getline(cin, v);
    cout << "Ingrese el Id del producto a actualizar: " << endl;
    getline(cin, v);
    cout << "Ingrese el producto: " << endl;
    getline(cin, prod);
    cout << "Ingrese el Id de la marca del producto : " << endl;
    getline(cin, idM);
    cout << "Ingrese la Descripcion del producto: " << endl;
    getline(cin, Des);
    cout << "Ingrese la imagen del producto: " << endl;
    getline(cin, Ima);
    cout << "Ingrese el precio de costo del producto: " << endl;
    getline(cin, pre_c);
    cout << "Ingrese el precio de venta del producto: " << endl;
    getline(cin, pre_v);
    cout << "Ingrese la existencia del producto: " << endl;
    getline(cin, exi);
 
    Producto p = Producto(prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v);
    p.actualizar();
    p.leer();

}


void borrarpro() {
    system("cls");
    string prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v;
    getline(cin, v);
    cout << "Ingrese el Id del producto que desea eliminar: " << endl;
    getline(cin, v);

    Producto p = Producto(prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v);
    p.borrar();
    p.leer();

}

void M_marca() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    do
    {
        int switch_on = 0;
        SetConsoleTextAttribute(hConsole, 3); cout << "+----------------------------------------------------------------------+" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|     Si desea agregar una Marca presione                    (1)       |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|     Si desea ver las Marca ingresadas presione             (2)       |  " << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|     Si de sea actulaizar las Marca ingresadas presione     (3)       |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|     Si de sea borrar una marca presione                    (4)       |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|     regresar                                               (5)       |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|     Si desea salir presione                                (0)       |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "+----------------------------------------------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearmarca(); break;

        case 2: leermarca(); break;

        case 3: actualizarmarca(); break;


        case 4: borrarmarca(); break;
        case 5: M_producto(); break;


        case 0: exit(-1);

        default: cout << "ERROR! NUMERO INVALIDO, POR FAVOR INGRESE OTRO. " << endl;
            break;
        }


    } while (1 == 1);

}

void crearmarca() {
    system("cls");
    string marca, var;
    getline(cin, marca);
    cout << "Ingrese la marca: " << endl;
    getline(cin, marca);

    Marca m = Marca(marca, var);
    m.crear();
    m.leer();

}

void leermarca() {
    system("cls");
    string marca, var;
    cout << "***LISTA DE Marca INGRESADAS****" << endl;
    cout << "----------------------------------------" << endl;

    Marca m = Marca(marca, var);
    m.leer();
}

void actualizarmarca() {
    system("cls");
    string marca, var;
    getline(cin, var);
    cout << "Ingrese el Id de la marca a actualizar: " << endl;
    getline(cin, var);
    cout << " **" << endl;
    getline(cin, marca);
    cout << "Ingrese la marca: " << endl;
    getline(cin, marca);

    Marca m = Marca(marca, var);

    m.actualizar();
    m.leer();

}


void borrarmarca() {
    system("cls");
    string marca, var;
    getline(cin, var);
    cout << "Ingrese el Id de la marca que desea eliminar: " << endl;
    getline(cin, var);

    Marca m = Marca(marca, var);
    m.borrar();
    m.leer();

}


/*-------------------------------------------------------PROVEEDORES--------------------------------------------------*/

void M_proveedor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    do
    {
        int switch_on = 0;
        SetConsoleTextAttribute(hConsole, 3); cout << "+--------------------------------------------------+"<<endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|   para agregar un proveedor ingrese        (1)   |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|   para leer la tabla ingresa               (2)   |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|   para actualizar la tabla ingresa         (3)   |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|   para borrar de la tabla ingresa          (4)   |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|   regresar                                 (5)   |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "|   para salir presiona                      (0)   |" << endl;
        SetConsoleTextAttribute(hConsole, 3); cout << "+--------------------------------------------------+" << endl;
        cout << "-->"; cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearProd(); break;

        case 2: leerProd(); break;

        case 3: actualizarProd(); break;


        case 4: borrarProd(); break;

        case 5: Madmin(); break;


        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);

}

void crearProd() {
    system("cls");
    string proveedor, nit, direccion, telefono, varpro;
    getline(cin, proveedor);
    cout << "ingrese  proveedor: " << endl;
    getline(cin, proveedor);
    cout << "ingrese el nit del proveedor: " << endl;
    getline(cin, nit);
    cout << "ingrese la direccion del proveedor: " << endl;
    getline(cin, direccion);
    cout << "ingrese el telefono del proveedor: " << endl;
    getline(cin, telefono);

    Proveedor p = Proveedor(proveedor, nit, direccion, telefono, varpro);
    p.crear();
    p.leer();
    system("pause");
    system ("cls");

}

void leerProd() {
    system("cls");
    string proveedor, nit, direccion, telefono, varpro;
    cout << "------------TABLA PROVEEDORES-----------" << endl;
    cout << "----------------------------------------" << endl;

    Proveedor p = Proveedor(proveedor, nit, direccion, telefono, varpro);
    p.leer();
    system("pause");
	system ("cls");
}

void actualizarProd() {
    system("cls");
    string proveedor, nit, direccion, telefono, varpro;
    getline(cin, varpro);
    cout << "ingrese el id del proveedor que desea actualizar: " << endl;
    getline(cin, varpro);
    cout << " ********" << endl;
    getline(cin, proveedor);
    cout << "ingrese el nombre del proveedor: " << endl;
    getline(cin, proveedor);
    cout << "ingrese el nit del proveedor: " << endl;
    getline(cin, nit);
    cout << "ingrese la direccion del proveedor: " << endl;
    getline(cin, direccion);
    cout << "ingrese el telefono del proveedor: " << endl;
    getline(cin, telefono);

    Proveedor p = Proveedor(proveedor, nit, direccion, telefono, varpro);
    p.actualizar();
    p.leer();
    system("pause");
	system ("cls");

}


void borrarProd() {
    system("cls");
    string proveedor, nit, direccion, telefono, varpro;
    getline(cin, proveedor);
    cout << "ingrese el id del proveedor que desea borrar: " << endl;
    getline(cin, varpro);

    Proveedor p = Proveedor(proveedor, nit, direccion, telefono, varpro);
    p.borrar();
    p.leer();
    system("pause");
	system ("cls");

}
