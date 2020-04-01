#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

/*
	
*/

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

void pause() {
	system("pause");
};
void cls() {
	system("cls");
};

void ingresar(node &start,node &last, int valor) {// ingresa un valor al vector dinamico
	node z = new(struct list);
	z->num = valor;
	if (start == NULL) start = z;
	if (last != NULL) last->sig = z;
	z->ant = last;
	last = z;
};
void ingresar(node2& start, node2& last,int cant) {// ingresa un valor al vector dinamico
	int alt = 0;
	string nom = "", ape = "";
	cout << " " <<cant + 1 << ")_______________________________________________________ \n";
	node2 z = new(struct list2);
	z->nom = nom;
	z->ape = ape;
	z->alt = alt;
	if (start == NULL) start = z;
	if (last != NULL) last->sig = z;
	z->ant = last;
	last = z;
};
void average(node start, float &avg) {// calcula el promedio de los valores del vector, para el programa 1
	int sum = 0;
	int b = 0;
	node list = start;
		if (list!= NULL) {
			while (list->sig != NULL) {// suma todos los valores del vector en la variable sum
				sum += list->num;
				list = list->sig;
				b += 1;
		}
		avg = sum / b;
		cout << " la media es de: " << avg <<" \n";
	}
	else {
		cout << " no hay numeros en el vector \n";
	}
}; 
void mostrarfifo(node start) {// muestra el vector desde el primer ingresado
	node z = start;
	int i = 0;
	system("cls");
	cout << " nº" << "    |    " << "num    " << " \n";
	while (z != NULL) {
		cout << " " << i + 1 << "    |    " << z->num << "\n";
		i += 1;
		z = z->sig;
	}
};
void negandpos(node start) {// cuenta y muestra la cantidad de numeros positivos, negativos y por ahora no, pero tambien los ceros
	node z = start;
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
	val.money = ((val.value * val.hrs) + (val.anti * 300));// la ecuacion
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
void showvecto() {

};
void program1(){
	/*
		1. Ingresar 5 (voy a cambiarlo por X numeros, para mas fps) números y calcular su media
	*/
	node start = NULL; // el primer nodo
	node last = NULL; //  el ultimo nodo
	float avg = 0; // el promedio de los nodos
	int val = 0;// el valor nuevo ingresado
	string name = " 1. Ingresar 5 números y calcular su media. \n \n";
	// its a easy menu
	int w = 1;
	const int exit = 4;
	char c = 'a';// keyboard input	
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
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
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
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
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
	char c = 'a';// keyboard input
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
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
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
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
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
	char c = 'a';// keyboard input
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
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
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
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
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
	const int exit = 4;
	char c = 'a';// keyboard input
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
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
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
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
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
	char c = 'a';// keyboard input
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
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
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
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
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
	int w = 1;
	const int exit = 4;
	char c = 'a';// keyboard input
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
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			
			break;
		case 2:
			//option 2
			
			break;
		case 3:
			//option 3
			
			break;
		case exit:
			//exit message
			break;
		default:
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
			break;
		};
	}
};
void control_vacbtd() {// the menu of the "variables, acumuladores, contadores, bucles y toma de deciciones" program
	// its a easy menu
	int w = 1;
	const int exit = 5;
	char c = 'a';// keyboard input
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			if (w == 1) { cout << ">>"; } cout << " programa de calculo de promedio \n";
			if (w == 2) { cout << ">>"; } cout << " programa calculador de negativos y positivos \n";
			if (w == 3) { cout << ">>"; } cout << " programa de positivos y negativos \n";
			if (w == 4) { cout << ">>"; } cout << " programa de gestion de empleados \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
			//detection of the cursor
		}
		cls();
		switch (w) {
		case 1:
			//option 1
			program1();
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
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
			break;
		};
	}
};
void control_max_min() {
	// its a easy menu
	int w = 1;
	const int exit = 3;
	char c = 'a';// keyboard input
	bool enter = false;
	cls();
	while (w != exit) { // its a easy menu
		enter = false;
		while (!enter) {
			cls();//cursor appears only in selected option
			if (w == 1) { cout << ">>"; } cout << " programa de calculo de promedio \n";
			if (w == 2) { cout << ">>"; } cout << " programa calculador de negativos y positivos \n";
			if (w == exit) { cout << ">>"; } cout << " salida \n";
			//detection of the cursor
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
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
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
			break;
		};
	}
};
void selection() {// the master core of this program (i tried to think a better name, but didnt work)
	// its a easy menu
	int w = 1;
	const int exit = 4;
	char c = 'a';// keyboard input
	bool enter = false;
	//advice for users
	cout << " press w to go up and s to go down \n";
	Sleep(2000);
	cout << " press f to enter \n";
	Sleep(500);
	pause();
	cls();
	//advice
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
			c = 'a';
			while (c != 's' && c != 'w' && c != 'f') {
				c = _getch();
			}
			if (c == 'w') {
				if (w > 1) {
					w = w - 1;
				}
				else {
					w = exit;
				}
			}
			if (c == 's') {
				if (w < exit) {
					w = w + 1;
				}
				else {
					w = 1;
				}
			}
			if (c == 'f') {
				enter = !enter;
			}
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
			break;
		case exit:
			//exit message
			break;
		default:
			cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
			system("shutdown -s -t ");// not shutdown the pc (i think that, but the reality could be different)
			break;
		};
	}
};
int main()
{
	selection();
	return(0);
};