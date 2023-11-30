/*
 * Proyecto OO
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 29/11/2023
 */
 
/*
 * Clase No Fragil, es herencia de la clase Paquete
 *
 */


#ifndef NOFRAGIL_H
#define NOFRAGIL_H

#include <bits/stdc++.h>
#include "paquete.h"

using namespace std;

//Herencia
class NOFragil: public paquete{
	private:
	//Atributos
	bool relleno;
	float volumen;
	float tax;
	
	public:
	//CONSTRUCTORES
	NOFragil(): tax(0), relleno(0), paquete(){};
	NOFragil(float weight, string cat, int cant,bool rel, float vol): paquete(weight, cat, cant), relleno(rel), volumen(vol){}; 
	
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
	* getter relleno
	*
	* @param
	* @return bool: relleno
	*/
	bool get_relleno(){
		return relleno;
	}
	
	/**
	* setter relleno
	*
	* @param bool:relleno
	* @return 
	*/
	void set_relleno(bool rel) {
		relleno=rel;
	}
	
	/**
	* Utiliza el valor de volumen y lo multiplica con una constante
	* para retornar el impuesto por ser un paquete No Fragil.  
	*
	* @param
	* @return float: impuesto a pagar
	*/
	float ImpNF() { 
		if(relleno==true) {
			tax=get_peso()*volumen*1.002;
		} else {
			tax=get_peso()*volumen*1.54;
		}
		return tax;
	}
};
#endif
