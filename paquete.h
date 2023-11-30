/*
 * Proyecto OO
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 29/11/2023
 */
 
/*
 * Clase Paquete, dividido en Fragil y No Fragil
 * Padre de herencia
 *
 */


#ifndef PAQUETE_H
#define PAQUETE_H

#include <bits/stdc++.h>
using namespace std;

//Inicia clase de Paquete
class paquete{
	private:
	
	//Atributos
	float peso;
	string categoria;
	int cant_art; // cantidad de articulos en la caja

	public: 
	
	//Constructores
	paquete(){};
	paquete(float weight, string cat, int cant): peso(weight), categoria(cat), cant_art(cant){};
	
	//GETTERS
	float get_peso();
	string get_cate();
	int get_cant();
	
	//SETTERS
	void set_peso(float);
	void set_cate(string);
	void set_cant(int);
	
	//METODO
	string tipoEnvio();
};

/**
 * Utiliza el valor de peso y en una condicional revisa si peso es 
 * mayor a 50kg y dependiendo de eso es el string que regresa;
 *
 * @param
 * @return string
*/
string paquete::tipoEnvio() {
	if(peso>50) {
		return "El envio tardara mas de dos semanas por el peso";
	} else {
		return "Envio Estandar";
	}
}

//GETTERS

/**
 * getter peso
 *
 * @param
 * @return float: peso del paquete
*/
float paquete::get_peso() {
	return peso;
}

/**
 * getter categoria
 *
 * @param
 * @return string: categoria del paquete
*/
string paquete::get_cate() {
	return categoria;
}

/**
 * getter cantidad de articulos
 *
 * @param
 * @return int: cantidad de articulos
*/
int paquete::get_cant() {
	return cant_art;
}
//SETTERS
/**
 * setter peso
 *
 * @param float: peso 
 * @return 
*/
void paquete::set_peso(float weight) {
	peso=weight;
}

/**
 * setter categoria
 *
 * @param string: categoria
 * @return 
*/
void paquete::set_cate(string cat) {
	categoria=cat;
}

/**
 * setter cantidad
 *
 * @param int: cantidad
 * @return 
*/
void paquete::set_cant(int cant) {
	cant_art=cant;
}

#endif
