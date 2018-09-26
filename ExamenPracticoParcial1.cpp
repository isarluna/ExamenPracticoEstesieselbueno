#include <iostream>
#include <conio.h>
using namespace std;
struct nodo{
	int dato;
	struct nodo *siguiente;
}*inicio,*aux,*actual,*anterior;
void insertarnodo(int);
void mostrarnodos();
void ordenarnodos();
int main(int argc, char** argv) {
	inicio=NULL;
	int opcion=1;
	int valor=0;
	do{
		cout<<"Elige una opcion"<<endl;
		cout<<"1.-Insertar nodo"<<endl;
		cout<<"2.-Mostrar nodos"<<endl;
		cout<<"3.-Ordenar nodos"<<endl;
		cout<<"4.-Salir"<<endl;
		cin>>opcion;
		if(opcion==1){
			cout<<"Introduce un valor: ";
			cin>>valor;
			insertarnodo(valor);
		}else if(opcion==2){
			mostrarnodos();
		}else if(opcion==3){
			ordenarnodos();
		}
	}while(opcion!=4);
	mostrarnodos();
	cin.get();
	return 0;
}
void insertarnodo(int valor){
	actual=inicio;
	if(actual==NULL){
			aux=new nodo();
			aux->dato=valor;
			aux->siguiente=NULL;
			inicio=aux;
	}else{
		while(actual->siguiente!=NULL)
		{
			actual=actual->siguiente;
			}		
		aux=new nodo();
		aux->dato=valor;
		aux->siguiente=NULL;
		actual->siguiente=aux;
	}
}
void mostrarnodos(){
	actual=inicio;
	while(actual!=NULL){
		cout<<actual->dato<<" ";
		actual=actual->siguiente;
	}
}
void ordenarnodos(){
	if(inicio!=NULL){		
		anterior=NULL;
		aux=NULL;
		actual=inicio;
		while((actual->siguiente!=NULL) && (actual->dato < actual->siguiente->dato)){							
				anterior=actual;
				actual=actual->siguiente;
		}
			if (actual->siguiente==NULL)
			{
				cout<<"Ordenacion terminada"<<endl;
			}else if(anterior==NULL){
				aux=actual;
				actual=actual->siguiente;
				inicio=actual;
				aux->siguiente=actual->siguiente;
				actual->siguiente=aux;
			}else{
				aux=actual;
				actual=actual->siguiente;
				anterior->siguiente=actual;
				aux->siguiente=actual->siguiente;
				actual->siguiente=aux;
			}
	}
}
