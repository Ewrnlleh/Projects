#include<reg51.h>
#include<intrins.h>

void main() {
	
	unsigned i;
	
	unsigned int WAVEVALUE[16] =
	{
		128,192,224,240,255,
		240,224,192,128,
		64,32,16,0,
		16,32,64
	};
	
	while(1) {
		
		for(i=0; i<16; i++)
			P1 = WAVEVALUE[i];
		
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		
	}
	
	
	
}