/*
 * Test02-7segment.c
 *
 * Created: 2024-03-21 오후 3:34:29
 * Author : SYSTEM-00
 */ 

// #define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

uint8_t digit[] ={0x3F, 0x06, 0x5B,0x4F,0x66,0x6D, 0x7D,0x27, 0x7F,0x67, 0x77, 0x7C, 0x58, 0x5E, 0x79,0x71,0x40,0x00};
char arr[5]; // // 세그먼트 이미지 정보를 담을 안전 영역

void TogglePinC(char *p, int n ) // n : n번째 비트, p : PORTx 포인터
{

	char b=1<<n;
	*p |= b; // PortC(출력 레지스터)의 n번째 비트를 HIGH로 출력
	_delay_ms(500);
	*p &= ~b; // PortC(출력 레지스터)의 n번째 비트를 LOW로 출력
	_delay_ms(500);

}
void seg(int sel, uint8_t c)
{   PORTC |= 0x0F;
	PORTC &= ~(1<< (3-sel));
	PORTD = c;
	_delay_ms(5);
}

void FND_4(char *inf) // segment Image 배열
{
	for (int i=0; i<4; i++)
	{
		seg(i,*(inf+i));
	}
}

char* Trans(unsigned long num) // 10진수 정수 ==> 16진수 문자열 변환 : 56506 ==> 0xDCBA  / 65535 ==> 0xFFFF
{					// 10진수 ==> 16진수 segment Image 배열
	int n1 = num % 16; // A :  
	int n2 = (num/16)%16; // B(11)
	int n3 = (num/256)%16; // C(12)
	int n4 = (num/4096); //D(13)
	if(!(num/4096))
	{
		n4 = 17;
		if (!(num/256))
		{
			n3=17;
			if(!(num/16))
			{
				n2=17;
			}
		}
	}
	arr[0]= digit[n1];
	arr[1]= digit[n2];
	arr[2]= digit[n3];
	arr[3]= digit[n4];
	
	//FND_4(arr);
	return arr;
}

int main(void)
{
  // uint8_t nubers[] = {0x77, 0x7C, 0x58, 0x5E, 0x79,0x71,0x67, 0x76, 0x06,0x1E}; // 영어 알파벳
    unsigned long j=0; 
	int mode=0;
	DDRD = 0xFF; // 세그먼트 제어 핀 8개를 출력으로 설정
	DDRC = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
	
    while (1) 
    {
		if (!(PINB & 0x01 == 1))  // SW 눌렸을 때 : true
		{
			_delay_ms(200);
			mode++;
			if (mode >=3) {mode=0; j =0;}
		}
		
		switch (mode)
		{
			case 0 : 
			arr[0]=digit[16];
			arr[1]=digit[16];
			arr[2]=digit[16];
			arr[3]=digit[16];
			FND_4(arr);
			break;
			case 1 : FND_4(Trans(j++)); _delay_ms(5);
			break;
		    case 2 : FND_4(Trans(j)); break;
		}
		/*for (i=0; i<4; i++)
		{
		PORTC |= 0x0F;
		PORTC &=~(1<<(3-i));
		
		for (j=0; j<16; j++)
		{
			PORTD = digit[j];
			_delay_ms(100);
		}
	} 
	} return 0;*/
	  
	 
	}
}



 
