# arc4

an encryption library in C, based on the [RC4](https://en.wikipedia.org/wiki/RC4)
[stream cipher](https://en.wikipedia.org/wiki/Stream_cipher).

### introduction

In cryptography, RC4 (Rivest Cipher 4, also known as ARC4 or ARCFOUR,
meaning Alleged RC4, see below) is a stream cipher.
While it is remarkable for its simplicity and speed in software,
multiple vulnerabilities have been discovered in RC4, rendering it insecure.
It is especially vulnerable when the beginning of the output keystream
is not discarded, or when nonrandom or related keys are used.

To make this implementation of the RC4 cipher more secure, the first
500,000,000 bytes of the output stream are automatically discarded.

##### regardless, it is worth noting that this library isn't fit to be used in high-risk circumstances.

### usage

+ clone the repository

```console
git clone https://github.com/samarthkulshrestha/arc4.git
cd arc4/
```

+ build with make

```console
make
```

this build command outputs the dynamically-linked shared object file `arc4.so`.

+ the example in `ex.c` outlines the usage of the library. here's a quick
preview:

```c
#include "arc4.h"

int main(void) {
  // allocating memory with custom types
  Arc4 *rc4;
  i16 skey, stext;
  char *key, *from;
  i8 *encrypted, *decrypted;

  key = "tomatoes";                                 // keylen = 8 to 2048 bits
  skey = strlen(key);
  from = "to thine own self be true.";
  stext = strlen(from);

  rc4 = rc4init((i8 *)key, skey);                   // initialising encryption
  encrypted = rc4enc(rc4, (i8 *)from, stext);       // encrypt

  rc4uninit(rc4);                                   // uninitialise

  rc4 = rc4init((i8 *)key, skey);                   // reinitialise
  decrypted = rc4dec(rc4, (i8 *)encrypted, stext);  // decrypt

  return 0;
}
```

### contribute

+ i <3 pull requests and bug reports!
+ don't hesitate to [tell me my code-fu sucks](https://github.com/samarthkulshrestha/arc4/issues/new), but please tell me why.

### license

this project is licensed under the MIT License.

Copyright (c) 2024 Samarth Kulshrestha.

