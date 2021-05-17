

#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Nodo {
	int Dato;
	Nodo* siguiente;
};

void insertarCola(Nodo&, Nodo&, int);
bool cola_vacia(Nodo*);
void suprimirCola(Nodo&, Nodo&, int&);
void delay(int secs) {
	for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

int main() {
	Nodo* frente = NULL;
	Nodo* fin = NULL;
	int num;
	int opc;

	do {
		cout << "\t.:Nemo:.\n";
		cout << "1. Insertar dato" << endl;
		cout << "2. Mostrar too los datos" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;

		switch (opc) {
		case 1: cout << "\n Ingreseme la cola: ";
			cin >> num;
			insertarCola(frente, fin, num);
			break;
		case 2: cout << "\muestreme la cola: ";
			while (frente != NULL) {
				suprimirCola(frente, fin, num);
				if (frente != NULL) {
					cout << num << " , ";
				}
				if (frente != NULL) {
					cout << num << ",";
				}
			}
			system("pause");
			break;
			break;
		case 3: break;
		}
		system("cls");
	} while (opc != 3);

	srand(time(NULL));
	//num=rand();
	//ajustar rango de numeros variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
	for (int i = 1; i <= 200; i++)
	{
		num = 1 + rand() % (91 - 1);
		cout << i << ". " << num << endl;
		delay(1);
	}

	return 0;
}

void insertarCola(Nodo*& frente, Nodo*& fin, int num) {
	Nodo* nuevo_nodo = new Nodo();

	nuevo_nodo->Dato = num;
	nuevo_nodo->siguiente = NULL;

	if (cola_vacia(frente)) {
		frente = nuevo_nodo;
	}
	else {
		fin->siguiente = nuevo_nodo;
	}

	fin = nuevo_nodo;

	cout << "\tElemento" << num << " inserted correctly\n";
}

bool cola_vacia(Nodo* frente) {
	return (frente == NULL) ? true : false;
}

void suprimirCola(Nodo*& frente, Nodo*& fin, int& num) {
	num = frente->Dato;
	Nodo* aux = frente;

	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else {
		frente = frente->siguiente;
	}

	delete aux;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
