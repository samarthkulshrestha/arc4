#include "arc4.h"
#include <assert.h>

export Arc4 *rc4init(i8 *key, i16 size) {
  i16 x;
  i16 tmp1, tmp2;
  i32 n;

  Arc4 *p;

  if (!(p = malloc(sizeof(struct s_arc4))))
    assert_perror(errno);

  for (x = 0; (int)x < 256; x++)
    p->s[x] = 0;

  p->i = p->j = p->k = 0;
  tmp1 = tmp2 = 0;

  for (p->i = 0; (int)p->i < 256; p->i++)
    p->s[p->i] = p->i;

  for (p->i = 0; (int)p->i < 256; p->i++) {
    tmp1 = p->i % size;
    tmp2 = p->j + p->s[p->i] + key[tmp1];
    p->j = tmp2 % 256;

    tmp1 = p->s[p->i];
    tmp2 = p->s[p->j];
    p->s[p->i] = tmp2;
    p->s[p->j] = tmp1;
  }

  p->i = p->j = 0;
  rc4whitewash(n, p);

  return p;
}

i8 rc4byte(Arc4 *p) {
  i16 tmp1, tmp2;

  p->i = (p->i + 1) % 256;
  p->j = (p->j + p->s[p->i]) % 256;

  tmp1 = p->s[p->i];
  tmp2 = p->s[p->j];
  p->s[p->i] = tmp2;
  p->s[p->j] = tmp1;

  tmp1 = (p->s[p->i] + p->s[p->j]) % 256;
  p->k = p->s[tmp1];

  return p->k;
}

export i8 *rc4enc(Arc4 *p, i8 *cleartext, i16 size) {
  i8 *ciphertext;
  i16 x;

  ciphertext = (i8 *)malloc(size + 1);
  if (!ciphertext)
    assert_perror(errno);

  for (x = 0; x < size; x++)
    ciphertext[x] = cleartext[x] ^ rc4byte(p);

  return ciphertext;
}
