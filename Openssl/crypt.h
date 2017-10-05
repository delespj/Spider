#ifndef CRYPT_H_
# define CRYPT_H_

#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

#define AES_KEYLEN 256

class Crypt
{
  public:
	Crypt();
 	~Crypt();

	int aes_Encrypt(unsigned char *message, int message_len, unsigned char **cipher_message);
    int aes_Decrypt(unsigned char *cipher_message, int cipher_len, unsigned char **message_decrypt);

    int get_aesKey(unsigned char **aes_key);
    int set_aesKey(unsigned char *aes_key, int key_len);

    int get_aesIv(unsigned char **aes_iv);
    int set_aesIv(unsigned char *aes_iv, int iv_len);

  private:

    EVP_CIPHER_CTX *aesEncrypt;
    EVP_CIPHER_CTX *aesDecrypt;

    unsigned char *aesKey;
    unsigned char *aesIv;

    int initialise();
    int generate_aesKey(unsigned char **aes_key, unsigned char **aes_iv);

};

#endif