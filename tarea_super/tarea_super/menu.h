#pragma once
#include <iostream>
#include <mysql.h>
#include "Cliente.h"
#include <string>
#include "M_ventas.h"
#include "Producto.h"
#include "Marca.cpp"
#include "Proveedor.h"
#include "Compra.h"
#include "Compra_Detalle.h"
#include "Producto.h"
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

/*---------incluye proveedor-------*/
void M_compra();
void crearCompra();
void leerCompra();
void actualizarCompra();
void borrarCompra();

/*---------incluye marca-------*/
void M_compra();
void crearCompra();
void leerCompra();
void actualizarCompra();
void borrarCompra();

/*---------incluye marca Detalle-------*/
void M_D_compra();
void crearD_compra();
void leerD_compra();
void actualizarD_Compra();
void borrarD_Compra();

/*---------MAESTROS-----------------------*/
void Maestro_compras();


/*submenus empleado crear Cliente 1*/
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
        cout << "administrar Producto (2)"<< endl;
        cout << "administra proveedores (3)" << endl;
        cout << "comprar a proveedores (4)" << endl;
        cout << "mostrar opciones de empleados (5)" << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); menu_empleados(); break;
        case 2: system("cls"); M_producto(); break;
		case 3: system("cls"); M_proveedor(); break;
        case 4: system("cls"); Maestro_compras(); break;
			// compra detalle estra en el menu de compra
			//se tiene que crear un registro maestro de compra a proveedores y un detalle de compra a proveedores
        case 5: system("cls"); M_empleado(); break;


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
        cout << "Venta (1)" << endl;
        cout << "gestionar Producto (2)" << endl;
        cout << "registra Cliente (3)" << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: system("cls"); menu_Venta(); break;
        case 2: system("cls"); subM_Producto(); break;
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
        cout << "1. Producto" << endl;
        cout << "2. Marca " << endl;
        cout << "3. SALIR " << endl;
        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
            system("cls");
            subM_Producto();
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

        case 3: system("cls"); menu_Venta(); break;

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
        cout << "para agregar empleado ingresa 1" << endl;
        cout << "para leer la tabla empleados ingresa 2" << endl;
        cout << "para actualizar un empleado ingresa 3" << endl;
        cout << "para borrar de la tabla empleados ingresa 4 " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "para agregar puesto ingresa 5" << endl;
        cout << "para leer la tabla puestos ingresa 6" << endl;
        cout << "para actualizar un puesto ingresa 7" << endl;
        cout << "para borrar de la tabla puesto ingresa 8 " << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
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
    do
    {
        int switch_on = 0;
        cout << "Si desea agregar un Producto presione 1 : " << endl;
        cout << "Si desea ver los Producto ingresados presione 2 : " << endl;
        cout << "Si de sea actulaizar los Producto ingresados presione 3 : " << endl;
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
    do
    {
        int switch_on = 0;
        cout << "Si desea agregar una Marca presione 1 : " << endl;
        cout << "Si desea ver las Marca ingresadas presione 2 : " << endl;
        cout << "Si de sea actulaizar las Marca ingresadas presione 3 : " << endl;
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
    do
    {
        int switch_on = 0;
        cout << "para agregar un proveedor ingrese 1: " << endl;
        cout << "para leer la tabla ingresa 2: " << endl;
        cout << "para actualizar la tabla ingresa 3" << endl;
        cout << "para borrar de la tabla ingresa 4 " << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearProd(); break;

        case 2: leerProd(); break;

        case 3: actualizarProd(); break;


        case 4: borrarProd(); break;


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

/*-------------------------------------------------------COMPRA--------------------------------------------------*/

void M_compra() {
    do
    {
        int switch_on = 0;
        cout << "para agregar una nueva compra ingrese 1: " << endl;
        cout << "para leer la tabla ingresa 2: " << endl;
        cout << "para actualizar la tabla ingresa 3" << endl;
        cout << "para borrar de la tabla ingresa 4 " << endl;
		cout << "Ingresar a Compra detalle " << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearCompra(); break;

        case 2: leerCompra(); break;

        case 3: actualizarCompra(); break;

        case 4: borrarCompra(); break;
			
        case 5: M_D_compra(); break;


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
    cout << "ingrese el numero de orden de compra: " << endl;
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
    cout << "------------------------------------" << endl;
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

/*-------------------------------------------------------COMPRA DETALLE--------------------------------------------------*/

void M_D_compra() {
    do
    {
        int switch_on = 0;
        cout << "para agregar una nuevo detalle de compra ingrese 1: " << endl;
        cout << "para leer los detalles de compra ingresa 2: " << endl;
        cout << "para actualizar la tabla ingresa 3" << endl;
        cout << "para borrar de la tabla ingresa 4 " << endl;
        cout << "para salir presiona 0" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearD_compra(); break;

        case 2: leerD_compra(); break;

        case 3: actualizarD_Compra(); break;


        case 4: borrarD_Compra(); break;


        case 0: exit(-1);

        default: cout << "error ingresa un caracter valido!!!!" << endl; break;
        }


    } while (1 == 1);

}


void crearD_compra()
{
    system("cls");
    string idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;
    getline(cin, idCompra);
    cout << "ingrese el id de la compra: " << endl;
    getline(cin, idCompra);
    cout << "ingrese el id del producto: " << endl;
    getline(cin, idProducto);
    cout << "ingrese la cantidad: " << endl;
    getline(cin, canitdad);
    cout << "ingrese el precio de costo unitario: " << endl;
    getline(cin, precio_costo_unitario);

    Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
    cd.crear();
    cd.leer();

}

void leerD_compra()
{
    system("cls");
    string idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;
    cout << "------------TABLA DETALLES DE COMPRAS-----------" << endl;
    cout << "------------------------------------" << endl;
    Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
    cd.leer();
    system("pause");
    system("cls");

}

void actualizarD_Compra()
{
    system("cls");
    string idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;
    getline(cin, varDcom);
    cout << "ingrese el id del detalle de compra que desea actualizar: " << endl;
    getline(cin, varDcom);
    cout << " ********" << endl;
    getline(cin, idCompra);
    cout << "ingrese el id de la compra que desea actualizar: " << endl;
	getline(cin, idCompra);
	cout << "ingrese e id del producto que desea actualizar: " << endl;
	getline(cin, idProducto);
	cout << "ingrese la cantidad que desea actualizar: " << endl;
	getline(cin, canitdad);
	cout << "ingrese el precio de costo unitario que desea actualizar: " << endl;
	getline(cin, precio_costo_unitario);

    Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
    cd.actualizar();
    cd.leer();
    system("pause");
    system("cls");

}


void borrarD_Compra()
{
    system("cls");
    string idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;
    getline(cin, varDcom);
    cout << "ingrese el id de la compra que desea borrar: " << endl;
    getline(cin, varDcom);
    Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
    cd.borrar();
    cd.leer();
    system("pause");
    system("cls");
}   


void Maestro_compras(){
    //proveedores
    string proveedor, nit, direccion, telefono, varpro;
    //compras
    string no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom;
    //Producto
    string producto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso, var_producto;
    //compra detalle
	string idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;

    string idcompra = varcom;
    string idproducto = var_producto;

	cout << "MAESTRO DETALLE DE COMPRAS" << endl;
    getline(cin, proveedor);
	cout << "1. Proveedores" << endl;
	getline (cin, proveedor);
	cout << "2. nit " << endl;
	getline (cin, nit);
	cout << "3. direccion " << endl;
	getline (cin, direccion);
	cout << "4. telefono " << endl;
	getline (cin, telefono);
	
    system("cls");
    cout << "MAESTRO DETALLE DE COMPRAS" << endl;
	getline(cin, no_orden_compra);
	cout << "1. No orden de compra" << endl;
	getline (cin, no_orden_compra);
    varpro = idproveedor;
    idproveedor = idproveedor;
	cout << "2. fecha de orden de compra" << endl;
	getline (cin, fecha_orden);
	cout << "3. fecha de ingreso" << endl;
	getline (cin, fechaingreso);
	
	system("cls");
	cout << "MAESTRO DETALLE DE COMPRAS" << endl;
	
	getline(cin, producto);
	cout << "1. Producto" << endl;
	getline (cin, producto);
	cout << "2. idMarca " << endl;
	getline (cin, idMarca);
	cout << "3. Descripcion " << endl;
	getline (cin, Descripcion);
	cout << "4. Imagen " << endl;
	getline (cin, Imagen);
	cout << "5. precio de costo " << endl;
	getline (cin, precio_costo);
	cout << "6. precio de venta " << endl;
	getline (cin, precio_venta);
	cout << "7. existencia " << endl;
	getline (cin, existencia);
	cout << "8. fecha de ingreso " << endl;
	getline (cin, fecha_ingreso);
	
	Compra c = Compra(no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom);
	c.crear();
	c.leer();
	
    Producto p = Producto(producto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso, var_producto);
	p.crear();
	p.leer();
	
	Compra_detalle cd = Compra_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varDcom);
	cd.crear();
	cd.leer();	
	
	
}
