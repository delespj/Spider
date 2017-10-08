#include "crypt.hh"
#include <string.h>
#include <iostream>

Crypt::Crypt() 
{
  initialise();
  set_aesKey();
  set_aesIv();
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

std::string    Crypt::decrypt(std::string encryptedMessage)
{
  unsigned char*        cipher_message;
  char* decryptedMessage = NULL;

  cipher_message = (unsigned char*)malloc(48 + 1);
  strcpy((char*)cipher_message, encryptedMessage.c_str());
  int   decrpytedMessageSize = this->aes_Decrypt(cipher_message, 48, (unsigned char**)&decryptedMessage);

  std::cout << "decrypted message : " << decryptedMessage << std::endl;
  return (decryptedMessage);
}


int Crypt::set_aesKey()
{
  this->aesKey = (unsigned char*)malloc(32 + 1);
  strcpy((char*)this->aesKey, "92105739640519249765841578435238");
  return 0;
}

int Crypt::set_aesIv()
{
  this->aesKey = (unsigned char*)malloc(16 + 1);
  strcpy((char*)this->aesKey, "1429753135795235");
  return 0;
}
