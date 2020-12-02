#ifndef RLE_H
#define RLE_H

struct Pair{
    char _c;
    unsigned _n;
};

struct Encoded{
    unsigned _length;
    struct Pair *_arr;
};

struct Encoded* encode(char *str);

char *decode(struct Encoded* enc);

#endif