/**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Universidad Javeriana (Bogotá - Colombia)
 * Pensamiento Algorítmico
 * 
 * Taller 9: Búsqueda
 * Estructuras
 *
 * Autores: 
 * -------------------
 * Brayan Castro
 * Johnny Cubides
 * Carolina Pulido
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// -----------------------------------------------------------------
// Estructuras
// -----------------------------------------------------------------
/**
  * Estructura del formato de la salida. 
  * Contiene la palabara buscada, el estado de la búsqueda (ESTA o 
  * NOESTA) y las posiciones donde se encuentra la palabra buscada 
  * en el vector de búsqueda (inicializadas por defecto en 100).
  */  
struct estado
{
	string palabra;
	string verificacion;
	int pos[3] = {100, 100 , 100};
};

// -----------------------------------------------------------------
// Declaración de Funciones
// -----------------------------------------------------------------
/**
  * Verifica si las palabras del vector de búsqueda están dentro
  * de las palabras guardadas en el diccionario y llena los campos 
  * del vector de estados para cada palabra.
  */
vector<estado> verificarPalabras(vector<string> words, vector<string> dic);

/**
  * Visualiza la salida de las búsquedas 
  */
void visualizarSalida(vector<estado> salidas);


// -----------------------------------------------------------------
// Main
// -----------------------------------------------------------------
int main()
{
	int m, n;

	/** 
	 * Se ingresan la cantidad (m) y las palabras a 
	 * almacenar en el diccionario
	 * */
	cout << "Ingrese la cantidad de palabras para agregar al diccionario: ";
	cin >> m;

	vector<string> dic(m); 
	for (int i = 0; i< m ; i++){
		cout << "Palabra " << i +1 << " : ";
		cin >> dic[i]; 
	}
	
	/** 
	 * Se ingresan la cantidad (n) y las palabras a 
	 * almacenar en el vector de búsqueda. Cada palabra
	 * puede estar repetida máximo 3 veces.
	 * */
    cout << "Ingrese la cantidad de palabras a buscar: ";
    cin >> n;
    
    vector<string> words(n); 
    string aux;
    int repetida;
    int ciclo;
    for (int i = 0; i< n ; i++){
        ciclo = 1;
        do{
            repetida = 0;
    		cout << "Palabra " << i+1<< " : ";
    		cin >> aux;
    		for(int k = 0; k < n; k++){
    		    if(aux==words[k]){
    		        repetida++;
    		    }
    		}
    		if(repetida<3){
    		    ciclo = 0;
    		}else{
    		    cout<<"Palabra ya esta repetida 3 veces"<<endl;
    		}
        }while(ciclo == 1);
    	words[i] = aux;
    }

	/** 
	 * Se declara el vector de estados para la salida y 
	 * se llama a la función que se encarga de inicializarlo.
	 * */
	vector<estado> salidas (n); // vector de estados
	salidas = verificarPalabras(words, dic);
	
	/**
	* Se llama a la función que visualiza los resultados
	*/
	visualizarSalida(salidas);

  return 0;
}

// -----------------------------------------------------------------
// Funciones
// -----------------------------------------------------------------
/**
  * Verifica si las palabras del vector de búsqueda están dentro
  * de las palabras guardadas en el diccionario y llena los campos 
  * del vector de estados para cada palabra.
  * Las palabras en el vector de estados (salidas) no pueden estar
  * repetidas. 
  * @param words Vector de palabras a buscar. words.size() != 0
  * @param dic Vector de palabras del diccionario. dic.size() != 0
  * @return salidas Vector de estados de la búsqueda de cada palabra
  */
vector<estado> verificarPalabras(vector<string> words, vector<string> dic){
  int n = words.size(), m  = dic.size(), ctd = 0, state = 0;
  vector<estado> salidas(n);
  for(int t = 0; t < n; t++){
    state = 0;
      for(int v = t+1; v < n; v++){
        if(words[t] == words[v]){
          state++;
        }
      }
      if(state == 0){
        salidas[ctd].palabra = words[t];
          ctd++;
        }
  }
  int p = 0;
  for (int i = 0; i < ctd; i++)
	{
    p = 0;
	  for(int j = 0; j < n; j++)
		{
		  if (salidas[i].palabra == words[j]){
		    salidas[i].pos[p] = j;
		    for(int w = 0; w < m; w++)
      	{
       	  if(salidas[i].palabra == dic[w]){
       	    salidas[i].verificacion = "ESTA";
       	    p++;
       	  }
        }
       	if(p==0){
          salidas[i].verificacion = "NOESTA";
          salidas[i].pos[0] = (-1)*j;
        }
		  }
		}
	}
	salidas.resize(ctd);  
  return salidas;
}

/**
  * Visualiza la salida de las búsquedas 
  * @param salidas Vector de estados de la búsqueda de cada palabra
  */
void visualizarSalida(vector<estado> salidas){
  cout << "********************\n";
  cout << "****** SALIDA ******\n";
  cout << "********************\n";
  cout << "---------------------------------------------\n";
  cout << "Palabra - Estado - Posiciones \t\t \n";
  cout << "---------------------------------------------\n";
  int ctd = salidas.size();
  for (int i = 0; i < ctd; i++){
    cout << salidas[i].palabra << "\t \t " << salidas[i].verificacion << "\t \t ";
    for (int j = 0; j<3; j++) 
    {
      if(salidas[i].pos[j] != 100)
        cout<< salidas[i].pos[j] << "\t ";
    }
   	cout << "\n";
  }
}
