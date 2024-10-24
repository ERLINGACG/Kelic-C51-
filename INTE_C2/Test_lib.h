#ifndef Test_lib
#define Test_lib


#include<reg51.h>
#include<intrins.h>



#define uchar unsigned char
#define uint unsigned int

void delay(uint ms){

    uchar i;
    while(ms--){

        for(i=110;i>0;i--);
    }
 }

int Temp_signal_test(){  //键盘信号输出函数

	
	unsigned char temp;
	unsigned char X;
	unsigned char Y;
	unsigned char Z;
	int num;

	P3=0X0F;                            //进行扫描  0000 1111，列全部投入高电平
	temp=P3;                            //读取键盘输入，读取任意行输入
	temp=temp&P3;                       //进行与运算，重新赋值，1与任意数都为他本身，0与0为0，1与1为1
	if (temp!=0X0F){                    //如果有键按下
		 
		 delay(10);                     //延时消除抖动
		 temp=P3;
		 temp=temp&P3;
		 if (temp!=0X0F){               //确定有键按下
			
			 X=P3;                      //读取行输入         
			 P3=0XF0;                   //进列扫描  1111 0000，列全部投入低电平
			 Y=P3&0XF0;                 //读取列输入
			 Z=X|Y;                     //合并行列输入
			 switch(Z){
				case 0x77:       
						num=0;
						break;
				case 0x7b:
						num=1;
						break;
				case 0x7d:
						num=2;
						break;
				case 0x7e:
					   num=3;
					   break;
				case 0xb7:
					   num=4;
					   break;
				case 0xbb:
					   num=5;
					   break;
				case 0xbd:
					   num=6;
					   break;
				case 0xbe:
					   num=7;
					   break;
				case 0xd7:
					   num=8;
					   break;
				case 0xdb:
					   num=9;
					   break;
				case 0xdd:
					   num=10;
					   break;
				case 0xde:
					   num=11;
					   break;
				case 0xe7:
					   num=12;
					   break;
				case 0xeb:
					   num=13;
					   break;
				case 0xed:
					   num=14;
					   break;
				case 0xee:
					   num=15;
					   break;

			   default:
					   num=0;
					   break;
				
				



			  }


		
	 }

	}
	return num;
}	

#endif







