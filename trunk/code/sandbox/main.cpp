/*
	Esto es un archivo de prueba en desarrollo.

Author: Roberto Herrera Esteban
Date: 18/03/14
Last change: 18/03/14



*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

#define size 126
using namespace std;
//using namespace space;

int main() {

	string nombre;
	cout << "Introduze el nombre del archivo a cargar" << endl;
	cin >> nombre;
	nombre = nombre + ".txt";
	char *nombreFichero = strdup(nombre.c_str());
	/// Buffer de datos
	char dato[size];
	for(int i=0; i < size ; i++){
            dato[i]='\0';
    }
	int nlineas = 0;
	int npos = 0;
//	char c;
    int i_lectura = 0;
	ifstream fichero;
	fichero.open(nombreFichero,ios::in);
	//
    if(fichero.good()){
		while(!fichero.eof()){
			fichero.getline(dato,size,'\n');
			nlineas++;
			npos=0;
			for(int i=0;i<size;i++){ 
            //while(dato[i_lectura]!= '}'){
/*				if(dato[i]=='\n'){             
					nlineas++;
				}
				*/
				cout << dato[i];
				if(dato[i]==','){
					npos++;
				}
            //i_lectura++;
			}
			cout << endl;
			
		}
		//
		cout << endl << nlineas << "   " << npos << endl << endl;
		//numero de lineas, tamaño de dato
		char vtime[nlineas][8];
		for (int i = 0; i < nlineas ; i++){
            for(int j = 0; j < 8; j++){
                    vtime[i][j]=' ';
            }
        }
		//numero de lineas, posicion del dato, tamaño de dato
		char vpos[nlineas][npos][8];
		for (int i = 0; i < nlineas ; i++){
            for(int j = 0; j < npos; j++){
                    for(int k = 0; k<8 ;k++){
                            vpos[i][j][k]=' ';
                            }
                    }
        }

		int linea=-1;
		int iterator=0;
		
		int ic=0;
		
		//ponerse al principio del fichero   ??
		//fichero.close();
		//ifstream fichero_1;
	    //fichero_1.open(nombreFichero,ios::in);
	    fichero.clear();
	    fichero.seekg(ios::beg);
		cout << "inicio" << endl << endl;
		
		
		while(!fichero.eof()){
                              cout << endl << "pasada" << endl;
			fichero.getline(dato,size,'\n');
			ic=0;
			iterator = 0;
			linea = linea++;
		//	int fin=1;
			for(int i=0;i<size;i++){
                    cout << "-'" << iterator << "'-";
                //cout << dato[i];
				if(dato[i]!=','){
                 
					if(dato[i]=='{'){
                                     //no hacer nada
                    }else if(dato[i]=='}'){
					//	fin=0;
					cout << "ruptura" << endl;
					break;
					cout << "no se deberia ver";
					}else{
						//tiempo
						if(ic==0){
							vtime[linea][iterator]=dato[i];
							cout <<vtime[linea][iterator] ;
							iterator++;
						//posiciones
                        }else if (ic<=nlineas){
							vpos[linea][ic-1][iterator] = dato[i];						
							cout << vpos[linea][ic-1][iterator] ;
							iterator++;
						}
					}
                 
				}else{
					//aumento la posicion del vector de posiciones o tiempo
					ic++;
					if(ic==0){
							vtime[linea][iterator]='\0';			
							cout <<vtime[linea][iterator] ;
							iterator++;
						//posiciones
						}else{
							vpos[linea][ic-1][iterator] = '\0';							
							cout << vpos[linea][ic-1][iterator] ;
							iterator++;
						}
					//poscion donde guardo la informacion
					iterator=0;
					cout << " ";
				}
				
			}
			
			
		}
		//cierro fichero
		fichero.close();
		
		for(int i=0;i<nlineas;i++){
                 cout << endl << "Linea: ";        
                int j=0;
                while(vtime[i][j]!='\0'){
                
                cout << vtime[i][j];     
                }  
        }
		
		// nuevo fichero de salida
		string nombr_e;
		string robot;
		cout << "Introduze un nombre para exportar el archivo" << endl;
		cin >> nombr_e;
		cout << "Nombre del objeto de la case Robot" << endl;
		cin >> robot;
		
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" ; 
		cout << endl << endl << " pene" << vtime[0][0] << endl << endl;
		string nombr_exp = nombr_e + "_exported.txt";
		char *nombreExp = strdup(nombr_exp.c_str());
        ofstream exportar;
        exportar.open(nombreExp,ios::out|ios::trunc);
		
		//nombre de la funcion
		exportar << "void " << nombr_e << "(){" << endl << endl;
		//declaracion
		for(int i= 0; i < nlineas;i++){
		//tiempo
			exportar << "int time_" << i+1 << " = " ;
			int x=0;
			while(vtime[i][x]!='\0'){
                    
                    cout << vtime[i][x];
				exportar << vtime[i][x];
				x++;
			}	
			exportar << ";" << endl;
			//posiciones
			exportar << "int vector_" << i+1 << "[] = {";
			for(int j=0;j<npos;j++){
				//ultima
				if(j==npos-1){
					for(int y = 0; y < 8; y++){
						exportar << vpos[i][j][y];
					}
					exportar << "};" << endl;
				}else{
					for(int y = 0; y < 8; y++){
						exportar << vpos[i][j][y];
					}
					exportar << ",";
				}
			}
		}
		// movimientos
		exportar << endl << endl;
		for(int i= 0; i <nlineas;i++){
			exportar << robot << ".move(time_" << i+1 << ", vector_" << i+1 << ");" << endl;
		}
		//fin
		exportar << endl << "}" ;
		
		exportar.close();
		
		cout << "Exportacion finalizada" << endl << endl;
		
		
		

			
	
	}else{
		cout << "Fallo al abrir el archivo" << endl << endl;
	}
	int espera;
    cin >> espera;
return 0;
}



