#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define MS                  500
#define export              __attribute__((visibility("default")))
#define rc4dec(x, y, z)     rc4enc(x, y, z)
#define rc4uninit(x)        free(x)
#define rc4whitewash(x,y)   for (x = 0; x < (MS * 1000000); x++) \
                              (volatile i8)rc4byte(y);

typedef unsigned char i8;
typedef unsigned short int i16;
typedef unsigned int i32;

struct s_arc4 {
  i16 i, j, k;
  i8 s[256];
};

typedef struct s_arc4 Arc4;

export Arc4 *rc4init(i8*, i16);
i8 rc4byte(Arc4*);
export i8 *rc4enc(Arc4*, i8*, i16);
