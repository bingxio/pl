#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct User {
  char *id;
  char *create_at;
} turaiiao;

typedef struct Car {
  turaiiao *driver;
} car;

int main() {
  turaiiao *a = malloc(sizeof (turaiiao));

  a->id = "455dfb782cx067as953dlvs33v0df78azcd42068as545ds207";
  a->create_at = "20190516";

  int len = strlen(a->id);

  for (int i = 0; i < len; i ++) {
    int c = a->id[i];

    if (c >= 'a' && c <= 'z') {
      printf("%-2c", c);
    }
  }

  printf("\n");

  car *d = malloc(sizeof (car));

  d->driver = a;

  turaiiao *e = (turaiiao *) d->driver;

  printf("%s \n", e->id);
  printf("%s \n", e->create_at);

  turaiiao **f = &a;

  printf("%s %s \n", ((turaiiao *) *f)->id, ((turaiiao *) *f)->create_at);

  free(a);

  a = malloc(sizeof (turaiiao));

  a->id = "1234567890000000000987654321234567890098776tre2143";
  a->create_at = "7890";

  f = &a;

  printf("%s %s \n", ((turaiiao *) *f)->id, ((turaiiao *) *f)->create_at);
}