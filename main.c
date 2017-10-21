#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunes.h"
#include <time.h>


int compare_to(song_node* n1, song_node* n2){
  if (strcmp(n1->artist,n2->artist)!=0){
    return strcmp(n1->artist,n2->artist);
  }
  else{
    return strcmp(n1->song,n2->song);
  }
    
}

void print_letter(char c){
  int y = (int)c-'a';
  song_node *x =  table[y];
  printf("Table for artists starting with %c : ", c);  
  while (x->next){
    printf("%s - %s | ", x->artist, x->song);
    x= x->next;
  }
  printf("%s - %s ", x->artist, x->song);
  printf("\n\n");
}
void print_library(){
  int i = 0;
  printf("Entire Library : ");
  for (; i<26; i++){
    if (table[i]){
    song_node *x = table[i];
    while(x->next){
      printf("%s - %s | ", x->artist, x->song);
      x = x->next;
    }
      printf("%s - %s | ", x->artist, x->song);

    }
  }
}


void add_helper(song_node* n, int a){
  song_node * x = table[a];
  if (!table[a]){//empty list
    table[a] = n;
    return;
  }
  if (compare_to(n,x)<0){//front of list
    table[a] = n;
    n->next = x;
    return;
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
  printf("Song Doesn't Exist");
  return 0;
}
song_node * search_artist(char a[256]){
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
   if (!(strcmp(a,z->artist))){
      return z;
    }
 
   printf("Artist doesn't exist)");
     return 0;
}

void print_artist(char a[256]){
  printf("Songs for artist %s : ", a);
   char x = a[0];
  int y = (int)x-'a';
  song_node *z = table[y];
  while (z->next){
    if (!(strcmp(a,z->artist))){
      printf("%s | ", z->song);
      z=z->next;
    }
    else{
      z=z->next;
    }
  }
  if (!(strcmp(a,z->artist))){
      printf("%s | ", z->song);
    }
 
}

void free_chain(song_node* n){
  if(!n){
    return;
  }
  free_chain(n->next);
  free(n);
  return;
}



void delete_all(){
  int i;
  for(i = 0; i < 26; i++){
    free_chain(table[i]);
    table[i] = 0;
  }
}

song_node * get_previous(char s[256], char a[256]){
  song_node * spot = search_song(s, a);
  if(!spot){
    return 0;
  }
  char x = a[0];
  int y = (int)x - 'a';
  song_node * tabler = table[y];
  if(tabler == spot){
    return 0;
  }
  else{
    song_node * prev = table[0];
    while(tabler != spot){
      prev = tabler;
      tabler = tabler->next;
    }
    return prev;
  }
}

void delete_song(char s[256], char a[256]){
  song_node * spot = search_song(s, a);
  if(!spot){
    printf("Song doesn't exist");
    return;
  }
  else{
    song_node * prev = get_previous(s, a);
    if(!prev){//first element
      if(!spot->next){//only element
	free(spot);
	char x = a[0];
	int y = (int)x - 'a';
	table[y] = 0;
      }
      else{
	char x = a[0];
	int y = (int)x - 'a';
	table[y] = spot->next;
	free(spot);
      }
    }
    else{
      if(!spot->next){//last element
	prev->next = 0;
	free(spot);
      }
      else{//middle case
	prev->next = spot->next;
	free(spot);
      }      
    }
  } 
}



void shuffle(int n){
  srand(time(NULL));
  int i = 0;
  int attempts = 0;
  printf("Shuffling : \n");
  while(i < n && attempts < 5000){
    attempts++;
    int let = rand() % 26;
    song_node * ele = table[let];
    if(ele){
      int added = 0;
      while(!added){
	int boo = rand() % 10;
	if(!boo){
	  printf("%s - %s\n", ele->artist, ele->song);
	  i++;
	  added = 1;
	}
	if(!ele->next){
	  added = 1;
	}
	else{
	  ele = ele->next;	
	}
      }
    }
  }
  if(i < n){
    printf("out of songs!");
  }
}

int main(){


  printf("\t\t\t Testing add and print_letter\n\n");
  song_node* b=malloc(550);
  strcpy(b->artist, "adele");
  strcpy(b->song, "hello");
  add(b);
    
  song_node* a=malloc(550);
  strcpy(a->artist, "adele");
  strcpy(a->song, "rolling in the deep");
  add(a);
  
 
    song_node* c=malloc(550);
  strcpy(c->artist, "ariana grande");
  strcpy(c->song, "side to side");
  add(c);
  
  
  song_node* d=malloc(550);
  strcpy(d->artist, "post malone");
  strcpy(d->song, "rockstar");
  add(d);
  print_letter('a');
 
  printf("\t\t\tTesting search_node\n\n");

  printf("Search for adele - hello : Got %s - %s\n\n", search_song("hello","adele")->artist, search_song("hello","adele")->song);

  printf("\t\t\tTesting search_artist\n\n");

  printf("Search for artist adele : Got %s - %s\n\n", search_artist("adele")->artist, search_artist("adele")->song);

  printf("\t\t\tTesting print_artist\n\n");

  print_artist("apick");
  printf("\n\n");

  song_node * e = malloc(550);
  strcpy(e->song,"gucci gang");
  strcpy(e->artist, "lil pump");
  add(e);
  song_node *f = malloc(550);
  strcpy(f->song, "believer");
  strcpy(f->artist, "imagine dragons");
  add(f);
   song_node *g = malloc(550);
  strcpy(g->song, "thunder");
  strcpy(g->artist, "imagine dragons");
  add(g);
 
  printf("\t\t\tTesting print_library\n\n");
  print_library();
  printf("\n\n");
  printf("\t\t\tTesting shuffle\n\n");
  shuffle(5);
  printf("\n\n");
  printf("\t\t\tTesting delete_song\n\n");
  printf("Before : ");
  print_letter('a');
  printf("Deleted adele - hello\nAfter : ");
  delete_song("hello", "adele");
  print_letter('a');
  printf("\t\t\tTesting delete_all\n\n");
  printf("Before : ");
  print_library();
  delete_all();
  printf("\nAfter : ");
  print_library();
  printf("\n\n");
  
  return 0;
}


