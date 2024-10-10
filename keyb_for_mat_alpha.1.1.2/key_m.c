#include <reg52.h>
#include <free_function.h>


#define uint unsigned int  //宏定义
#define uchar unsigned char  //宏定义
	

sbit WEI=P2^7;  //位选端口
sbit DUN=P2^6;  //段选端口

unsigned char code LeCom[]   ={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0x00}; //数码管位选码表0~8

unsigned char code SMG_table[] ={
				0x3F,   //0
				0x06,  	//1
				0x5B,  	//2
				0x4F, 	//3
				0x66, 	//4
				0x6D, 	//5
				0x7D,  	//6
				0x07,  	//7
				0x7f,   //8
				0x6F,   //9
				0x77,   //A
				0x7C,   //B
				0x39,   //C
				0x5E,   //D
				0x79,   //E
				0x71    //F
};



void delay(uint ms){   //延时函数
			
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
				
				



			  }


		
	 }

	}
	return num;
}	



void SMG_Show_add(int add_signal,int add_com){
			
			WEI=1;DUN=0;
			P0=LeCom[add_com];
			
		
			WEI=0;DUN=1;
			P0=SMG_table[add_signal];
			delay(10);
			
			
}



 





void main(){
	while(1){

		int num_all   =Temp_signal_test();
		int add_com   =Temp_signal_test();
		
		SMG_Show_add(num_all,is_value_max_for_modulus(add_com,8,8));

	}


}