#include <stdio.h>
#include <stdlib.h>
#include <string.h>

song_node* add_helper(song_node*, int);

typedef struct song_node{
  char song[256];
  char artist[256];
  struct song_node *next;
}song_node;

/*song_node insert_front(char ){
  song_node

  }*/
song_node* add(song_node* n){
  return add_helper(n,1);
}
song_node* add_helper(song_node* n, int a){
  return n;
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
  return 0;
}
