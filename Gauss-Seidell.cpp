#include <iostream>
#include <windows.h>
#include <conio.h>

#define error 0.2

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* 	
	Método Gauss-Seidell
	
	Presentado por: 
		Edwin González, 
		Rolando Peña, 
		Christian Pinzón 
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ecuaciones[3][4];
int i, j, k, n;
float x, y, z;	// Variables para almacenar los valores previos en cada iteración
float incognitas[3]; // Variables
float pError[3]; // Porcentajes de error de las variables

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicio()
{
	cout << "\t\tMetodo de Gauss-Seidel" << endl << endl;
	cout << "\t\tA11x + A12y + A13z = B1" << endl;
	cout << "\t\tA21x + A22y + A23z = B2" << endl;
	cout << "\t\tA31x + A32y + A33z = B3" << endl << endl;
	k=0;
	
	for(i=0; i<3; i++)
	{
		cout << "Ecuacion " << i+1 << endl;
    	for(j=0; j<4; j++)
    	{
    		if(j<3)
    		{
    			cout << "A" <<i+1 <<j+1<<" : ";
			}else
			{
				cout << "B" <<i+1 <<" : ";
			}
        	cin >> ecuaciones[i][j];
        	k++;
    	}
    	cout << endl;
	}
	

		cout << "Inserte un valor inicial para X : "; cin>>x;
		cout << "Inserte un valor inicial para Y : "; cin>>y;
		cout << "Inserte un valor inicial para Z : "; cin>>z;
		
	system("CLS");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

boolean verificar()
{
	boolean esDominante;
	
		
    	if(abs(ecuaciones[0][0])>(ecuaciones[0][1]+ecuaciones[0][2])){
    		esDominante = true;	
		}
    	else{
    		esDominante = false;
		}
    	
	
    	if(abs(ecuaciones[0][0])>(ecuaciones[1][0]+ecuaciones[2][0])){
    		esDominante = true;	
		}
    	else{
    		esDominante = false;
		}	
	
	
	if(esDominante)
	{
		if(abs(ecuaciones[1][1])>(ecuaciones[1][0]+ecuaciones[1][2])){
    		esDominante = true;	
		}
    	else{
    		esDominante = false;
		}
    	
	
    	if(abs(ecuaciones[1][1])>(ecuaciones[0][1]+ecuaciones[2][1])){
    		esDominante = true;	
		}
    	else{
    		esDominante = false;
		}
		
		if(esDominante)
		{
				if(abs(ecuaciones[2][2])>(ecuaciones[2][0]+ecuaciones[2][1])){
		    		esDominante = true;	
				}
		    	else{
		    		esDominante = false;
				}
		    	
			
		    	if(abs(ecuaciones[2][2])>(ecuaciones[0][2]+ecuaciones[1][2])){
		    		esDominante = true;	
				}
		    	else{
		    		esDominante = false;
				}
		}
	}
	
	return esDominante;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void procedimiento()
{
	n=0;
	do{
	    // Calculo de valores para las incognitas
	    incognitas[0] = (ecuaciones[0][3]-(ecuaciones[0][1]*y)-(ecuaciones[0][2]*z))/ecuaciones[0][0];
	    
	    pError[0] = ((incognitas[0]-x)/incognitas[0])*100;
	    x = incognitas[0];
	    
		incognitas[1] = (ecuaciones[1][3]-(ecuaciones[1][0]*x)-(ecuaciones[1][2]*z))/ecuaciones[1][1];
	    
	    pError[1] = ((incognitas[1]-y)/incognitas[1])*100;
	    y = incognitas[1];
	     
		incognitas[2] = (ecuaciones[2][3]-(ecuaciones[2][0]*x)-(ecuaciones[2][1]*y))/ecuaciones[2][2];
	    
		pError[2] = ((incognitas[2]-z)/incognitas[2])*100;
	    z = incognitas[2];
	    
	    // Se enumera la iteración actual
		cout << "Iteracion " << n+1 << endl << endl;
		
		// Se imprime el valor actual de las incognitas
	    for(i=0; i<3; i++)
	    {
	    	cout << (char)(120+i) << " = " << incognitas[i] << endl;
	    }
	      
	    cout << endl;
	    
	    // Se imprimen porcentajes de error
	    for(i=0; i<3; i++)
	    {
	    	cout << "Ea" << (char)(120+i) << " = " << pError[i] << "%" << endl;
	    }
	    
		n = n+1;
	    getch();
	    system("CLS");
	    
	    // Mientras los porcentajes de error sean menor a...
    }while(pError[0]>error || pError[1]>error || pError[2]>error);
    
	cout<< "Resultados:"<<endl;
    // Se imprime el valor final de las incognitas
	    for(i=0; i<3; i++)
	    {
	    	cout << (char)(120+i) << " = " << incognitas[i] << endl;
	    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

	do{
		system("CLS");
		cout<<"\t\tMetodos Numericos"<<endl
		<<"Resolucion de sistemas de ecuaciones"<<endl
		<<"Introduzca las constantes de las ecuaciones"<<endl
		<<endl;
		
		inicio();
		if(verificar())
		{
			procedimiento();	
		}else
		{
			cout<< "La matriz no es diagonalmente dominante. No es posible resolver por Gauss-Seidell";
		}
		system("Pause");
		
		cout<<"Desea seguir? Teclee 's' minuscula.";
	}while(getch()=='s');
	return 0;
}
