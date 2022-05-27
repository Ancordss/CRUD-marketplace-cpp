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
				  cout << "compra en proceso insertada" << endl;
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
			  cout << "------------ Datos de la compra ------------" << endl;
			cout  <<"|idcompra||no de compra||idproveedor||     fecha de Orden     ||           fecha Ingreso          |" << endl;
			  string consulta = "select * from compras";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout<< "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					  cout << "     " << fila[0] << "         " << fila[1] << "            " << fila[2] << "              " << fila[3] << "                 " << fila[4]  << endl;
					  cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;

				  }

			  }
			  else {
				  cout << " xxx Error al Consultar  xxx" << endl;
			  }

		  }
		  else {
			  cout << "Error al leer" << endl;
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

	  void leeru() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  cout << "------------ id de la venta ------------" << endl;
			  string consulta = "select idCompra from ventas\
                                WHERE  no_orden_compra = '" + no_orden_compra + "';";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << endl;
				  }

			  }
			  else {
				  cout << " xxx Error al Consultar  xxx" << endl;
			  }

		  }
		  else {
			  cout << "Error al leer" << endl;
			  system("pause");
		  }
		  cn.cerrar_conexion();
	  }


};




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

	  void leer() {

		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  system("cls");
			  cout << "***************************COMPROBANTE GENERADO**************************" << endl;
			  cout << "*************************************************************************" << endl;
			  cout << "*************************************************************************" << endl;
			  string consulta = "SELECT compras.no_orden_compra from compras where idCompra = '" + idCompra + "'; ";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "No. de orden de compra: " << fila[0] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta: " << endl;
			  }

			  // mostrar proveedor
			  consulta = "SELECT proveedores.proveedor, proveedores.telefono\
				        FROM proveedores\
                        INNER JOIN compras\
						ON compras.idProveedor = proveedores.idProveedor\
				        WHERE compras.idCompra = '" + idCompra + "'; ";

			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Proveedor: " << fila[0] << " " << fila[1] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta: " << endl;
			  }

			  // mostrar fecha 

			  consulta = "SELECT compras.fecha_orden from compras where idCompra = '" + idCompra + "'; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Fecha de orden de compra: " << fila[0] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta: " << endl;
			  }

			  // fecha del ingrreso 

			  consulta = "SELECT compras.fechaingreso from compras where idCompra = '" + idCompra + "'; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Fecha de ingreso: " << fila[0] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta o no : " << endl;
			  }



			  // mostrar nit 

			  consulta = "SELECT proveedores.nit\
						from proveedores\
				        INNER JOIN compras\
						ON compras.idProveedor = proveedores.idProveedor\
				        WHERE compras.idCompra = '" + idCompra + "'; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Nit: " << fila[0] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta: " << endl;
			  }
			
			  cout << "*************************************************************************" << endl;
			  cout << '\n';
			  cout << "|   producto Adquirido   | Cantidad | Precio costo unitario | Total | " << endl;

			  //mostrar adquisicion

			  consulta = "SELECT productos.producto, compras_detalle.canitdad, compras_detalle.precio_costo_unitario, canitdad * precio_costo_unitario AS total\
						from compras_detalle\
                        INNER JOIN productos\
                        ON compras_detalle.idProducto = productos.idProducto\
                        WHERE compras_detalle.idCompra = '" + idCompra + "' and productos.existencia>0; "; 
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "      " << fila[0] << "               - " << fila [1] << "         - " << fila[2] << "              - " << fila[3] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta xxxxxxxx " << endl;
			  }

			  // mostrar total

			  consulta = "SELECT SUM(canitdad * precio_costo_unitario) AS total_pagar\
						from compras_detalle\
						INNER JOIN productos\
						ON compras_detalle.idProducto = productos.idProducto\
						WHERE compras_detalle.idCompra = '" + idCompra + "' and compras_detalle.idProducto > 0; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << " * ***********************************************total a pagar : " << "Q." << fila[0] << endl;

				  }
			  }
			  else {
				  cout << "Error en la consultaaaaaaaaaaaaa: " << endl;
			  }


		  }
	  }

	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO compras_detalle (idCompra, idProducto, canitdad, precio_costo_unitario) VALUES ('" + idCompra + "','" + idProducto + "','" + canitdad + "','" + precio_costo_unitario + "');";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "ingreso exitoso" << endl;
			  }
			  else {
				  cout << "error al insertar" << endl;
			  }

		  }
		  else {
			  cout << "Error al leer" << endl;
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
			  system("pause");
		  }
		  cn.cerrar_conexion();
	  }

	  void leer2() {

		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  freopen("texto.txt", "w", stdout);

			  system("cls");
			  cout << "***************************COMPROBANTE GENERADO**************************" << endl;
			  cout << "*************************************************************************" << endl;
			  cout << "*************************************************************************" << endl;
			  string consulta = "SELECT compras.no_orden_compra from compras where idCompra = '" + idCompra + "'; ";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "No. de orden de compra: " << fila[0] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta: " << endl;
			  }

			  // mostrar proveedor
			  consulta = "SELECT proveedores.proveedor, proveedores.telefono\
				        FROM proveedores\
                        INNER JOIN compras\
						ON compras.idProveedor = proveedores.idProveedor\
				        WHERE compras.idCompra = '" + idCompra + "'; ";

			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Proveedor: " << fila[0] << " " << fila[1] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta: " << endl;
			  }

			  // mostrar fecha 

			  consulta = "SELECT compras.fecha_orden from compras where idCompra = '" + idCompra + "'; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Fecha de orden de compra: " << fila[0] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta: " << endl;
			  }

			  // fecha del ingrreso 

			  consulta = "SELECT compras.fechaingreso from compras where idCompra = '" + idCompra + "'; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Fecha de ingreso: " << fila[0] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta o no : " << endl;
			  }



			  // mostrar nit 

			  consulta = "SELECT proveedores.nit\
						from proveedores\
				        INNER JOIN compras\
						ON compras.idProveedor = proveedores.idProveedor\
				        WHERE compras.idCompra = '" + idCompra + "'; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Nit: " << fila[0] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta: " << endl;
			  }

			  cout << "*************************************************************************" << endl;
			  cout << '\n';
			  cout << "|   producto Adquirido   | Cantidad | Precio costo unitario | Total | " << endl;

			  //mostrar adquisicion

			  consulta = "SELECT productos.producto, compras_detalle.canitdad, compras_detalle.precio_costo_unitario, canitdad * precio_costo_unitario AS total\
						from compras_detalle\
                        INNER JOIN productos\
                        ON compras_detalle.idProducto = productos.idProducto\
                        WHERE compras_detalle.idCompra = '" + idCompra + "' and productos.existencia>0; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "      " << fila[0] << "               - " << fila[1] << "         - " << fila[2] << "              - " << fila[3] << endl;
				  }
			  }
			  else {
				  cout << "Error en la consulta xxxxxxxx " << endl;
			  }

			  // mostrar total

			  consulta = "SELECT SUM(canitdad * precio_costo_unitario) AS total_pagar\
						from compras_detalle\
						INNER JOIN productos\
						ON compras_detalle.idProducto = productos.idProducto\
						WHERE compras_detalle.idCompra = '" + idCompra + "' and compras_detalle.idProducto > 0; ";
			  c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << " * ***********************************************total a pagar : " << "Q." << fila[0] << endl;

				  }
			  }
			  else {
				  cout << "Error en la consultaaaaaaaaaaaaa: " << endl;
			  }


		  }
	  }


};