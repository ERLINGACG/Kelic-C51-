
//目标：显示"Name is XXX","Num：2022114732"
#include <REG51.H>
#include <Test_lib.h>


// unsigned char code table_2[]={"Num:2022114732"};

signed char cnt=0;
bit flag=0;
int sec=0;
int hou;
int min;
int num;

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
    
    
        EA=1;                        //开启总中断
        ET0=1;                        //开启定时器0中断
        TR0=1;                        //启动定时器0
     
    cnt++;
    if(cnt==20){
        cnt=0;
        flag=1;
    }
    
	

}
void Set_time(){
    

    if(flag==1){
        flag=0;
        sec=sec+1;
    }
    
    if(sec==60){
        sec=0;
        min=min+1;
        
    }
    if(min==60){
            min=0;
            hou=hou+1;
        
   }

    if(num==1){
        sec++;
    }
    else if(num==2){
        min++;
    }
    else if(num==3){
        hou++;
    }

    Test_LCD(hou,min,sec);
}


void main(){

    
    if(num==0){
        Sycn_int();
    }
    while(1){ 
        num=Key_buttom();
        Set_time();
        delay(100);
    };
    //pass

}