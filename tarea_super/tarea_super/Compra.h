#pragma once
#include <iostream>
#include <string>
#include "ConexionDB.h"

using namespace std;


class Compra
{
private: string  no_orden_compra, idproveedor, fecha_orden, fechaingreso, varcom;

public: Compra() {}
	  Compra(string n_ord, string idp, string f_ord, string f_ing, string v)
	  {
		  no_orden_compra = n_ord;
		  idproveedor = idp;
		  fecha_orden = f_ord;
		  fechaingreso = f_ing;
		  varcom = v;
	  }
	  // set 
	  void setNo_orden_compra(string n_ord) { no_orden_compra = n_ord; }
	  void setIdproveedor(string idp) { idproveedor = idp; }
	  void setFecha_orden(string f_ord) { fecha_orden = f_ord; }
	  void setFechaingreso(string f_ing) { fechaingreso = f_ing; }
	  void setvarcom(string v) { varcom = v; }
	  // get
	  string getNo_orden_compra() { return no_orden_compra; }
	  string getIdproveedor() { return idproveedor; }
	  string getFecha_orden() { return fecha_orden; }
	  string getFechaingreso() { return fechaingreso; }
	  string getvarcom() { return varcom; }

	  // metodos

	  //crear compra
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO compras (no_orden_compra, idproveedor, fecha_orden, fechaingreso) VALUES ('" + no_orden_compra + "', '" + idproveedor + "',NOW(),NOW())";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "compra efectuada con exito" << endl;
			  }
			  else {
				  cout << "Error al generar compra" << endl;
			  }
		  }
		  else {
			  cout << "No se pudo conectar a la base de datos" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  //leer compra

	  void leer() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  cout << "****lISTADO****" << endl;
			  string consulta = "SELECT * FROM compras";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << endl;
				  }

			  }
			  else {
				  cout << "Error al leer las compras " << endl;
			  }
		  }
		  else {
			  cout << "No se pudo conectar a la base de datos" << endl;
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
			  string insert = "UPDATE compras\
					        SET no_orden_compra = '" + no_orden_compra + "', idproveedor = '" + idproveedor + "',fechaingreso = '" + fechaingreso + "'\
							WHERE idCompra ='" + varcom + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "compra actualizada con exito" << endl;
				  system("pause");
			  }
			  else {
				  cout << "no saleeeeee" << endl;
			  }
		  }
		  else {
			  cout << "No se pudo conectar a la base de datos" << endl;
			  system("pause");
		  }
		  cn.cerrar_conexion();
		  system("pause");
	  }

	  //borrar compra

	  void borrar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "DELETE FROM compras WHERE idCompra = '" + varcom + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << " compra borrada con exito" << endl;
			  }
			  else {
				  cout << "Error al borrar la compra" << endl;
			  }
		  }
		  else {
			  cout << "No se pudo conectar a la base de datos" << endl;
		  }
		  cn.cerrar_conexion();
	  }


};