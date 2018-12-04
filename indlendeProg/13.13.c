#include <stdio.h>
#include <stdlib.h>
void Funktion(char message[], int shift);

int main(void)
{
    //Variabler
    char ch, message[80];
    int shift,i;
    
    //Input
    printf("Enter the message to be encrypted: ");
    fgets(message, 80, stdin);
    printf("Enter shift amount (1-25): ");
    scanf(" %d", &shift);
    
    //Output
    printf("Encrypted message: ");
    Funktion(message,shift);

    
}

void Funktion(char* message, int shift)
{
    //Pointer to point at message
    char* pnd;
    char encrypted_message[80];
    
    pnd = message;
    
    //Loop through the pointer to end.
    for(pnd = message; *pnd; pnd++)
    {
        //Check for BIG letters
        if ('A'<=*pnd&&*pnd<='Z')
        {
            *encrypted_message=((*pnd - 'A') + shift) % 26 + 'A';
        }
        //Check for small Letters
        else if ('a'<=*pnd&&*pnd<='z')
        {
            *encrypted_message=((*pnd - 'a') + shift) % 26 + 'a';
        }
        //Space and symbols
        else
        {
             *encrypted_message=*pnd;
        }
        //Print letter.
        printf("%c",*encrypted_message);
    }
}

