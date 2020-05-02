#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<Windows.h>

using namespace std;

void menu();
void productos();
void consulta();

int main() {
	menu();
	return 0;
	
}

void productos(){

int codigo=0, minimo=0, actual=0, precio=0, articulo=0;
char provee[20]; 

	ofstream escritura;
	escritura.open("prod.txt", ios::out | ios::app);
	if (escritura.is_open()) {
				
		cout << "INGRESE LOS SIGUIENTES DATOS\n";
		cin>>articulo;
		for(int i=0;i<articulo;i++){
		cout << "\nIngrese el codigo del articulo: ";
		cin >> codigo;
		cout << "Ingrese el nivel minimo del producto: ";
		cin >> minimo;
		cout << "Ingrese el nivel actual : ";
		cin >> actual;
		cout << "Ingrese Prooveedores: ";
		cin >> provee;
		cout << "Ingrese el Precio: ";
		cin >> precio;
		
		escritura << codigo << " " << minimo << " " << actual << " " << provee << " " << precio  << endl;
		}
	}
	else {
		cout << "Error, el Archivo No se Pudo Abrir" << endl;
	}
	escritura.close();

}

void consultas() {
int codigo=0, minimo=0, actual=0, precio=0, articulo=0;
char provee[20]; 
	ifstream lectura;
	lectura.open("prod.txt", ios::out | ios::in | ios::app);
	if (lectura.is_open()) {
		while (!lectura.eof()) {
			cout << "__________" << endl;
			
			cout << "codigo: " << codigo << endl;
			lectura >> codigo;
			
			cout << "minimo: " << minimo << endl;
			lectura >> minimo;
			
			cout << "actual: " << actual << endl;
			lectura >> actual;
			
			cout << "provee: " << provee << endl;
			lectura >> provee;
			
			cout << "precio: " << precio << endl;
			lectura >> precio;
			
			cout << "__________" << endl;
			
		
		cout<<"\n";
		
		
	cout<<"\n"; 

		}
	
	cout<<"hacer pedido: "<<minimo<<endl;
	



	}else {
		cout << "Error, el Archivo No se Pudo Abrir, No ha sido creado" << endl;
	}

	lectura.close();
	system("pause");

}

void menu() {
	int opcion = 0;
	while (opcion != 1) {
		system("cls");
	 cout << "  - - - - - - \n";
	 cout << " |         - - -  MENU - - -         |\n";
	 cout << " | 1 AGREGAR PRODUCTOS         |\n";
	 cout << " | 2 MOSTRAR PRUDUCTOS         |\n";
			cout << "Que desea hacer? ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			system("cls");
			productos();
			break;
			
			case 2:
				system("cls");
				consultas();
				break;
	
		}
	}
}
