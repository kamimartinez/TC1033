/*
 * Proyecto OO
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 29/11/2023
*/

/*
 * Descripcion este es mi proyecto para la clase de Pensamiento
 * Computacional Orientado a Objetos. Es un programa que captura
 * la informacion de una persona, preguntandole datos como nombre, 
 * apellido y numero de celular. Le pregunta al usuario si desea 
 * ingresar paquetes, estos dividos entre fragil y no fragil, 
 * permitiendo al usuario saber cuanto debe pagar por cada paquete.
 * Finalmente, da el impuesto total. 
*/

//Bibliotecas
#include <bits/stdc++.h>
#include <string>
#include "paquete.h"
#include "persona.h"
#include "fragil.h"
#include "nofragil.h"

using namespace std;

int main(){
	//Se piden los valores para poder crear la clase Persona
	string nombre, apellido;
	long long numero;
	cout << "Nombre: " << endl;
	cin >> nombre;
	cout << "Apellido: " << endl;
	cin >> apellido;
	cout << "Numero de telefono: " << endl;
	cin >> numero;
	persona P1(nombre, apellido, numero);
	
	//Imprime un metodo de la clase Persona, la cual es su username
	cout << "Tu nombre de usuario es "<<P1.username() << endl;
	int x, i, y;
	
	//Pregunta la cantidad de paquetes a pedir
	cout << "¿Cuantos paquetes deseas ingresar?" << endl;
	cin >> x;
	
	int contF=-1, contNF=-1; //Contadores para conocer por cual Fragil y NoFragil estamos
	
	//Ciclo para la x cantidad de paquetes
	for(i=0;i<x;i++) {
		
		
		cout << endl;
		cout << "PAQUETE " << i << endl;
		cout << "¿Es tu paquete fragil? (1 para verdadero/cualquier otro numero falso)" << endl;
		cin >> y;
		
		//Verifica si el paquete es fragil, crea un objeto Fragil para añadirlo como componente de la clase Persona
		if(y==1) {
			contF++;
			float weight, vol;
			string cat;
			int cant;
			cout << "Peso: " << endl;
			cin >> weight;
			cout << "Categoria: " << endl;
			cin >> cat;
			cout << "Cantidad de articulos en el paquete: " << endl;
			cin >> cant;
			cout << "Volumen del paquete: " << endl;
			cin >> vol;
			
			//Agrega el componente
			P1.add_F(weight, cat, cant, vol);
			
			//Imprime el impuesto correspondiente al paquete
			cout << P1.get_nombre() <<  " el impuesto a pagar por el paquete es de $" << P1.muestra_impF(contF) << endl;
			
			//Imprime el tipo de envio
			cout << P1.envio_F(contF) << endl;
		} else {
			
			//En el caso, de que el paquete sea No Fragil
			contNF++;
			float weight, vol;
			string cat;
			int cant;
			bool rel;
			cout << "Peso: " << endl;
			cin >> weight;
			cout << "Categoria: " << endl;
			cin >> cat;
			cout << "Cantidad de articulos en el paquete: " << endl;
			cin >> cant;
			cout << "Volumen del paquete: " << endl;
			cin >> vol;
			cout << "¿El paquete contiene relleno? (0 falso/1 verdadero)" << endl;
			cin >> rel;
			
			//Agrega el paquete No Fragil a la clase Persona
			P1.add_NF(weight, cat, cant, rel, vol);
			
			//Imprime el impuesto correspondiente al paquete
			cout << P1.get_nombre() << " el impuesto a pagar por el paquete es de $" << P1.muestra_impNF(contNF) << endl;
			
			//Imprime el tipo de envio
			cout << P1.envio_NF(contNF) << endl;
		}
	}
	
	//Imprime los impuestos totales a pagar por el usuario
	cout << endl;
	cout << "El total de impuestos a pagar " << P1.get_nombre() << " " << P1.get_apellido() << " es de $" << P1.pago_total() << endl;
	return 0;
}
