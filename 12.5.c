#include <stdio.h>

void reverse(char *begin,char *end){
    char temp;
    while(begin>end){
        temp=*begin;
        *begin-- = *end;
        *end++ = temp;
    }
}

int getLength(char *s){
    int counter;
    char* begin;
    
    begin = s;
    
    while(*begin != '\0'){
        counter++;
        begin++;
    }
    return counter;
}

int main(void)
{
    char s[500];
    char last;
    int i,j, length;
    char *begin=s;
    char *end=s;
    
    printf("Enter a sentence: ");
    gets(s);
    printf("\n");
    length=getLength(s);
    begin=&s[length-1];
    
    for (i=length-1; i>=0; i--){
        if (*(end+i)=='!' || *(end+i)=='?' || *(end+i)=='.'){
            last = *(end+i);
            *(end+i)=' ';
        }
        if (*(end+i)==' '){
            //printf("------flip word------\n"); //MELLEMREGNINGER PRINT
            reverse(begin,(end+i+1));
            begin = end+i-1;
            /*for (j=length;j>=0;j--){ //MELLEMREGNINGER PRINT
                printf("%c",s[j]);
            }
            printf("\n");*/
        } else if(i==0){
            //printf("------flip word------\n"); //MELLEMREGNINGER PRINT
            reverse(begin,(end+i));
            /*for (j=length;j>=0;j--){     //MELLEMREGNINGER PRINT
                printf("%c",s[j]);
            }
            printf("\n");*/
        }
    }
    printf("\n\nThe reserved sentence is:");
    for (j=length;j>=0;j--){
        printf("%c",s[j]);
    }
    printf("%c\n\n", last);
}

 
