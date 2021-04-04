#include "deck.h"

Deck* createDeck () {
  return NULL;
}

/*Função que retorna a coordenada armazenada na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getFront (Deck *d) {
   /*Terminar ...*/
   return d->p;
}

/*Função que retorna a coordenada armazenada na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getRear (Deck *d) {
   /*Terminar ...*/
    Deck *aux = d;
    while (aux->next != NULL)
    {
        aux = aux->prev;
    }

    return aux->p;
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
   /*Terminar ...*/
   field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/
   /*Terminar ...*/
   Deck *novo = (Deck*)malloc(sizeof(Deck));
    novo->p = p;
    novo->proximo = d;
    novo->anterior = NULL;
  
    if(d != NULL){
      d->prev = novo;
    }
  
    return novo;
}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   /*Terminar ...*/
  field[p.x][p.y] = '*';  /*Ponto inserido faz parte do corpo da Snake!*/
  Node *aux = d;
  while(aux->next != NULL){
      aux = aux->next;  
  }
  Deck *novo = (Deck*)malloc(sizeof(Deck));
  novo->next = NULL;
  novo->prev = aux;
  novo->p = p;
  aux->next = novo;
  
  return novo;
  /*Terminar ...*/
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteFront (Deck *d, char field[][SIZE]) {
   /*Terminar ...*/
   //field[x][y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
   /*Terminar ...*/
  Deck *aux = d->next;
  field[d->p.x][d->p.y] = ' ';
  free(d);
  aux->prev = NULL;
  return aux;
}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteRear (Deck *d, char field[][SIZE]) {
   /*Terminar ...*/
   //field[x][y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
   /*Terminar ...*/
  Deck aux * = d;
  while(aux->next != NULL){
    aux = aux->next;
  }
  
  field[aux->p.x][aux->p.y] = ' ';
  aux->next->prev = NULL;
  free(aux);
  
  return d;
}


