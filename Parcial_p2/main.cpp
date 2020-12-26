#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Tipo2
{
    int dato;
    char dato2[3];
};
struct NodoListaTipo2
{
    Tipo2 info;
    NodoListaTipo2 *sgte;
};
struct Tipo1
{
    int dato;
};
struct NodoListaTipo1
{
    Tipo1 info;
    NodoListaTipo1 *sgte;
    NodoListaTipo2 *sublista;
};
void CrearArchivo()
{
    FILE *f;
    f=fopen("Prueba.txt","wb");
    Tipo2 t;

    t.dato=2;
    strcpy(t.dato2,"s0");
    fwrite(&t,sizeof(Tipo2),1,f);

    t.dato=2;
    strcpy(t.dato2,"s8");
    fwrite(&t,sizeof(Tipo2),1,f);

    t.dato=4;
    strcpy(t.dato2,"s9");
    fwrite(&t,sizeof(Tipo2),1,f);

    fclose(f);
    return;
}
/***PARCIAL P2***/
void push(NodoListaTipo2 *&slista,char info2[],int info)
{
    NodoListaTipo2 *paux2=slista;
    cout << "ENTRA en push" << endl;
    while(paux2 && paux2->sgte)//RECORRE PARA ENCONTRAR EL ULTIMO NODO
    {
        paux2=paux2->sgte;
    }
    if(paux2)//SI LO ENCUENTRA INSERTA NODO AL FINAL
    {
        paux2->sgte=new NodoListaTipo2();
        paux2=paux2->sgte;
        strcpy(paux2->info.dato2,info2);//METE LA INFO INFO2 A DATO2 (CHAR)
        paux2->info.dato=info;//METE LA INFO A DATO (INTEGER)
        paux2->sgte=NULL;//ULTIMO NODO A NULL
    }
    else//SINO CREA LA SUBLISTA
    {
        slista=new NodoListaTipo2();
        strcpy(slista->info.dato2,info2);
        slista->info.dato=info;
        slista->sgte=NULL;//ULITMO NODO A NULL
    }
    return;
}
/***PARCIAL P2***/
void LeerArchivo(FILE *f,NodoListaTipo1 *&lista)
{
    NodoListaTipo1 *paux1=lista;
    f=fopen("Prueba.txt","rb");
    Tipo2 t;
    while(fread(&t,sizeof(Tipo2),1,f))
    {
        paux1=lista;//PAUX VUELVE AL INICIO DE LA LISTA PARA RECORRERLA NUEVAMENTE
        while(paux1 && (paux1->info.dato!=t.dato))//RECORRE LA LISTA HASTA Q ENCUENTRA EL NODO
        {//RECORRE LA LISTA COMPARANDO LA INFORMACION DEL ARCHIVO CON EL NODO
            paux1=paux1->sgte;
        }
        if(paux1)//SI ENCONTRO EL NODO HACE PUSH
        {
            cout << "ENTRA en if paux1" << endl;
            push(paux1->sublista,t.dato2,t.dato);//ENTRA CON DATOS SEPARADOS POR SUS TIPOS DE DATOS
        }
        else//SI NO SALE UN MENSAJE DE NO SE HA ENCONTRADO
        {
            cout << "NO SE HA ENCONTRADO EL NODO" << endl;
        }
    }
    fclose(f);
    return;
}
void insertarnodo(NodoListaTipo1 *&lista,int dato)
{
    NodoListaTipo1 *paux=lista;
    if(!lista)//SI LA LISTA NO EXISTE LA CREA
    {
        lista=new NodoListaTipo1();
        lista->info.dato=dato;
        lista->sgte=NULL;
    }
    else//SI EXISTE LE AGREGA NODOS AL FINAL
    {
        while(paux->sgte)//BUSCA EL ULTIMO
        {
            paux=paux->sgte;
        }
        paux->sgte=new NodoListaTipo1();
        paux=paux->sgte;
        paux->info.dato=dato;
        paux->sgte=NULL;
    }
    return;
}

void AgregarNodo(NodoListaTipo1 *&lista)
{
    NodoListaTipo1 *paux1=lista;
    paux1=new NodoListaTipo1();
    paux1->sgte=lista->sgte->sgte->sgte;
    lista->sgte->sgte=paux1;
    paux1->info.dato=5;
    return;
}

void AgregarSubNodo(NodoListaTipo2 *&slista,int dato)
{
    NodoListaTipo2 *aux=slista;
    if(!slista)
    {
        slista=new NodoListaTipo2();
        slista->info.dato=dato;
        cout << "Ingrese S para " << slista->info.dato << endl;
        cin >> slista->info.dato2;
        slista->sgte=NULL;
    }
    else
    {
        while(aux->sgte)
        {
            aux=aux->sgte;
        }
        aux->sgte=new NodoListaTipo2();
        aux->sgte->info.dato=dato;
        cout << "Ingrese S para " << aux->info.dato2 << endl;
        cin >> aux->sgte->info.dato2;
        aux->sgte->sgte=NULL;
    }
    return;
}

void insertarsublista(NodoListaTipo1 *&lista,int dato)
{
    NodoListaTipo1 *paux=lista;
    while(paux && paux->info.dato!=dato)
    {
        paux=paux->sgte;
    }
    AgregarSubNodo(paux->sublista,dato);
    return;
}
/*NodoListaTipo2 *BuscarSLista(NodoListaTipo2 *&lista,char dato[])
{
    NodoListaTipo2 *paux2=lista;
    while(paux2 && paux2->info.dato2!=dato)
    {
        paux2=paux2->sgte;
    }
    return paux2;
}*/
/***PARCIAL P1 A***/
void Borrarsublista(NodoListaTipo2 *&slista,char dato[])
{//BUSCA S2 PARA BORRAR
    NodoListaTipo2 *paux2=slista;
    while(paux2  && strcmp(paux2->info.dato2,dato))//MIENTRAS PAUX2 EXISTA Y LA INFO SEA DIFERENTE
    {
        paux2=paux2->sgte;//PAUX2 AVANZA
    }
    slista->sgte=paux2->sgte;//COMO SOLO PUEDO USAR UN PUNTERO UTILIZO SLISTA PARA ENLANZAR
    //EL PRIMERO CON EL ULTIMO
    delete paux2;//LIBERA LA MEMORIA
    return;
}
/***PARCIAL P1 A***/
void BuscarLista(NodoListaTipo1 *&lista,int dato)
{//BUSCA EL NODO INGRESADO
    NodoListaTipo1 *paux1=lista;
    while(paux1 && paux1->info.dato!=dato)//MIENTRAS EXISTA PAUX Y LA INFO SEA DIFERENTE
    {
        paux1=paux1->sgte;//PAUX AVANZA
    }
    if(paux1)//SI ENCONTRO PAUX1
    {
        Borrarsublista(paux1->sublista,"s2");//ENTRA A SU RESPECTIVA SUBLISTA PARA BUSCAR S2
    }
    else//SI NO LO ENCONTRO
    {
        cout << "NO SE HA ENCONTRADO EL DATO" << endl;
    }
    return;
}
void Bsublista(NodoListaTipo2 *lista)
{
    NodoListaTipo2 *paux2=lista;
    while(paux2)
    {
        cout << "Info 1: " << paux2->info.dato << endl;
        cout << "Info 2: " << paux2->info.dato2 << endl;
        cout << "___________" << endl;
        paux2=paux2->sgte;
    }
    return;
}

void MostrarSublista(NodoListaTipo1 *lista)
{
    NodoListaTipo1 *paux=lista;
    while(paux)
    {
        cout << "Info: " << paux->info.dato << endl;
        cout << "----------------------------" << endl;
        Bsublista(paux->sublista);
        paux=paux->sgte;
    }
    return;
}
char pop(NodoListaTipo2 *&pila)
{
    char info[3];
    NodoListaTipo2 *paux2=pila;
    NodoListaTipo2 *ant=NULL;
    while(paux2 && paux2->sgte)
    {
        ant=paux2;
        paux2=paux2->sgte;
    }
    if(paux2!=pila)
    {
        cout << "Info: " << paux2->info.dato2 << endl;
        strcpy(info,paux2->info.dato2);
        delete paux2;
        ant->sgte=NULL;
    }
    else
    {
        cout << "ENTRA A PILA" << endl;
        cout << "Info: " << pila->info.dato2 << endl;
        strcpy(info,pila->info.dato2);
        delete paux2;
        pila=NULL;
    }
    return info[3];
}
/***PARCIAL P3***/
void BuscarNodo(NodoListaTipo1 *&lista,int dato)
{
    NodoListaTipo1 *paux1=lista;
    NodoListaTipo2 *paux2=NULL;
    char x[3];
    while(paux1 && paux1->info.dato!=dato)//RECORRE LA LISTA HASTA ENCONTRAR EL NODO
    {
        paux1=paux1->sgte;
    }
    if(paux1)//SI LO ENCUENTRA QUE HAGA POP EN LA SUBLISTA
    {
        paux2=paux1->sublista;
        while(paux2)//RECORRE LA SUBLISTA PARA HACER POP
        {
            cout << "Info: " << paux2->info.dato << endl;
            cout << "Info: " << pop(paux2)<< endl;
        }
    }
    else//SINO SALE EL MENSAJE DE NO SE HA ENCONTRADO
    {
        cout << "No se ha encontrado nodo o la sublista esta vacia" << endl;
    }
    return;
}

void Mostrar(NodoListaTipo1 *lista)
{
    NodoListaTipo1 *paux1=lista;
    while(paux1)
    {
        cout << "Info: " << paux1->info.dato << endl;
        paux1=paux1->sgte;
    }
    return;
}
void borrartodassublistas(NodoListaTipo2 *&lista)
{
    NodoListaTipo2 *paux2;
    NodoListaTipo2 *ant=NULL;
    while(lista)
    {
        paux2=lista;
        while(paux2 && paux2->sgte)
        {
            ant=paux2;
            paux2=paux2->sgte;
        }
        if(paux2!=lista)
        {
            delete paux2;
            ant->sgte=NULL;
        }
        else
        {
            delete paux2;
            lista=NULL;
        }
    }
    cout << "**Sublista borrada**" << endl;
    return;
}
void borrar(NodoListaTipo1 *&lista)
{
    NodoListaTipo1 *paux;
    NodoListaTipo1 *ant;
    /***** borra de adelante hacia atras *****/
    while(lista)//del primero al anteultimo
    {
        ant=NULL;
        paux=lista;
        while (paux && paux->sgte)
        {
            ant=paux;
            paux=paux->sgte;
        }
        if(paux)
        {
            borrartodassublistas(paux->sublista);
            delete paux;
            if(ant)
                ant->sgte=NULL;
            else//ultimo nodo
                lista = NULL;
        }
    }
    cout << "----------------------------" << endl;
    cout << "***DATOS BORRADOS***" << endl;
    return;
}

int main()
{
    int valor;
    NodoListaTipo1 *listaP=NULL;
    FILE *f;
    CrearArchivo();
    insertarnodo(listaP,1);
    insertarnodo(listaP,2);
    insertarnodo(listaP,3);
    insertarnodo(listaP,4);
    cout << "------------------------------------------------" << endl;
    cout << "*****TOTAL DE NODOS INGRESADOS*****" << endl;
    Mostrar(listaP);
    insertarsublista(listaP,1);
    insertarsublista(listaP,1);
    insertarsublista(listaP,1);
    insertarsublista(listaP,3);
    insertarsublista(listaP,4);
    insertarsublista(listaP,4);
    insertarsublista(listaP,4);
    cout << "  " << endl;
    cout << "****TODAS LAS SUBLISTAS***" << endl;
    MostrarSublista(listaP);
    cout << " " << endl;
    cout << "Busca s2 para borrar " << endl;
    BuscarLista(listaP,1); /***PARCIAL P1 A***/
    cout << "  " << endl;
    cout << "***SUBLISTA ACTUALIZADA***" << endl;
    MostrarSublista(listaP);
    cout << " " << endl;
    cout << "Agregar un nodo 5" << endl;
    AgregarNodo(listaP);/***PARCIAL P1 B***/
    cout << " " << endl;
    cout << "***LISTA ACTUALIZADA***" << endl;
    Mostrar(listaP);
    cout << "Agrega subnodos desde un arhivo" << endl;
    LeerArchivo(f,listaP); /***PARCIAL P2***/
    cout << "***SUBLISTA ACTUALIZADA 2***" << endl;
    MostrarSublista(listaP);
    cout << "Ingrese el Nodo el cual desea hacer pop: " << endl;
    cin >> valor;
    BuscarNodo(listaP,valor);/***PARCIAL P3***/
    cout << "  " << endl;
    cout << "***SUBLISTA ACTUALIZADA 3***" << endl;
    MostrarSublista(listaP);
    cout << "  " << endl;
    cout << "***BORRAR TODO***" << endl;
    borrar(listaP);
    return 0;
}
