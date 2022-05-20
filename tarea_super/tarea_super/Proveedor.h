#pragma once
#include <iostream>
#include <string>
#include "ConexionDB.h"
using namespace std;

class Proveedor
{
	//atributos
private: string proveedor, nit, direccion, telefono, varpro;
	   //constructor
public: Proveedor() {
}
	  Proveedor(string prove, string n, string dir, string tel, string v)
	  {
		  proveedor = prove;
		  nit = n;
		  direccion = dir;
		  telefono = tel;
		  varpro = v;
	  }
	  //metodos set 
	  void setProveedor(string prove) { proveedor = prove; }
	  void setNit(string n) { nit = n; }
	  void setDireccion(string dir) { direccion = dir; }
	  void setTelefono(string tel) { telefono = tel; }
	  void setVar(string v) { varpro = v; }
	  //metodos get
	  string getProveedor() { return proveedor; }
	  string getNit() { return nit; }
	  string getDireccion() { return direccion; }
	  string getTelefono() { return telefono; }
	  string getVar() { return varpro; }


	  //metodos
	//crear
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO proveedores (proveedor, nit, direccion, telefono) VALUES ('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "')";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "Proveedor creado" << endl;
			  }
			  else {
				  cout << "Error al crear proveedor" << endl;
			  }
		  }
		  else {
			  cout << "No se pudo conectar a la base de datos" << endl;
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

			  cout << "****lISTADO****" << endl;

			  string consulta = "SELECT * FROM proveedores";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << endl;
				  }

			  }
			  else {
				  cout << "Error al leer proveedores" << endl;
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
			  string insert = "UPDATE proveedores\
					        SET proveedor = '" + proveedor + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = '" + telefono + "'\
							WHERE	idProveedor ='" + varpro + "';";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "Proveedor actualizado" << endl;
				  system("pause");
			  }
			  else {
				  cout << "Error al actualizar proveedor" << endl;
				  system("pause");
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
			  string insert = "DELETE FROM proveedores WHERE idProveedor = '" + varpro + "';";
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