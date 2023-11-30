/*
 * Proyecto OO
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 29/11/2023
 */
 
/*
 * Clase Fragil, es herencia de la clase Paquete
 *
 */

#ifndef FRAGIL_H
#define FRAGIL_H

#include <bits/stdc++.h>
#include "paquete.h"

using namespace std;

//Herencia
class Fragil: public paquete{
	private:
	
	//ATRIBUTOS
	float volumen;
	float tax;
	
	public:
	//CONSTRUCTORES
	Fragil(): tax(0), paquete(){};
	Fragil(float weight, string cat, int cant, float vol): paquete(weight, cat, cant), volumen(vol){}; 
	
	//GETTERS
	
	/**
	* getter volumen
	*
	* @param
	* @return float:volumen
	*/
	float get_volumen(){
		return volumen;
	}
	
	/**
	* setter volumen
	*
	* @param float: volumen
	* @return 
	*/
	void set_volumen(float vol){
		volumen=vol;
	}
	
	/**
	* Utiliza el valor de volumen y lo multiplica con una constante
	* para retornar el impuesto por ser un paquete Fragil.  
	*
	* @param
	* @return float: impuesto a pagar
	*/
	float ImpF() { 
		tax=volumen*1.27;
		return tax;
	}
};

#endif
