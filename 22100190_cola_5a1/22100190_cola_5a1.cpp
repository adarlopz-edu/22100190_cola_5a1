#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    string apellido;
    int registro;
    int edad;

    //constructor
    Persona(string nombre, string apellido, int registro, int edad) : nombre(nombre), apellido(apellido), registro(registro), edad(edad) {}
};

class Nodo {
public:
    Persona* datos;
    Nodo* siguiente;

    //constructores
    Nodo() : datos(NULL), siguiente(NULL) {}
    Nodo(Persona* datos) : datos(datos), siguiente(NULL) {}
};

class Lista {
private:
    Nodo* inicio;
    int contador;

public:
    //constructor
    Lista() : inicio(NULL), contador(0) {}

    //todas las funciones principales
    void agregar(Persona* datos);
    Persona* dequeue();
    int contar();
    bool estaVacia();
    void limpiar();
    Nodo* getInicio() {
        return inicio;
    }

};

void Lista::agregar(Persona* datos) {
    //agrega un nood al final de la cola
    Nodo* nuevo = new Nodo(datos);
    if (inicio == NULL) {
        inicio = nuevo;
    }
    else {
        Nodo* temp = inicio;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    contador++;
}

Persona* Lista::dequeue() {
    if (inicio != NULL) {
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        Persona* datos = temp->datos;
        delete temp;
        contador--;
        return datos;
    }
    return NULL;
}

bool Lista::estaVacia() {
    return inicio == NULL;
}

int Lista::contar() {
    return contador;
}

void Lista::limpiar() {
    while (inicio != NULL) {
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        delete temp->datos;
        delete temp;
        contador--;
    }
}

int main() {
    Lista cola;
    char opcion;

    cola.agregar(new Persona("juan", "lopez", 22100190, 21));
    cola.agregar(new Persona("pedro", "lopez", 22100191, 21));
    cola.agregar(new Persona("valentino", "lopez", 22100192, 21));

    //menu
    while (true) {
        cout << endl << "Queue brad" << endl << endl;
        cout << "a. Agregar nodo" << endl;
        cout << "b. Obtener" << endl;
        cout << "c. Contar" << endl;
        cout << "d. Vacio" << endl;
        cout << "e. Limpiar" << endl;
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion;

        if (opcion == 'a') {
            string nombre, apellido;
            int registro, edad;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            cout << "Ingrese el registro: ";
            cin >> registro;
            cout << "Ingrese la edad: ";
            cin >> edad;
            cola.agregar(new Persona(nombre, apellido, registro, edad));
        }
        if (opcion == 'b') {
            Persona* primerElemento = cola.dequeue();
            if (primerElemento != NULL) {
                cout << "Datos obtenidos: " << endl;
                cout << "Nombre: " << primerElemento->nombre << endl;
                cout << "Apellido: " << primerElemento->apellido << endl;
                cout << "Registro: " << primerElemento->registro << endl;
                cout << "Edad: " << primerElemento->edad << endl << endl;
            }
            else {
                cout << "La cola esta vacia" << endl << endl;
            }
        }
        if (opcion == 'c') {
            cout << "Cantidad de nodos en la cola: " << cola.contar() << endl << endl;
        }
        if (opcion == 'd') {
            if (cola.estaVacia()) {
                cout << "La cola esta vacia" << endl << endl;
            }
            else {
                cout << "La cola no esta vacia" << endl << endl;
            }
        }
        if (opcion == 'e') {
            cola.limpiar();
            cout << "Todos los elementos de la cola han sido eliminados" << endl << endl;
        }
    }
}
