#ifndef __TEST_LIB_H__
#define __TEST_LIB_H__

#include <REG51.H>
#include <intrins.h>


#define uchar unsigned char
#define uint unsigned int
#define LCDDB P0
sbit LCDEN=P3^4; //LCD使能端
sbit LCDRS=P3^5; //命令选择端
sbit LCDRW=P3^6; //读写控制端

sbit KEY1=P3^0;
sbit KEY2=P3^1;
sbit KEY3=P3^2;
sbit KEY4=P3^3;


void delay(uint ms){

    uchar i;
    while(ms--){

        for(i=110;i>0;i--);
    }
 }

int Key_buttom(){
    int num=0;
    if(KEY1==0 || KEY2==0 || KEY3==0 || KEY4==0){


        delay(10);
        if(KEY1==0){
            num=1;
        }
        if(KEY2==0){

            num=2;
        }
        if(KEY3==0){
            num=3;
        }
        if(KEY4==0){
            num=4;
        }

    }
    return num;

}



void Lcd_Busy_Wait(){         //等待LCD空闲

    unsigned char sta;      
    LCDDB=0xFF;
    LCDEN=0;                     //使能端低电平
    LCDRS=0;                     //数据/命令选择端低电平
    LCDRW=1;                     //读模式
    do{
       LCDEN=1;                   //使能端高电平
       sta=LCDDB;                 
       LCDEN=0;                

    }while(sta&0x80);            //等待LCD忙标志位清零

}

void Lcd_Cmd(unsigned char cmd){    //写指令
    
 Lcd_Busy_Wait();
    LCDEN=0;                       //使能端低电平
    LCDRS=0;                       //数据/命令选择端低电平，命令模式
    LCDRW=0;                       //写入模式
    LCDDB=cmd;                     //写入命令
    LCDEN=1;                       //使能端高电平
    LCDEN=0;                       //使能端低电平

}

void Lcd_Init(){                     //LCD初始化
    
   
    Lcd_Cmd(0x38); //工作模式设置，16x2显示，5*7点阵字体
    Lcd_Cmd(0x0C); //显示开
    Lcd_Cmd(0x06); //文字不动，地址自增
    Lcd_Cmd(0x01); //清屏

}

void Lcd_Darw_Char(unsigned char Data){     //绘制字符
    Lcd_Busy_Wait();                       //等待LCD空闲
    LCDEN=0;                               //使能端低电平
    LCDRS=1;                               //数据/命令选择端高电平，数据模式
    LCDRW=0;                               //写入模式
    LCDDB=Data;
    LCDEN=1;
    LCDEN=0;
}

void Test_LCD(int hour,int minute,int second){
    unsigned char code DateTime[]={"2024-10-31 UTC+8"};
    unsigned char code timeString[]={'0','1','2','3','4','5','6','7','8','9'};
    unsigned char i;
    LCD_Init();            //初始化
    Lcd_Cmd(0x00|0x80);   //写入第一行数据
    for(i=0;i<16;i++){

        Lcd_Darw_Char(DateTime[i]);

    }

    Lcd_Cmd(0x40|0x80);   //写入第二行数据
    Lcd_Darw_Char(timeString[(hour/10)%10]);
    Lcd_Darw_Char(timeString[hour%10]);
    Lcd_Darw_Char(':');
    Lcd_Darw_Char(timeString[(minute/10)%10]);
    Lcd_Darw_Char(timeString[minute%10]);
    Lcd_Darw_Char(':');
    Lcd_Darw_Char(timeString[(second/10)%10]);
    Lcd_Darw_Char(timeString[second%10]);
    
}

#endif