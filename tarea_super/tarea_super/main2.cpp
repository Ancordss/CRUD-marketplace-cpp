// tarea_super.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <mysql.h>
#include "Proveedor.h"
#include "compra.h"
#include "Compras_detalle.h"
#include <string>
using namespace std;

void M_proveedor();
void crearPro();
void leerPro();
void actualizarPro();
void borrarPro();

void M_compra();
void crearCompra();
void leerCompra();
void actualizarCompra();
void borrarCompra();


void M_D_compra();
void crearD_compra();
void leerD_compra();
void actualizarD_Compra();
void borrarD_Compra();


int main() {
	/*
	int q_estado;
	ConexionBD cn = ConexionBD();
	cn.abrir_conexion();

	if (cn.getConectar()) {
		cout << "Conexion Exitosa..." << endl;
	}
	else{ cout << "Error en la | Exitosa." << endl;
	}
			system("pause");
	return 0;
	*/
	do
	{
		cout << "Bienvenido al menu principal " << endl;
		cout << "1. PROVEEDOR " << endl;
		cout << "2. COMPRAS " << endl;
		cout << "3. DETALLE DE COMPRAS " << endl;
		cout << "4. SALIR " << endl;
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1:
			system ("cls");
			M_proveedor();
			break;
		
		case 2: 
			system("cls");
			M_compra();
			break;
			
		case 3:
			system("cls");
			M_D_compra();
			break;
		
		case 0: exit(-1);

		}

	} while (1 == 1);

}

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
		case 1: crearPro(); break;

		case 2: leerPro(); break;

		case 3: actualizarPro(); break;


		case 4: borrarPro(); break;


		case 0: exit(-1);

		default: cout << "error ingresa un caracter valido!!!!" << endl;
			break;
		}


	} while (1 == 1);

}

void crearPro() {
	system("cls");
	string proveedor, nit, direccion, telefono, varpro;
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
	p.crear();
	p.leer();

}

void leerPro() {
	system("cls");
	string proveedor, nit, direccion, telefono, varpro;
	cout << "------------TABLA PROVEEDORES-----------" << endl;
	cout << "----------------------------------------" << endl;

	Proveedor p = Proveedor(proveedor, nit, direccion, telefono, varpro);
	p.leer();
}

void actualizarPro() {
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

}


void borrarPro() {
	system("cls");
	string proveedor, nit, direccion, telefono, varpro;
	getline(cin, proveedor);
	cout << "ingrese el id del proveedor que desea borrar: " << endl;
	getline(cin, var);

	Proveedor p = Proveedor(proveedor, nit, direccion, telefono, varpro);
	p.borrar();
	p.leer();

}

void M_compra() {
	do
	{
		int switch_on = 0;
		cout << "para agregar una nueva compra ingrese 1: " << endl;
		cout << "para leer la tabla ingresa 2: " << endl;
		cout << "para actualizar la tabla ingresa 3" << endl;
		cout << "para borrar de la tabla ingresa 4 " << endl;
		cout << "para salir presiona 0" << endl;
		cin >> switch_on;
		switch (switch_on)
		{
		case 1: crearCompra(); break;

		case 2: leerCompra(); break;

		case 3: actualizarCompra(); break;


		case 4: borrarCompra(); break; 


		case 0: exit(-1);

		default: cout << "error ingresa un caracter valido!!!!" << endl;
			break;
		}


	} while (1 == 1);

}

void crearCompra(){
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
	
	Compra c= Compra(no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom);
	c.crear();
	c.leer();
	system ("pause");
	system ("cls");
}

void leerCompra()
{
	system ("cls");
	string no_oreden_compra, idproveedor, fecha_orden, fechaingreso, varcom;
	cout << "------------TABLA COMPRAS-----------" << endl;
	cout << "------------------------------------" << endl;
	Compra c = Compra(no_oreden_compra, idproveedor, fecha_orden, fechaingreso, varcom);
	c.leer();
	system ("pause");
	system ("cls");
}

void actualizarCompra()
{
	system ("cls");
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
	system ("pause");
	system ("cls");
}

void borrarCompra()
{
	system ("cls");
	string no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom;
	getline(cin, var);
	cout << "ingrese el id de la compra que desea borrar: " << endl;
	getline(cin, var);
	Compra c = Compra(no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom);
	c.borrar();
	c.leer();
	system ("pause");
	system ("cls");
}


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
	string idCompra, idProducto, canitdad, precio_costo_unitario, var;
	getline(cin, idCompra);
	cout << "ingrese el id de la compra: " << endl;
	getline(cin, idCompra);
	cout << "ingrese el id del producto: " << endl;
	getline(cin, idProducto);
	cout << "ingrese la cantidad: " << endl;
	getline(cin, canitdad);
	cout << "ingrese el precio de costo unitario: " << endl;
	getline(cin, precio_costo_unitario);
	
	Compras_detalle cd = Compras_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varD);
	cd.crear();
	cd.leer();

}

void leerD_compra()
{
	system ("cls");
	string idCompra, idProducto, canitdad, precio_costo_unitario, varD;
	cout << "------------TABLA DETALLES DE COMPRAS-----------" << endl;
	cout << "------------------------------------" << endl;
	Compras_detalle cd = Compras_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varD);
	cd.leer();
	system ("pause");
	system ("cls");

}

void actualizarD_Compra()
{
	system ("cls");
	string idCompra, idProducto, canitdad, precio_costo_unitario, varD;
	getline(cin, varD);
	cout << "ingrese el id de la compra que desea actualizar: " << endl;
	getline(cin, varD);
	cout << " ********" << endl;
	getline(cin, idCompra);
	cout << "ingrese el id del producto: " << endl;
	getline(cin, idProducto);
	cout << "ingrese la cantidad: " << endl;
	getline(cin, canitdad);
	cout << "ingrese el precio de costo unitario: " << endl;
	getline(cin, precio_costo_unitario);
	
	Compras_detalle cd = Compras_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varD);
	cd.actualizar();
	cd.leer();
	system ("pause");
	system ("cls");
	
}


void borrarD_Compra()
{
	system ("cls");
	string idCompra, idProducto, canitdad, precio_costo_unitario, varD;
	getline(cin, varD);
	cout << "ingrese el id de la compra que desea borrar: " << endl;
	getline(cin, var);
	Compras_detalle cd = Compras_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varD);
	cd.borrar();
	cd.leer();
	system ("pause");
	system ("cls");
}



//menu de compras a proveedores

void M_C_proveedor()
	{
		string proveedor, nit, direccion, telefono, varpro;
		string  no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom;
		// me voy a imaginar los el nombre de la variables de producto
		// ver si las variables de producto son iguales a los de la clase producto
		string pruducto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso, varprod;
		string idCompra, idProducto, canitdad, precio_costo_unitario, varD
		int switch_on = 0;
		system ("cls");com
		int switch_on = 0;
		cout<< "BIENVENIDO A LA SECCION COMPRAS" << endl;
		cout << "Datos del PROVEEDOR" << endl;
		getline (cin, proveedor);
		cout << "Ingrese Proveedor" << endl;
		getline (cin, proveedor);
		cout << "ingrese nit: " << endl;
		getline (cin, nit);
		cout << "ingrese direccion: " << endl;
		getline (cin, direccion);
		cout << "ingrese telefono: " << endl;
		getline (cin, telefono);
		system ("cls");
		cout << "DATOS DE LA COMPRA" << endl;
		getline (cin, no_orden_compra);
		cout << "ingrese el numero de orden de compra: " << endl;
		getline (cin, no_orden_compra);
		cout << "ingrese el id del proveedor: " << endl;
		getline (cin, fecha_orden);
		cout << "ingrese la fecha de ingreso de la orden de compra (YYYY-MM-DD): " << endl;
		getline (cin, fechaingreso);
		system ("cls");
		cout << "DATOS DEL PRODUCTO" << endl;
		getline (cin, pruducto);
		cout << "ingrese el nombre del producto: " << endl;
		getline (cin, pruducto);
		cout << "ingrese el id de la marca: " << endl;
		getline (cin, idMarca);
		cout << "ingrese la descripcion: " << endl;
		getline (cin, Descripcion);
		cout << "ingrese la imagen: " << endl;
		getline (cin, Imagen);
		cout << "ingrese el precio de costo unitario: " << endl;
		getline (cin, precio_costo);
		cout << "ingrese el precio de venta unitario: " << endl;
		getline (cin, precio_venta);
		cout << "ingrese la existencia: " << endl;
		getline (cin, existencia);
		cout << "ingrese la fecha de ingreso del producto (YYYY-MM-DD): " << endl;
		getline (cin, fecha_ingreso);
		system ("cls");

		Proveedor p = Proveedor(proveedor, nit, direccion, telefono, varpro);
		Compra c = Compra(no_orden_compra, fecha_orden, fechaingreso, varcom);
		Producto pr = Producto(pruducto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso, varprod);
		p.crear();
		c.crear();
		pr.crear();

		Compras_detalle cd = Compras_detalle(idCompra, idProducto, canitdad, precio_costo_unitario, varD); 
		cd.leer();

	}