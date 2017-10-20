#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct song_node{
  char song[256];
  char artist[256];
  struct song_node *next;
} song_node;
song_node * table[26];




int compare_to(song_node* n1, song_node* n2){
  if (strcmp(n1->artist,n2->artist)!=0){
    return strcmp(n1->artist,n2->artist);
  }
  else{
    return strcmp(n1->song,n2->song);
  }
    
}

void print_table(int a){
  song_node *x =  table[a];
  printf("table for %d : ", a);  
  while (x->next){
    printf("%s - %s | ", x->artist, x->song);
    x= x->next;
  }
  printf("%s - %s | ", x->artist, x->song);
  printf("\n\n");
}


void add_helper(song_node* n, int a){
  song_node * x = table[a];
  if (!table[a]){//empty list
    table[a] = n;
    return;
  }
  if (compare_to(n,x)<0){//front of list
    table[a] = n;
    n->next;
  }
  song_node * prev = table[a];
  while(compare_to(n,x)>=0&&x->next){//middle of list
    prev = x;
    x= x->next;
  }
  if (x && compare_to(n,x)<=0){//middle
  n->next = x;
  prev->next = n;
  }
  else{//end
    x->next = n;
  }
}

void add(song_node* n){
  char x = (n->artist)[0];
  int y = (int)x - 'a';
  add_helper(n,y);
}


song_node * search_song(char s[256] , char a[256] ){
   char x = a[0];
  int y = (int)x - 'a';
  song_node * z = table[y];
  while (z->next){//loops until end element
    if (!(strcmp(s,z->song)||strcmp(a,z->artist))){
      return z;
    }
    else{
      z=z->next;
    }
  }
    if (!(strcmp(s,z->song)||strcmp(a,z->artist))){//last element
   return z;
  }
  printf("No Such Element");
  return 0;
}
song_node * artist(char a[256]){
  char x = a[0];
  int y = (int)x-'a';
  song_node *z = table[y];
  while (z->next){
    if (!(strcmp(a,z->artist))){
      return z;
    }
    else{
      z = z->next;
    }
  }
}



int main(){

  printf("\t\t\t Testing add\n\n");
  song_node* b=malloc(550);
  strcpy(b->artist, "adick");
  strcpy(b->song, "barvarddropout");
  add(b);
    
  song_node* a=malloc(550);
  strcpy(a->artist, "adick");
  strcpy(a->song, "casper");
  add(a);
  
 
    song_node* c=malloc(550);
  strcpy(c->artist, "amar");
  strcpy(c->song, "humble");
  add(c);
  
  
  song_node* d=malloc(550);
  strcpy(d->artist, "am");
  strcpy(d->song, "yal");
  add(d);
  print_table(0);
 
  printf("\t\t\tTesting search_node\n\n");

  printf("Search for amar - humble : Got %s - %s\n\n", search_song("humble","amar")->artist, search_song("humble","amar")->song);
  

  return 0;
}
