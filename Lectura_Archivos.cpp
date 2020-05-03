#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stack>

using namespace std;

int main(){
	stack<string> pila;
	fstream archivo("resgistro.txt");
	string letra;
	string renglon;
	int contador = 0;
	if(!archivo.is_open()){
			archivo.open("registro.txt", ios::in);
		}
	while (!archivo.eof()){
		letra = archivo.get();
		if(letra == "<"){
			renglon=letra;
				while(letra!=">"){
						letra=archivo.get();
						renglon += letra;
					}
				pila.push(renglon);	
				contador++;
			}
		if(letra!="<"){
			while(letra!="<"){
				letra= archivo.get();
				renglon += letra;
				}
			pila.push(renglon);
			contador++;
			}
	}
	
	for(int i=0; i<contador;i++){
		cout<<pila.top()<<"\n";
		pila.pop();
		}

	archivo.close();
	system("pause");

}
