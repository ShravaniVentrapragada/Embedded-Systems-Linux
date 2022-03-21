#include<LPC21xx.h>  

int main()  

{  

      unsigned int val; //Declaring register for polling approach  

      PINSEL0=0x00000000; // For GPIO 

     PINSEL1=0x00400000; // Selecting channel 0 AIN0  

     IODIR0=0x000003FF; // for configuring pin 0.0 to 0.9 

     ADCR = 0x00210401; // configuring ADCR FOR CHANNEL 0  

    while(1) 

        { 

    while(!(ADDR & 0x80000000)) // loop will continue till done bit is not 1  

    {  

             //IOCLR0=0x000003FF; 

        val = ((ADDR>>6) & (0x3FF)); // shifted by 6 because 15:6 bits are important, for 

                                                          // getting last 10 digits we will do AND operation with 3FF   

        IOSET0=val; 

        }  

    } 

}