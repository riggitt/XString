#include "ValueAppends.h"
/** Appends a formated digit into input string
	 * @param size fixed char length */
	// TODO What about sprintf??
void appendLong(String &s,long digit, int size){

//		char p[size];
//		String x = "%0" +String(digit) +"d";
//		n=sprintf (p,(const char*)x,digit);

	if(digit < 0){digit *=(-1);s.concat('-');size--;}
	while (digit<pow(10,--size) && size>0){s.concat('0');}
	s.concat(digit);
}

void appendByte(String &s, byte digit){appendLong(s,digit,3);}

 /** Appends a formated float number into input string */
void appendFloat(String &s,float number, int intSize,int floatSize){

	if(number < 0){number*=(-1.f);s.concat('-');intSize--;}

	// int part
	long part = number;
	appendLong(s,part,intSize);
	s.concat('.');
	// real part
	part = ((number - part)*pow(10,floatSize));
	appendLong(s,part,floatSize);
}

/** Appends a formated float number in e mode into input string */
void appendEFloat(String &s,float number){

	float sign = (number < 0.0f) ? -1.f : 1.f;
	float base = abs(number);
	int e = 0;

	if((long)base < 1){
		while((long)base < 1) {
			base *= 10.0f;
			e++;
		}
		e *= -1;
	}else{
		while((long)base >= 10) {
			base /= 10.0f;
			e++;
		}
	}
	appendFloat(s,sign*base,2,8);
	s.concat('e');
	appendLong(s,e,3);

}

// TO STREAM PRINT METHODS

void printFormattedLong(Stream *stream,long digit, int size){
	String s;
	appendLong(s,digit,size);
	stream->print(s);

}

void printFormattedByte(Stream *stream,byte digit){
	printFormattedLong(stream,digit,3);

}
void printFormattedFloat(Stream *stream,float number, int intSize,int floatSize){
	String s;
	appendFloat(s,number,intSize,floatSize);
	stream->print(s);

}

void printFormattedEFloat(Stream *stream,float number){
	String s;
	appendEFloat(s,number);
	stream->print(s);

}

//float getEFloat(String &s){
//
//	 int n = s.indexOf('e');
//	 XString baseString;
//	 baseString = s.substring(0,n-1);
//	 // base
//	 float eFloat = baseString.getFloat();
//	 // exponent
//	 int exp = s.substring(n+1).toInt();
//	 n = 0;
//	 while(n < exp) eFloat*=10.0f;
//	 return eFloat;
//
//}
