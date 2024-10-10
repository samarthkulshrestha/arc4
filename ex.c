#include "arc4.h"

#define F fflush(stdout)

int main(void);

// ef20 ac12

void printbin(i8 *input, const i16 size) {
  i16 i;
  i8 *p;

  assert(size > 0);

  for (i = size, p = input; i; i--, p++) {
    if (!(i % 2))
      printf(" ");

    printf("%.02x", *p);
  }

  printf("\n");
  return;
}

int main() {
  Arc4 *rc4;
  i16 skey, stext;
  char *key, *from;
  i8 *encrypted, *decrypted;

  key = "tomatoes";         // 8 bits -> 2048 bits
  skey = strlen(key);
  from = "to thine own self be true.";
  stext = strlen(from);

  printf("initialising encryption...\n"); F;
  rc4 = rc4init((i8 *)key, skey);
  printf("done.\n");

  printf("'%s'\n  -> ", from);
  encrypted = rc4enc(rc4, (i8 *)from, stext);
  printbin((i8 *)encrypted, stext);

  printf("\n==============================\n");
  rc4uninit(rc4);
  printf("initialising encryption...\n"); F;
  rc4 = rc4init((i8 *)key, skey);
  printf("done.\n");

  decrypted = rc4dec(rc4, (i8 *)encrypted, stext);
  printf("  -> '%s'\n", decrypted);

  return 0;
}
