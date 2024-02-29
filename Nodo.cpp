#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;  
};

Nodo* cabeza = NULL;
Nodo* cola = NULL;

void insertarNodo() {
    int x; 
    string linea;
    cout << "Ingrese dato: ";
    getline(cin, linea);
    
    try {
    x = stoi(linea);
    } catch (invalid_argument& e) {
    cout << "Error: Por favor ingrese un numero entero." << endl;
    return;
    }
    
    Nodo* nuevo = new Nodo();  
    nuevo->dato = x;
    nuevo->siguiente = NULL;

    if(cabeza == NULL) { 
    cabeza = nuevo;
    cola = nuevo;
    } else {
    cola->siguiente = nuevo;
    cola = nuevo;
    }  
}

void mostrarLista() {
    
    Nodo* actual = cabeza;
    while(actual != NULL) {
    cout << actual->dato << " ";
    actual = actual->siguiente;
    }
}  

void editarNodo() {
    int n, nuevoDato;
    cout << "\nQue nodo desea editar? ";
    cin >> n;
    cin.ignore();
    
    Nodo* actual = cabeza;
    Nodo* anterior = NULL;
    
    for(int i=0; i < n-1; i++) {
    anterior = actual;
    actual = actual->siguiente;
    }
    
    if(actual != NULL) {
    cout << "Ingrese el nuevo dato: ";
    string linea;
    getline(cin, linea);
    
    try {
        actual->dato = stoi(linea);
    } catch (invalid_argument& e) {
        cout << "Error: Por favor ingrese un numero entero." << endl;
        return;
    }
    } else {
    cout << "Error: El nodo no existe." << endl;
    return;
    }
}

void eliminarNodo() {
    int n;
    cout << "\nQue nodo desea eliminar? ";
    cin >> n;
    cin.ignore();
    
    Nodo* actual = cabeza;
    Nodo* anterior = NULL;
    
    if(n == 1) {
    if(actual != NULL) {
        cabeza = actual->siguiente;
        delete actual;
    } else {
        cout << "Error: La lista esta vacia." << endl;
        return;
    }
    } else {
    for(int i=0; i < n-1; i++) {
        if(actual != NULL) {
        anterior = actual;
        actual = actual->siguiente;
        } else {
        cout << "Error: El nodo no existe." << endl;
        return;
        }
    }
    
    if(actual != NULL) {
        anterior->siguiente = actual->siguiente;
        delete actual;
    } else {
        cout << "Error: El nodo no existe." << endl;
        return;
    }
    }
}

int main() {

    int opcion;

    while(true) {

    cout << "\n\n--- MENU ---\n\n";
    cout << "Seleccione una opcion: \n\n";
    cout << "1. Insertar nodo\n";
    cout << "2. Mostrar lista\n";
    cout << "3. Editar nodo\n";
    cout << "4. Eliminar nodo\n"; 
    cout << "5. Salir\n";
    
    cout << "\nOpcion: ";
    cin >> opcion;
    cin.ignore();

    if(opcion == 1) {
        insertarNodo(); 
    } else if(opcion == 2) {
        mostrarLista();
    } else if(opcion == 3) {
        editarNodo();
    } else if(opcion == 4) {  
        eliminarNodo();
    } else if(opcion == 5) {
        break;
    } 
    }
    
    return 0;
}
