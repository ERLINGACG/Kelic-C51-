#include <reg51.h>
#include <Test_lib.h>


#define uchar unsigned char
#define uint unsigned int

sbit WEI=P2^7;  //位选端口
sbit DUN=P2^6;  //段选端口
signed char cnt=0;
bit flag=0;
int sec=0;

unsigned char code SMG_table[] ={        //段选码表（共阴极
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

void Sycn_int(){                //初始化，同步
    
    TMOD=0x01;                    //设置定时器0工作方式
    TH0=(65535-50000)/256;       //设置定时器0的初值
    TL0=(65535-50000)%256;
    
    
        EA=1;                        //开启总中断
        ET0=1;                        //开启定时器0中断
        TR0=1;                        //启动定时器0
        
    
        
    
}


void int_T0() interrupt 1{
    // int sgi2 = Temp_signal_test();
    TH0=(65535-50000)/256;
    TL0=(65535-50000)%256;
    
    // if (Temp_signal_test()==1){
        EA=1;                        //开启总中断
        ET0=1;                        //开启定时器0中断
        TR0=1;                        //启动定时器0
    //  }
    cnt++;
    if(cnt==20){
        cnt=0;
        flag=1;
    }
    
	

}


void Show_Time(){
    int w;
    int min;
	int hour;
    if (Temp_signal_test()==1){
            
            sec++;
                   
        }
    if (Temp_signal_test()==4){
            
            min++;
                   
        }
    if (Temp_signal_test()==5){
            
            hour++;
                   
        }
    if(flag==1 ){
        flag=0;
        sec++;
    }
	
	if(sec>=60){

		sec=0;
		min++;
        
	}
	if(min>=60){

            min=0;
            hour++;
    }
	// int i;
    
	for(w=0;w<8;w++){       
		WEI=1;DUN=0;
        P0=0X00;
        switch(w){

            case 0:
               P0=0X7f; WEI=0;DUN=1;
			   P0=SMG_table[sec%10];
            break;

			case 1:
               P0=0Xbf; WEI=0;DUN=1;
			   P0=SMG_table[(sec/10)%10];
            break;
			case 2:
               P0=0Xdf; WEI=0;DUN=1;
			   P0=0X40;
			   break;
			case 3:
			   P0=0Xef; WEI=0;DUN=1;
			   P0=SMG_table[min%10];
			   break;
			case 4:
			   P0=0Xf7; WEI=0;DUN=1;
			   P0=SMG_table[(min/10)%10];
			   break;
			case 5:
			   P0=0Xfb; WEI=0;DUN=1;
			   P0=0X40;
			   break;
			case 6:
			   P0=0Xfd; WEI=0;DUN=1;
			   P0=SMG_table[hour%10];
			   break;
			case 7:
			   P0=0Xfe; WEI=0;DUN=1;
			   P0=SMG_table[(hour/10)%10];
			   break;
			default:
			   break;
        }
        delay(2);
    }





}






void main(){
    
        
    
    Sycn_int();
    while(1){
        
        Show_Time();
    

    }

}