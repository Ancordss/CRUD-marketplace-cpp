#pragma once
#include <iostream>
using namespace std;
class Persona
{
    //atributos
protected: string nombres, apellidos, nit, direccion, genero, telefono, correo_electronico;


protected:
    Persona() {

    }
    //constructor
    Persona(string nom, string ape, string nt, string gen, string dir, string tel, string ce) {
        nombres = nom;
        apellidos = ape;
        nit = nt;
        genero = gen;
        direccion = dir;
        telefono = tel;
        correo_electronico = ce;
  

    }
};

