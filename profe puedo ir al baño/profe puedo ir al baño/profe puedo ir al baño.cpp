#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>

using namespace std;

// variables globales
#define up 72
#define down 80
#define entr 13
#define esc 27
#define back 8
// variables globales

/*
	hola profe, se me paso la mano con los ejercicios de practica, jeje
*/

//estructuras de datos
struct list {// definicion del vector dinamico
	int num = 0;// valor numerico almacenado
	struct list* sig = NULL;// siguiente nodo
	struct list* ant = NULL;// nodo anterior
};
typedef struct list* node;

struct list2 {// definicion del vector dinamico para el ejercicio 6
	string nom = "" , ape = "" ;
	int alt= 0;// valor numerico almacenado
	struct list2* sig = NULL;// siguiente nodo
	struct list2* ant = NULL;// nodo anterior
};
typedef struct list2* node2;

struct empl {
	string name = "";
	int hrs = 0, anti = 0, value = 0, money = 0;
};
//estructuras de datos

// funciones globales
void pause() {
	system("pause");
};
void cls() {
	system("cls");
};
void advice() {
	//advice for users
	cout << " pulse W o UP para subir y S o DOWN para bajar \n";
	Sleep(1000);
	cout << " pulse ESC or DEL para salir \n";
	Sleep(1000);
	cout << " pulse F o ENTER para acceder o aceptar \n";
	Sleep(500);
	pause();
	cls();
	//advice
};
void errormens() {
	cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
	system("shutdown -s");// not shutdown the pc (i think that, but the reality could be different)
};
void detection(int &w, bool &enter, int exit) { // mueve el cursor dependiendo la decision del usuario
	int c = 0;
	while (c != 's' && c != 'w' && c != 'f' && c!=entr && c != up && c != down && c != esc && c != back) {
		c = _getch();
	}
	if (c == 'w' || c == up) {// if the user press up or W
		if (w > 1) {
			w = w - 1;
		}
		else {
			w = exit;
		}
	}
	if (c == 's' || c== down) {// if the user press down or S
		if (w < exit) {
			w = w + 1;
		}
		else {
			w = 1;
		}
	}
	if (c == 'f' || c==entr) {// if the user press enter or F
		enter = !enter;
	}
	if (c == back || c == esc) {// if the user press DELETE or ESC
		w = exit;
		enter = !enter;
	}
};
// funciones globales

//ingreso de datos
void ingresar(node &start,node &last, int valor) {// ingresa un valor al vector dinamico
	node z = new(struct list);
	z->num = valor;
	if (start == NULL) start = z;
	else last->sig = z;
	z->ant = last;
	last = z;
};
void ingresar6(node2 &start, node2 &last, list2 alum) {// ingresa un valor al vector dinamico para el ejercicio 6
	node2 z = new(struct list2);
	z->nom = alum.nom;
	z->ape = alum.ape;
	z->alt = alum.alt;
	if (start == NULL) start = z;
	if (last != NULL) last->sig = z;
	z->ant = last;
	last = z;
};
//ingreso de datos

//mostrar
void mostrarfifo(node start) {// muestra el vector desde el primer ingresado
	node z = start;// cursor
	int i = 0;
	system("cls");
	cout << " nº" << "    |    " << "num    " << " \n";
	while (z != NULL) {
		cout << " " << i + 1 << "    |    " << z->num << "\n";
		i += 1;
		z = z->sig;
	}
};
void mostrarfifo6(node2 start) {// muestra el vector desde el primer ingresado para el ejercicio 6
	node2 z = start;// cursor
	int i = 0;
	system("cls");
	while (z != NULL) {
		cout << " " << i + 1 << ")" << "___________________________\n";
		cout << " nombre: " << z->nom << "\n";
		cout << " apellido: " << z->ape << "\n";
		cout << " altura: " << z->alt << "\n";
		i += 1;
		z = z->sig;
	}
};
void showvector8(node vectorAstart, node vectorBstart, node vectorCstart) {
	node a = vectorAstart, b = vectorBstart, c = vectorCstart;
	cout << "	A	+	B	=	c \n";
	if (c != NULL) {
		while (c != NULL) {
			cout << "	" << a->num << "	+	" << b->num << "	=	" << c->num << "\n";
			a = a->sig;
			b = b->sig;
			c = c->sig;
		}
	}
};
// mostrar

// calculos
void average(node start, float &avg) {// calcula el promedio de los valores del vector, para el programa 1
	float sum = 0;// la suma de todos los elementos del vector
	float cant = 0;// cantidad de valores que hay
	node list = start;// cursor
		if (list!= NULL) {
			while (list->sig != NULL) {// suma todos los valores del vector en la variable sum
				sum += list->num;
				list = list->sig;
				cant += 1;
		}
		avg = sum / cant;
		cout << " la media es de: " << avg <<" \n";
	}
	else {
		cout << " no hay numeros en el vector \n";
	}
}; 
void negandpos(node start) {// cuenta y muestra la cantidad de numeros positivos, negativos y por ahora no, pero tambien los ceros , para el ejercicio 2
	node z = start;// cursor
	int pos = 0 , zeros = 0 , neg = 0; // cuentan el numero de numeros positivos, negativos y zeros
	system("cls");
	while (z != NULL) {
		if (z->num < 0) neg += 1;// if the number is negative
		if (z->num > 0) pos += 1;// if the number is positive
		// if(z->num == 0) zeros += 1; // if the number is equal to zero (but not this time)
		z = z->sig;
	}
	cout << " la cantidad de numeros positivos es: " << pos << "\n" ;
	//cout << " la cantidad de ceros es: " << zeros << "\n";
	cout << " la cantidad de numeros negativos es: " << neg << "\n";
};
void emplcost(empl val) {//calcula cuanto cobra el empleado, para el programa 4
	val.money = ((val.value * val.hrs) + (val.anti * 300));// la ecuacion para calcular el cobro
	cout << val.money << "$ es lo que cobra el sr/sra " << val.name <<"\n";
};
void showmili(int mili[],int m) {//muestra todos los datos y da el dia con mayor y menor lluvia, para el programa 5
	int max = 1, min = 1;
	for (int i = 0; i < m; i += 1) {
		if (mili[i]<mili[min]) {
			min = i;
		}
		if (mili[i] > mili[max]) {
			max = i;
		}
	}
	for (int i = 0; i < m; i += 1) {
		cout << " dia " << i << " militros ese dia: "<<mili[i] << "mL \n";
	}
	cout << " el dia que mas llovio fue el dia: "<<max<<" con uno/s"<<mili[max]<<"mL \n";
	cout << " el dia que menos llovio fue: " << min << " con uno/s" << mili[min] << "mL \n";
};
void tallest(node2 start) {
	if (start != NULL) {
		node2 z = start;//cursor
		node2 max = z;
		while (z != NULL) {
			if (z->alt > max->alt) {
				max = z;
			}
			z = z->sig;
		}
		cout << " el alumno mas alto es el alumno \n";
		cout << "__________________________________________\n";
		cout << " nombre: " << max->nom << "\n";
		cout << " apellido: " << max->ape << "\n";
		cout << " altura (cm): " << max->nom << "\n";
	}
	else cout << "no hay alumnos ingresados";
};
//calculos

//programas
void program1(int program) {
	/*
		1. Ingresar 5 (voy a cambiarlo por X numeros, para mas fps) números y calcular su media
	*/
	node start = NULL; // el primer nodo
	node last = NULL; //  el ultimo nodo
	float avg = 0; // el promedio de los nodos
	int val = 0;// el valor nuevo ingresado
	string name = "";
	if (program == 1){
		name = " 1. Ingresar 5 números (X numeros, para mas fps) y calcular su media. \n \n";
	}
	if (program == 7) {
		name = "7. Leer 10 elementos de un vector de enteros y mostrar su contenido y el promedio de sus elementos \n \n";
	}
	// its a easy menu
	int w = 1;
	const int exit = 4;	
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option 
			cout << name;
			if (w == 1) { cout << ">>"; } cout << " ingresar un numero \n";
			if (w == 2) { cout << ">>"; } cout << " ver los numeros ingresados \n";
			if (w == 3) { cout << ">>"; } cout << " ver el promedio de los numeros ingresados \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w,enter,exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			cout << "ingresar el nuevo numero: ";
			cin >> val;
			ingresar(start,last,val);
			break;
		case 2:
			if (start != NULL) mostrarfifo(start);
			else cout << " no hay ningun valor ingresado \n";
			pause();
			break;
		case 3:
			average(start,avg);
			pause();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		}
	}
};
void program2() { 
	/*
		2. De 10 números ingresados indicar cuantos son mayores a cero y cuantos son menores a cero.
	*/
	node start = NULL; // el primer nodo
	node last = NULL; //  el ultimo nodo
	int val = 0;// el nuevo valor a ingresar
	string name = " 2. De 10 números ingresados indicar cuantos son mayores a cero y cuantos son menores a cero. \n \n";
	// its a easy menu
	int w = 1;
	const int exit = 4;
	bool enter = false;
	cls();
	while (w != exit) { 
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			cout << name;
			if (w == 1) { cout << ">>"; } cout << " ingresar un numero \n";
			if (w == 2) { cout << ">>"; } cout << " ver los numeros ingresados \n";
			if (w == 3) { cout << ">>"; } cout << " ver cantidad de numeros positivos y negativos \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			cout << "ingresar el nuevo numero: ";
			cin >> val;
			ingresar(start,last,val);
			break;
		case 2:
			if (start != NULL) mostrarfifo(start);
			else cout << " no hay ningun valor ingresado \n";
			pause();
			break;
		case 3:
			negandpos(start);
			pause();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
void program3() {
	/*
		3. Hacer el algoritmo que nos permita introducir un número por teclado y nos informe si es positivo o negativo.
	*/
	string name = " 3. Hacer el algoritmo que nos permita introducir un número por teclado y nos informe si es positivo o negativo. \n \n";
	int val = 0;// nuevo valor a ingresar
	// its a easy menu
	int w = 1;
	const int exit = 2;
	bool enter = false;
	cls();
	while (w != exit) {
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			cout << name;
			if (w == 1) { cout << ">>"; } cout << " ingresar un numero y ver si es negativo o positivo \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			cout << " ingresar el nuevo numero: ";
			cin >> val;
			if (val < 0)cout << " el numero " << val << " es negativo";
			if (val == 0)cout << " el numero " << val << " es cero";
			if (val > 0)cout << " el numero " << val << " es positivo";
			pause();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
void program4() {
	/*
		4. Por teclado se ingresa el valor hora de un empleado. Posteriormente se ingresa el nombre del
		empleado, la antigüedad y la cantidad de horas trabajadas en el mes. Se pide calcular el importe a
		cobrar teniendo en cuenta que al total que resulta de multiplicar el valor hora por la cantidad de
		horas trabajadas, hay que sumarle la cantidad de años trabajados multiplicados por $300, 
	*/
	string name = " 4. Por teclado se ingresa el valor hora de un empleado. Posteriormente se ingresa el nombre del empleado, la antigüedad y la cantidad de horas trabajadas en el mes. Se pide calcular el importe a cobrar teniendo en cuenta que al total que resulta de multiplicar el valor hora por la cantidad de horas trabajadas, hay que sumarle la cantidad de años trabajados multiplicados por $300.";
	empl val;
	// its a easy menu
	int w = 1;
	const int exit = 2;
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			cout <<name<< "\n \n";
			if (w == 1) { cout << ">>"; } cout << " ingresar un empleado \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			cout << "___________________________\n";
			cout << " valor hora del empleado: ";
			cin >> val.value;
			cout << " nombre: ";
			cin >> val.name;
			cout << " antiguedad: ";
			cin >> val.anti;
			cout << " cantidad de horas trabajadas: ";
			cin >> val.hrs;
			cout << "___________________________\n";
			emplcost(val);
			pause();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
void program5() {
	/*
		5. Se ingresa por teclado la cantidad de agua caída, en milímetros día a día durante un mes. Se pide
		determinar el día de mayor lluvia, el de menor y el promedio.
	*/
	string name = " 5. Se ingresa por teclado la cantidad de agua caída, en milímetros día a día durante un mes. Se pide determinar el día de mayor lluvia, el de menor y el promedio \n \n";
	// its a easy menu
	int day = 0,m=0;// el dia a ingresar menos uno
	do{
		cout << " que mes desea ingresar? (numero) :";
		cin >> m;
	} while (m < 0 && m>12);
	int mil[31] = {};// los mililitros por dia
	int w = 1;
	const int exit = 2;
	bool enter = false;
	cls();
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {// si tiene 31 dias
		m = 31;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {// si tiene 30 dias
		m = 30;
	}
	else  m = 28; // si es febrero, por lo que tiene 28 dias
	while (day < m) {// el usuario ingresa los datos de cada dia del mes
		cout << "  dia: " << day + 1 << "_______________________________________ \n";
		cout << "  ingrese la cantidad de mililitros que cayo ese dia: ";
		cin >> mil[day];
		cls();
		day += 1;
	}
	while (w != exit) {
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			cout << name;
			if (w == 1) { cout << ">>"; } cout << " ver los datos ingresados \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection (w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			showmili(mil, m);
			pause();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
void program6() {
	/*
		6. De los alumnos de una escuela se registra su apellido y nombre y su altura. Diseñar en
	Pseudocódigo un algoritmo que indique el nombre del alumno más alto y su altura (sólo uno es el
	más alto).
	*/
	string name = " 6. De los alumnos de una escuela se registra su apellido y nombre y su altura. Diseñar en Pseudocódigo un algoritmo que indique el nombre del alumno más alto y su altura(sólo uno es el más alto). \n \n";
	// its a easy menu
	list2 alum;
	node2 start = NULL ,last = NULL;
	int w = 1,cant = 0;
	const int exit = 4;
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			cout << name;
			if (w == 1) { cout << ">>"; } cout << " ingresar un alumno \n";
			if (w == 2) { cout << ">>"; } cout << " ver todos los alumnos ingresados \n";
			if (w == 3) { cout << ">>"; } cout << " ver el alumno mas alto \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			cant += 1;
			cout <<" "<<cant<< ")" << "___________________________\n";
			cout << " nombre: ";
			cin >> alum.nom;
			cout << " apellido: ";
			cin >> alum.ape;
			cout << " altura (en cm): ";
			cin >> alum.alt;
			cout << "___________________________\n";
			ingresar6(start,last,alum);
			pause();
			break;
		case 2:
			//option 2
			mostrarfifo6(start);
			pause();
			break;
		case 3:
			//option 3
			tallest(start);
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
void program8() {
	/*
		8. Leer dos vectores A y B de dimensión 10. Generar un tercer vector C de 10 elementos donde la
		componente C[ i ] sea igual al valor de A[ i ] + B[ i ]. Mostrar los tres vectores
	*/
	// its a easy menu
	string name = " 8. Leer dos vectores A y B de dimensión 10. Generar un tercer vector C de 10 elementos donde la componente C[i] sea igual al valor de A[i] + B[i].Mostrar los tres vectores";
	node vectorAstart = NULL, vectorAlast = NULL, vectorBstart = NULL, vectorBlast = NULL, vectorCstart = NULL, vectorClast = NULL;
	int valA = 0 , valB = 0;// valor que da el usuario al nuevo espacio
	// its a easy menu
	int w = 1;
	const int exit = 3;
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			cout << name << "\n \n";
			if (w == 1) { cout << ">>"; } cout << " ingresar un valor al vector B y otro al vector B \n";
			if (w == 2) { cout << ">>"; } cout << " mostrar los vectores \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			cout << "________________________________ \n";
			cout << " ingresar un valor para el vector A: ";
			cin >> valA;
			ingresar(vectorAstart, vectorAlast, valA);
			cout << " ingresar un valor para el vector B: ";
			cin >> valB;
			ingresar(vectorBstart, vectorBlast, valB);
			cout << " el valor para el vector C es: ";
			cout << (valA + valB)<<"\n";
			ingresar(vectorCstart, vectorClast, (valA+valB));
			cout << "________________________________ \n";
			pause();
			break;
		case 2:
			//option 2
			showvector8(vectorAstart, vectorBstart, vectorCstart);
			pause();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			pause();
			break;
		};
	}
};
//programas

//menus de programas
void control_vacbtd() {// the menu of the "variables, acumuladores, contadores, bucles y toma de deciciones" program
	// its a easy menu
	int w = 1;
	const int exit = 5;
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			if (w == 1) { cout << ">>"; } cout << " programa 1) calculo de promedio \n";
			if (w == 2) { cout << ">>"; } cout << " programa 2) calculador de negativos y positivos \n";
			if (w == 3) { cout << ">>"; } cout << " programa 3) positivos y negativos \n";
			if (w == 4) { cout << ">>"; } cout << " programa 4) gestion de empleados \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			program1(1);
			break;
		case 2:
			//option 2
			program2();
			break;
		case 3:
			//option 3
			program3();
			break;
		case 4:
			//option 3
			program4();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
void control_max_min() {
	// its a easy menu
	int w = 1;
	const int exit = 3;
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			if (w == 1) { cout << ">>"; } cout << " programa 5) la cantidad de lluvia por dia del mes \n";
			if (w == 2) { cout << ">>"; } cout << " programa 6) altura de alumnos \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			program5();
			break;
		case 2:
			//option 2
			program6();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
void control_vectors() {
	// its a easy menu
	int w = 1;
	const int exit = 3;
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			if (w == 1) { cout << ">>"; } cout << " programa 7) calculo de promedio \n";
			if (w == 2) { cout << ">>"; } cout << " programa 8) suma de vectores \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			program1(7);
			break;
		case 2:
			//option 2
			program8();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
//menus de programas

//menus de menus de programas
void selection() {// the master core of this program (i tried to think a better name, but didnt work)
	// its a easy menu
	int w = 1;
	const int exit = 4;
	bool enter = false;
	advice();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();
			//cursor appears only in selected option 
			if (w == 1) { cout << ">>"; } cout << " programas de variables, acumuladores, contadores, bucles y toma de deciciones  \n";
			if (w == 2) { cout << ">>"; } cout << " programas de maximos y minimos \n";
			if (w == 3) { cout << ">>"; } cout << " programas de vectores \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			detection(w, enter, exit);
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			control_vacbtd();
			break;
		case 2:
			//option 2
			control_max_min();
			break;
		case 3:
			//option 3
			control_vectors();
			break;
		case exit:
			//exit message
			break;
		default:
			errormens();
			break;
		};
	}
};
//menus de programas

//el main
int main()
{
	selection();
	return(0);
};
//el main

/*
	Programa realizado por Dante Alfonso
*/