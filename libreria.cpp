#include <bits/stdc++.h>
using namespace std;

//Inicia clase de Paquete
class paquete{
	private:
	float peso;
	string categoria;
	int cant_art; // cantidad de articulos en la caja

	public: 
	paquete();
	paquete(float weight, string cat, int cant): peso(weight), categoria(cat), cant_art(){};

	float get_peso();
	string get_cate();
	int get_cant();

	void set_peso(float);
	void set_cate(string);
	void set_cant(int);

	float impuesto(float weight);
};
//METODO PAQUETE
float paquete::impuesto(float weight) {
	float acum=0;
	if(weight<=5) {
		acum=weight*1.57;
	} else if(weight<=10) {
		acum=weight*1.2;
	} else {
		acum=weight*0.89;
	}
	return acum;
}
//GETTERS
float paquete::get_peso() {
	return peso;
}

string paquete::get_cate() {
	return categoria;
}

int paquete::get_cant() {
	return cant_art;
}
//SETTERS
void paquete::set_peso(float weight) {
	peso=weight;
}

void paquete::set_cate(string cat) {
	categoria=cat;
}

void paquete::set_cant(int cant) {
	cant_art=cant;
}
//CLASE DE PERSONA
class persona{
	private:
	string nombre;
	string apellido;
	long long numero;
	string calle;
	int num_casa;

	public:
	persona();
	persona(string name, string last_name, long long num, string street, int num_home) {
		nombre=name;
		apellido=last_name;
		numero=num;
		calle=street;
		num_casa=num_home;
	}

	string get_nombre();
	string get_apellido();
	long long get_numero();
	string get_calle();
	int get_num_casa();

	void set_nombre(string);
	void set_apellido(string);
	void set_numero(long long);
	void set_calle(string);
	void set_num_casa(int);

	string username(string name, string last_name);
};
//METODO
string persona::username(string name, string last_name) {
	string user="";
	user+=name.substr(0, 4);
	user+=last_name.substr(0, 4);
	return user;
}
//GETTERS
string persona::get_nombre(){
	return nombre;
}

string persona::get_apellido(){
	return apellido;
}

long long persona::get_numero() {
	return numero;
}

string persona::get_calle(){
	return calle;
}

int persona::get_num_casa() {
	return num_casa;
}
//SETTERS
void persona::set_nombre(string name) {
	nombre=name;
}

void persona::set_apellido(string last_name) {
	apellido=last_name;
}

void persona::set_numero(long long num) {
	numero=num;
}

void persona::set_calle(string street) {
	calle=street;
}

void persona::set_num_casa(int num_home) {
	num_casa=num_home;
}

//CLASE TRANSPORTE
class transporte{
	private: 
	float kg;
	bool inter;  //¿Es internacional?
	string pais_dest;

	public:

	transporte();
	transporte(float p, bool nacional, string pais) {
		kg=p;
		inter=nacional;
		pais_dest=pais;
	}
	
	float get_kg();
	bool get_inter();
	string get_pais();

	void set_kg(float);
	void set_inter(bool);
	void set_pais(string);

	float importacion(float p, bool nacional);

};
//METODO
float transporte::importacion(float p, bool nacional) {
	float acum=1;
	if(nacional==true) { //Es internacional
		for(int i=0;i<p;i++) {
			acum+=1.5;
		}
	} else {
		for(int i=0;i<p;i++) {
			acum+=1.2;
		}
	}
	return acum;
}
//GETTERS
float transporte::get_kg(){
	return kg;
}

bool transporte::get_inter(){
	return inter;
}

string transporte::get_pais() {
	return pais_dest;
}
//SETTERS
void transporte::set_kg(float p) {
	kg=p;
}

void transporte::set_inter(bool nacional) {
	inter=nacional;
}

void transporte::set_pais(string pais) {
	pais_dest=pais;
}

int main() {
	paquete p1(8.7, "Maquillaje", 8);
	cout << p1.impuesto(8.7) << endl;
	persona Kamila("Kamila", "Martinez", 79035898, "Epigmenio Gonzalez", 500);
	cout << "Tu nombre de usuario es "<<Kamila.username("Kamila", "Martinez") << endl;
	transporte t1(8.7, true, "El Salvador");
	cout << "Te cobrare " << t1.importacion(8.7, true) << " por importacion" << endl;
	return 0;
}
