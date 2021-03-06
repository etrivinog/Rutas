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
   
   //Se marca el �ltimo cliente como null para saber que ya no hay mas clientes
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
   //Se marca la �ltima ruta como nula para indicar que no hay m�s rutas en el vector
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

void actualizarRutas(Ruta rutas[]){
	//Este m�todo actualiza todas ras rutas
	
	//variable archivo
	ofstream archivo;
	
	//Crear el archivo
	archivo.open("rutas.csv");
	
	//Variable para recorrer las rutas
	int i=0;
	//Variable para concatenar la ruta
	string ruta, cupo,disponible, ocupada, precio;
	//Recorrer el vector de rutas
	while(rutas[i].codigo != "\0"){
		
		//Convertir entero a string para poder concatenarlo
		cupo = static_cast<std::ostringstream*>(&(std::ostringstream() << rutas[i].cupo))->str();
		disponible = static_cast<std::ostringstream*>(&(std::ostringstream() << rutas[i].disponible))->str();
		ocupada = static_cast<std::ostringstream*>(&(std::ostringstream() << rutas[i].ocupada))->str();
		precio = static_cast<std::ostringstream*>(&(std::ostringstream() << rutas[i].precio))->str();
		
		ruta = ""+rutas[i].codigo+","+rutas[i].rutas+","+rutas[i].origen+","+rutas[i].destino
				+","+rutas[i].disponibilidad+","+rutas[i].tipo+","+rutas[i].hora
				+","+cupo+","+disponible+","+ocupada
				+","+rutas[i].fecha+","+precio+"\n";
		
		//Escribir la ruta en el archivo
		archivo << ruta;
		
		//Aumenta la variable
		i++;
		
	}
	
	archivo.close();
	
}

void comprar(string codigoRuta, Ruta rutas[], cliente cliente1){
	
	//Variable para recorrer las rutas
	int i = 0;
	string medioDePago;//Medio de pago
	//Ciclo para recorrer las rutas
	while(rutas[i].codigo != "\0"){
		
		//Si la ruta actual es la ruta de la que se quiere comprar
		if(rutas[i].codigo == codigoRuta){
			
			//Si la ruta a�n tiene cupos disponibles
			if(rutas[i].disponible > 0){
				//Se resta un cupo disponible a la ruta
				rutas[i].disponible--;
				//Se aumenta un cupo ocupado a la ruta
				rutas[i].ocupada++;
				
				do{
					
					cout<<"ESCOGA UN MEDIO DE PAGO:\n\n";
					cout<<"1. Efectivo\n";
					cout<<"2. Tarjeta de credito\n";
					cout<<"3. Tarjeta debito\n";
					cout<<"INGRESE UNA OPCION: ";
					cin>>medioDePago;
					
					if(medioDePago == "1"){
						medioDePago = "EFECTIVO";
					}else if(medioDePago == "2"){
						medioDePago = "TARJETA DE CREDITO";
					}else if(medioDePago == "3"){
						medioDePago = "TARJETA DEBITO";
					}
					
				}while(medioDePago != "EFECTIVO" && medioDePago != "TARJETA DE CREDITO" && medioDePago != "TARJETA DEBITO");
				
				srand(time(NULL));
				
				int tiquete = rand();
				
				cout<<"\n\n�TIQUETE COMPRADO CON EXITO!\n\n";
				cout<<"Detalles de factura:\n";
				cout<<"-------------------------------------------------------\n";
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
				cout<<"-------------------------------------------------------\n";
				
				//Si se ha la cantidad de silla ocupadas
				//es igual al cupo m�ximo, se indica que
				//la ruta no est� disponible
				if(rutas[i].ocupada == rutas[i].cupo){
					rutas[i].disponibilidad = "false";
				}
								
				//Actualizar archivo de rutas
				actualizarRutas(rutas);
				
			}else{
				//Si no tiene cupos disponibles, se da un mensaje de error
				cout<<"\n\n�LO SENTIMOS, ESTA RUTA NO TIENE CUPOS DOSPONIBLES!\n";
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
	cout<<"\nINGRESE UN ORIGEN: ";
	cin>>origen;
	cout<<"INGRESE UN DESTINO: ";
	cin>>destino;
	cout<<"INGRESE UNA FECHA (Ej: 02-dic): ";
	cin>>fecha;
	
		
	cout<<"RUTAS ENCONTRADAS:"<<endl<<endl;
	cout<<"ID\tORIGEN\tDESTINO\tTIPO\tHORA\tCUPOS\tFECHA\tPRECIO"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
	
	//Variable para �ndice del vector
	int i = 0;
	//Variable para saber si se encontraron o no rutas disponibles
	int rutasEncontradas = 0;
	//Recorrer todas las rutas
	while(rutas[i].codigo != "\0"){
		
		//Compara el origen, el destino y la fecha cada ruta con los datos ingresados
		//y verifica que est� disponible
		if(rutas[i].origen == origen && rutas[i].destino == destino && rutas[i].fecha == fecha && rutas[i].disponibilidad == "true"){
			
			//Mostrar informaci�n de la ruta
			cout<<rutas[i].codigo<<" "<<rutas[i].rutas<<" "<<rutas[i].origen<<" ";
			cout<<rutas[i].destino<<" "<<rutas[i].disponibilidad<<" "<<rutas[i].tipo<<" ";
			cout<<rutas[i].hora<<" "<<rutas[i].cupo<<" "<<rutas[i].disponible<<" ";
			cout<<rutas[i].ocupada<<" "<<rutas[i].fecha<<" "<<rutas[i].precio<<endl;
			
			//Se dice que se encontr� una ruta disponible
			rutasEncontradas++;
			
		}
		
		//Se aumenta el contador
		i++;
		
	}
	
	//Si no se encuentran rutas que cumplan con los criterios
	if(rutasEncontradas == 0){
		
		//Se muestra un mensaje dicendo que no se encontraron rutas que
		//cumplan con los criterios
		cout<<"\n\nNo se encontraron rutas que cumplan las condiciones\n\n";
		system("PAUSE");
		
		//Se sale de la funci�n
		return;
		
	}
	
	char opc;
	string codigo;
	
	//Ciclo para comprar tiquetes
		//Pregunta si desea comprar un tiquete
		cout<<"�\nCOMPRAR TIQUETE?\n";
		cout<<"\n1. SI\n";
		cout<<"2. NO\n";
		
		cout<<"\nINGRESE UNA OPCION: ";
		cin>>opc;
		
	do{
		//Si el usuario deea comprar
		if(opc == '1'){
			
			//Se pide el c�digo de la ruta que desea comprar
			cout<<"\nINGRESE EL C�DIGO DE LA RUTA: ";
			cin>>codigo;
			
			//Se ejecuta la funci�n de hacer la compra
			comprar(codigo,rutas,cliente1);
			
			//Pregunta si desea comprar otro tiquete
			cout<<"\n�DESEA COMPRAR OTRO TIQUETE?\n";
			cout<<"1. SI\n";
			cout<<"2. NO\n";
			cout<<"INGRESE UNA OPCI�N: ";
			cin>>opc;
			
		}else{
			//Si no desea comprar, se sale de la funci�n
			return;
		}
		
		
	}while(opc == '1');//Se repite si la opci�n es 1.
	
}

bool iniciarAdmin(){
	
	string usuario, password;
	
	cout<<"INGRESE USUARIO: ";
	cin>>usuario;
	cout<<"INGRESE PASSWORD: ";
	cin>>password;
	
	if(usuario == "mafe" && password == "1234"){
		return true;
	}else{
		return false;
	}
	
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
		
		//Comparar el Usuario y la contrase�a
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
	
	//Si llega a esta punto es porque no hubo alg�n cliente con el usuario
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

void archivarcliente(string linea1){
	string frase;
	ofstream archivo;
	archivo.open("clientes.csv",ios::app);
  	archivo << linea1;
	archivo.close();
}

int buscarcliente(cliente clientes[], string id1){//manda la posici? del elemento buscado, sino retorna -1
	int i=0;
	while(clientes[i].Usuario != "\0"){
		if(clientes[i].Usuario == id1){
			return i;
		}
		i++;
	}
	return -1;
}

void menu2(int &opc){
	
	cout<<"1. CONSULTAR RUTAS DISPONIBLES POR ORIGEN-DESTINO\n";
	cout<<"2. VER DETALLE DE LA RUTA POR ID\n";
	cout<<"3. COMPRAR TIQUETE\n";
	cout<<"\nINGRESE UNA OPCION: ";
	cin>>opc;
	
}

void consultarRutaPorId(Ruta rutas[]){
	string codigo;
	
	cout<<"\n\nINGRESE EL CODIGO DE LA RUTA: ";
	cin>>codigo;
	
	int i=0;
	while(rutas[i].codigo != "\0"){
		
		if(rutas[i].codigo == codigo){
			
			cout<<rutas[i].codigo<<" "<<rutas[i].rutas<<" "<<rutas[i].origen<<" ";
			cout<<rutas[i].destino<<" "<<rutas[i].disponibilidad<<" "<<rutas[i].tipo<<" ";
			cout<<rutas[i].hora<<" "<<rutas[i].cupo<<" "<<rutas[i].disponible<<" ";
			cout<<rutas[i].ocupada<<" "<<rutas[i].fecha<<" "<<rutas[i].precio<<endl;
			
			break;
		}
		i++;
	}
	
}


void numeroreservas(Ruta rutas[]){
	int i=0;
	cout<<endl;
	while(rutas[i].codigo != "\0"){
		cout<<"PARA LA RUTA "<<rutas[i].codigo<<"SE HAN HECHO "<<rutas[i].disponible<<" RESERVAS"<<endl;
		i++;
	}
}


void origendestino(Ruta rutas[]){//Para una lista ordenada por origen-destino
	int i=0, cont1=0;
	cout<<"Origen \t  Destino \t  Numero de reservas"<<endl;
	cout<<"---------------------------------------------"<<endl;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="bogota" && rutas[i].destino=="cartagena"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Bogota   \t  Cartagena \t "<<cont1<<endl;
	
	i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="cartagena" && rutas[i].destino=="bogota"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Cartagena \t  Bogota \t "<<cont1<<endl;
	
	i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="bogota" && rutas[i].destino=="medellin"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Bogota   \t  Medellin \t "<<cont1<<endl;
	
	i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="medellin" && rutas[i].destino=="bogota"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Medellin \t  Bogota \t "<<cont1<<endl;
	
		i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="cartagena" && rutas[i].destino=="medellin"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Cartagena \t  Medellin \t "<<cont1<<endl;
	
		i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="medellin" && rutas[i].destino=="cartagena"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Mededellin \t  Cartagena \t "<<cont1<<endl;
	
		i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="cartagena" && rutas[i].destino=="caracas"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Cartagena \t  Caracas \t "<<cont1<<endl;
	
		i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="bogota" && rutas[i].destino=="caracas"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Bogota   \t  Caracas \t "<<cont1<<endl;
	
		i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="caracas" && rutas[i].destino=="bogota"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Caracas \t  Bogota \t "<<cont1<<endl;
	
		i=0, cont1=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].origen=="caracas" && rutas[i].destino=="cartagena"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<"Caracas \t  Cartagena \t "<<cont1<<endl;
}


void viajes(Ruta rutas[]){
	int i=0, cont1=0, cont2=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].destino!="caracas"){
			cont1+=rutas[i].disponible;
		}
		i++;
	}
	cout<<cont1<<" viajaron en el interior del pais"<<endl;
	
	i=0;
	while(rutas[i].codigo != "\0"){
		if(rutas[i].destino=="caracas"){
			cont2+=rutas[i].disponible;
		}
		i++;
	}
	cout<<cont2<<" viajaron al extranjero "<<endl<<endl;
	
	cout<<"EN total viajaron: "<<cont1+cont2<<" PAsajeros"<<endl<<endl;
}


// salida: en la funcion main se llaman las funciones anteriormente declaradas y se imprimen los datos
int main(){
  	// se declaran la variables 
  	cliente clienteSesion;
  	int opc=0,opc3=0;
  	
  	bool sesion;
  	
  	cliente clientes[1000];
  	Ruta rutas[1000];
  
  	//administrador a[100];
  	cargardatosc(clientes);
  	cargardatosr(rutas);
  
  	menu(opc);
  	
	if(opc == 1){//Si se autentic� como cliente
  		
  		//Si iniciar usuario devulve false hubo un error en el inicio de sesi�n,
  		//Si devuelve true, inici� sesi�n correctamente.
  		sesion = iniciarUsuario(clientes,clienteSesion);
  		
  		if(sesion == true){
  			string opc2;
  			for(;;){
  				
  				menu2(opc3);
  				if(opc3 == 1){
					consultarRuta(rutas, clienteSesion);
				}else if(opc3 == 2){
					consultarRutaPorId(rutas);
				}else if(opc3 == 3){
					
					string codigo;
					cout<<"\n\nINGRESE EL CODIGO DE LA RUTA: ";
					cin>>codigo;
					
					comprar(codigo,rutas,clienteSesion);
				}
				
				cout<<"\n\n�DESEA SALIR?\n";
				cout<<"1. SI\n";
				cout<<"OTRA TECLA. NO\n";
				cout<<"INGRESE UNA OPCION:";
				cin>>opc2;
				
				if(opc2 == "1"){
					break;
				}
				
			}
		}
		else
		{
			cout<<"\n\nVERIFIQUE LOS DATOS DE INICIO DE SESI�N\n\n";
		}
  		
	}else if(opc == 2){//Si se autentic� como administrador
		
		sesion = iniciarAdmin();
		if(sesion == true){
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
					case 4:
				system("cls");
					cout<<"LISTADO DE RESERVAS"<<endl<<endl;
					numeroreservas(rutas);
					system("pause");					
					break;
				case 5:
				system("cls");
					cout<<"TOTAL DE RESERVAS ORIGEN-DESTINO"<<endl<<endl;
					origendestino(rutas);
					system("pause");					
					break;
				case 6:
				system("cls");
					cout<<"ENUMERAR VIAJES INTERNACIONALES Y NACIONALES"<<endl<<endl;
					viajes(rutas);
					system("pause");					
					break;
				default: break;
				}
			}
		}else
		{
			cout<<"\n\nVERIFIQUE LOS DATOS DE INICIO DE SESI�N\n\n";
		}
	}else{//Opci�n salir
  		cout<<"::GRACIAS POR CONSULTAR NUESTRO MENU::"<<endl;// se imprime un mensaje de salida
  	}
  return 0;
}
