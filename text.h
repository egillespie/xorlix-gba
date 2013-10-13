#ifndef ELG_TEXT_H
#define ELG_TEXT_H

/* Sets/gets the palette used to render the text */
void  txtSetPalette(short);
short txtGetPalette(void);

/* Get length routines */
short txtLenN(short);

/* Print different types of data */
void  txtPrintC(short, short, char);
void  txtPrintS(short, short, const char*, short);
void  txtPrintN(short, short, short);

/* Returns the tileset index of the specified character */
short txtIndexOf(char);

#endif
