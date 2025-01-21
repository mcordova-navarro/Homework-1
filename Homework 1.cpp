//título: Fordward List

//Integrantes:
//Aaron Rojas Durand
//Milton Joel Cordova Navarro
#include "iostream"
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;

public:
    List() : head(NULL) {}

    void Iterar() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void Push_Front(int num) {
        Node* nodo = new Node;
        nodo->data = num;
        nodo->next = head;
        head = nodo;
    }

    void Push_back(int num) {
        Node* nodo = new Node;
        nodo->data = num;
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodo;
        nodo->next = NULL;
    }

    void Pop_front() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void Pop_Back() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }

    void InsertPosition(int position) {
        Node* nodo = new Node;
        nodo->data = position;
        Node* temp = head;
        int i = 0;
        while (i++ < position - 1) {
            temp = temp->next;
        }
        nodo->next = temp->next;
        temp->next = nodo;
    }

    void Clear() {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = NULL;
        cout << "Lista eliminada completamente" << endl;
    }

    void swap(Node* nodo1, Node* nodo2) {
        int temp = nodo1->data;
        nodo1->data = nodo2->data;
        nodo2->data = temp;
    }

    void sort() {
        if (head == NULL || head->next == NULL) return;

        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp != NULL && temp->next != NULL) {
                if (temp->data > temp->next->data) {
                    swap(temp, temp->next);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
    }

    void ImprimirLista() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    bool empty() {
        if (head == NULL) {
            cout << "vacio" << endl;
            return true;
        } else {
            cout << "no vacio" << endl;
            return false;
        }
    }

    int size() {
        int i = 0;
        Node* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            i++;
        }
        return i;
    }

    void front() {
        if (head == NULL) {
            cout << "Lista vacía" << endl;
        } else {
            cout << "Elemento al frente: " << head->data << endl;
        }
    }

    void back() {
        if (head == NULL) {
            cout << "Lista vacía" << endl;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            cout << "Elemento al final: " << temp->data << endl;
        }
    }

    int operator[](int index) {
    Node* temp = head;  // Usamos el puntero head de la clase.
    int i = 0;
    
    // Recorremos la lista hasta llegar al índice deseado.
    while (temp != NULL && i < index) {
        temp = temp->next;
        i++;
    }

    // Si hemos llegado a un nodo válido, retornamos el valor.
    if (temp != NULL) {
        return temp->data;
    } else {
        // Si no hay un nodo en esa posición, mostramos un mensaje de error.
        cout << "Índice fuera de rango" << endl;
        return -1;
    }
}
};

int main() {
    List lista;
    lista.Push_Front(2);
    lista.Push_Front(3);
    lista.Push_Front(4);
    lista.Push_Front(6);
    cout << "Lista antes de ordenar:" << endl;
    lista.ImprimirLista();


    lista.Push_back(10);
    lista.Push_back(11);
    cout << "Lista después de agregar más elementos:" << endl;
    lista.ImprimirLista();

    lista.Pop_front();
    cout << "Lista después de hacer Pop_front:" << endl;
    lista.ImprimirLista();

    lista.Pop_Back();
    cout << "Lista después de hacer Pop_Back:" << endl;
    lista.ImprimirLista();

    lista.empty();//retorna si la lista esta vacia o no
    cout << "Tamaño de la lista: " << lista.size() << endl;

    lista.sort();
    cout << "Lista después de ordenar:" << endl;
    lista.ImprimirLista();

    lista.reverse();
    cout << "Lista después de invertir:" << endl;
    lista.ImprimirLista();

    // Test front(), back(), y el operador []
    lista.front();
    lista.back();
    // Accediendo a los elementos usando el operador []
    cout << "Elemento en el índice 0: " << lista[0] << endl;
    cout << "Elemento en el índice 2: " << lista[2] << endl;
    cout << "Elemento en el índice 4: " << lista[4] << endl;  // Índice fuera de rango

    lista.Clear();
    cout<<"Despues de eliminar la lista y sus elementos: "<<endl;
    lista.ImprimirLista();


    return 0;
}
