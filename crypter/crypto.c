#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"

bool checkInputText(const char* input, const char* checkSet) {
  bool isLegal = true;
  char ckey;

  if(input ==   '\0'){
    return false;
  }

for (int i = 0; input[i] != '\0'; i++){
  ckey = input[i];
  if(isLegal == false) {
    return false;
  }
  isLegal = false;
  for (int k = 0; checkSet[i] != '\0'; k++) {
    if(ckey == checkSet[i]){
      isLegal = true;
    }
  }
}
return true;
}

bool checkKey(KEY key){
  bool isLegal = true;
  char legalCharacters[] = KEY_CHARACTERS;
  char ckey;
  if(key.chars == '\0') {
    return false;
  }

for (int i = 0; key.chars[i] != '\0'; i++){
  ckey = key.chars[i];
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

void extendKey (const char* input, char* ouput, int increase) {
  int i, k;
  int length = strlen(input);

  for (i = 0, k = 0; i < increase; i++, k++) {
    if(k == length){
      k = 0;
    }
  }
}

void xor (KEY key, const char* input, char* output) {
  if (key.type == 1) {
    char* extendedKey = (char*) malloc(sizeof(char) * (strlen(input) + 1));
    extendKey(key.chars, extendedKey, strlen(input));

    for (int i = 0; i < strlen(input); i++) {
      output[i] = output[i] - 'A' + 1;
      extendedKey[i] = extendedKey[i] - 'A' + 1;

      output[i] = output[i] ^ extendedKey[i];
      output[i] = output[i] + 'A' -1;
    }
    free(extendedKey);

  } else {
    *output = *input;
  }
}


int encrypt(KEY key, const char* input, char* output){
  if(strlen(key.chars) == 0){
    return E_KEY_TOO_SHORT;
  }
  else if(!checkKey(key)) {
    return E_KEY_ILLEGAL_CHAR;
  }
  else if (!checkInputText(input, MESSAGE_CHARACTERS)) {
    return E_MESSAGE_ILLEGAL_CHAR;
  } else {
    xor(key, input, output);
  }
  return 0;
}

int decrypt(KEY key, const char* cypherText, char* output){
  if(strlen(key.chars) == 0){
    return E_KEY_TOO_SHORT;
  }
  else if(!checkKey(key)) {
    return E_KEY_ILLEGAL_CHAR;
  }
  else if (!checkInputText(cypherText, CYPHER_CHARACTERS)) {
    return E_MESSAGE_ILLEGAL_CHAR;
  } else {
    xor(key, cypherText, output);
  }
  return 0;
}
