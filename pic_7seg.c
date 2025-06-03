#include <16F877A.h>
#device ADC=10
#use delay(crystal=4MHz)

//#define  PORT_B ccc7seg

INT8 ccdat[]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};
void main()
{
int count=0;
int mod1=0,mod2=0;
output_b(~(ccdat[1]));
output_bit(PIN_C0,1);// enable 1 
output_bit(PIN_C1,1);// enable 2 
   while(TRUE)
   {
    for(count=0;count<=99;count++)
    {
      mod1=count/10;
      mod2=count%10;
      output_bit(PIN_C0,0);
      output_bit(PIN_C1,1);
      output_b(~(ccdat[mod1]));
      delay_ms(1);
      output_bit(PIN_C0,1);
      output_bit(PIN_C1,0);
      output_b(~(ccdat[mod2]));
      delay_ms(80);
    }
    //TODO: User Code
   }

}
