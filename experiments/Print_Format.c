/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define NUM 0x1234

typedef union {
        struct {
            unsigned char byte4;
            unsigned char byte3;
            unsigned char byte2;
            unsigned char byte1;
        };
        unsigned int var;
}new;

typedef union {
    struct {
        unsigned int byte_4:8;
        unsigned int byte_3:8;
        unsigned int byte_2:8;
        unsigned int byte_1:8;
    };
    unsigned int var;
}bytes_t;

int main()
{
    int x = 0x12;
    bytes_t bytes;
    new byt;
    byt.var = bytes.var = 0x12345678;
    
    /**Format
     * The printf(“:%s:\n”, “Hello, world!”); statement prints the string (nothing special happens.)
     * The printf(“:%15s:\n”, “Hello, world!”); statement prints the string, but print 15 characters. If the string is smaller the “empty” positions will be filled with “whitespace.”
     * The printf(“:%.10s:\n”, “Hello, world!”); statement prints the string, but print only 10 characters of the string.
     * The printf(“:%-10s:\n”, “Hello, world!”); statement prints the string, but prints at least 10 characters. If the string is smaller “whitespace” is added at the end. (See next example.)
     * The printf(“:%-15s:\n”, “Hello, world!”); statement prints the string, but prints at least 15 characters. The string in this case is shorter than the defined 15 character, thus “whitespace” is added at the end (defined by the minus sign.)
     * The printf(“:%.15s:\n”, “Hello, world!”); statement prints the string, but print only 15 characters of the string. In this case the string is shorter than 15, thus the whole string is printed.
     * The printf(“:%15.10s:\n”, “Hello, world!”); statement prints the string, but print 15 characters.
     * If the string is smaller the “empty” positions will be filled with “whitespace.” But it will only print a maximum of 10 characters, thus only part of new string (old string plus the whitespace positions) is printed.
     * The printf(“:%-15.10s:\n”, “Hello, world!”); statement prints the string, but it does the exact same thing as the previous statement, accept the “whitespace” is added at the end.
     * */
    printf("%.37s\n","=================================================");
    printf("First byte\t|\t0x%-10x|\n",bytes.byte_1);
     printf("%.37s\n","------------------------------------------------");
    printf("Second byte\t|\t0x%-10x|\n",bytes.byte_2);
    printf("%.37s\n","------------------------------------------------");
    printf("Third byte\t|\t0x%-10x|\n",bytes.byte_3);
    printf("%.37s\n","------------------------------------------------");
    printf("Fourth byte\t|\t0x%-10x|\n",bytes.byte_4);
    printf("%.37s\n","------------------------------------------------");
    printf("variable\t|\t0x%-10x|\n",bytes.var);
    printf("%.37s\n\n","=================================================");
    printf("%.37s\n","=================================================");
    printf("First byte\t|\t0x%-10x|\n",byt.byte1);
    printf("%.37s\n","------------------------------------------------");
    printf("Second byte\t|\t0x%-10x|\n",byt.byte2);
    printf("%.37s\n","------------------------------------------------");
    printf("Third byte\t|\t0x%-10x|\n",byt.byte3);
    printf("%.37s\n","------------------------------------------------");
    printf("Fourth byte\t|\t0x%-10x|\n",byt.byte4);
    printf("%.37s\n","------------------------------------------------");
    printf("variable\t|\t0x%-10x|\n",byt.var);
    printf("%.37s\n","=================================================");

    return 0;
}

