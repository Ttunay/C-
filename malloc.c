#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 81 

struct namect {
  char * fname;
  char * lname;
  int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup( struct namect *);

char * s_gest(char * st, int n);


int main(void)
{
  struct namect person;

  getinfo(&person);
  makeinfo(&person);
  showinfo(&person);
  cleanup(&person);

  return 0;
}
void getinfo (struct namect * pst)
{
  char temp[SLEN];
  printf("your name?\n");
  s_gest(temp,SLEN);
  // выделение памяти 
  pst->fname = (char *) malloc(strlen(temp)+1);
  // копирование имени в выделенную память
  strcpy(pst->fname,temp);
  printf("you lastname\n");
  s_gest(temp,SLEN);
  pst->lname = (char *) malloc(strlen(temp)+1);
  strcpy(pst->lname,temp);
}
void makeinfo(struct namect * pst)
{
  pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo(const struct namect * pst)
{
  printf("%s %s your name and lastname %d bykv\n",pst->fname,pst->lname, pst->letters);
}


void cleanup(struct namect * pst){
  free(pst->fname);
  free(pst->lname);
}


char * s_gest(char * st, int n)
{
  char * ret_val;
  char * find;
  ret_val = fgets(st,n,stdin);
  if(ret_val)
  {
    find = strchr(st, '\n');
    if(find)
      *find = '\0';
    else 
        while(getchar()!= '\n')
        continue;  
  } 
  return  ret_val;
}