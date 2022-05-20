#pragma once
#include <iostream>
#include <mysql.h>
#include "Clientes.h"
#include <string>
#include "Ventas.h"
#include "Productos.h"
#include "Marcas.cpp"
using namespace std;




void menu_ventas();

void crear_venta();
void leer_venta();
void actualizar_venta();
void borrar_venta();



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

/*submenu admin  productos 3*/
void M_producto();
void subM_productos();
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

/*submenus empleado crear clientes 1*/
void M_clientes();
void menu_clientes();
void crearC();
void borrarC();
void actualizarC();
void leerC();

void menuUser() {
    do
    {
        int switch_on = 0;
        cout << "ingresar en modo?" << endl;
        cout << "Administrador (1)" << endl;
        cout << "empleado (2)" << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
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
    do
    {
        int switch_on = 0;
        cout << "administrar empleados (1)" << endl;
        cout << "administrar productos (2)"<< endl;
        cout << "administra proveedores (3)" << endl;
        cout << "comprar a proveedores (4)" << endl;
        cout << "mostrar opciones de empleados (4)" << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); menu_empleados(); break;

        case 2: system("cls"); M_producto(); break;
        case 4: system("cls"); M_empleado(); break;


        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);
}


void M_empleado() {
    do
    {
        int switch_on = 0;
        cout << "ventas (1)" << endl;
        cout << "gestionar productos (2)" << endl;
        cout << "registra clientes (3)" << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 2: system("cls"); subM_productos(); break;
        case 3: system("cls"); menu_clientes(); break;


        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);




}


void M_producto() {
    do
    {
        cout << "xxx seleciona que quieres hacer:" << endl;
        cout << "1. Productos" << endl;
        cout << "2. marcas " << endl;
        cout << "3. SALIR " << endl;
        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
            system("cls");
            subM_productos();
            break;

        case 2:
            system("cls");
            M_marca();
            break;

        case 0: exit(-1);

        }

    } while (1 == 1);
}









void M_clientes() {
    do
    {
        int switch_on = 0;
        cout << "para agregar cliente ingrese 1" << endl;
        cout << "para agregar empleado ingrese 2" << endl;
        cout << "para hacer una venta ingrese 3" << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); menu_clientes(); break;

        case 2: system("cls"); menu_empleados(); break;

        case 3: system("cls"); menu_ventas(); break;

        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);

}


void menu_clientes() {
    do
    {
        int switch_on = 0;
        cout << "para agregar contenido ingresa 1" << endl;
        cout << "para leer la tabla ingresa 2" << endl;
        cout << "para actualizar la tabla ingresa 3" << endl;
        cout << "para borrar de la tabla ingresa 4 " << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); crearC(); break;

        case 2: system("cls"); leerC(); break;

        case 3: system("cls"); actualizarC(); break;

        case 4: system("cls"); borrarC(); break;

        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);


}


void menu_empleados() {
    do
    {
        int switch_on = 0;
        cout << "para agregar contenido ingresa 1" << endl;
        cout << "para leer la tabla ingresa 2" << endl;
        cout << "para actualizar la tabla ingresa 3" << endl;
        cout << "para borrar de la tabla ingresa 4 " << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); empleados_crear(); break;

        case 2: system("cls"); empleados_leer(); break;

        case 3: system("cls"); empleados_actualizar(); break;

        case 4: system("cls"); empleados_borrar(); break;

        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl;
            break;
        }


    } while (1 == 1);




}




void menu_ventas() {
    do
    {
        int switch_on = 0;
        cout << "para agregar contenido ingresa 1" << endl;
        cout << "para leer la tabla ingresa 2" << endl;
        cout << "para actualizar la tabla ingresa 3" << endl;
        cout << "para borrar de la tabla ingresa 4 " << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); crear_venta(); break;

        case 2: system("cls"); leer_venta(); break;

        case 3: system("cls"); actualizar_venta(); break;

        case 4: system("cls"); borrar_venta(); break;

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
    cout << "ingrese fecha ingreso: ";
    getline(cin, fi);




    Nit r = Nit(nt);
    r.verificanit();

    Clientes c = Clientes(nom, ape, nt, gen, dir, tel, ce, fi, v);
    c.crear();
}



void borrarC() {
    string nom, ape, nt, gen, dir, tel, ce, fi, v;
    getline(cin, nom);
    cout << "ingrese id del producto a eliminar: ";
    getline(cin, v);

    Clientes c = Clientes(nom, ape, nt, gen, dir, tel, ce, fi, v);
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
    cout << "ingrese fecha ingreso: ";
    getline(cin, fi);

    Clientes c = Clientes(nom, ape, nt, gen, dir, tel, ce, fi, v);
    c.actualizar();

}

void leerC() {
    string nom, ape, nt, gen, dir, tel, ce, fi, v;
    cout << "--------------TABLA Clientes----------------------------" << endl;
    Clientes c = Clientes(nom, ape, nt, gen, dir, tel, ce, fi, v);
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
    getline(cin, ge);
    cout << "ingrese fecha nacimiento: ";
    getline(cin, fn);
    cout << "ingrese idpuesto: ";
    getline(cin, idpuesto);
    cout << "ingrese fecha inicio: ";
    getline(cin, fi);
    cout << "ingrese fecha ingreso: ";
    getline(cin, fin);



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
    getline(cin, ge);
    cout << "ingrese fecha nacimiento: ";
    getline(cin, fn);
    cout << "ingrese idpuesto: ";
    getline(cin, idpuesto);
    cout << "ingrese fecha inicio: ";
    getline(cin, fi);
    cout << "ingrese fecha ingreso: ";
    getline(cin, fin);

    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.actualizar();

}

void empleados_leer() {
    string nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v;
    cout << "--------------TABLA empleados----------------------------" << endl;
    Empleados a = Empleados(nom, ape, nt, gen, dir, tel, ce, dpi, ge, fn, idpuesto, fi, fin, v);
    a.leer();

}



/*-------------------------------------------------------ventas--------------------------------------------------*/

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
    cout << "fecha ingreso: ";
    getline(cin, fechaI);


    Ventas u = Ventas(noF, sr, fechaF, idcl, idemp, fechaI, v);
    u.crear();


}

void leer_venta() {
    string noF, sr, fechaF, idcl, idemp, fechaI, v;
    cout << "--------------TABLA ventas----------------------------" << endl;
    Ventas u = Ventas(noF, sr, fechaF, idcl, idemp, fechaI, v);
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
    cout << "fecha ingreso: ";
    getline(cin, fechaI);

    Ventas u = Ventas(noF, sr, fechaF, idcl, idemp, fechaI, v);
    u.actualizar();

}


void borrar_venta() {
    string noF, sr, fechaF, idcl, idemp, fechaI, v;
    getline(cin, v);
    cout << "ingrese id de la venta a eliminar: ";
    getline(cin, v);

    Ventas u = Ventas(noF, sr, fechaF, idcl, idemp, fechaI, v);
    u.borrar();



}




void subM_productos() {
    do
    {
        int switch_on = 0;
        cout << "Si desea agregar un Producto presione 1 : " << endl;
        cout << "Si desea ver los productos ingresados presione 2 : " << endl;
        cout << "Si de sea actulaizar los productos ingresados presione 3 : " << endl;
        cout << "Si de sea borrar un producto presione 4 : " << endl;
        cout << "Si desea salir presione 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearpro(); break;

        case 2: leerpro(); break;

        case 3: actualizarpro(); break;


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
    cout << "Ingrese la fecha que ingreso el producto: " << endl;
    getline(cin, fe_ing);


    productos p = productos(prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v);
    p.crear();
    p.leer();

}

void leerpro() {
    system("cls");
    string prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v;
    cout << "***LISTA DE PRODUCTOS INGRESADOS****" << endl;
    cout << "----------------------------------------" << endl;

    productos p = productos(prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v);
    p.leer();
}

void actualizarpro() {
    system("cls");
    string prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v;
    getline(cin, v);
    cout << "Ingrese el Id del producto a actualizar: " << endl;
    getline(cin, v);
    cout << " **" << endl;
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
    cout << "Ingrese la fecha que ingreso el producto: " << endl;
    getline(cin, fe_ing);

    productos p = productos(prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v);
    p.actualizar();
    p.leer();

}


void borrarpro() {
    system("cls");
    string prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v;
    getline(cin, v);
    cout << "Ingrese el Id del producto que desea eliminar: " << endl;
    getline(cin, v);

    productos p = productos(prod, idM, Des, Ima, pre_c, pre_v, exi, fe_ing, v);
    p.borrar();
    p.leer();

}

void M_marca() {
    do
    {
        int switch_on = 0;
        cout << "Si desea agregar una Marca presione 1 : " << endl;
        cout << "Si desea ver las marcas ingresadas presione 2 : " << endl;
        cout << "Si de sea actulaizar las marcas ingresadas presione 3 : " << endl;
        cout << "Si de sea borrar una marca presione 4 : " << endl;
        cout << "Si desea salir presione 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearmarca(); break;

        case 2: leermarca(); break;

        case 3: actualizarmarca(); break;


        case 4: borrarmarca(); break;


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

    marcas m = marcas(marca, var);
    m.crear();
    m.leer();

}

void leermarca() {
    system("cls");
    string marca, var;
    cout << "***LISTA DE MARCAS INGRESADAS****" << endl;
    cout << "----------------------------------------" << endl;

    marcas m = marcas(marca, var);
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

    marcas m = marcas(marca, var);

    m.actualizar();
    m.leer();

}


void borrarmarca() {
    system("cls");
    string marca, var;
    getline(cin, var);
    cout << "Ingrese el Id de la marca que desea eliminar: " << endl;
    getline(cin, var);

    marcas m = marcas(marca, var);
    m.borrar();
    m.leer();

}