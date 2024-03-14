//#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "adc.h"
 
/************************************************
 ALIENTEK 战舰STM32F103开发板实验17
 ADC 实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
extern __IO uint16_t ADC_ConvertedValue; 
float ADC_ConvertedValueLocal1,ADC_ConvertedValueLocal2,ADC_ConvertedValueLocal3,ADC_ConvertedValueLocal4,ADC_ConvertedValueLocal5; 
 
 int main(void)
 {
	u16 adcx1,adcx2,adcx3,adcx4,adcx5;	 
	float ttt,ttt1;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	LCD_Init();			 	
 	Adc_Init();		  		//ADC初始化

	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(60,50,200,16,16,"ADC_IA0_VAL:");	      
	LCD_ShowString(60,70,200,16,16,"ADC_IA0_VOL:0.000V");	 
	POINT_COLOR=BLUE;//设置字体为蓝色	 
	LCD_ShowString(60,90,200,16,16,"ADC_VC0_VAL:");	      
	LCD_ShowString(60,110,200,16,16,"ADC_VC0_VOL:00.000V");
	POINT_COLOR=RED;//设置字体为红色
	LCD_ShowString(60,130,200,16,16,"ADC_VC1_VAL:");	      
	LCD_ShowString(60,150,200,16,16,"ADC_VC1_VOL:0.000V");
	POINT_COLOR=BLUE;//设置字体为蓝色
	LCD_ShowString(60,170,200,16,16,"ADC_VC2_VAL:");	      
	LCD_ShowString(60,190,200,16,16,"ADC_VC2_VOL:0.000V");
  POINT_COLOR=GREEN;//设置字体为蓝色
	LCD_ShowString(60,210,200,16,16,"ADC_VC2_VAL:");	      
	LCD_ShowString(60,230,200,16,16,"ADC_VC2_VOL:0.000V");	 
	while(1)
	{
		adcx1=Get_Adc_Average(0,25);
		LCD_ShowxNum(156,50,adcx1,4,16,0);//显示ADC的值
		ADC_ConvertedValueLocal1 =(float)adcx1*(3.3/4095);
		LCD_ShowxNum(156,70,(u16)ADC_ConvertedValueLocal1,1,16,0);//显示电压值
		LCD_ShowxNum(172,70,(u16)(ADC_ConvertedValueLocal1*1000)%1000 ,3,16,0X80);
		
		adcx2=Get_Adc_Average(10,25);
		LCD_ShowxNum(156,90,adcx2,4,16,0);//显示ADC的值
		ADC_ConvertedValueLocal2 =(float)adcx2*(3.3/4095);
		LCD_ShowxNum(156,110,(u16)ADC_ConvertedValueLocal2,2,16,0);//显示电压值
		LCD_ShowxNum(180,110,(u16)(ADC_ConvertedValueLocal2*1000)%1000 ,3,16,0X80);
		
		adcx3=Get_Adc_Average(11,25);
		LCD_ShowxNum(156,130,adcx3,4,16,0);//显示ADC的值
		ADC_ConvertedValueLocal3 =(float)adcx3*(3.3/4095);
		LCD_ShowxNum(156,150,(u16)ADC_ConvertedValueLocal3,1,16,0);//显示电压值
		LCD_ShowxNum(172,150,(u16)(ADC_ConvertedValueLocal3*1000)%1000 ,3,16,0X80);
		
		adcx4=Get_Adc_Average(12,25);
		LCD_ShowxNum(156,170,adcx4,4,16,0);//显示ADC的值
		ADC_ConvertedValueLocal4 =(float)adcx4*(3.3/4095);
		LCD_ShowxNum(156,190,(u16)ADC_ConvertedValueLocal4,1,16,0);//显示电压值
		LCD_ShowxNum(172,190,(u16)(ADC_ConvertedValueLocal4*1000)%1000 ,3,16,0X80);	
		adcx4=Get_Adc_Average(12,25);
		
		adcx5=Get_Adc_Average(13,25);
		LCD_ShowxNum(156,210,adcx5,4,16,0);//显示ADC的值
		ADC_ConvertedValueLocal5 =(float)adcx5*(3.3/4095);
		LCD_ShowxNum(156,230,(u16)ADC_ConvertedValueLocal5,1,16,0);//显示电压值
		LCD_ShowxNum(172,230,(u16)(ADC_ConvertedValueLocal5*1000)%1000 ,3,16,0X80);		
	}
 }


 
 