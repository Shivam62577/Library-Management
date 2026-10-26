#include<stdio.h>
#include<string.h>

int main(void){

    FILE *ptr = fopen("data.txt","w");

    int id=5;
    char BookTitle[50] = "The C rpogramming language";
    char author[50] = "Brian Kernighan";

    fprintf(ptr,"%d\n%s\n%s\n",id,BookTitle,author);
    fclose(ptr);
    return 0;
}