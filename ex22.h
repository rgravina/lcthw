#ifndef _ex22_h
#define _ex22_h

// makes this var available to other c files
extern int THE_SIZE;

// sets a static variable in ex22.c
int get_age();
void set_age(int age);

// updates a static variable inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif
