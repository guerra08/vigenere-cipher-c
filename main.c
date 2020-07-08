#include <stdio.h>
#include <string.h>

void encryptText(char* rawText, char* key);
void decryptText(char* encText, char* key);
void makeKey(int size, char* key, char* genKey);

int main(int argc, char* argv[]){
    if(argc == 1){
        printf("---- Vigenère Cipher ----\n\n");
        printf("Encrypts / decrypts text using the Vigenère Cipher\n");
        printf("Both text and key need to be in uppercase.\n\n");
        printf("Commands: \n");
        printf("    --enc: Encrypts raw text argument \n");
        printf("    --dec: Decrypts text to raw \n\n");
        printf("Examples: \n");
        printf("    vigenere --enc \"HELLO\" \"TRT\"\n");
        printf("    vigenere --dec \"FCCDS\" \"LOP\"\n");
        return 0;
    }
    else if(argc == 4){
        char genKey[strlen(argv[2]) + 1];
        makeKey(strlen(argv[2]), argv[3], genKey);
        if(strcmp(argv[1], "--enc") == 0){
            encryptText(argv[2], genKey);
        }
        else if(strcmp(argv[1], "--dec") == 0){
            decryptText(argv[2], genKey);
        }
        return 0;
    }
    else{
        printf("Invalid arguments\n");
        return 1;
    }
}

void makeKey(int size, char* key, char* genKey){
    int i = 0;
    int j = 0;
    while(1){
        if(i == strlen(key)){
            i = 0;
        }
        if(j == size){
            break;
        }
        genKey[j] = key[i];
        i++;
        j++;
    }
    genKey[size - 1] = '\0';
}

void encryptText(char* rawText, char* key){
    int size = strlen(rawText) + 1;
    char encrypted[size];
    for(int i = 0; i < strlen(rawText); i++){
        char c = (rawText[i] + key[i]) % 26; 
        c += 'A';
        encrypted[i] = c;
    }
    encrypted[size - 1] = '\0';
    printf("Encrypted text: %s\n", encrypted);
}

void decryptText(char* encText, char* key){
    int size = strlen(encText) + 1;
    char decrypted[size];
    for(int i = 0; i < strlen(encText); i++){
        char c = (encText[i] - key[i] + 26) % 26; 
        c += 'A';
        decrypted[i] = c;
    }
    decrypted[size - 1] = '\0';
    printf("Decrypted text: %s\n", decrypted);
}