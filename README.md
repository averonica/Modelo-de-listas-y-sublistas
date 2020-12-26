# Modelo-de-listas-y-sublistas
## Programa creado con el fin de verificar los ejercicios de un examen tomado en la Universidad Tecnologica Nacional
Enunciado:

(https://raw.githubusercontent.com/averonica/Modelo-de-listas-y-sublistas/master/assets/Sublistas.png)
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
-Arias, Verónica Yanina
