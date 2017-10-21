typedef struct song_node{
  char song[256];
  char artist[256];
  struct song_node *next;
} song_node;
song_node * table[26];
//tunes.h

int compare_to(song_node *, song_node*);
void print_letter(char);
void print_library();
void add_helper(song_node*, int);
void add(song_node*);
song_node * search_song(char[], char[]);
song_node * search_artist(char []);
void print_artist(char[]);
void free_chain(song_node *);
void delete_all();
song_node * get_previous(char[], char[]);
void delete_song(char[], char[]);
void shuffle(int);
