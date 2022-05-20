/*Este archivo contiene la tabla clientes ventas y ventas detalle heredando de la clase persona caracteristicas del comprador este caso nuestro clientes.*/

#pragma once
#include "Persona.h"
#include <iostream>
#include <string>
#include "ConexionDB.h"

class Clientes :
    public Persona
{
private: string fecha_ingreso, var;

public:
    Clientes() {

    }
    Clientes(string nom, string ape, string nt, string gen, string dir, string tel, string ce, string fi,string v) : Persona(nom,ape,nt,gen,dir,tel,ce) {
        fecha_ingreso = fi;
        var = v;
       
    }

    //metodo get and set
//set

    void setNom(string nom) { nombres = nom; }
    void setApe(string ape) { apellidos = ape; }
    void setTel(string tel) { telefono = tel; }
    void setDir(string dir) { direccion = dir; }
    void setGen(string gen) { genero = gen; }
    void setEmail(string ce) { correo_electronico = ce; }
    void setNit(string nt) { nit = nt; }
    void setFIngres(string fi) { fecha_ingreso = fi; }

    string getNom() { return nombres; }
    string getApe() { return apellidos; }
    string getTel() { return telefono; }
    string getDir() { return direccion; }
    string getGen() { return genero; }
    string getEmail() { return correo_electronico; }
    string getNit() { return nit; }
    string getFIngres() { return fecha_ingreso; }


    /*incio funciones del programa*/



    void leer() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "------------ Datos de los estudiantes ------------" << endl;
            string consulta = "select * from clientes";
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
            string insert = "INSERT INTO clientes(nombres,apellidos,NIT,genero,telefono,correo_electronico,fechaingreso)VALUES('" + nombres + "','" + apellidos + "','" + nit + "','" + genero + "','" + telefono + "','" + correo_electronico + "','" + fecha_ingreso + "'); ";
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
            string insert = "DELETE FROM clientes WHERE idClientes='" + var + "';";
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
            string insert = "UPDATE clientes\
                             SET nombres='" + nombres + "',apellidos='" + apellidos + "', NIT= '" + nit + "', genero='" + genero + "', telefono = '" + telefono + "', correo_electronico = '" + correo_electronico + "'\
                             WHERE idClientes='" + var + "';";
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

class Nit {
private:
    string nt;
    char largo, guion, ceroinicial, digito;

public:
    Nit(string nt)
    {
        this->nt = nt;
        this->largo = nt.length();
        this->digito = nt[9];
        this->guion = nt[8];
        this->ceroinicial = nt[0];
    }

    void verificanit() {
        int suma = 0, resto;
        char resultado, dcorrecto;

        // Validaciones: largo de 10 caracteres, ausencia de 0 inicial y existencia del guión
        if (largo == 9 && ceroinicial != '0' && guion == '-')
        {
            suma = ((nt[7] - '0') * 2) + //Se llama a la posición y al restarle '0' se pasa a int
                ((nt[6] - '0') * 3) +
                ((nt[5] - '0') * 4) +
                ((nt[4] - '0') * 5) +
                ((nt[3] - '0') * 6) +
                ((nt[2] - '0') * 7) +
                ((nt[1] - '0') * 2) +
                ((nt[0] - '0') * 3);

            resto = suma % 11;
            resultado = 11 - resto;

        }
       /* else {
            cout << "\nError en el formato del nit: debe tener 8 dígitos, no comenzar en 0, tener guion y dígito verificador"
                << endl;
        }*/

        if (resultado == 10) {
            dcorrecto = 'K';
        }
        else if (resultado == 11) {
            dcorrecto = '0';
        }
        else {
            dcorrecto = resultado;

        }

        if (dcorrecto == (digito - '0')) {
            cout << "\nEl nit está correcto!" << endl;
        }
        else {
            cout << "\nnit está incorrecto! " << endl;
        }
    }
};

/*******************************************************************************************************************************************/
class Empleados :
    public Persona
{
private: string fecha_inicio_l, fecha_ingreso,fecha_nacimiento, DPI, idPuesto, var, puesto;

public:

    Empleados() {

    }
  
        Empleados(string nom, string ape, string nt, string gen , string dir, string tel, string ce, string dpi, string ge, string fn, string idpuesto, string fi, string fin, string v) : Persona(nom, ape, nt, gen, dir, tel, ce) {

        fecha_inicio_l = fi;
        fecha_ingreso = fin;
        DPI = dpi;
        idPuesto = idpuesto;
        var = v;

    }

   
//set

    void setNom(string nom) { nombres = nom; }
    void setApe(string ape) { apellidos = ape; }
    void setDir(string dir) { direccion = dir; }
    void setTel(string tel) { telefono = tel; }
    void setDpi(string dpi) { DPI = dpi; }
    void setGen(string ge) {  genero = ge; }
    void setEmail(string fn) { fecha_nacimiento = fn; }
    void setNit(string idpuesto) { idPuesto = idpuesto; }
    void setFInicio(string fi) { fecha_inicio_l = fi; }
    void setFIngreso(string fin) { fecha_ingreso = fin; }

//get
    string getNom() { return nombres; }
    string getApe() { return apellidos; }
    string getDir() { return direccion; }
    string getTel() { return telefono; }
    string getDpi() { return DPI; }
    string getGen() { return genero; }
    string getEmail() { return fecha_nacimiento; }
    string getNit() { return idPuesto; }
    string getFInicio() { return fecha_inicio_l; }
    string getFIngreso() { return fecha_ingreso; }
    

    
   void leer() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "------------ DATOS DE LOS EMPLEADOS ------------" << endl;
            string consulta = "select * from empleados";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] <<  "," << fila[9] << "," << fila[10] <<endl;
                }

            }
            else {
                cout << " ----- Error  -----" << endl;
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
        if (cn.getConectar()) {    //error en insert fecha_nacimiento arreglar.
           string insert = "INSERT INTO empleados(nombres,apellidos,direccion,telefono,DPI,genero,fecha_nacimiento,idPuesto,fecha_inicio_labores,fechaingreso)VALUES('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" +  DPI + "','" + genero + "','" + fecha_nacimiento + "','" + idPuesto + "','" + fecha_inicio_l + "','" + fecha_ingreso+ "'); ";
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
            cout << "Error al crear" << endl;
            system("pause");
        }
        cn.cerrar_conexion();
    }
    


    void borrar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
             string insert = "DELETE FROM empleados WHERE idempleado='" + var + "';";
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "ingreso exitoso" << endl;
            }
            else {
                cout << "error al eliminar datos" << endl;
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
        string insert = "UPDATE empleados\
                             SET nombres='" + nombres + "',apellidos='"+ apellidos + "',direccion='" + direccion + "',telefono='" + telefono + "',DPI='" +  DPI + "',genero='" + genero + "',fecha_nacimiento='" + fecha_nacimiento + "',idPuesto='" + idPuesto + "',fecha_inicio_labores='" + fecha_inicio_l + "',fecha_ingreso='" + fecha_ingreso+ "'\
                             WHERE idempleado='" + var + "';";
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
            cout << "--------Error--------" << endl;
            system("pause");
        }
        cn.cerrar_conexion();
        system("pause");

    }


       void leerPuesto() {
           int q_estado;
           ConexionBD cn = ConexionBD();
           MYSQL_ROW fila;
           MYSQL_RES* resultado;
           cn.abrir_conexion();
           if (cn.getConectar()) {
               cout << "------------ DATOS DE LOS EMPLEADOS ------------" << endl;
               string consulta = "select * from puestos";
               const char* c = consulta.c_str();
               q_estado = mysql_query(cn.getConectar(), c);
               if (!q_estado) {
                   resultado = mysql_store_result(cn.getConectar());
                   while (fila = mysql_fetch_row(resultado)) {
                       cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[9] << "," << fila[10] << endl;
                   }

               }
               else {
                   cout << " ----- Error  -----" << endl;
               }

           }
           else {
               cout << "Error al leer" << endl;
               system("pause");
           }
           cn.cerrar_conexion();
       }


       void crearpuesto() {
           int q_estado;
           ConexionBD cn = ConexionBD();
           cn.abrir_conexion();
           if (cn.getConectar()) {    //error en insert fecha_nacimiento arreglar.
               string insert = "INSERT INTO puestos(puesto)VALUES('" + nombres + "'); ";
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
               cout << "Error al crear" << endl;
               system("pause");
           }
           cn.cerrar_conexion();
       }

       void borrarPuesto() {
           int q_estado;
           ConexionBD cn = ConexionBD();
           cn.abrir_conexion();
           if (cn.getConectar()) {
               string insert = "DELETE FROM puestos WHERE idpuesto='" + var + "';";
               const char* i = insert.c_str();
               q_estado = mysql_query(cn.getConectar(), i);
               if (!q_estado) {
                   cout << "ingreso exitoso" << endl;
               }
               else {
                   cout << "error al eliminar datos" << endl;
               }

           }
           else {
               cout << "Error al leer" << endl;
               system("pause");
           }
           cn.cerrar_conexion();
       }

       void actualizarpuesto() {
           int q_estado;
           ConexionBD cn = ConexionBD();
           cn.abrir_conexion();
           if (cn.getConectar()) {
               string insert = "UPDATE puestos\
                             SET puesto='" + nombres + "'\
                             WHERE idpuesto='" + var + "';";
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
               cout << "--------Error--------" << endl;
               system("pause");
           }
           cn.cerrar_conexion();
           system("pause");

       }



};