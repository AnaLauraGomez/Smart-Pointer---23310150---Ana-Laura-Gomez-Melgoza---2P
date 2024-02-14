#include <iostream>
#include <memory>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* Los smart pointers en C++ hacen la funcion de los punteros tradicionales 
    pero tienen la facilidad de liberar la memoria que obtienen una vez que salgan de su funcion automaticamente*/

    /*
        unique_ptr
        Apunta a un objeto (solo puede hacerlo a uno, por eso el unico (a menos que se reasigne)) 
        y cuando se sale del ambito se libera esa memoria automaticamente 
    */

   // Crear un objeto único
    unique_ptr<int> ptr(new int(10));
    
    // Acceder al objeto a través del puntero
    cout << "Valor almacenado: " << *ptr << endl;

    // Cambiar el valor a través del puntero
    *ptr = 100;

    cout << "Nuevo valor almacenado: " << *ptr << endl;
    // Al salir del ámbito, el objeto es liberado automáticamente

    /*  shared_ptr
        Permite que múltiples punteros compartan la propiedad de un objeto.
    */

   // Crear un objeto compartido
    shared_ptr<int> ptr1(new int(20));

    // Crear otro puntero compartiendo el mismo objeto
    shared_ptr<int> ptr2 = ptr1;
    cout << "ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << endl;

    // Acceder y modificar el objeto a través de uno de los punteros
    *ptr1 = 100;
    cout << "ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << endl;
    // Al salir del ámbito del último puntero que referencia al objeto, la memoria se libera automáticamente


    return 0;
}
