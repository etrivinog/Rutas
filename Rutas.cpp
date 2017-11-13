/* 
* Autor:Daniela Segura Torres y marcela narvaez
* Fecha:03/11/2017
* Grupo:T 
* Tema:caso pasaje
*
*/
#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include <sstream>
using namespace std;
//inicio: se emplean las estructuras necesarias para los clientes y administradores

// se crea la estuctura de los datos de los clientes 
struct cliente{ 
  string Usuario;
  string Password;
  string Nombre;
  string Apellido;
 
 };
 
struct Admin{
	string identificacion;
	string password;
};
  // se crea la estuctura de las rutas
struct Ruta{
 string codigo;
 string rutas;
 string origen;
 string destino;
 string disponibilidad;
 string tipo;
 string hora;
 int cupo;
 int disponible;
 int ocupada;
 string fecha;
 float precio;
};

//se cargan los datos del archivo clientes 
 void cargardatosc(cliente c[]){
 	int i = 0;
   ifstream f; string linea; char s=',';
   f.open("clientes.csv");
   while(!f.eof()){
     getline(f, linea, s);
     c[i].Usuario=linea;
     getline(f, linea, s);
     c[i].Password=linea;
     getline(f, linea,s);
     c[i].Nombre=linea;
     getline(f, linea);
     c[i].Apellido=linea;
   	 //cout<<c[i].Usuario<<" "<<c[i].Password<<" "<<c[i].Nombre<<" "<<c[i].Apellido<<endl;
   	 i++;
   }
   
   //Se marca el ùltimo cliente como null para saber que ya no hay mas clientes
   //en el vector
   c[i].Usuario = '\0';
   cout<<"SE HAN CARGADO: "<<i<<" CLIENTES"<<endl;
   f.close();
 }
 //se cargan los datos del archivo rutas
 void cargardatosr(Ruta k[]){
   ifstream f; string linea; char s=',';
   f.open("rutas.csv");
   int i=0;
   while(!f.eof()){
     getline(f, linea, s);
     k[i].codigo=linea;
     getline(f, linea, s);
     k[i].rutas=linea;
     getline(f, linea,s);
     k[i].origen=linea;
     getline(f, linea, s);
     k[i].destino=linea;
     getline(f, linea, s);
     k[i].disponibilidad=linea;
     getline(f, linea, s);
     k[i].tipo=linea;
     getline(f, linea, s);
     k[i].hora=linea;
     getline(f, linea, s);
     k[i].cupo=atoi(linea.c_str());
     getline(f, linea,s);
     k[i].disponible=atoi(linea.c_str());
     getline(f, linea,s);
     k[i].ocupada=atoi(linea.c_str());
     getline(f, linea,s);
     k[i].fecha=linea;
     getline(f, linea);
     k[i].precio=atoi(linea.c_str());
     
     i++;
   }
   //Se marca la ùltima ruta como nula para indicar que no hay màs rutas en el vector
   k[i].codigo = "\0";
   f.close();
   cout<<"SE HAN CARGADO: "<<i<<" RUTAS"<<endl;
 }
   
 
 // se crea una funcion que pida los datos para el registro de un cliente
void datoscliente(cliente c[], int &n, string us, string pas){
  for(int i=0; i<n; i++){
    cout<<"USUARIO:";
    cin>>us;
    cout<<"PASSWORD:";
    cin>>pas;
  }
   
}
 
 // se crea un menu inicial que determina que tipo de usuario ingresa a la plataforma
void menu ( int &n ){   
  cout<<"\n\n:::BIEMBENIDO A EL SISTEMA DE FACTURACION :::"<<endl;
  cout<<"1- USUARIO"<<endl;
  cout<<"2-ADMINISTRADOR"<<endl;
  cout<<"3-EXIT"<<endl;
  cout<<"\nINGRESE SU OPCION:";
  cin>>n;
   
  //system("PAUSE");
  system("CLS");
}
//funcion para elmenu de  pago del pasaje 
void pago(int &n){
  cout<<"INDIQUE LA FORMA DE PAGO DEL PASAJE:"<<endl;
  cout<<"1-TARJETA DE CREDITO"<<endl;
  cout<<"2-TARJETA DEBITO"<<endl;
  cout<<"3-EFECTIVO"<<endl;
  
}

// esta funcion es la encargada de el menu de funcionamiento de un 
void operacionadministrador(int &opcion){
  cout<<":::OPCIONES DEL ADMINISTRADOR:::"<<endl;
  cout<<"1-VER DATOS DE TODOS LOS USUARIOS"<<endl;
  cout<<"2-BUSCAR PERSONAS POR IDENTIFICACION"<<endl;
  cout<<"3-BUSCAR PERSONAS POR APELLIDO"<<endl;
  cout<<"4-VER EL NUMERO DE RESERVAS REALIZADAS"<<endl;
  cout<<"5-VER EL NUMERO DE RESERVAS POR CIUDAD"<<endl;
  cout<<"6-VER EL NUMERO DE PERSONAS QUE SOLICITARON RESERVAS AL EXTRANJERO"<<endl;
  cout<<"7-VER EL NUMERO DE PERSONAS QUE SOLICITARON RESERVAS DENTRO DEL PAIS"<<endl;
  cin>>opcion;
}
void datosamd(string us, string pa){
    cout<<"USUARIO:";
    cin>>us;
    cout<<"PASSWORD:";
    cin>>pa;
    /*if(us= "mafe" and pa= 4321){
     operacionadministrador(n);
      
    }
    else{
      cout<<"USUARIO O CONTRASEÑA INCORECTA";
    }*/
}
void detalleruta(){
	string idRuta;
   	cout<<"INGRESE EL CODIGO DE LA RUTA"<<endl;
   	cin>>idRuta;
   
}

void consultarRuta(Ruta rutas[]){
	
	string origen, destino, fecha;
	cout<<"..::CONSULTA DE RUTAS::..";
	cout<<"INGRESE UN ORIGEN: ";
	cin>>origen;
	cout<<"INGRESE UN DESTINO: ";
	cin>>destino;
	cout<<"INGRESE UNA FECHA (Ej: 02-dic): ";
	cin>>fecha;
	
	//Variable para èndice del vector
	int i = 0;
	//Recorrer todas las rutas
	while(rutas[i].codigo != "\0"){
		
		//Compara el origen, el destino y la fecha cada ruta con los datos ingresados.
		if(rutas[i].origen == origen && rutas[i].destino == destino && rutas[i].fecha == fecha){
			
			cout<<"RUTAS ENCONTRADAS:"<<endl<<endl;
			
			//Mostrar información de la ruta
			cout<<rutas[i].codigo<<" "<<rutas[i].rutas<<" "<<rutas[i].origen<<" ";
			cout<<rutas[i].destino<<" "<<rutas[i].disponibilidad<<" "<<rutas[i].tipo<<" ";
			cout<<rutas[i].hora<<" "<<rutas[i].cupo<<" "<<rutas[i].disponible<<" ";
			cout<<rutas[i].ocupada<<" "<<rutas[i].fecha<<" "<<rutas[i].precio<<endl;
			
		}
		
		//Se aumeta el contador
		i++;
		
	}
	
}

bool iniciarUsuario(cliente clientes[]){
	
	string usuario, password;
	
	cout<<"INGRESE USUARIO: ";
	cin>>usuario;
	cout<<"INGRESE PASSWORD: ";
	cin>>password;
	
	//Variable para recorrer los clientes
	int i=0;
	//Recorrer los clientes
	while(clientes[i].Usuario != "\0"){
		
		//Comparar el Usuario y la contraseña
		if(clientes[i].Usuario == usuario && clientes[i].Password == password){
			
			//Si encuentra el cliente con ese id y con ese password
			cout<<"\n\nUSUARIO ENCONTRADO\n";
			system("PAUSE");
			//retorna true
			return true;
			
		}
		//Aumenta la variable para recorrer los clientes
		i++;
		
	}
	
	//Si llega a esta punto es porque no hubo algùn cliente con el usuario
	//y el password ingresados.
	//Retorna false
	return false;
	
}

void menuAdmin(){
	cout<<"OPCIONES PARA EL ADMINISTRADOR"<<endl<<endl;
	cout<<"1. REGISTRAR NUEVO USUARIO"<<endl;
	cout<<"2. LISTAR TODOS LOS USUARIO"<<endl;
	cout<<"3. BUSCAR PERSONA POR ID"<<endl;
	cout<<"4. VER EL TOTAL DE RESERVAS REALIZADAS POR CADA RUTA"<<endl;
	cout<<"5. VER EL TOTAL DE RESERVAS ORIGEN-DESTINO"<<endl;
	cout<<"6. ENUMERAR VIAJES INTERNACIONALES Y NACIONALES"<<endl;
	cout<<"7. SALIR"<<endl;	
	
	
}

void archivarcliente(string linea1){
	string frase;
	ofstream archivo;
	archivo.open("clientes.csv",ios::app);
  	archivo << linea1;
	archivo.close();
}

int contarclientes(cliente clientes[]){
	int i=0;
	while(clientes[i].Usuario != "\0"){
		i++;
	}
	return i;
}

void imprimirclientes(cliente clientes[]){
	int i=0;
	cout<<"  ID                  PASSWORD                  NOMBRE                  APELLIDO"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	while(clientes[i].Usuario != "\0"){
		//cout<<clientes[i].Usuario
		cout<<clientes[i].Usuario<<"                  "<<clientes[i].Password<<"                  ";
		cout<<clientes[i].Nombre<<"                  "<<clientes[i].Apellido<<endl;
		i++;
	}
}

// salida: en la funcion main se llaman las funciones anteriormente declaradas y se imprimen los datos
int main(){
  	// se declaran la variables 
  	int opc=0;
  	string j;
  	string nombre;
  	string apellido;
  	int id;
  	string password; 
  	string origen;
  	string destino;
  	string fecha;
  	ifstream f;
 	 //char fd;
  	string us;
  	
  	bool sesion;
  	
  	cliente clientes[1000];
  	Ruta rutas[1000];
  
  	//administrador a[100];
  	cargardatosc(clientes);
  	cargardatosr(rutas);
  
  	menu(opc);
  	
  	//Probar Los clientes
  	//cout<<clientes[1].Usuario<<" "<<clientes[1].Password<<" "<<clientes[1].Nombre<<" "<<clientes[1].Apellido<<endl;
  	//Probar las rutas
	/*cout<<rutas[1].codigo<<" "<<rutas[1].rutas<<" "<<rutas[1].origen<<" ";
	cout<<rutas[1].destino<<" "<<rutas[1].disponibilidad<<" "<<rutas[1].tipo<<" ";
	cout<<rutas[1].hora<<" "<<rutas[1].cupo<<" "<<rutas[1].disponible<<" ";
	cout<<rutas[1].ocupada<<" "<<rutas[1].fecha<<" "<<rutas[1].precio<<endl;*/
	
	if(opc == 1){//Si se autentic� como cliente
  		
  		//Si iniciar usuario devulve false hubo un error en el inicio de sesión,
  		//Si devuelve true, inició sesión correctamente.
  		sesion = iniciarUsuario(clientes);
  		
  		if(sesion == true){
			consultarRuta(rutas);
		}
		else
		{
			cout<<"\n\nVERIFIQUE LOS DATOS DE INICIO DE SESIÓN\n\n";
		}
  		
	}else if(opc == 2){//Si se autentic� como administrador
		int op=1, pos=0;
		string id1, password1, nombre1, apellido1, linea1="";
		while(op!=7){
			system("cls");
			menuAdmin();
			cin>>op;
			switch(op){
				case 1:
					system("cls");
					cout<<"INGRESAR UN NUEVO CLIENTE"<<endl<<endl;
					cout<<"INGRESE ID DE USUARIO: ";
					cin>>id1;
					do{					
						cout<<"INGRESE PASSWORD DE USUARIO (4 DIGITOS): ";
						cin>>password1;
					}while(password1.size()!=4);					
					cout<<"INGRESE NOMBRE DE USUARIO: ";
					cin>>nombre1;
					cout<<"INGRESE APELLIDO DE USUARIO: ";
					cin>>apellido1;	
					pos=contarclientes(clientes);
					clientes[pos].Usuario=id1;				
					clientes[pos].Password=password1;				
					clientes[pos].Nombre=nombre1;				
					clientes[pos].Apellido=apellido1;
					linea1='\n'+id1+','+password1+','+nombre1+','+apellido1;			
					archivarcliente(linea1);
					cout<<"GUARDADO EXITOSAMENTE"<<endl;
					system("pause");
					break;
				case 2:
					system("cls");
					cout<<"LISTADO DE CLIENTES"<<endl<<endl;
					imprimirclientes(clientes);
					system("pause");					
					break;
				case 3:
					break;
				default: break;
			}
		}
	}else{//Opci�n salir
  		cout<<"::GRACIAS POR CONSULTAR NUESTRO MENU::"<<endl;// se imprime un mensaje de salida
  	}
  return 0;
}
