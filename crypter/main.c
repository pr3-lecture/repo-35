#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"

 int main(int argc, char* argv[]) {
   if(argc == 1) {
     printf("Keine Parameter \n");
   }

   KEY key = {1, argv[1]};
   char input[100];
   int returnValue;
   char* result;

   if (argc == 2) {
     fgets(input, 100, stdin);
     result = (char*) malloc(sizeof(char) * strlen(input));
     if(strstr(argv[0], "encrypt")) {
       returnValue = encrypt(key, input, result);
     } else if (strstr(argv[0], "decrypt")) {
       returnValue = decrypt(key, input, result);
     }
     printf("%s \n", result);
     free(result);
   }

   switch(returnValue) {
     case E_KEY_TOO_SHORT:
      fprintf(stderr, "Key zu kurz"); break;
     case E_KEY_ILLEGAL_CHAR:
      fprintf(stderr, "Ungültige Zeichen in Key");break;
     case E_MESSAGE_ILLEGAL_CHAR:
      fprintf(stderr, "Ungültige Zeichen in Nachricht"); break;
     case E_CYPHER_ILLEGAL_CHAR:
      fprintf(stderr, "Ungültige Zeichen in verschlüsseltem Text"); break;
     default: return returnValue;
   }
 }
