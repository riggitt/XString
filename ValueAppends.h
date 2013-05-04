/* ValueAppends.h
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
#ifndef VALUEAPPENDS_H_
#define VALUEAPPENDS_H_

#include <Arduino.h>

// STRING APPENDING

/** Appends a formated digit into input string  @param size fixed char length */
void appendLong(String &s,long digit, int size = 2);
/** Appends 3 char long byte */
void appendByte(String &s,byte digit);
 /** Appends a formated float number into input string */
void appendFloat(String &s,float number, int intSize = 2,int floatSize = 2);
/** Appends a formated float number in e mode into input string */
void appendEFloat(String &s,float number);


// STREAM PRINTING

/** Print formatted digit through stream */
void printFormattedLong(Stream *stream,long digit, int size = 2);
/** Prints 3 char byte throuh stream */
void printFormattedByte(Stream *stream,byte digit);
/** Print formatted float number through stream */
void printFormattedFloat(Stream *stream,float number, int intSize = 2,int floatSize = 2);
/** Print formatted e float number through stream */
void printFormattedEFloat(Stream *stream,float number);
//float getEFloat(String &s);

#endif /* VALUEAPPENDS_H_ */
