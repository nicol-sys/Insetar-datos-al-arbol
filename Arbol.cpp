#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

void insertar(Nodo*&, int);
void Mostrararbol(Nodo*);

int main() {
    Nodo* arbol = NULL;
    int opcion, dato;

    while (true) {
        cout << "MENU"<< endl;
        cout << "1. Insertar un número"<< endl;
        cout << "2. Mostrar datos del árbol"<< endl;
        cout << "3. Salir"<< endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Digite un número: ";
                cin >> dato;
                insertar(arbol, dato);
                break;
            case 2:
                cout << "Datos del árbol:" << endl;
                Mostrararbol(arbol);
                cout << endl;
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                return 0;
            default:
                cout << "Opción no válida" << endl;
        }
    }

    return 0;
}

void insertar(Nodo*& arbol, int x) {
    if (arbol == NULL) {
        arbol = new Nodo();
        arbol->dato = x;
        arbol->izquierda = NULL;
        arbol->derecha = NULL;
        cout << "El elemento " << x << " ha sido insertado" << endl;
    } else if (arbol->dato == x) {
        cout << "El elemento " << x << " ya existe en el árbol" << endl;
    } else if (arbol->dato > x) {
        insertar(arbol->izquierda, x);
    } else {
        insertar(arbol->derecha, x);
    }
}

void Mostrararbol(Nodo* arbol) {
    if (arbol != NULL) {
        Mostrararbol(arbol->izquierda);
        cout << arbol->dato << " ";
        Mostrararbol(arbol->derecha);
    }
}
