#pragma once
#include <iostream>
#include <string>
#include "ConexionDB.h"
using namespace std;

class productos
{
	//atributos
private: string producto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso, var;
	   //constructor
public: productos() {
}
	  productos(string prod, string idM, string Des, string Ima, string pre_c, string pre_v, string exi, string fe_ing, string v)
	  {
		  producto = prod;
		  idMarca = idM;
		  Descripcion = Des;
		  Imagen = Ima;
		  precio_costo = pre_c;
		  precio_venta = pre_v;
		  existencia = exi;
		  fecha_ingreso = fe_ing;
		  var = v;
	  }
	  //metodos set 
	  void setproducto(string prod) { producto = prod; }
	  void setidMarca(string idM) { idMarca = idM; }
	  void setDescripcion(string Des) { Descripcion = Des; }
	  void setImagen(string Ima) { Imagen = Ima; }
	  void setprecio_costo(string pre_c) { precio_costo = pre_c; }
	  void setprecio_venta(string pre_v) { precio_venta = pre_v; }
	  void setexistencia(string exi) { existencia = exi; }
	  void setfecha_ingreso(string fe_ing) { fecha_ingreso = fe_ing; }
	  void setVar(string v) { var = v; }
	  //metodos get
	  string getproducto() { return producto; }
	  string getidMarca() { return idMarca; }
	  string getDescripcion() { return Descripcion; }
	  string getImagen() { return Imagen; }
	  string getprecio_costo() { return precio_costo; }
	  string getprecio_venta() { return precio_venta; }
	  string getexistencia() { return existencia; }
	  string getfecha_ingreso() { return fecha_ingreso; }
	  string getVar() { return var; }


	  //metodos
	//crear
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO productos (producto, idMarca, Descripcion, Imagen, precio_costo, precio_venta,existencia,fecha_ingreso) VALUES ('" + producto + "','" + idMarca + "','" + Descripcion + "','" + Imagen + "','" + precio_costo + "','" + precio_venta + "','" + existencia + "','" + fecha_ingreso + "');";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "El PRODUCTO SE CREO CORRECTAMENTE" << endl;
			  }
			  else {
				  cout << "OCURRIO UN ERROR AL CREAR EL PRODUCTO" << endl;
			  }
		  }
		  else {
			  cout << "ERROR EN LA CONEXION DE LA BASE DE DATOS" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  //leer 
	  void leer() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  cout << "*LISTA DE PRODUCTOS INGRESADOS*" << endl;
			  string consulta = "SELECT * FROM productos";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << " , " << fila[9] << endl;
				  }

			  }
			  else {
				  cout << "OCURRIO UN ERROR AL INTENTAR LEER LOS PRODUCTOS" << endl;
			  }
		  }
		  else {
			  cout << "ERROR EN LA CONEXION CON LA BASE DE DATOS" << endl;
			  system("pause");
		  }
		  cn.cerrar_conexion();
	  }

	  //actualizar
	  void actualizar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "UPDATE productos\
					        SET producto = '" + producto + "', idMarca = '" + idMarca + "', Descripcion = '" + Descripcion + "', Imagen = '" + Imagen + "', precio_costo = '" + precio_costo + "', precio_ventas = '" + precio_venta + "', existencia = '" + existencia + "', fecha_ingreso = '" + fecha_ingreso + "'\
							WHERE	idProducto ='" + var + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "EL PRODUCTO HA SIDO ACTUALIZADO CORRECTAMENTE" << endl;
				  system("pause");
			  }
			  else {
				  cout << "HA OCURRIDO UN ERROR AL ACTUALIZAR EL PRODUCTO" << endl;
				  system("pause");
			  }
		  }
		  else {
			  cout << "OCURRIO UN ERROR EN LA CONEXION DE LA BASE DE DATOS" << endl;
			  system("pause");
		  }
		  cn.cerrar_conexion();
		  system("pause");
	  }

	  //borrar 
	  void borrar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "DELETE FROM productos WHERE idProducto = '" + var + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "SE HA ELIMIDADO EL PRODUCTO CORRECTAMENTE" << endl;
			  }
			  else {
				  cout << "HA OCURRIDO UN ERROR AL TRATAR DE ELIMINAR EL PRODUCTO" << endl;
			  }
		  }
		  else {
			  cout << "OCURRIO UN ERROR EN LA CONEXION DE LA BASE DE DATOS" << endl;
		  }
		  cn.cerrar_conexion();
	  }
};