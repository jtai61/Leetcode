#ifndef BITWISE_H
#define BITWISE_H

#include <stdio.h>

#define SET_BIT(x, n)       ((x) |= (1 << (n)))
#define CLEAR_BIT(x, n)     ((x) &= ~(1 << (n)))
#define FLIP_BIT(x, n)      ((x) ^= (1 << (n)))
#define CHECK_BIT(x, n)     ((x) & (1 << (n)))

typedef unsigned char u8;
typedef unsigned int u32;

u32 CountBitOne(u32);
int Find_MSB(u8);
void XOR_swap(u8 *, u8 *);

#endif
