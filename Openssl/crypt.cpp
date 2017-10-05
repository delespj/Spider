#include "crypt.h"
#include <iostream>

Crypt::Crypt() 
{
  initialise();
}

Crypt::~Crypt()
{
  EVP_CIPHER_CTX_free(aesEncrypt);
  EVP_CIPHER_CTX_free(aesDecrypt);

  free(aesKey);
  free(aesIv);
}

int Crypt::initialise() 
{
  aesEncrypt = EVP_CIPHER_CTX_new();
  aesDecrypt = EVP_CIPHER_CTX_new();

  if( aesEncrypt == NULL || aesDecrypt == NULL)
    return -1;

  generate_aesKey(&aesKey, &aesIv);

  return 0;
}


int Crypt::generate_aesKey(unsigned char **aes_key, unsigned char **aes_iv) 
{
  *aes_key = (unsigned char*)malloc(AES_KEYLEN/8);
  *aes_iv = (unsigned char*)malloc(AES_KEYLEN/8);

  if(aes_key == NULL || aes_iv == NULL) 
    return -1;

  if(RAND_bytes(*aes_key, AES_KEYLEN/8) == 0)
    return -1;
  
  if(RAND_bytes(*aes_iv, AES_KEYLEN/8) == 0)
      return -1;
  return 0;
}

int Crypt::aes_Encrypt(unsigned char *message, int message_len, unsigned char **cipher_message) 
{
  int size_block = 0;
  int cipher_len = 0;

  *cipher_message = (unsigned char*)malloc(message_len + AES_BLOCK_SIZE);
  if(cipher_message == NULL)
    return -1;

  if(EVP_EncryptInit_ex(aesEncrypt, EVP_aes_256_cbc(), NULL, aesKey, aesIv) != 1)
    return -1;

  if(EVP_EncryptUpdate(aesEncrypt, *cipher_message, &size_block, message, message_len) != 1)
    return -1;

  cipher_len += size_block;

  if(EVP_EncryptFinal_ex(aesEncrypt, *cipher_message + cipher_len, &size_block) != 1)
    return -1;

  return cipher_len + size_block;
}

int Crypt::aes_Decrypt(unsigned char *cipher_message, int cipher_len, unsigned char **message_decrypt) 
{
  int message_len = 0;
  int size_block = 0;

  *message_decrypt = (unsigned char*)malloc(cipher_len);
  if(*message_decrypt == NULL)
    return -1;

  if(EVP_DecryptInit_ex(aesDecrypt, EVP_aes_256_cbc(), NULL, aesKey, aesIv) != 1) 
    return -1;

  if(EVP_DecryptUpdate(aesDecrypt, (unsigned char*)*message_decrypt, &size_block, cipher_message, cipher_len) != 1)
    return -1;

  message_len += size_block;

  if(EVP_DecryptFinal_ex(aesDecrypt, (unsigned char*)*message_decrypt + message_len, &size_block) != 1)
    return -1;

  message_len += size_block;
  return message_len;
}

int Crypt::get_aesKey(unsigned char **aes_key) 
{
  *aes_key = this->aesKey;
  return *this->aesKey;
}

int Crypt::set_aesKey(unsigned char *aes_key, int key_len) 
{  
  if(key_len != AES_KEYLEN/8)
    return -1;

  memcpy(this->aesKey, aes_key, AES_KEYLEN/8);
  return 0;
}

int Crypt::get_aesIv(unsigned char **aes_iv) 
{
  *aes_iv = this->aesIv;
  return *this->aesIv;
}

int Crypt::set_aesIv(unsigned char *aes_iv, int iv_len) 
{
  if(iv_len != AES_KEYLEN/8) 
    return -1;

  memcpy(this->aesIv, aes_iv, AES_KEYLEN/8);
  return 0;
}
