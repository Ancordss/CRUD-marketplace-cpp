#pragma once
#include <iostream>
#include <string>
#include "ConexionDB.h"
using namespace std;

class Compra_detalle
{
private: string idCompra, idProducto, canitdad, precio_costo_unitario, varDcom;

public: Compra_detalle() {}

	  Compra_detalle(string idCom, string idPro, string cant, string pre_cos_u, string v)
	  {

		  idCompra = idCom;
		  idProducto = idPro;
		  canitdad = cant;
		  precio_costo_unitario = pre_cos_u;
		  varDcom = v;


	  }

	  //set
	  void setIdCompra(string idCom) { idCompra = idCom; }
	  void setIdProducto(string idPro) { idProducto = idPro; }
	  void setCantidad(string cant) { canitdad = cant; }
	  void setPrecio_costo_unitario(string pre_cos_u) { precio_costo_unitario = pre_cos_u; }
	  void setVar(string v) { varDcom = v; }

	  // get

	  string getIdCompra() { return idCompra; }
	  string getIdProducto() { return idProducto; }
	  string getCantidad() { return canitdad; }
	  string getPrecio_costo_unitario() { return precio_costo_unitario; }
	  string getVar() { return varDcom; }




	  //crear compra detalle
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO compras_detalle (idCompra, idProducto, canitdad, precio_costo_unitario) VALUES ('" + idCompra + "', '" + idProducto + "', '" + canitdad + "', '" + precio_costo_unitario + "')";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "detalle de compra creado" << endl;
			  }
			  else {
				  cout << "Error al generar detalle de compra " << endl;
			  }
		  }
		  else {
			  cout << "No se pudo conectar a la base de datos" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  //leer detalle de compra

	  void leer() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  cout << "****lISTADO****" << endl;
			  string consulta = "SELECT * FROM compras_detalle";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << endl;
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
			  string insert = "UPDATE compras_detalle\
					        SET idCompra = '" + idCompra + "', idProducto = '" + idProducto + "', canitdad = '" + canitdad + "', precio_costo_unitario = '" + precio_costo_unitario + "'\
							WHERE idCompras_Detalle ='" + varDcom + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "Detalle de compra actualizada con exito" << endl;
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

	  //borrar 
	  void borrar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "DELETE FROM compras_detalle WHERE idCompras_Detalle = '" + varDcom + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "Proveedor eliminado" << endl;
			  }
			  else {
				  cout << "Error al eliminar proveedor" << endl;
			  }
		  }
		  else {
			  cout << "No se pudo conectar a la base de datos" << endl;
		  }
		  cn.cerrar_conexion();
	  }
};