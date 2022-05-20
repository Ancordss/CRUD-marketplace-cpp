#pragma once
#include <iostream>
#include <string>
#include "ConexionDB.h"

class Ventas
{
private: string nofactura,serie,fechafactura,idcliente,idempleado,fecha_ingreso,var;

public:
    Ventas() {

    }
    Ventas(string noF, string sr, string fechaF, string idcl, string idemp, string fechaI, string v)  {
        nofactura = noF;
        serie = sr;
        fechafactura = fechaF;
        idcliente = idcl;
        idempleado = idemp;
        fecha_ingreso = fechaI;
        var = v;

    }

    //metodo get and set
//set

    void setNom(string noF) { nofactura = noF; }
    void setApe(string sr) { serie = sr; }
    void setTel(string fechaF) { fechafactura = fechaF; }
    void setDir(string idcl) { idcliente = idcl; }
    void setGen(string idemp) { idempleado = idemp; }
    void setEmail(string fechaI) { fecha_ingreso = fechaI; }
    void setNit(string v) { var = v; }


    string getNom() { return nofactura; }
    string getApe() { return serie; }
    string getTel() { return fechafactura; }
    string getDir() { return idcliente; }
    string getGen() { return idempleado; }
    string getEmail() { return fecha_ingreso; }
    string getNit() { return var; }


    /*incio funciones del programa*/



    void leer() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "------------ Datos de los estudiantes ------------" << endl;
            string consulta = "select * from ventas";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
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

    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            // string insert = "INSERT INTO estudiantes(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento)VALUES('" + carnet + "','" + nombres + "','" + apellido + "','" + direccion + "','" + telefono + "','" + genero + "','" + email + "','" + fecha_nacimiento + "'); ";
            string insert = "INSERT INTO ventas(nofactura,serie,fechafactura,idcliente,idempleado,fechaingreso)VALUES('" + nofactura + "','" + serie + "','" + fechafactura + "','" + idcliente + "','" + idempleado + "','" + fecha_ingreso + "'); ";
            // string insert = "INSERT INTO productos(producto,idMarca,Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso)VALUES('" + nombres + "','" + idMarca + "','" + descripcion + "','" + precio_costo + "','" + precio_venta + "','" + existencia + "','" + fecha_ingreso + "'); ";
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

    void borrar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            // string t = to_string(telefono); //convierte int a string para mandar a mysql
            string insert = "DELETE FROM ventas WHERE idVentas='" + var + "';";
            // string insert = "INSERT INTO productos(producto,idMarca,Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso)VALUES('" + nombres + "','" + idMarca + "','" + descripcion + "','" + precio_costo + "','" + precio_venta + "','" + existencia + "','" + fecha_ingreso + "'); ";
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

    void actualizar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            // string t = to_string(telefono); //convierte int a string para mandar a mysql
            string insert = "UPDATE ventas\
                             SET nofactura='" + nofactura + "',serie='" + serie + "',fechafactura= '" + fechafactura + "', idcliente='" + idcliente + "', idempleado= '" + idempleado + "', fechaingreso= '" + fecha_ingreso + "'\
                             WHERE idVentas='" + var + "';";
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "ingreso exitoso" << endl;
                system("pause");
            }
            else {
                cout << "error al insertar" << endl;
                system("pause");
            }

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();
        system("pause");

    }

};






