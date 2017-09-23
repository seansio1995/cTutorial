# include <stdio.h>
# include <stdlib.h>

int main(){
  char *str;

  str=(char*)malloc(15);
  strcpy(str,"Hello World");
  printf("String %s, Address: %u\n",str,str);


  strcat(str,"!");
  printf("String %s, Address: %u\n",str,str);
  free(str);
  return 0;
}
