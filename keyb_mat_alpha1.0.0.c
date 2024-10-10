#include <reg51.h>

#define uint unsigned int
#define uchar unsigned char
	

sbit WEI=P2^7;
sbit DUN=P2^6;


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
	int num=0;

	P3=0X0F;
	temp=P3;
	temp=temp&P3;
	if (temp!=0X0F){
		 
		 delay(10);
		 temp=P3;
		 temp=temp&P3;
		 if (temp!=0X0F){
			 
			 X=P3;
			 P3=0XF0;
			 Y=P3&0XF0;
			 Z=X|Y;
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
					   num=-1;
					   break;
				
				



			  }


		
	 }

	}
	return num;
}	

void SMG_Show_add(int add_signal){
			
			WEI=1;DUN=0;
			P0=0xfe;
			
		
			WEI=0;DUN=1;
			P0=SMG_table[add_signal];
			delay(200);
			
}



 





void main(){
	while(1){

		int num_all=Temp_signal_test();
		SMG_Show_add(num_all);

	}


}