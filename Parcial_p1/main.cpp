#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Tipo2
{
	char dato1[3];
    char dato2[3];
};
struct NodoListaTipo2
{
	Tipo2 info;
	NodoListaTipo2 *sgte;
    NodoListaTipo2 *ant;
};
struct Tipo1
{
   char dato1[3];
};
struct NodoListaTipo1
{
	Tipo1 info;
	NodoListaTipo1 *sgte;
	NodoListaTipo2 *sublista;
};
void ArchivoPrueba()
{
    FILE *f;
    f=fopen("Prueba.txt","wb");
    Tipo2 t;

    strcpy(t.dato1,"N1");
    strcpy(t.dato2,"s0");
    fwrite(&t,sizeof(Tipo2),1,f);

    strcpy(t.dato1,"N2");
    strcpy(t.dato2,"s9");
    fwrite(&t,sizeof(Tipo2),1,f);

    strcpy(t.dato1,"N4");
    strcpy(t.dato2,"s8");
    fwrite(&t,sizeof(Tipo2),1,f);

    fclose(f);
    return;
}
void insertarnodo(NodoListaTipo1 *&lista,char dato[])
{
    NodoListaTipo1 *paux=lista;
    if(!lista)//SI ES NULL
    {
        lista=new NodoListaTipo1();
        strcpy(lista->info.dato1,dato);
        lista->sgte=NULL;
    }
    else//
    {
        while(paux->sgte)
        {
            paux=paux->sgte;
        }
        paux->sgte=new NodoListaTipo1();
        paux=paux->sgte;
        strcpy(paux->info.dato1,dato);
        paux->sgte=NULL;
    }
    return;
}

void Mostrar(NodoListaTipo1 *lista)
{
    NodoListaTipo1 *paux1=lista;
    while(paux1)
    {
        cout << "Info: " << paux1->info.dato1 << endl;
        paux1=paux1->sgte;
    }
    return;
}

void AgregarSubNodo(NodoListaTipo2 *&slista,char dato[])
{
    NodoListaTipo2 *aux=slista;
    if(!slista)//SI LA LISTA NO EXSTE LA CREA
    {
        slista=new NodoListaTipo2();
        strcpy(slista->info.dato1,dato);
        cout << "Ingrese S para " << slista->info.dato1 << endl;
        cin >> slista->info.dato2;
        slista->sgte=NULL;
        slista->ant=NULL;
    }
    else//SINO EL AGREGA NODO
    {
        while(aux->sgte)//BUSCA EL ULTIMO PARA AGREGAR EL NUEVO NODO EN EL SIGUEINTE
        {
           aux=aux->sgte;
        }
        aux->sgte=new NodoListaTipo2();
        strcpy(aux->sgte->info.dato1,dato);
        cout << "Ingrese S para " << aux->info.dato1 << endl;
        cin >> aux->sgte->info.dato2;
        aux->sgte->ant=aux;
        aux->sgte->sgte=NULL;
    }
    return;
}

void insertarsublista(NodoListaTipo1 *&lista,char dato[])
{
   NodoListaTipo1 *paux=lista;
   while(paux && strcmp(paux->info.dato1,dato))//BUSCA EL NODO PARA CREAR LA SUBLISTA
   {
    paux=paux->sgte;
   }
      AgregarSubNodo(paux->sublista,dato);
   return;
}
/***PARCIAL P1 A***/
NodoListaTipo2 *BuscarDato(NodoListaTipo2 *&lista,char dato[])
{//BUSCA LA DIRECCION DE MEMORIA DEL SUBNODO
    NodoListaTipo2 *paux2=lista;
    while(paux2 && strcmp(paux2->info.dato2,dato))
    {
        paux2=paux2->sgte;
    }
    return paux2;//CUANDO LO ENCUENTRA RETORNA
}
/***PARCIAL P1 A***/
void borrarsublista(NodoListaTipo2 *&sublista,char dato[])
{//SE POSICIONA EN EL NODO S6, ENLANZA EL NODO ANTERIOR CON EL SIGUIENTE DE S6.
//SOLO VALIDO PARA ESTE CASO PARTICULAR.
    NodoListaTipo2 *paux2;
    //SE PUEDE HACER SIN BUSCARDATO, ES DECIR CON UN WHILE
    paux2=BuscarDato(sublista,dato);//TOMA LA DIRE DE MEMORIA DEL SUBNODO
    if(paux2)//SI EXISTE HACE EL BORRADO
    {
      paux2->ant->sgte=paux2->sgte;
      if(paux2->sgte)
       paux2->sgte->ant=paux2->ant;
      delete paux2;
      cout << "Se ha borrado correctamente el nodo" << endl;
    }
    else
        cout << "No se ha encontrado el nodo" << endl;
      delete paux2;
}
/***PARCIAL P1 A***/
void Buscar(NodoListaTipo1 *&lista,char dato[])
{
    NodoListaTipo1 *paux1=lista;
      while(paux1 && strcmp(paux1->info.dato1,dato))//MIENTRAS PAUX EXISTA Y LA INFO SEA DIFERENTE AL DATO A BUSCAR
      {
          paux1=paux1->sgte;//PAUX AVANZA
      }
        if(paux1)//SI LO ENCUENTRA ENTRA
          borrarsublista(paux1->sublista,"s6");
    return;
}

void Bsublista(NodoListaTipo2 *lista)
{
    NodoListaTipo2 *paux2=lista;
    while(paux2)
    {
        cout << "Info 1: " << paux2->info.dato1 << endl;
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
      cout << "Info: " << paux->info.dato1 << endl;
      cout << "----------------------------" << endl;
      Bsublista(paux->sublista);
      paux=paux->sgte;
    }
   return;
}
/***PARCIAL P1 B***/
void AgregarNodo(NodoListaTipo1 *&lista, char dato[])
{
    NodoListaTipo1 *paux1=new NodoListaTipo1();
    strcpy(paux1->info.dato1,dato);
    paux1->sgte=lista->sgte->sgte;
    lista->sgte->sgte=paux1;
    return;
}

void borrartodassublistas(NodoListaTipo2 *&lista)
{
    NodoListaTipo2 *paux2;
    while(lista)
    {
        paux2=lista;
        while(paux2 && paux2->sgte)
        {
            paux2=paux2->sgte;
        }
        if(paux2 && paux2->ant)
        {
            paux2->ant->sgte=NULL;
            delete paux2;
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
/***PARCIAL P2***/
void LeerArchivo(FILE *f,NodoListaTipo1 *&lista)
{
    NodoListaTipo1 *paux1=lista;
    NodoListaTipo2 *paux2=NULL;
    f=fopen("Prueba.txt","rb");
    Tipo2 t;
    while(fread(&t,sizeof(Tipo2),1,f))//RECORRE EL ARCHIVO
    {
        paux1=lista;//POSICIONA A PAUX AL PRINCIPIO PARA VOLVER A RECORRER LA LISTA
        cout << "Tipo2: " << t.dato1 << endl;
        while(paux1 && strcmp(t.dato1,paux1->info.dato1))//RECORRE LA LISTA QUE LA INFO SEA IGUAL
        {
            paux1=paux1->sgte;
        }
            if(!paux1->sublista)//Si no existe que lo cree
            {
             cout << "ENTRA 1" << endl;
             paux1->sublista=new NodoListaTipo2();
             paux2=paux1->sublista;
             paux2->info=t;//METE LA INFO TODA JUNTA
             paux2->sgte=NULL;
             paux2->ant=NULL;
            }
            else //Si existe lo agregua
            {
             cout << "ENTRA 2" << endl;
             paux2=paux1->sublista;
             while(paux2 && paux2->sgte)
                paux2=paux2->sgte;
             paux2->sgte=new NodoListaTipo2();
             paux2->sgte->ant=paux2;
             paux2=paux2->sgte;
             paux2->info=t;//METE LA INFO TODA JUNTA
             paux2->sgte=NULL;
            }
    }
    fclose(f);
    return;
}
/***PARCIAL P3***/
void BorrarSublistaNodo(NodoListaTipo2 *&sublistas)
{//BORRA LA SUBLISTA PARA EVITAR FUGAS DE MEMORIA
    NodoListaTipo2 *paux2=sublistas;
    while(sublistas)//MIENTRAS EXISTA LA SUBLISTA
    {
      paux2=sublistas;//CUANDO SE REPITE PAUX2 VUELVE AL PRINCIPIO
      while(paux2 && paux2->sgte)//MIENTRAS PAUX2 Y EL SIGUIENTE EXISTAN
      {
        paux2=paux2->sgte;//BUSCA EL ULTIMO
      }
      if(paux2!=sublistas)//SI PAUX2 ES DIFERENTE AL INICIO DE LA LISTA
      {
        paux2->ant->sgte=paux2->sgte;//ENLANZA EL NODO ANTERIOR AL SIGUIENTE DE PAUX2
        delete paux2;//ELIMINA PAUX2
      }
      else//SI PAUX2 ES IGUAL AL INICIO DE LA LISTA
      {
        delete paux2;//ELIMINA PAUX2 DIRECTAMENTE
        sublistas=NULL;//SUBLISTA IGUAL A NULL
      }
      cout << "Nodo de sublista BORRADO" << endl;
   }
    return;
}
/***PARCIAL P3***/
void EliminarNodo(NodoListaTipo1 *&lista,char valor[])
{
    NodoListaTipo1 *paux1=lista;
    NodoListaTipo1 *ant=NULL;
    bool borrado=1;
    while(paux1 && borrado)//RECORRE LA LISTA SI EXISTE Y SI NO SE HA BORRADO EL NODO AUN*/
    {
       if(!(strcmp(paux1->info.dato1,valor)))//CUANDO ES IGUAL ENTRA
       {
         if(paux1!=lista)//SI PAUX ES DIFERENTE A LISTA
         {
            BorrarSublistaNodo(paux1->sublista);//BORRA SU SUBLISTA
            ant->sgte=paux1->sgte;//EL PUNTERO ANTERIOR APUNTA AL SIGUIENTE QUE TIENE Q BORRAR
            delete paux1;//BORRA EL NODO
            cout << "***NODO BORRADO***" << endl;
            borrado=0;//CONFIRMA EL BORRADO PARA SALIR DEL WHILE YA QUE PAUX SE PIERDE
         }
         else//SI ES IGUAL A LA PRIMERA POSICION DE LA LISTA
         {
            BorrarSublistaNodo(paux1->sublista);//BORRA SU SUBLISTA
            lista=paux1->sgte;//LISTA APUNTA AL SIGUIENTE NODO
            delete paux1;//BORRA EL NODO
            cout << "***NODO BORRADO***" << endl;
            borrado=0;//CONFIRMA EL BORRADO PARA SALIR DEL WHILE YA QUE PAUX SE PIERDE
         }
       }
       else//SINO SIGUE AVANZANDO
       {
           ant=paux1;//SE POSICIONA EN PAUX
           paux1=paux1->sgte;//PAUX AVANZA
       }
    }
    if(borrado)//SI BORRADO ES 1 SIGNIFICA QUE NO SE HA ENCONTRADO EL NODO
    cout << "NO SE HA ENCONTRADO EL NODO" << endl;
    cout << "----------------------------" << endl;
    return;
}

void borrar(NodoListaTipo1 *&lista)
{
    NodoListaTipo1 *paux;
    NodoListaTipo1 *ant;
    /***** borra de adelante hacia atras *****/
    while (lista)//del primero al anteultimo
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
    FILE *f;
    char valor1[3];
    NodoListaTipo1 *listaQ=NULL;
    ArchivoPrueba();
    insertarnodo(listaQ,"N1");
    insertarnodo(listaQ,"N2");
    insertarnodo(listaQ,"N3");
    insertarnodo(listaQ,"N4");
    cout << "------------------------------------------------" << endl;
    cout << "*****TOTAL DE NODOS INGRESADOS*****" << endl;
    Mostrar(listaQ);
    insertarsublista(listaQ,"N1");
    insertarsublista(listaQ,"N1");
    insertarsublista(listaQ,"N1");
    insertarsublista(listaQ,"N3");
    insertarsublista(listaQ,"N4");
    insertarsublista(listaQ,"N4");
    insertarsublista(listaQ,"N4");
    cout << "  " << endl;
    cout << "****TODAS LAS SUBLISTAS***" << endl;
    MostrarSublista(listaQ);
    cout << " " << endl;
    cout << "Busca s6 para borrar " << endl;
    Buscar(listaQ,"N4"); /***PARCIAL P1 A***/
    cout << "  " << endl;
    cout << "***SUBLISTA ACTUALIZADA***" << endl;
    MostrarSublista(listaQ);
    cout << "Agrega N5" << endl;
    AgregarNodo(listaQ,"N5");/***PARCIAL P1 B***/
    cout << "  " << endl;
    cout << "***LISTA ACTUALIZADA***" << endl;
    Mostrar(listaQ);
    cout << "  " << endl;
    cout << "***SUBLISTA ACTUALIZADA 2***" << endl;
    MostrarSublista(listaQ);
    cout << " " << endl;
    cout << "Agrega subnodos desde un arhivo" << endl;
    LeerArchivo(f,listaQ);/***PARCIAL P2***/
    cout << "Ingrese el Nodo a borrar: " << endl;
    cin >> valor1;
    EliminarNodo(listaQ,valor1);/***PARCIAL P3***/
    cout << "  " << endl;
    cout << "***LISTA ACTUALIZADA***" << endl;
    Mostrar(listaQ);
     cout << "  " << endl;
    cout << "***SUBLISTA ACTUALIZADA 3***" << endl;
    MostrarSublista(listaQ);
    cout << "  " << endl;
    cout << "***BORRAR TODO***" << endl;
    borrar(listaQ);
    return 0;
}
