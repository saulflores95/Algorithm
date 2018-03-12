#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct nodo
{
	int dato;
	struct nodo *siguiente;
	struct nodo *anterior;
};

void insertar(struct nodo **inicio, struct nodo **final, int dato);
void mostrarAscendentemente(struct nodo *inicio);
void mostrarDecendentemente(struct nodo *final);
struct nodo * crearNodo(int dato);
void eliminar(struct nodo **inicio, struct nodo **final, int dato);

int main()
{
	struct nodo *inicio = NULL, *final = NULL;
	char opc;
	int dato;
	do{	
		printf("\n1. Insertar en la lista");
		printf("\n2. Eliminar un elemento ");
		printf("\n3. Imprimir la lista Asendentemente");
		printf("\n4. Imprimir la lista Decendentemente");
		printf("\n5. Salir");
		printf("\nOpcion: [ ]\b\b");
		opc=getche();
		switch(opc)
		{ 
		case '1':
			printf("\nEscribe dato a insertar: ");
			scanf("%d",&dato);
			if(inicio == NULL)
			{
					inicio = crearNodo(dato);
					final = inicio;
			}
			else
				insertar(&inicio, &final, dato);
		break;
		case '3': 
			mostrarAscendentemente(inicio);
		break;
		case '2':
			printf("\nEscribe dato a borrar: ");
			scanf("%d",&dato);
			eliminar(&inicio, &final, dato);
		break;
		case '4': 
			mostrarDecendentemente(final);
		break;
	}
	}while(opc!='5');
	
	
	return 0;
}

void eliminar(struct nodo **inicio, struct nodo **final, int dato)
{
	struct nodo *aux, *p, *q = NULL;
	int bandera = 0;
	p=*inicio;
	
	while(p != NULL && dato != p->dato)
	{
		q = p; 
		p = p->siguiente;
		
	}
	
	if(q == NULL && dato == (*inicio)->dato) // es el primer elemento
	{
		aux = *inicio;
		(*inicio)->siguiente->anterior = NULL;
		*inicio = (*inicio)->siguiente;
		free(aux);
		bandera = 1;
	}
	else if( p == NULL && dato == (*final)->dato) // es el ultimo elemento
	{
		aux = *final;
		(*final)->anterior->siguiente = NULL;
		*final = (*final)->anterior;
		free(aux);
		bandera = 1;
	}
	else // esta entre medias
	{
		aux = p;
		q->siguiente = p->siguiente;
		p->siguiente->anterior = q;
		free(aux);
		bandera = 1;
	}
	
	if(bandera == 0)
	{
		puts("\nDato no encontrado\n");
	}
}

void mostrarAscendentemente(struct nodo *inicio)
{
	struct nodo *aux;
	aux = inicio;
	
	while(aux != NULL)
	{
		printf("\n%d", aux->dato);
		aux = aux->siguiente;
	}
	
}

void insertar(struct nodo **inicio, struct nodo **final, int dato)
{
	
	struct nodo *p, *q = NULL, *nuevo;
	
	p=*inicio;
	nuevo = crearNodo(dato);
	while(p != NULL && dato >= p->dato)
	{
		q = p;
		p = p->siguiente;
	}
	
	if(q == NULL) // es el primer elemento
	{
		nuevo->siguiente = *inicio;
		(*inicio)->anterior =  nuevo;
		*inicio = nuevo;
	}
	else if(p == NULL)  // es el ultimo de la lista
	{
		nuevo->anterior = *final;
		(*final)->siguiente = nuevo;
		*final = nuevo;
	}
	else  // en medio de la lista
	{
		
		nuevo->siguiente = p->siguiente;
		nuevo->anterior = p;
		p->siguiente->anterior = nuevo;
		p->siguiente = nuevo;
		
	}
	
}


void mostrarDecendentemente(struct nodo *final)
{
	struct nodo *aux;
	aux = final;
	
	while(aux != NULL)
	{
		printf("\n%d", aux->dato);
		aux = aux->anterior;
	}
	
}


struct nodo * crearNodo(int dato)
{
	struct nodo *nuevo;
	nuevo = (struct nodo *) malloc(sizeof(struct nodo));
	nuevo->dato = dato;
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	
	return (nuevo);
	
}
