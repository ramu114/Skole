#include <stdio.h>

//Function to reverse word/sentence with pointers
void reverse(char *begin,char *end){
    char temp;
    while(begin>end){
        temp=*begin;
        *begin-- = *end;
        *end++ = temp;
    }
}

//Get the length of the sentence
int getLength(char *s){
    int counter;
    char* begin;
    
    begin = s;
    
    while(*begin != '\0'){ //'\0' is the hidden end of the array.
        counter++;
        begin++;
    }
    return counter;
}

int main(void)
{
	/*Variabler*/
    char s[500];
    char last;
    int i,j, length;
    char *begin=s;
    char *end=s;
    
	/*Input*/
    printf("Enter a sentence: ");
    gets(s);
    length=getLength(s);
    begin=&s[length-1];
    
	/*Loops to flip sentence, and then flip the words*/
    for (i=length-1; i>=0; i--){
        if (*(end+i)=='!' || *(end+i)=='?' || *(end+i)=='.'){ /*find end of sentence and save it*/
            last = *(end+i);
            *(end+i)=' ';
        }
        if (*(end+i)==' '){
            //printf("------flip word------\n"); //Prototypes PRINT
            reverse(begin,(end+i+1));
            begin = end+i-1;
            /*for (j=length;j>=0;j--){ //Prototypes PRINT
                printf("%c",s[j]);
            }
            printf("\n");*/
        } else if(i==0){
            //printf("------flip word------\n"); //Prototypes PRINT
            reverse(begin,(end+i));
            /*for (j=length;j>=0;j--){     //Prototypes PRINT
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
