#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
	Método Gauss-Jordan
	
	Presentado por: 
		Edwin González, 
		Rolando Peña, 
		Christian Pinzón 
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int i, j, k, n;
float ecuaciones[3][4];

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar()
{
	for(i=0; i<3; i++)
	{
		cout << "\t\t";
    	for(j=0; j<4; j++)
    	{
    		if(j<3)
    		{
    			cout << " " <<ecuaciones[i][j];
			}else
			{
				cout << " || "<<ecuaciones[i][j];
			}
    	}
    	cout << endl;
	}
		cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicio()
{
	cout << "\t\tMetodo de Gauss-Jordan" << endl << endl;
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
	system("CLS");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void procedimiento()
{
	
 	mostrar();
	
	// Asegurar que el valor de A11 sea igual a 1 (F1/A11)
	if(ecuaciones[0][0]!=1){
	    for(int x=3;x>=0;x--)
			ecuaciones[0][x]/=ecuaciones[0][0];
		 	mostrar();
	}
	
	// Hacer que el coeficiente A21 sea 0 (F2 - (A21*F1))
	for(int x=3;x>=0;x--)
		ecuaciones[1][x] = ecuaciones[1][x]+(ecuaciones[0][x]*(-1*ecuaciones[1][0]));
	 mostrar();
	
	// Hacer que el coeficiente A31 sea 0 (F3 - (A31*F1))
	for(int x=3;x>=0;x--)
		ecuaciones[2][x] = ecuaciones[2][x]+(ecuaciones[0][x]*(-1*ecuaciones[2][0]));
	 mostrar();
	
	// Hacer que el coeficiente A22 sea 1  (F2/A22)
	if(ecuaciones[1][1]!=1)
	{
	    for(int x=3;x>=1;x--)
			ecuaciones[1][x]/=ecuaciones[1][1];
			mostrar();
	}
	
	// Hacer que el coeficiente A32 sea 0 (F3 - (A32*F2))
	for(int x=3;x>=1;x--)
		ecuaciones[2][x] = ecuaciones[2][x]+(ecuaciones[1][x]*(-1*ecuaciones[2][1]));
	mostrar();
	
	// Hacer que el coeficiente A33 sea 1 (F3/A33)
	if(ecuaciones[2][2]!=1){
		ecuaciones[2][3]/=ecuaciones[2][2];
		ecuaciones[2][2]/=ecuaciones[2][2];
		mostrar();
	}
	
	// ------ Hacer '0' la matriz triangular superior * :
	
	// Hacer que A12 sea 0 (F1-(A12*F2))
	for(int x=3;x>=1;x--)
		ecuaciones[0][x] = ecuaciones[0][x]+(ecuaciones[1][x]*(-1*ecuaciones[0][1]));
 	mostrar();
	
	// Hacer que el coeficiente A13 sea 0 y obtener valor de la incognita X1  
	ecuaciones[0][3] = ecuaciones[0][3]+(ecuaciones[2][3]*(-1*ecuaciones[0][2]));
	// (F1-(A13*F3))
	ecuaciones[0][2] = ecuaciones[0][2]+(ecuaciones[2][2]*(-1*ecuaciones[0][2]));
 	mostrar();
	
	// Hacer que el coeficiente A23 sea 0 y obtener valor de la incognita X2 
	ecuaciones[1][3] = ecuaciones[1][3]+(ecuaciones[2][3]*(-1*ecuaciones[1][2]));
	// (F2-(A23*F3))
	ecuaciones[1][2] = ecuaciones[1][2]+(ecuaciones[2][2]*(-1*ecuaciones[1][2]));
	mostrar();
	
	cout<<endl<<"\t-----------------------------------------------";
	
	cout<<"\n\nX1 = "<<ecuaciones[0][3]<<
			"\nX2 = "<<ecuaciones[1][3]<<
			"\nX3 = "<<ecuaciones[2][3]<<
			"\n"<<endl;
	
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
		procedimiento();
		system("Pause");
		
	cout<<"Desea seguir? Teclee 's' minuscula.";
	}while(getch()=='s');
 	return 0;
 }

