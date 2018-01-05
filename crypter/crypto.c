#include <stdio.h>
#include <stdbool.h>
#include "crypto.h"

bool checkInputText(char* input) {
  bool isLegal = true;
  char legalCharacters[] = MESSAGE_CHARACTERS;
  char ckey;

for (int i = 0; input[i] != '\0'; i++){
  ckey = input[i];
  if(isLegal == false) {
    return false;
  }
  isLegal = false;
  for (int k = 0; legalCharacters[i] != '\0'; k++) {
    if(ckey == legalCharacters[i]){
      isLegal = true;
    }
  }
}
return true;
}

int checkKey(KEY key){

}


int encrypt(KEY key, const char* input, char* output){
  if (key.type == 1) {



  } else {
    *output = *input;
    return 0;
  }


}
