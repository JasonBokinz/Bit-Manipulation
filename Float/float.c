#include <stdio.h>


float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
    /* DO NOT CHANGE THE DECLARATION OF "f" (This will be converted to float later) */
    unsigned int f = 0; // DO NOT CHANGE
    /*------------------------------------------------------------------------------*/
    
    /* Start Coding Here */
    unsigned int sign, floatExponent, floatFraction;

    sign = sign_bit & 1;
    sign = sign << 31;
    /* 11111111 to decimal is 255, & makes sure only 8 LSB are considered */
    floatExponent = exponent & 255; 
    floatExponent = floatExponent << 23;
    /* 11111111111111111111111 to deciaml is 8388607, & makes sure only 23 LSB are considered */
    floatFraction = fraction & 8388607;

    /* combines the 3 parts of the IEEE with | operator */
    f = (sign) | (floatExponent) | (floatFraction);
    
    /*-------------------*/
    
    /* DO NOT CHANGE THE RETURN VALUE (This returns the binary representation of "f" as float) */
    return *((float*)&f); // DO NOT CHANGE
    /* ----------------------------------------------------------------------------------------*/
}

int main(int argc, char* argv[])
{
    (void) argc; // to supress compiler warning
    (void)argv;  // to supress compiler warning   
    return 0;
}

