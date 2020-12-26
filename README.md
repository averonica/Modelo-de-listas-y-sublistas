# Modelo-de-listas-y-sublistas
## Programa creado con el fin de verificar los ejercicios de un examen tomado en la Universidad Tecnologica Nacional
Enunciado (T1):
![Sublistas](https://user-images.githubusercontent.com/38114502/103158094-ece58d00-4798-11eb-98d9-34452f1afbaf.png)

Los nodos de la lista principal son de tipo NodoListaTipo1 y los de la lista secundaria son de tipo
NodoListaTipo2.
1. Utilizando sólo dos punteros: NodoListaTipo1 *paux1 y NodoListaTipo2 *paux2;
1.a. Elimine el nodo S6 de la sublista correspondiente.
1.b. Agregue un nodo N5 entre los nodos N2 y N3
2. Realice un subprograma que lea de un archivo, recibido por parámetro junto con listaQ, todos los
registros de Tipo2 que contenga y los ubique al final de la sublista que corresponda a cada uno.
La correspondencia a una sublista determinada se da por la igualdad del valor del miembro dato1
del registro leído con el valor de dato1 del nodo de la lista principal..
3. Desarrolle un subprograma que dados por parámetros un valor y la lista, elimine el nodo de la lista
principal que cumpla !strcmp(dato1, valor).
4. ADICIONAL:
Si se necesitaran 100 estructuras como listaQ
4.a.Qué tipo de variable propondría utilizar? Realice la declaración e inicialización de la misma.
4.b Si se modificara Tipo1 de modo que contenga además de dato1, el número de lista a la que
debería cargarse:
Struct Tipo1
{
int lista;
char dato1[3];
}

Enunciado (T2):
![Sublistas2](https://user-images.githubusercontent.com/38114502/103158437-a09c4c00-479c-11eb-9889-6071e7832757.png)


Los nodos de la lista principal son de tipo NodoListaTipo1 y los de la lista secundaria son de tipo
NodoListaTipo2.
1. Utilizando sólo dos punteros: NodoListaTipo1 *paux1 y NodoListaTipo2 *paux2;
1.a. Elimine el nodo S2 de la sublista correspondiente.
1.b. Agregue un nodo con dato 5 entre los nodos 3 y 4.
2. Realice un subprograma que lea de un archivo, recibido por parámetro junto con listaP, todos los
registros de Tipo2 que contenga y haga push dentro de la pila que corresponda a cada uno. La
correspondencia a una pila determinada se da por la igualdad del valor del miembro dato1 del
registro leído con el valor de dato1 del nodo de la lista principal..
3. Desarrolle un subprograma que reciba la lista y un número a buscar. Si encuentra el nro debe
listar todos los elementos de la pila haciendo pop de la misma y dejándola vacía.
4. ADICIONAL:
Si se necesitaran 50 estructuras como listaP
4.a.Qué tipo de variable propondría utilizar? Realice la declaración e inicialización de la misma.
4.b Si se modificara Tipo1 de modo que contenga además de dato1, el número de lista a la que
debería cargarse:
Struct Tipo1
{
int lista;
int dato;;
}
Diseñe un subprograma que lea un archivo registros de Tipo1 y los cargue en la estructura
propuesta en 4a. Puede utilizar las primitivas provistas.

-Arias, Verónica Yanina
