#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{
  char song[256];
  char artist[256];
  struct song_node *next;
} song_node;
song_node * table[26];






void print_table(int a){
  song_node *x =  table[a];
  printf("table for %d : ", a);  
  while (x){
    printf("%s , %s ; ", x->artist, x->song);
    x= x->next;
  }
  printf("\n");
}
void add_helper(song_node* n, int a){
  song_node * x = table[a];
  if (!table[a]){
    printf("x\n");
    table[a] = n;
    return;
  }
  printf("y\n");
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
  add(a);
  song_node* b=malloc(1000);
  strcpy(b->artist, "alilpump");
  strcpy(b->song, "harvarddropout");
  add(b);

  print_table(0);
  song_node* c=malloc(1000);
  strcpy(c->artist, "apump");
  strcpy(c->song, "yale");
  add(c);
 
  print_table(0);
  song_node* d=malloc(1000);
  strcpy(d->artist, "am");
  strcpy(d->song, "yal");
  add(d);
  
  
  print_table(0);
  return 0;
}
