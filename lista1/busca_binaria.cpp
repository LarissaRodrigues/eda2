#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct No{
  char inferior;
  char superior;
  struct No *next;
  struct No *previus;
  int data;
  }tNo;



tNo *allocate_no(tNo *pointer){
  return (tNo*) malloc(sizeof(1));
}

int main(){/*{{{*/
  tNo *sentinela;;
  tNo *primeiro;
  tNo *segundo;
  tNo *terceiro;
  tNo *quarto;
  tNo *quinto;
  tNo *sexto;
  tNo *setimo;
  tNo *oitavo;
  tNo *iterator;
  tNo *_sentinela = allocate_no(sentinela);
  tNo *_primeiro= allocate_no(primeiro);
  tNo *_segundo= allocate_no(segundo);
  tNo *_terceiro= allocate_no(terceiro);
  tNo *_quarto= allocate_no(quarto);
  tNo *_quinto= allocate_no(quinto);
  tNo *_sexto= allocate_no(sexto);
  tNo *_setimo= allocate_no(setimo);
  tNo *_oitavo= allocate_no(oitavo);
  tNo *_iterator = allocate_no(iterator);
/*}}}*/
  

  _sentinela->next = _primeiro;/*{{{*/
 _primeiro->next = segundo;
 _segundo->next = terceiro;
 _terceiro->next = quarto;
 _quarto->next = quinto;
 _quinto->next = sexto;
 _sexto->next = setimo;
 _setimo->next = oitavo;
 _oitavo->next = sentinela;
 iterator = sentinela;
     
 /*{{{*/

 _sentinela->previus= _oitavo;;/*{{{*/
 _primeiro->next = _segundo;
 _primeiro->previus= _sentinela;
 _segundo->next = _terceiro;
 _segundo->previus= _primeiro;
 _terceiro->next = _quarto;
 _terceiro->previus= _segundo;
 _quarto->next = _quinto;
 _quarto->previus= _terceiro;
 _quinto->next = _sexto;
 _quinto->previus = _quarto;
 _sexto->next = _setimo;
 _sexto->previus= _quinto;
 _setimo->next =_oitavo;
 _setimo->previus= _sexto;
 _oitavo->next = _sentinela;
 _oitavo->previus= _setimo;
     /*}}}*/
  
 _sentinela->data = 0;
 _primeiro->data = 12;
 _segundo->data = 25;
 _terceiro->data = 33;
 _quarto->data = 37;
 _quinto->data = 48;
 _sexto->data = 57;
 _setimo->data = 86;
 _oitavo->data = 92;
     
  int valor; cout << "Informe o valor que deseja buscar"<<endl; cin  >> valor;
  
  if(_quarto->data > valor){
  _iterator = _quarto->previus;
  bool achou = false;
  _sentinela->inferior= 'I'; 
  _iterator->superior= 'S';
  while(true){
    if (_iterator->data == valor){
      achou = true;
      break;
    }
    if(_iterator->inferior== 'I')
      break;
    _iterator = _iterator->previus;
  }
  if(achou == true){
    cout <<"valor encontrado dentro da lista"<<endl;
  }
  else
    cout <<"valor não encontrado"<<endl;
  }
  else{
    _oitavo->superior= 'S';
    _iterator = _quarto->next;
    _iterator->inferior = 'I';
    bool achou = false;
    while(true){
      if (_iterator->data == valor){
        achou = true;
        break;
    }
    if(_iterator->superior == 'S')
      break;
    _iterator = _iterator->next;
  }
    if(achou == true)
      cout <<"valor encontrado dentro da lista"<<endl;
    else
      cout <<"valor não encontrado"<<endl;
  }




    } 

