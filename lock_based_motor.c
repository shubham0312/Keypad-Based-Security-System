sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;
sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;

char Read_Keypad()
{
  P1_4_bit=1;
  P1_5_bit=1;
  P1_6_bit=1;
  P1_7_bit=1;
  P1_0_bit=0;
  P1_1_bit=1;
  P1_2_bit=1;
  P1_3_bit=1;
  if(P1_4_bit==0){delay_ms(100);while(P1_4_bit==0);return 0x37;}
  if(P1_5_bit==0){delay_ms(100);while(P1_5_bit==0);return 0x38;}
  if(P1_6_bit==0){delay_ms(100);while(P1_6_bit==0);return 0x39;}
  if(P1_7_bit==0){delay_ms(100);while(P1_7_bit==0);return 0x2F;}
  P1_0_bit=1;
  P1_1_bit=0;
  P1_2_bit=1;
  P1_3_bit=1;
  if(P1_4_bit==0){delay_ms(100);while(P1_4_bit==0);return 0x34;}
  if(P1_5_bit==0){delay_ms(100);while(P1_5_bit==0);return 0x35;}
  if(P1_6_bit==0){delay_ms(100);while(P1_6_bit==0);return 0x36;}
  if(P1_7_bit==0){delay_ms(100);while(P1_7_bit==0);return 0x2A;}
  P1_0_bit=1;
  P1_1_bit=1;
  P1_2_bit=0;
  P1_3_bit=1;
  if(P1_4_bit==0){delay_ms(100);while(P1_4_bit==0);return 0x31;}
  if(P1_5_bit==0){delay_ms(100);while(P1_5_bit==0);return 0x32;}
  if(P1_6_bit==0){delay_ms(100);while(P1_6_bit==0);return 0x33;}
  if(P1_7_bit==0){delay_ms(100);while(P1_7_bit==0);return 0x2D;}
  P1_0_bit=1;
  P1_1_bit=1;
  P1_2_bit=1;
  P1_3_bit=0;
  if(P1_4_bit==0){delay_ms(100);while(P1_4_bit==0);return 'C';}
  if(P1_5_bit==0){delay_ms(100);while(P1_5_bit==0);return 0x30;}
  if(P1_6_bit==0){delay_ms(100);while(P1_6_bit==0);return 0x2B;}
  return 0;
}

void main() {

int i=0,j,k=0,l=0;
unsigned char a[5];
unsigned char b[5]={0x36,0x35,0x34,0x33,0x32};
       lcd_init();
       lcd_cmd(_lcd_clear);
       lcd_cmd(_lcd_cursor_off);
       B:lcd_out(1,2," PASSWORD BASED ");
         lcd_out(2,7,"LOCK ");
        delay_ms(2500);
        lcd_cmd(_lcd_clear);
        lcd_out(1,2,"ENTER PASSWORD");
        delay_ms(2000);
       A:i=0;
       lcd_cmd(_lcd_clear);
       k=0;
        while(1)
        {
        do
        {
        j=Read_Keypad();
        }
        while(!j);
            lcd_chr(2,i+6,j);
            a[i]=j  ;
            delay_ms(200);
            lcd_chr(2,i+6,'*');
            i++;

          if(i==5)
          break;
          }
            for(j=0;j<5;j++)
            {
            if(a[j]!=b[j])
            break;

            else
            k++;
            }
        if(k==5)
        {
              lcd_cmd(_lcd_clear);
              lcd_out(1,2,"PASSWORD OK");
              p3_4_bit=0;
              p3_5_bit=1;
              delay_ms(1300);
              p3_4_bit=1;
              p3_5_bit=0;
              delay_ms(1300);
              p3_4_bit=0;
              p3_5_bit=0;
              goto B;


        }
         else
         {
         lcd_cmd(_lcd_clear);
              lcd_out(1,5,"INCORRECT");
              delay_ms(1200);
              lcd_cmd(_lcd_clear);
              lcd_out(1,2,"ENTER AGAIN");
              delay_ms(1000);
              goto A;
         }

}
