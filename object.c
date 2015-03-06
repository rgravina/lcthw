#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self) {
  Object *obj = self;
  if(obj) {
    if(obj->description) free(obj->description);
    free(obj);
  }  
}

void Object_describe(void *self) {
  Object *obj = self;
  printf("%s.\n", obj->description);  
}

int Object_init(void *self) {
  // do nothing
  return 1;
}

void *Object_move(void *self, Direction direction) {
  printf("You can't go in that direction.\n");
  return NULL;
}

int Object_attack(void *self, int damage) {
  printf("You can't attack that.\n");
  return 0;  
}

void *Object_new(size_t size, Object proto, char *description) {
  // setup default functions
  if(!proto.init) proto.init = Object_init;
  if(!proto.describe) proto.describe = Object_describe;
  if(!proto.destroy) proto.destroy = Object_destroy;
  if(!proto.attack) proto.attack = Object_attack;
  if(!proto.move) proto.move = Object_move;

  // Note: I don't quite understand this...
  // Make a struct of one size and them point a different pointer at to cast it.
  Object *el = calloc(1, size);

  // copy description
  el->description = strdup(description);

  if(!el->init(el)) {
    // didin't initialise properly
    el->destroy(el);
    return NULL;
  } else {
    // object of any type
    return el;
  }
}
