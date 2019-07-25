#ifndef __HELLO_OBJECT_H__
#define __HELLO_OBJECT_H__

extern char *public_message;

void set_message( char *str );
char *get_message( void );
int get_message_len( void );

#endif
