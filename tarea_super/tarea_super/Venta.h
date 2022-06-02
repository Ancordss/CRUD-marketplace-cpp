#pragma once
#include <iostream>
#include <string>
#include "ConexionDB.h"
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include "Cliente.h"    



class Venta
{
private: string nofactura,serie,fechafactura,idcliente,idempleado,fecha_ingreso,var;

public:
    Venta() {

    }
    Venta(string noF, string sr, string fechaF, string idcl, string idemp, string fechaI, string v)  {
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
            //string insert = "INSERT INTO ventas(nofactura,serie,fechafactura,idcliente,idempleado,fechaingreso)VALUES('" + nofactura + "','" + serie + "','" + fechafactura + "', '" + idcliente + "', '" + idempleado + "','" + fecha_ingreso + "'); ";
            //string insert = "INSERT INTO ventas(nofactura,serie,fechafactura,idempleado,fechaingreso)VALUES('" + nofactura + "','" + serie + "',NOW(), '" + idempleado + "',NOW()); ";
            string insert = "INSERT INTO ventas(nofactura,serie,fechafactura,idcliente,idempleado,fechaingreso)VALUES('" + nofactura + "', '" + serie + "', NOW(), (select idClientes from clientes where clientes.NIT = '" + idcliente + "'), '" + idempleado + "', NOW()); ";
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
               // cout << "ingreso exitoso" << endl;
                //system("pause");
            }
            else {
                cout << "usuario no registrado..." << endl;
                system("pause");
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
                             SET nofactura='" + nofactura + "',serie='" + serie + "',fechafactura= '" + fechafactura + "', idcliente='" + idcliente + "', idempleado= '" + idempleado + "'\
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


    void leeru() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "------------ id de la venta ------------" << endl;
            string consulta = "select idVentas from ventas\
                               WHERE nofactura = '" + nofactura + "';";
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

    void leerCV() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << endl;

            string consulta = "select nombres, apellidos\
                               from clientes where NIT = '" + idcliente + "';";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout<< " cliente: " << fila[0] << " " << fila[1]  << endl;
                }

            }
            else {
                cout << " xxx Error al Consultar  xxx" << endl;
            }

            consulta = "select NIT\
                               from clientes where NIT = '" + idcliente + "';";
            c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << " NIT: " << fila[0] << endl;
                }

            }
            else {
                cout << " xxx Error al Consultar  xxx" << endl;
            }

            consulta = "select telefono\
                        from clientes where NIT = '" + idcliente + "';";
            c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << " Telefono: " << fila[0] << endl;
                }

            }
            else {
                cout << " xxx Error al Consultar  xxx" << endl;
            }
            cout << "+---------------------------------------------------------------------------------------+" << endl;

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();
    }

};

class venta_detalle
{
private: string cantidad, precio_unitario, idVenta, idProducto, var;

public: venta_detalle() {

}
      venta_detalle(string cant, string pre_uni, string idV, string idP,string v) {
         
          cantidad = cant;
          precio_unitario = pre_uni;
          idVenta = idV;
          idProducto = idP;
          var = v;
      }

      void setCant(string cant) { cantidad = cant; }
      void setPre_uni(string pre_uni) { precio_unitario = pre_uni; }
      void setidV(string idV) { idVenta = idV; }
      void setidP(string idP) { idProducto = idP; }
      void setVar(string v) { var = v; }


      string getCant() { return cantidad; }
      string getPre_uni() { return precio_unitario; }
      string getidV() { return idVenta; }
      string getidP(){ return idProducto; }
      string getVar() { return var; }


      void leer() {
          int q_estado;
          ConexionBD cn = ConexionBD();
          MYSQL_ROW fila;
          MYSQL_RES* resultado;
          cn.abrir_conexion();
          if (cn.getConectar()) {
              system("cls");
              cout << "-----------------Factura generada-----------------" << endl;
              cout << "--------------------------------------------------" << endl;
              cout << "--------------------------------------------------" << endl;
              string consulta = "SELECT ventas.serie from ventas\
                                 inner join clientes on ventas.idcliente = clientes.idClientes\
                                 where clientes.NIT = '" + idVenta + "'\
                                 order by ventas.serie DESC limit 1; ";
              const char* c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout <<" serie: "<< fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al resolver el no de serie   xxx" << endl;
              }

              //no factura manda a mostrar 
              consulta = "SELECT ventas.nofactura from ventas\
                                 inner join clientes on ventas.idcliente = clientes.idClientes\
                                 where clientes.NIT = '" + idVenta + "'\
                                 order by ventas.serie DESC limit 1; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout <<" No de Factura: "<< fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al resover el numero de factura  xxx" << endl;
              }

              //muestra fecha 
              consulta = "SELECT ventas.fechaingreso from ventas\
                                 inner join clientes on ventas.idcliente = clientes.idClientes\
                                 where clientes.NIT = '" + idVenta + "'\
                                 order by ventas.serie DESC limit 1; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " Fecha/hora: " << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al mostrar la fecha  xxx" << endl;
              }

              //muestra cliente
              consulta = "select nombres,apellidos from clientes where NIT = '" + idVenta + "'; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " Cliente: " << fila[0] << " " << fila[1] << endl;
                  }

              }
              else {
                  cout << " xxx Error al obtener nombre de cliente  xxx" << endl;
              }

              //muestra nit
              consulta = "select clientes.NIT from clientes where NIT = '" + idVenta + "'; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " NIT: " << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al obtener el nit xxx" << endl;
              }
              cout << "--------------------------------------------------" << endl;
              cout << '\n';
              cout << "|        codigo        | cant | precio_U | |Total|" << endl;
              cout << '\n';
              //muestra compras
              consulta = "SELECT productos.producto, marcas.marca, ventas_detalle.cantidad, ventas_detalle.precio_unitario, cantidad * precio_unitario AS total\
                  from ventas\
                  inner join clientes on clientes.idClientes = ventas.idcliente\
                  inner join ventas_detalle on ventas_detalle.idVentas = ventas.idVentas\
                  inner join productos on productos.idProducto = ventas_detalle.idproducto\
                  inner join marcas on marcas.idMarca = productos.idMarca\
                  where ventas_detalle.idVentas =(SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente=clientes.idClientes where clientes.NIT='" + idVenta + "' order by idVentas DESC limit 1); ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout <<" " << fila[0] << " " << fila[1] << "       -  " << fila[2] << "     -  " << fila[3]<< " - " << fila[4] << endl;
                  }
              }
              else {
                  cout << " xxx Error al obtener las compras xxx" << endl;
              }

              //muestra total a pagar
              consulta = "SELECT sum(cantidad * precio_unitario) AS total_pagar\
                          from ventas_detalle\
                          inner join productos\
                          on ventas_detalle.idproducto = productos.idProducto\
                          where ventas_detalle.idVentas = (SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente = clientes.idClientes where clientes.NIT ='" + idVenta + "' order by idVentas DESC limit 1) and productos.existencia > 0; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << "------------------------------ total a pagar: "<< "Q" << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al obtener el nit xxx" << endl;
              }


              //muestra atendido por 
              cout << '\n';
              consulta = "SELECT empleados.nombres, empleados.apellidos\
                          from empleados\
                          inner join ventas\
                          on ventas.idempleado = empleados.idempleado\
                          where ventas.idVentas = (SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente = clientes.idClientes where clientes.NIT ='" + idVenta + "' order by idVentas DESC limit 1); ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << "atendido por: " << fila[0]<< " " << fila[1] << endl;
                      cout << '\n';
                  }

              }
              else {
                  cout << " xxx Error al obtener el nit xxx" << endl;
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
              string insert = "INSERT INTO ventas_detalle(idVentas,idProducto,cantidad,Precio_Unitario)VALUES((SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente=clientes.idClientes where clientes.NIT='" + idVenta + "' order by idVentas DESC limit 1),'"+ idProducto+ "','" + cantidad + "','" + precio_unitario + "'); ";
              // string insert = "INSERT INTO productos(producto,idMarca,Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso)VALUES('" + nombres + "','" + idMarca + "','" + descripcion + "','" + precio_costo + "','" + precio_venta + "','" + existencia + "','" + fecha_ingreso + "'); ";
              const char* i = insert.c_str();
              q_estado = mysql_query(cn.getConectar(), i);
              if (!q_estado) {
                  cout << "     ok!" << endl;
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
              string insert = "UPDATE ventas_detalle\
                             SET idVentas='" + idVenta + "',idProducto='" + idProducto + "',cantidad= '" + cantidad + "', precio_unitario='" + precio_unitario + "'\
                             WHERE idVentas_detalle='" + var + "';";
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

      void borrar() {
          int q_estado;
          ConexionBD cn = ConexionBD();
          cn.abrir_conexion();
          if (cn.getConectar()) {
              // string t = to_string(telefono); //convierte int a string para mandar a mysql
              string insert = "DELETE FROM ventas_detalle WHERE idVentas_detalle='" + var + "';";
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
      
      void leerI() {
          int q_estado;
          ConexionBD cn = ConexionBD();
          MYSQL_ROW fila;
          MYSQL_RES* resultado;
          cn.abrir_conexion();
          if (cn.getConectar()) {
              freopen("texto.txt", "w", stdout);
              cout << "-----------------Factura generada-----------------" << endl;
              cout << "--------------------------------------------------" << endl;
              cout << "--------------------------------------------------" << endl;
              string consulta = "SELECT ventas.serie from ventas\
                                 inner join clientes on ventas.idcliente = clientes.idClientes\
                                 where clientes.NIT = '" + idVenta + "'\
                                 order by ventas.serie DESC limit 1; ";
              const char* c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " serie: " << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al resolver el no de serie   xxx" << endl;
              }

              //no factura manda a mostrar 
              consulta = "SELECT ventas.nofactura from ventas\
                                 inner join clientes on ventas.idcliente = clientes.idClientes\
                                 where clientes.NIT = '" + idVenta + "'\
                                 order by ventas.serie DESC limit 1; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " No de Factura: " << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al resover el numero de factura  xxx" << endl;
              }

              //muestra fecha 
              consulta = "SELECT ventas.fechaingreso from ventas\
                                 inner join clientes on ventas.idcliente = clientes.idClientes\
                                 where clientes.NIT = '" + idVenta + "'\
                                 order by ventas.serie DESC limit 1; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " Fecha/hora: " << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al mostrar la fecha  xxx" << endl;
              }

              //muestra cliente
              consulta = "select nombres,apellidos from clientes where NIT = '" + idVenta + "'; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " Cliente: " << fila[0] << " " << fila[1] << endl;
                  }

              }
              else {
                  cout << " xxx Error al obtener nombre de cliente  xxx" << endl;
              }

              //muestra nit
              consulta = "select clientes.NIT from clientes where NIT = '" + idVenta + "'; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " NIT: " << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al obtener el nit xxx" << endl;
              }
              cout << "--------------------------------------------------" << endl;
              cout << '\n';
              cout << "|       codigo        | cant | precio_U | |Total|" << endl;
              cout << '\n';
              //muestra compras
              consulta = "SELECT productos.producto, marcas.marca, ventas_detalle.cantidad, ventas_detalle.precio_unitario, cantidad * precio_unitario AS total\
                  from ventas\
                  inner join clientes on clientes.idClientes = ventas.idcliente\
                  inner join ventas_detalle on ventas_detalle.idVentas = ventas.idVentas\
                  inner join productos on productos.idProducto = ventas_detalle.idproducto\
                  inner join marcas on marcas.idMarca = productos.idMarca\
                  where ventas_detalle.idVentas =(SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente=clientes.idClientes where clientes.NIT='" + idVenta + "' order by idVentas DESC limit 1); ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " " << fila[0] << " " << fila[1] << "       -  " << fila[2] << "     -  " << fila[3] << " - " << fila[4] << endl;
                  }
              }
              else {
                  cout << " xxx Error al obtener las compras xxx" << endl;
              }

              //muestra total a pagar
              consulta = "SELECT sum(cantidad * precio_unitario) AS total_pagar\
                          from ventas_detalle\
                          inner join productos\
                          on ventas_detalle.idproducto = productos.idProducto\
                          where ventas_detalle.idVentas = (SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente = clientes.idClientes where clientes.NIT ='" + idVenta + "' order by idVentas DESC limit 1) and productos.existencia > 0; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << "------------------------------ total a pagar: " << "Q" << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al obtener el nit xxx" << endl;
              }


              //muestra atendido por 
              cout << '\n';
              consulta = "SELECT empleados.nombres, empleados.apellidos\
                          from empleados\
                          inner join ventas\
                          on ventas.idempleado = empleados.idempleado\
                          where ventas.idVentas = (SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente = clientes.idClientes where clientes.NIT ='" + idVenta + "' order by idVentas DESC limit 1); ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << "atendido por: " << fila[0] << " " << fila[1] << endl;
                      cout << '\n';
                  }

              }
              else {
                  cout << " xxx Error al obtener el nit xxx" << endl;
              }
          }
          else {
              cout << "Error al leer" << endl;
              system("pause");
          }
          cn.cerrar_conexion();
      }

      void leerVD() {
          int q_estado;
          ConexionBD cn = ConexionBD();
          MYSQL_ROW fila;
          MYSQL_RES* resultado;
          cn.abrir_conexion();
          if (cn.getConectar()) {
              cout << '\n';
              cout << " nombre  marca    cantidad   precio_U  | Total |" << endl;
              cout << '\n';
              string consulta = "SELECT productos.producto, marcas.marca, ventas_detalle.cantidad, ventas_detalle.precio_unitario, cantidad* precio_unitario AS total\
                  from ventas\
                  inner join clientes on clientes.idClientes = ventas.idcliente\
                  inner join ventas_detalle on ventas_detalle.idVentas = ventas.idVentas\
                  inner join productos on productos.idProducto = ventas_detalle.idproducto\
                  inner join marcas on marcas.idMarca = productos.idMarca\
              where ventas_detalle.idVentas = (SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente = clientes.idClientes where clientes.NIT = '" + idVenta + "' order by idVentas DESC limit 1); ";
              const char* c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << " " << fila[0] << " " << fila[1] << "        " << fila[2] << "       " << fila[3] << "   " << fila[4] << endl;
                  }

              }
              else {
                  cout << " xxx Error al Consultar  xxx" << endl;
              }

              consulta = "SELECT sum(cantidad * precio_unitario) AS total_pagar\
                          from ventas_detalle\
                          inner join productos\
                          on ventas_detalle.idproducto = productos.idProducto\
                          where ventas_detalle.idVentas = (SELECT ventas.idVentas FROM ventas  INNER JOIN clientes ON  ventas.idcliente = clientes.idClientes where clientes.NIT ='" + idVenta + "' order by idVentas DESC limit 1) and productos.existencia > 0; ";
              c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << '\n';
                      cout << "------------------------------ total a pagar: " << "Q" << fila[0] << endl;
                  }

              }
              else {
                  cout << " xxx Error al obtener el nit xxx" << endl;
              }


          }
          else {
              cout << "Error al leer" << endl;
              system("pause");
          }
          cn.cerrar_conexion();
      }

};



