#include <iostream>
#include <ctime>    
#include <cstdlib>

using namespace std;

void ordenar(int *v, int n) {

	for (int i=0; i<n-1; i++)						// O(n)
		for (int j=0; j<n-i-1; j++)				// O(n)
			if (v[j]>v[j+1]) {				// O(1)
				int aux = v[j];			// O(1)
				v[j] = v[j+1];			// O(1)
				v[j+1] = aux;			// O(1)
			}

}

void sintaxis(){
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){
	// Lectura de parámetros
	if (argc!=3)
		sintaxis();
	
	int tam=atoi(argv[1]);     // Tamaño del vector
	int vmax=atoi(argv[2]);    // Valor máximo

	if (tam<=0 || vmax<=0)
		sintaxis();

	// Generación del vector aleatorio
	int *v=new int[tam];       // Reserva de memoria
	srand(time(0));            // Inicialización del generador de números pseudoaleatorios
	
	for (int i=0; i<tam; i++)  // Recorrer vector
		v[i] = rand() % vmax;  // Generar aleatorio [0,vmax[

	clock_t tini;    // Anotamos el tiempo de inicio
	tini=clock();

	ordenar(v,tam); // de esta forma forzamos el peor caso

	clock_t tfin;    // Anotamos el tiempo de finalización
	tfin=clock();

	// Mostramos resultados
	cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

	delete [] v;     // Liberamos memoria dinámica

}
