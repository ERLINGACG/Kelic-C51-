#include<reg52.h>

#define uint unsigned int
#define uchar unsigned char
	
sbit KEY1=P3^0;
sbit KEY2=P3^1;
sbit KEY3=P3^2;
sbit KEY4=P3^3;

sbit LED1=P1^1;
sbit LED2=P1^2;
sbit LED3=P1^3;

sbit WEI=P2^7;
sbit DUN=P2^6;
unsigned char led[]={0xfe,0xfd,0xf7,0xef,0xdf,0xbf,0x7f,0xff};
unsigned char code LeCom[]   ={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0x00};
unsigned char code LedChar[] ={
				0x3F,  //0
				0x06,	 //1
				0x5B,	 //2
				0x4F,	 //3
				0x66,  //4
				0x6D,  //5
				0x7D,  //6
				0x07,  //7
				0x3f   //0
};	
/*----------------------------*/
	 void delay(uint ms){
			
			uchar i;
			while(ms--){
				
					for(i=110;i>0;i--);
				
			}
 }
	 /*----------------------------*/
 
	void LED_C(){
		
		int j=0;
		for(j=0;j<=9;j++){
			
			P1=led[j];
			delay(500);
			
		}
		P1=0xff;
	}
	
	void SMG_C(){
		
		int j=0;
		for(j=0;j<=8;j++){
			
			WEI=1;DUN=0;
			P0=LeCom[j];
			
			
			WEI=0;DUN=1;
			P0=LedChar[j];
			delay(500);
			
		}
		P0=0x00;
	}
	void SMG_Show_add(int add_i){
			
			WEI=1;DUN=0;
			P0=0xfe;
			
		
			WEI=0;DUN=1;
			P0=LedChar[add_i];
			delay(200);
			
		}
		
		//
	
	
	
 void main(){
	 
	 int i=0;
	 int set_on=0;
	 while(1){
		 
		 if(KEY1==0 || KEY2==0 || KEY3==0 || KEY4==4 ) {
			 
			 
					delay(10);
			 
					if(KEY1==0){
						LED_C();
						
					}if(KEY2==0){
						SMG_C();
						
				  }if(KEY3==0){
						i++;
						if(i>=9){
							i=0;
						}
						
						SMG_Show_add(i);
						
					}if(KEY4==0){
						P0=0x00;
					
					
					
					}
					/*else{
						
						LED1=1;
						LED2=1;
						
					}*/
	 
			}
			
	 
	}
	
		
 
 
 }