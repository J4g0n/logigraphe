#ifndef base_h
#define base_h

typedef unsigned int Nat;
typedef int Rel;
typedef float Reel;

#define K 100
#define vrai (1==1)
#define faux (!vrai)
#define MALLOC(t) ((t*)malloc(sizeof(t))
#define MALLOCN(t,n) ((t*)malloc(n*sizeof(t))
#define REALLOC(t) ((t*)malloc(x,n*sizeof(t))
#define FREE(t) free(t)

#endif
