#pragma once
#include <iostream>
#include <string>
#include "ConexionDB.h"
using namespace std;

class marcas
{
	//atributos
private: string marca, var;
	   //constructor
public: marcas() {
}
	  marcas(string mar, string v)
	  {
		  marca = mar;
		  var = v;
	  }
	  //metodos set 
	  void setmarca(string mar) { marca = mar; }
	  void setVar(string v) { var = v; }
	  //metodos get
	  string getmarca() { return marca; }
	  string getVar() { return var; }


	  //metodos
	//crear
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO marcas (marca ) VALUES ('" + marca + "')";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "SE HA CREADO LA MARCA CORRECTAMENTE" << endl;
			  }
			  else {
				  cout << "OCURRIO UN ERROR AL CREAR LA MARCA " << endl;
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
			  cout << "*LISTA DE LAS MARCAS INGRESADAS*" << endl;
			  string consulta = "SELECT * FROM marcas";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << " , " << fila[1] << endl;
				  }

			  }
			  else {
				  cout << "OCURRIO UN ERROR AL INTENTAR LEER LAS MARCAS INGRESADAS" << endl;
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
			  string insert = "UPDATE marcas\
					        SET marca = '" + marca + "'\
							WHERE	idProducto ='" + var + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "LA MARCA HA SIDO ACTUALIZADA CORRECTAMENTE" << endl;
				  system("pause");
			  }
			  else {
				  cout << "HA OCURRIDO UN ERROR AL ACTUALIZAR LA MARCA" << endl;
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
			  string insert = "DELETE FROM marcas WHERE idMarca = '" + var + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "SE HA ELIMIDADO LA MARCA CORRECTAMENTE" << endl;
			  }
			  else {
				  cout << "HA OCURRIDO UN ERROR AL TRATAR DE ELIMINAR LA MARCA" << endl;
			  }
		  }
		  else {
			  cout << "OCURRIO UN ERROR EN LA CONEXION DE LA BASE DE DATOS" << endl;
		  }
		  cn.cerrar_conexion();
	  }
};