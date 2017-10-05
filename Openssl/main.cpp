
#include "crypt.h"
#include <stdio.h>

std::string getMessage(const char *);
void run(Crypt *);

using std::string;

void run(Crypt *crypt) 
{
  string message = getMessage("Message to AES encrypt: ");

  unsigned char *cipher_message = NULL;
  int cipher_len = crypt->aes_Encrypt((unsigned char*)message.c_str(), message.size()+1, &cipher_message);

  printf("Ciphertext is:\n");	
  BIO_dump_fp (stdout, (const char *)cipher_message, cipher_len);

  char *decryptedMessage = NULL;
  int decryptedMessageLength = crypt->aes_Decrypt(cipher_message, (int)cipher_len, (unsigned char**)&decryptedMessage);

  printf("Decrypted message: %s\n", decryptedMessage);  

  free(cipher_message);
  free(decryptedMessage);
  cipher_message = NULL;
  decryptedMessage = NULL;

}

string getMessage(const char *prompt) 
{
  string message;

  printf("%s\n", prompt); // ici tu rentres le message que tu veux <3 
  fflush(stdout);

  getline(std::cin, message);
  return message;
}

int main()
{
	Crypt crypt;

	run(&crypt);
	return 0;
}
