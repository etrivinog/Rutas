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
 //se crea la estructura para consultar las rutas
 struct consultar{
  string Origen;
  string Destino;
  string Fecha;
 };
 
 struct detalle{
   string codigo;
 };
  // se crea la estuctura de las rutas
struct inforuta{
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
 void obtcliente(int &n){
   ifstream f;  string linea;
   f.open("clientes.csv");
   while(!f.eof()){
     getline(f,linea);
     //cout<<linea<<endl;
     n++;
   }
   f.close();
   cout<<"SE ENCUENTRAN REGISTRADOS: "<<n<<" CLIENTES"<<endl;
 }

 void cargardatosc(cliente c[], int &n){
   ifstream f; string linea; char s=',';
   f.open("clientes.csv");
   for(int i=0;i<n;i++){
     getline(f, linea, s);
     c[i].Usuario=linea;
     getline(f, linea, s);
     c[i].Password=linea;
     getline(f, linea,s);
     c[i].Nombre=linea;
     getline(f, linea);
     c[i].Apellido=linea;
   	 //cout<<c[i].Usuario<<" "<<c[i].Password<<" "<<c[i].Nombre<<" "<<c[i].Apellido<<endl;
   }
   f.close();
 }
 //se cargan los datos del archivo rutas
 void obtrutas(int &n){
   ifstream f;  string linea;
   n=0;
   f.open("rutas.csv");
   while(!f.eof()){
     getline(f,linea);
     n++;
   }
   f.close();
   cout<<"HAY : "<<n<<" RUTAS"<<endl;
 }

 void cargardatosr(inforuta k[], int &n){
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
   f.close();
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
  // se crea una funcion que pida los datos para la consulta de rutas
void consultarutas(consultar d[], int &n, string ori, string dest, string fec){
  for(int i=0; i<n; i++){
    cout<<"ORIGEN:";
    cin>>ori;
    cout<<"DESTINO:";
    cin>>dest;
    cout<<"FECHA (ejemplo:02-dic):";
    cin>>fec;
  }
   
 }
 
 // se crea un menu inicial que determina que tipo de usuario ingresa a la plataforma
void menu ( int &n ){   
  cout<<":::BIEMBENIDO A EL SISTEMA DE FACTURACION :::"<<endl;
  cout<<"1- USUARIO"<<endl;
  cout<<"2-ADMINISTRADOR"<<endl;
  cout<<"3-EXIT"<<endl;
  cout<<"INGRESE SU OPCION:";
  cin>>n;
   
  //system("PAUSE");
  //system("CLS");
}
//funcion para elmenu de  pago del pasaje 
void pago(int &n){
  cout<<"INDIQUE LA FORMA DE PAGO DEL PASAJE:"<<endl;
  cout<<"1-TARJETA DE CREDITO"<<endl;
  cout<<"2-TARJETA DEBITO"<<endl;
  cout<<"3-EFECTIVO"<<endl;
  
}
// esta funcion es la encargada de el menu de funcionamiento de un cliente
void operacioncliente( cliente c[], int &n){
  cout<<":::OPCIONES DEL USUARIO:::"<<endl;
  cout<<"1-CONSULTAR LAS RUTAS DISPONIBLES POR DESTINO"<<endl;
  cout<<"2-VER DETALLE DE LA RUTA"<<endl;
  cout<<"3-CONSULTAR LA CANTIDAD DE ASIENTOS DISPONIBLES"<<endl;
  cout<<"4-COMPRAR UN TIQUETE"<<endl;
  
  cin>>n;
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
void detalleruta(detalle det[], string j){
   cout<<"INGRESE EL CODIGO DE LA RUTA"<<endl;
   cin>>j;
   
 }

// salida: en la funcion main se llaman las funciones anteriormente declaradas y se imprimen los datos
int main(){
  // se declaran la variables 
  int u=0;
  string j;
  string nom;
  string ap;
  int id;
  string pas; 
  string ori;
  string dest;
  string fec;
  ifstream f;
  //char fd;
  string us;
  cliente c[100];
  inforuta k[100];
  consultar d[100];
  detalle det[100];
  //administrador a[100];
  obtcliente(u);
  cargardatosc(c,u);
  obtrutas(u);
  cargardatosr(k,u);
  
  menu(u);
  	
  	//Probar Los clientes
  	cout<<c[1].Usuario<<" "<<c[1].Password<<" "<<c[1].Nombre<<" "<<c[1].Apellido<<endl;
  	//Probar las rutas
	cout<<k[1].codigo<<" "<<k[1].rutas<<" "<<k[1].origen<<" ";
	cout<<k[1].destino<<" "<<k[1].disponibilidad<<" "<<k[1].tipo<<" ";
	cout<<k[1].hora<<" "<<k[1].cupo<<" "<<k[1].disponible<<" ";
	cout<<k[1].ocupada<<" "<<k[1].fecha<<" "<<k[1].precio<<endl;
	
	if(u == 1){
  	
	}else if(u == 2){
	
	}else{
  	cout<<"::GRACIAS POR CONSULTAR NUESTRO MENU::"<<endl;// se imprime un mensaje de salida
  } 
  if(u==1){// se crea la condicion al ser escogido la opcion 1 del menu 
      
     
  }
  else if(u==2){// se crea la condicion al ser operacionadministrador
    
  }
  else {
    cout<<"::GRACIAS POR CONSULTAR NUESTRO MENU::"<<endl;// se imprime un mensaje de salida
  }
  return 0;
}
