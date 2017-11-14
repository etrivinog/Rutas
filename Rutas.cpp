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
#include <time.h>
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

struct Reserva{
	
	string ruta;
	string origen;
	string destino;
	string identicifacionCliente;
	//Se sabe si el cliente viaja al extranjero o al interior des pais
	//verificando el destino.
	
}reservas[1000];

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
   c[i].Usuario = "\0";
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
   
 // se crea un menu inicial que determina que tipo de usuario ingresa a la plataforma
void menu ( int &n ){   
  cout<<"\n\n:::BIENVENIDO A EL SISTEMA DE FACTURACION :::"<<endl;
  cout<<"1- USUARIO"<<endl;
  cout<<"2-ADMINISTRADOR"<<endl;
  cout<<"3-EXIT"<<endl;
  cout<<"\nINGRESE SU OPCION:";
  cin>>n;
   
  //system("PAUSE");
  system("CLS");
}
//funcion para elmenu de  pago del pasaje 
void pago(string &n){
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

void comprar(string codigoRuta, Ruta rutas[], cliente cliente1){
	
	//Variable para recorrer las rutas
	int i = 0;
	string medioDePago;//Medio de pago
	//Ciclo para recorrer las rutas
	while(rutas[i].codigo != "\0"){
		
		//Si la ruta actual es la ruta de la que se quiere comprar
		if(rutas[i].codigo == codigoRuta){
			
			//Si la ruta aún tiene cupos disponibles
			if(rutas[i].disponible > 0){
				//Se resta un cupo disponible a la ruta
				rutas[i].disponible--;
				//Se aumenta un cupo ocupado a la ruta
				rutas[i].ocupada++;
				
				cout<<"ESCOGA UN MEDIO DE PAGO:\n\n";
				cout<<"1. Efectivo\n";
				cout<<"2. Tarjeta\n";
				cout<<"INGRESE UNA OPCION: ";
				cin>>medioDePago;
				
				if(medioDePago == "1"){
					medioDePago = "EFECTIVO";
				}else if(medioDePago == "2"){
					medioDePago = "TARJETA";
				}
				
				srand(time(NULL));
				
				int tiquete = rand();
				
				cout<<"\n\n¡TIQUETE COMPRADO CON EXTIO!\n\n";
				
				cout<<"Empresa:                Los mas rapidos y furiosos 2\n";
				cout<<"Codigo del tiquete:     "<<tiquete<<endl;
				cout<<"Origen:                 "<<rutas[i].origen<<endl;
				cout<<"Destino:                "<<rutas[i].destino<<endl;
				cout<<"Fecha de viaje:         "<<rutas[i].fecha<<endl;
				cout<<"Hora de viaje:          "<<rutas[i].hora<<endl;
				cout<<"Precio:                 "<<rutas[i].precio<<endl;
				cout<<"Silla:                  "<<rutas[i].ocupada<<endl; //La silla es la ocupada
				cout<<"Forma de pago:          "<<medioDePago<<endl;
				cout<<"Nombre Pasajero:        "<<cliente1.Nombre<<endl;
				cout<<"Documento del pasajero: "<<cliente1.Usuario<<endl; //Es la identificacion
				
				//Si se ha la cantidad de silla ocupadas
				//es igual al cupo màximo, se indica que
				//la ruta no està disponible
				if(rutas[i].ocupada == rutas[i].cupo){
					rutas[i].disponibilidad = "false";
				}
				
				//Se crea la reserva
				int x = 0;
				while(reservas[x].destino != "\0"){
					x++;//Aumenta la x
				}
				
				//Actualizar archivo de rutas
				
			}else{
				//Si no tiene cupos disponibles, se da un mensaje de error
				cout<<"\n\n¡LO SENTIMOS, ESTA RUTA NO TIENE CUPOS DOSPONIBLES!\n";
			}
			
			//Terminar el ciclo de recorrer las rutas
			break;
			
		}
		
		//Aumenta la variable
		i++;
		
	}
	
}

void consultarRuta(Ruta rutas[],cliente cliente1){
	
	string origen, destino, fecha;
	cout<<"..::CONSULTA DE RUTAS::..";
<<<<<<< HEAD
	cout<<"INGRESE UN ORIGEN: ";
=======
>>>>>>> 06f7b704619affa8c47355106b282aca64c7bda6
	cout<<"\nINGRESE UN ORIGEN: ";
	cin>>origen;
	cout<<"INGRESE UN DESTINO: ";
	cin>>destino;
	cout<<"INGRESE UNA FECHA (Ej: 02-dic): ";
	cin>>fecha;
	
		
	cout<<"RUTAS ENCONTRADAS:"<<endl<<endl;
	cout<<"ID\tORIGEN\tDESTINO\tTIPO\tHORA\tCUPOS\tFECHA\tPRECIO"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
	
	//Variable para èndice del vector
	int i = 0;
	//Recorrer todas las rutas
	while(rutas[i].codigo != "\0"){
		
		//Compara el origen, el destino y la fecha cada ruta con los datos ingresados
		//y verifica que esté disponible
		if(rutas[i].origen == origen && rutas[i].destino == destino && rutas[i].fecha == fecha && rutas[i].disponibilidad == "true"){
			
			//Mostrar información de la ruta
			cout<<rutas[i].codigo<<" "<<rutas[i].rutas<<" "<<rutas[i].origen<<" ";
			cout<<rutas[i].destino<<" "<<rutas[i].disponibilidad<<" "<<rutas[i].tipo<<" ";
			cout<<rutas[i].hora<<" "<<rutas[i].cupo<<" "<<rutas[i].disponible<<" ";
			cout<<rutas[i].ocupada<<" "<<rutas[i].fecha<<" "<<rutas[i].precio<<endl;
			
		}
		
		//Se aumenta el contador
		i++;
		
	}
	
	char opc;
	string codigo;
	
	//Ciclo para comprar tiquetes
		//Pregunta si desea comprar un tiquete
		cout<<"¿\nCOMPRAR TIQUETE?\n";
		cout<<"\n1. SI\n";
		cout<<"2. NO\n";
		
		cout<<"\nINGRESE UNA OPCION: ";
		cin>>opc;
		
	do{
		//Si el usuario deea comprar
		if(opc == '1'){
			
			//Se pide el còdigo de la ruta que desea comprar
			cout<<"\nINGRESE EL CÓDIGO DE LA RUTA: ";
			cin>>codigo;
			
			//Se ejecuta la funciòn de hacer la compra
			comprar(codigo,rutas,cliente1);
			
			//Pregunta si desea comprar otro tiquete
			cout<<"\n¿DESEA COMPRAR OTRO TIQUETE?\n";
			cout<<"1. SI\n";
			cout<<"2. NO\n";
			cout<<"INGRESE UNA OPCIÓN: ";
			cin>>opc;
			
		}else{
			//Si no desea comprar, se sale de la función
			return;
		}
		
		
	}while(opc == '1');//Se repite si la opción es 1.
	
}

bool iniciarUsuario(cliente clientes[], cliente &c){
	
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
			
			//Carga los datos en sesion
			c.Nombre   = clientes[i].Nombre;
			c.Apellido = clientes[i].Apellido;
			c.Usuario  = clientes[i].Usuario;
			
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

<<<<<<< HEAD
int buscarcliente(cliente clientes[], string id1){//manda la posici�n del elemento buscado, sino retorna -1
	int i=0;
	while(clientes[i].Usuario != "\0"){
		if(clientes[i].Usuario == id1){
			return i;
		}
		i++;
	}
	return -1;
}

=======
void archivarcliente(string linea1){
	string frase;
	ofstream archivo;
	archivo.open("clientes.csv",ios::app);
  	archivo << linea1;
	archivo.close();
}


>>>>>>> 06f7b704619affa8c47355106b282aca64c7bda6
// salida: en la funcion main se llaman las funciones anteriormente declaradas y se imprimen los datos
int main(){
  	// se declaran la variables 
  	cliente clienteSesion;
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
  	reservas[0].destino = "\0"; //Declaramos la primera reserva nula;
  
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
	
	if(opc == 1){//Si se autenticó como cliente
  		
  		//Si iniciar usuario devulve false hubo un error en el inicio de sesión,
  		//Si devuelve true, inició sesión correctamente.
  		sesion = iniciarUsuario(clientes,clienteSesion);
  		
  		if(sesion == true){
  			string opc2;
  			for(;;){
				consultarRuta(rutas, clienteSesion);
				
				cout<<"\n\n¿DESEA SALIR?\n";
				cout<<"1. SI\n";
				cout<<"OTRA TECLA. NO\n";
				cout<<"INGRESE UNA OPCION:";
				cin>>opc2;
				
				if(opc2 != "1"){
					break;
				}
				
			}
		}
		else
		{
			cout<<"\n\nVERIFIQUE LOS DATOS DE INICIO DE SESIÓN\n\n";
		}
  		
	}else if(opc == 2){//Si se autenticó como administrador
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
					while(buscarcliente(clientes, id1) != -1){//mientras exista un elemento con ese id
						cout<<"\n\n\t...Ya existe ese usuario...\n\n";
						cout<<"INGRESE ID DE USUARIO: ";
						cin>>id1;
					}
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
					cout<<"\n...........GUARDADO EXITOSAMENTE................\n"<<endl;
					system("pause");
					break;
				case 2:
					system("cls");
					cout<<"LISTADO DE CLIENTES"<<endl<<endl;
					imprimirclientes(clientes);
					system("pause");					
					break;
				case 3:
					system("cls");
					cout<<"BUSCAR PERSONA POR ID"<<endl<<endl;
					cout<<"INGRESE ID A BUSCAR: ";
					cin>>id1;
					pos=buscarcliente(clientes, id1);
					if(pos==-1){
						cout<<"\n\n\t...NO EXISTE ESE CLIENTE...\n\n";
					}else{
						cout<<"\n\n  ID                  PASSWORD                  NOMBRE                  APELLIDO"<<endl;
						cout<<"--------------------------------------------------------------------------------"<<endl;
						//cout<<clientes[i].Usuario
						cout<<clientes[pos].Usuario<<"                  "<<clientes[pos].Password<<"                  ";
						cout<<clientes[pos].Nombre<<"                  "<<clientes[pos].Apellido<<endl<<endl<<endl;	
					}										
					system("pause");
					break;
				default: break;
			}
		}
	}else{//Opción salir
  		cout<<"::GRACIAS POR CONSULTAR NUESTRO MENU::"<<endl;// se imprime un mensaje de salida
  	}
  return 0;
}
