#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{
  char song[256];
  char artist[256];
  struct song_node *next;
} song_node;
struct song_node * table[26];



void print_table(int a){
  song_node *x =  table[a];
  printf("table for %d : ", a);  while (x){
    printf("%s , %s ; ", x->artist, x->song);
    x= x->next;
  }
  printf("\n");
}
void add_helper(song_node* n, int a){
  song_node * x = table[a];
  if (compareto(n,x)<0){
    n->next = x;
    table[a] = n;
  }
  while(compareto(n,x)>=0&&x->next){
    x = x->next;
  }
  n->next = x->next;
  x->next = n;
}

void add(song_node* n){
  char x = (n->artist)[0];
  int y = (int)x - 'a';
  add_helper(n,y);
}


int compareto(song_node* n1, song_node* n2){
  if (!(strcmp(n1->artist,n2->artist))){
    return strcmp(n1->artist,n2->artist);
  }
  else{
    return strcmp(n1->song,n2->song);
  }
}


int main(){

  song_node* a=malloc(1000);
  strcpy(a->artist, "adick");
  strcpy(a->song, "jasper");
  add_helper(a,0);
  print_table(0);
  return 0;
}
