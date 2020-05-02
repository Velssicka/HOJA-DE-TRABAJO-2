#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct estudiante {
	string nombre;
	int id;	
	float nota;	
};
void mp(); 
void ingresardatos(string na);
void leer_archivo(string na);
int main(){
	mp();	
}
void mp(){
	int resp;
	string nombrearchivo;
	cout<<"Ingrese el nombre que le dara al archivo: ";
	getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<" - - - OPCIONES - - - "<<"\n";
		cout<<"\n 1 - Ingresar Estudiantes "<<"\n";
		cout<<" 2 - Reporte "<<"\n";		
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Elija una opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			ingresardatos(nombrearchivo);			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo(nombrearchivo);
		}					
		else if (resp==4)
			break;
		else 
			break;
		
	} while(resp!=4);	
}

void ingresardatos(string na){
	int id_est;
	string nombre_est;
	float nota_est;
	
	cout<<"Ingrese el codigo del estudiante: "<<endl;
	cin>>id_est;
	fflush(stdin);
	cout<<"Ingrese el Nombre del estudiante: "<<endl;
	getline(cin,nombre_est);
	cout<<"Ingrese la Nota del estudiante: "<<endl;
	cin>>nota_est;
	
	ofstream archivo;
	fflush(stdin); 
	archivo.open(na.c_str(),ios::app);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	archivo<<nombre_est<<"\t"<<id_est<<"\t"<<nota_est<<endl;
	archivo.close();
}

void leer_archivo(string na){
	ifstream archivo;
	fflush(stdin);
	archivo.open(na.c_str(),ios::in); 
	if(archivo.fail()){
		cout<<"  No se pudo abrir el archivo";
		exit(1);
	}
	int lineas;
	string s;
	while (getline(archivo, s))
        lineas++;
    archivo.close();
    
    estudiante recordset[lineas];
	archivo.open(na.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo...";
		exit(1);
	}	
	
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
            break;
        }
        archivo>>recordset[i].nombre>>recordset[i].id>>recordset[i].nota;
	}
    archivo.close();
    for (int i = 0; i < lineas; i++){
    	cout<<recordset[i].id<<recordset[i].nombre<<recordset[i].nota<<endl;
	}
	system("Pause");
}
