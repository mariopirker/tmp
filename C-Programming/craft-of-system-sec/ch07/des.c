#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <openssl/des.h>

/* This function simply takes a key, a plaintext message and the size of the plain text as input 
   The outcome of the function will be the encrypted DES result */
char *Encrypt(char *Key, char *Msg, int size){
	static char 		*Res;
	int 			n=0;
	DES_cblock		Key2;
	DES_key_schedule	schedule;

	Res = (char *) malloc(size);
	
	/* prepare the key for use with DES_cfbit64_encrypt */
	/* We assume that the key is just 8 characters wide */
	memcpy(Key2,Key,8);
	DES_set_odd_parity(&Key2);
	DES_set_key_checked(&Key2, &schedule);

	/* the actual enryption occurs here */
	DES_cfb64_encrypt( (unsigned char *) Msg, (unsigned char *) Res, size,  &schedule, &Key2, &n, DES_ENCRYPT);
	return (Res);

}

/* This function simply takes a key, the encrypted plaintext and the size of the plain text as input
   The outcome of the function will be the decryted plain text */
char *Decrypt(char *Key, char *Msg, int size){
	static char 		*Res;
	int 			n=0;
	DES_cblock      	Key2;
        DES_key_schedule 	schedule;
 
        Res = ( char * ) malloc( size );
	/* Prepare the key for use with DES_cfb64_encrypt */
	memcpy( Key2, Key,8);
        DES_set_odd_parity( &Key2 );
        DES_set_key_checked( &Key2, &schedule );
	/* Decryption occurs here */
	DES_cfb64_encrypt( ( unsigned char * ) Msg, ( unsigned char * ) Res,
                           size, &schedule, &Key2, &n, DES_DECRYPT );
 
        return (Res);

}

int main(){
	char key[]="password";
	char key2[]="anotherkey";
	char clear[]="This is the secret message";
	
	char *decrypted;
	char *encrypted;

	encrypted=malloc(sizeof(clear));
	decrypted=malloc(sizeof(clear));

	printf("Clear text\t : %s \n", clear);
	memcpy(encrypted,Encrypt(key,clear,sizeof(clear)),sizeof(clear));
	printf("Encrypted text\t : %s\n",encrypted);
	//memcpy(decrypted,Decrypt(key2,encrypted,sizeof(clear)),sizeof(clear));
	memcpy(decrypted,Decrypt(key,encrypted,sizeof(clear)),sizeof(clear));
	printf("Decrypted text\t : %s\n",decrypted);

	return 0;

}
