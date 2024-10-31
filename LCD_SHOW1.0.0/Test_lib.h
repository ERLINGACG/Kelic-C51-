#ifndef __TEST_LIB_H__
#define __TEST_LIB_H__

#include <REG51.H>
#include <intrins.h>


#define uchar unsigned char
#define uint unsigned int
#define LCDDB P0
sbit LCDEN=P3^4; //LCD使能端
sbit LCDRS=P3^5; //数据/命令选择端
sbit LCDRW=P3^6; //数据/命令选择端

void delay(uint ms){

    uchar i;
    while(ms--){

        for(i=110;i>0;i--);
    }
 }

void Lcd_Busy_Wait(){

    unsigned char sta;
    LCDDB=0xFF;
    LCDEN=0;
    LCDRS=0;
    LCDRW=1;
    do{
       LCDEN=1;
       sta=LCDDB;
       LCDEN=0;

    }while(sta&0x80);

}
void Lcd_Cmd(unsigned char cmd){
    
 Lcd_Busy_Wait();
    LCDEN=0;
    LCDRS=0;
    LCDRW=0;
    LCDDB=cmd;
    LCDEN=1;
    LCDEN=0;

}
void Lcd_Init(){
    
   
    Lcd_Cmd(0x38); //8位数据长度，2行
    Lcd_Cmd(0x0C); //显示开
    Lcd_Cmd(0x06); //文字不动，地址自增
    Lcd_Cmd(0x01); //清屏

}

void Lcd_Darw_Char(unsigned char Data){
    Lcd_Busy_Wait();
    LCDEN=0;
    LCDRS=1;
    LCDRW=0;
    LCDDB=Data;
    LCDEN=1;
    LCDEN=0;
}




#endif