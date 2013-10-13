#include "text.h"

#include "gba/gba.h"

/* Static variables used only by functions defined in this file */
static short txtPalette = 0;

/* Sets the palette used to render the text */
void txtSetPalette(short pal) {
   if (pal >= 0 && pal <= 15)
      txtPalette = (pal << 12);
}

/* Gets the palette used to render the text */
short txtGetPalette(void) {
   return (txtPalette >> 12);
}

/* Returns the number of digits in a number, including the '-' if negative */
short txtLenN(short n) {
   short len = 0;

   /* Add an extra digit to the length if negative */
   if (n < 0) {
      n = -n;
      len++;
   }

   if (n < 10)         /* Requires only one character  */
      len++;
   else if (n < 100)   /* Requires two characters      */
      len += 2;
   else if (n < 1000)  /* Requires three characters    */
      len += 3;
   else if (n < 10000) /* Requires four characters     */
      len += 4;
   else                /* Requires all five characters */
      len += 5;

   return len;
}

/* Prints a single character at the location specified */
void txtPrintC(short x, short y, char c) {
   unsigned short *tileMem = ScreenBaseBlockAddr(17) + (((y << 5) + x) << 1);
   *tileMem = txtPalette | txtIndexOf(c);   
}

/* Prints a string beginning at the location specified */
void txtPrintS(short x, short y, const char* str, short len) {
   short i;

   for (i = 0; i < len; i++)
      txtPrintC(x++, y, *(str+i));
}

/* Prints a number beginning at the location specified */
void txtPrintN(short x, short y, short n) {
   /* A short can't take up more than 6 characters */
   char str[6];
   short nStart = 0;
   short nCur, len;
   
   /* Determine the length of the string */
   len = txtLenN(n);
   nCur = len - 1;

   /* If it's a negative number add the negate symbol */
   if (n < 0) {
      *str = '-';
      nStart++;
      n = -n;
   }

   /* Convert each decimal to a character, starting at the 1's digit */
   while (nCur >= nStart) {
      *(str + nCur--) = '0' + (n % 10);
      n /= 10;
   }

   /* Print the string we've created */
   txtPrintS(x, y, str, len);
}

/* Returns the tileset index of the specified character */
short txtIndexOf(char c) {
   /* We can map out alphanumerics mathematically */
   if (c >= 'A' && c <= 'Z')
      return (c - 'A' + 10);
   else if (c >= 'a' && c <= 'z')
      return (c - 'a' + 36);
   else if (c >= '0' && c <= '9')
      return (c - '0' + 62);

   /* "Special" Characters */
   switch (c) {
   case ':':
      return 72;
   case '/':
      return 73;
   case '.':
      return 74;
   case ',':
      return 75;
   case '-':
      return 76;
   default:
      break;
   }

   /* Default returns index of space ' ' */
   return 0;
}
