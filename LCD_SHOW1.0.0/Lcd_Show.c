
//目标：显示"Name is XXX","Num：2022114732"
#include <REG51.H>
#include <Test_lib.h>

unsigned char code table_1[]={"Name: is HRL"};
unsigned char code table_2[]={"Num:2022114732"};





void main(){

    unsigned char i;
    LCD_Init();            //初始化
    Lcd_Cmd(0x00|0x80);   //设置光标位置
    for(i=0;i<12;i++){

        Lcd_Darw_Char(table_1[i]);
        
    }
    Lcd_Cmd(0x40|0x80);   //设置光标位置
    for(i=0;i<14;i++){

        Lcd_Darw_Char(table_2[i]);
        
    }
    while(1);
    //pass

}