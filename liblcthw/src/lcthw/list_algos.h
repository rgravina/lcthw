#ifndef lcthw_List_Algos_h
#define lcthw_List_Algos_h

typedef int (*List_compare)(const void *a, const void *b);
int List_bubble_sort(List *words, List_compare strcmp);
List *List_merge_sort(List *words, List_compare strcmp);

#endif
