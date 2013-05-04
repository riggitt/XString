/* XString.h
 * Created on: 07/03/2013
 *      Author: J.M Tome
 * Copyright (c) 20012-2013 J.M Tome
 * Contact : josemiguel.tomejimenez@gmail.com
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 */
#ifndef XSTRING_H_
#define XSTRING_H_

#include "ValueAppends.h"

/** Xtra functionality String */
class XString : public String {

public :


	XString() : String(){}
	XString(String str) : String(str){}
	virtual ~XString(){}

	// VALUE FORMATTING
	void formatLong(int digit, int size = 2){appendLong(*this,digit,size);}
	void formatFloat(float number, int intSize = 2,int floatSize = 2){appendFloat(*this,number,intSize,floatSize);}
	void formatEFloat(float number){appendEFloat(*this,number);}

	// VALUE PARSING

	float getEFloat(){
		int n = indexOf('e');
		if(n == -1) return 0;
		XString baseString = substring(0,n-1);
		// base
		float eFloat = baseString.getFloat();
		// exponent
		int exp = substring(n+1,len).toInt();
		n = 0;
		while(n++ < exp) eFloat*=10.0f;
		return eFloat;
	}
	float getFloat(){return atof(buffer);}
	void print2Stream(Stream *stream){stream->print(*this);}
	void operator = (const String& str){String::operator=(str);}
	void operator = (const char*& str){String::operator=(str);}
	bool isEmpty(){return (length() == 0);}


};

#endif /* XSTRING_H_ */
