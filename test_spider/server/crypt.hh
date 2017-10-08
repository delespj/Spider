#ifndef CRYPT_HH_
# define CRYPT_HH_

#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

#define AES_KEYLEN 256
#define ENCRYPTED_MSG_LEN 48

class Crypt
{
  public:
  Crypt();
  ~Crypt();

  int aes_Encrypt(unsigned char *message, int message_len, unsigned char **cipher_message);
  int aes_Decrypt(unsigned char *cipher_message, int cipher_len, unsigned char **message_decrypt);

  int set_aesKey();
  int set_aesIv();

  std::string	decrypt(std::string encryptedMessage);
  std::string	encrypt(std::string message);

 private:

  EVP_CIPHER_CTX *aesEncrypt;
  EVP_CIPHER_CTX *aesDecrypt;

  unsigned char *aesKey;
  unsigned char *aesIv;

  int initialise();
};

#endif
