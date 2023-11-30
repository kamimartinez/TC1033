/*
 * Proyecto OO
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 29/11/2023
 */
 
/*
 * Clase Persona, maneja grupos de paquetes, divididos en
 * Fragil y No Fragil
 *
 */


#ifndef PERSONA_H
#define PERSONA_H

#include <bits/stdc++.h>
#include "paquete.h"
#include "fragil.h"
#include "nofragil.h"
using namespace std;

//CLASE DE PERSONA
class persona{
	private:
	
	//Atributos de la clase
	string nombre;
	string apellido;
	long long numero;
	
	//Arreglos correspondientes a Fragil y No fragil
	Fragil p_fragil[100];
	NOFragil p_nofragil[100];
	//Arreglos para los impuestos correspondientes de cada paquete
	float impF[100], impNF[100];
	int pos1, pos2;

	public:
	
	//Constructores
	persona(): pos1(0), pos2(0){};
	persona(string name, string last_name, long long num) {
		nombre=name;
		apellido=last_name;
		numero=num;
		pos1=0;
		pos2=0;
	}
	
	//Getters
	string get_nombre();
	string get_apellido();
	long long get_numero();
	
	//Setters
	void set_nombre(string);
	void set_apellido(string);
	void set_numero(long long);
	
	//Metodos
	string username();
	
	void add_F(float , string , int , float); //agrega paquete Fragil
	void add_NF(float , string, int ,bool, float);

	
	float muestra_impF(int pos);
	float muestra_impNF(int pos);
	float pago_total();
	string envio_F(int);
	string envio_NF(int);
};
//METODO

/**
 * Utiliza los strings de nombre y apellido.
 * Selecciona las primeras 4 letras de cada string y lo agrega en un solo string
 * Regresa el string creado como username
 *
 * @param
 * @return
*/
string persona::username() {
	string user="";
	user+=nombre.substr(0, 4);
	user+=apellido.substr(0, 4);
	return user;
}

/**
 * Utiliza los arreglos que contienen los paquetes de Fragil y manda
 * a llamar el metodo de tipo de envio. 
 *
 * @param
 * @return string
*/
string persona::envio_F(int pos){
	return p_fragil[pos].tipoEnvio();
}

/**
 * Utiliza los arreglos que contienen los paquetes de No Fragil y manda
 * a llamar el metodo de tipo de envio. 
 *
 * @param
 * @return string
*/
string persona::envio_NF(int pos){
	return p_nofragil[pos].tipoEnvio();
}


/**
 * Utiliza el arreglo de tipo Fragil para crear un objeto Fragil como
 * componente de la clase Persona. Tambien utiliza el arreglo ImpF para
 * agregar el impuesto del objeto creado. 
 *
 * @param
 * @return
*/
void persona::add_F(float weight, string cat, int cant, float vol) { 	
	p_fragil[pos1]=Fragil(weight, cat, cant, vol);
	impF[pos1]=p_fragil[pos1].ImpF();
	pos1++;
}

/**
 * Utiliza el arreglo de tipo Fragil para crear un objeto Fragil como
 * componente de la clase Persona. Tambien utiliza el arreglo ImpF para
 * agregar el impuesto del objeto creado. 
 *
 * @param
 * @return
*/
void persona::add_NF(float weight, string cat, int cant,bool rel, float vol) { 	
	p_nofragil[pos2]=NOFragil(weight, cat, cant, rel, vol);
	impNF[pos2]=p_nofragil[pos2].ImpNF();
	pos2++;
}

/**
 * Utiliza el arreglo de ImpF y ImpNF para agregar los valores de los
 * impuestos de los paquetes correspondiente a una misma variable y regresar 
 * esa misma.  
 *
 * @param
 * @return
*/
float persona::pago_total() {
	float total=0;
	for(int i=0;i<pos1;i++) {
		total+=impF[i];
	}
	for(int i=0;i<pos2;i++) {
		total+=impNF[i];
	}
	return total;
}

/**
 * Utiliza el arreglo ImpF para regresar el valor del impuesto
 * del objeto pedido por el usuario. 
 *
 * @param
 * @return float:ImpF
*/
float persona::muestra_impF(int pos) {
	return impF[pos];
}

/**
 * Utiliza el arreglo ImpNF para regresar el valor del impuesto
 * del objeto pedido por el usuario. 
 *
 * @param
 * @return float:ImpNF
*/
float persona::muestra_impNF(int pos) {
	return impNF[pos];
}

//GETTERS

/**
 * getter nombre
 *
 * @param
 * @return string: nombre del usuario
*/
string persona::get_nombre(){
	return nombre;
}

/**
 * getter apellido
 *
 * @param
 * @return string: apellido del usuario
*/
string persona::get_apellido(){
	return apellido;
}

/**
 * getter numero
 *
 * @param
 * @return long long: numero del usuario
*/
long long persona::get_numero() {
	return numero;
}

//SETTERS

/**
 * setter nombre
 *
 * @param
 * @return 
*/
void persona::set_nombre(string name) {
	nombre=name;
}

/**
 * setter apellido
 *
 * @param
 * @return 
*/
void persona::set_apellido(string last_name) {
	apellido=last_name;
}

/**
 * setter numero
 *
 * @param
 * @return 
*/
void persona::set_numero(long long num) {
	numero=num;
}


#endif
