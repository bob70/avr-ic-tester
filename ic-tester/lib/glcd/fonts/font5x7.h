/*
 * font5x7.h
 *
 * Created: 28/03/2012 1:52:20 AM
 *  Author: andy
 */ 

// Title		: Graphic LCD Font (Ascii Charaters)
// Author		: Pascal Stang

#ifndef FONT5X7_H_
#define FONT5X7_H_

// standard ascii 5x7 font
// defines ascii characters 0x20-0x7F (32-127)
static const char Font5x7[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00,	// (space) 0x20
	0x00, 0x00, 0x5F, 0x00, 0x00,	// !	0x21
	0x00, 0x07, 0x00, 0x07, 0x00,	// "	0x22
	0x14, 0x7F, 0x14, 0x7F, 0x14,	// #	0x23
	0x24, 0x2A, 0x7F, 0x2A, 0x12,	// $	0x24
	0x23, 0x13, 0x08, 0x64, 0x62,	// %	0x25
	0x36, 0x49, 0x55, 0x22, 0x50,	// &	0x26
	0x00, 0x05, 0x03, 0x00, 0x00,	// '	0x27
	0x00, 0x1C, 0x22, 0x41, 0x00,	// (	0x28
	0x00, 0x41, 0x22, 0x1C, 0x00,	// )	0x29
	0x08, 0x2A, 0x1C, 0x2A, 0x08,	// *	0x2A
	0x08, 0x08, 0x3E, 0x08, 0x08,	// +	0x2B
	0x00, 0x50, 0x30, 0x00, 0x00,	// ,	0x2C
	0x08, 0x08, 0x08, 0x08, 0x08,	// -	0x2D
	0x00, 0x60, 0x60, 0x00, 0x00,	// .	0x2E
	0x20, 0x10, 0x08, 0x04, 0x02,	// /	0x2F
	0x3E, 0x51, 0x49, 0x45, 0x3E,	// 	0x30
	0x00, 0x42, 0x7F, 0x40, 0x00,	// 1	0x31
	0x42, 0x61, 0x51, 0x49, 0x46,	// 2	0x32
	0x21, 0x41, 0x45, 0x4B, 0x31,	// 3	0x33
	0x18, 0x14, 0x12, 0x7F, 0x10,	// 4	0x34
	0x27, 0x45, 0x45, 0x45, 0x39,	// 5	0x35
	0x3C, 0x4A, 0x49, 0x49, 0x30,	// 6	0x36
	0x01, 0x71, 0x09, 0x05, 0x03,	// 7	0x37
	0x36, 0x49, 0x49, 0x49, 0x36,	// 8	0x38
	0x06, 0x49, 0x49, 0x29, 0x1E,	// 9	0x39
	0x00, 0x36, 0x36, 0x00, 0x00,	// :	0x3A
	0x00, 0x56, 0x36, 0x00, 0x00,	// ;	0x3B
	0x00, 0x08, 0x14, 0x22, 0x41,	// <	0x3C
	0x14, 0x14, 0x14, 0x14, 0x14,	// =	0x3D
	0x41, 0x22, 0x14, 0x08, 0x00,	// >	0x3E
	0x02, 0x01, 0x51, 0x09, 0x06,	// ?	0x3F
	0x32, 0x49, 0x79, 0x41, 0x3E,	// @	0x40
	0x7E, 0x11, 0x11, 0x11, 0x7E,	// A	0x41
	0x7F, 0x49, 0x49, 0x49, 0x36,	// B	0x42
	0x3E, 0x41, 0x41, 0x41, 0x22,	// C	0x43
	0x7F, 0x41, 0x41, 0x22, 0x1C,	// D	0x44
	0x7F, 0x49, 0x49, 0x49, 0x41,	// E	0x45
	0x7F, 0x09, 0x09, 0x01, 0x01,	// F	0x46
	0x3E, 0x41, 0x41, 0x51, 0x32,	// G	0x47
	0x7F, 0x08, 0x08, 0x08, 0x7F,	// H	0x48
	0x00, 0x41, 0x7F, 0x41, 0x00,	// I	0x49
	0x20, 0x40, 0x41, 0x3F, 0x01,	// J	0x4A
	0x7F, 0x08, 0x14, 0x22, 0x41,	// K	0x4B
	0x7F, 0x40, 0x40, 0x40, 0x40,	// L	0x4C
	0x7F, 0x02, 0x04, 0x02, 0x7F,	// M	0x4D
	0x7F, 0x04, 0x08, 0x10, 0x7F,	// N	0x4E
	0x3E, 0x41, 0x41, 0x41, 0x3E,	// O	0x4F
	0x7F, 0x09, 0x09, 0x09, 0x06,	// P	0x50
	0x3E, 0x41, 0x51, 0x21, 0x5E,	// Q	0x51
	0x7F, 0x09, 0x19, 0x29, 0x46,	// R	0x52
	0x46, 0x49, 0x49, 0x49, 0x31,	// S	0x53
	0x01, 0x01, 0x7F, 0x01, 0x01,	// T	0x54
	0x3F, 0x40, 0x40, 0x40, 0x3F,	// U	0x55
	0x1F, 0x20, 0x40, 0x20, 0x1F,	// V	0x56
	0x7F, 0x20, 0x18, 0x20, 0x7F,	// W	0x57
	0x63, 0x14, 0x08, 0x14, 0x63,	// X	0x58
	0x03, 0x04, 0x78, 0x04, 0x03,	// Y	0x59
	0x61, 0x51, 0x49, 0x45, 0x43,	// Z	0x5A
	0x00, 0x00, 0x7F, 0x41, 0x41,	// [	0x5B
	0x02, 0x04, 0x08, 0x10, 0x20,	// "\"	0x5C
	0x41, 0x41, 0x7F, 0x00, 0x00,	// ]	0x5D
	0x04, 0x02, 0x01, 0x02, 0x04,	// ^	0x5E
	0x40, 0x40, 0x40, 0x40, 0x40,	// _	0x5F
	0x00, 0x01, 0x02, 0x04, 0x00,	// `	0x60
	0x20, 0x54, 0x54, 0x54, 0x78,	// a	0x61
	0x7F, 0x48, 0x44, 0x44, 0x38,	// b	0x62
	0x38, 0x44, 0x44, 0x44, 0x20,	// c	0x63
	0x38, 0x44, 0x44, 0x48, 0x7F,	// d	0x64
	0x38, 0x54, 0x54, 0x54, 0x18,	// e	0x65
	0x08, 0x7E, 0x09, 0x01, 0x02,	// f	0x66
	0x08, 0x14, 0x54, 0x54, 0x3C,	// g	0x67
	0x7F, 0x08, 0x04, 0x04, 0x78,	// h	0x68
	0x00, 0x44, 0x7D, 0x40, 0x00,	// i	0x69
	0x20, 0x40, 0x44, 0x3D, 0x00,	// j	0x6A
	0x00, 0x7F, 0x10, 0x28, 0x44,	// k	0x6B
	0x00, 0x41, 0x7F, 0x40, 0x00,	// l	0x6C
	0x7C, 0x04, 0x18, 0x04, 0x78,	// m	0x6D
	0x7C, 0x08, 0x04, 0x04, 0x78,	// n	0x6E
	0x38, 0x44, 0x44, 0x44, 0x38,	// o	0x6F
	0x7C, 0x14, 0x14, 0x14, 0x08,	// p	0x70
	0x08, 0x14, 0x14, 0x18, 0x7C,	// q	0x71
	0x7C, 0x08, 0x04, 0x04, 0x08,	// r	0x72
	0x48, 0x54, 0x54, 0x54, 0x20,	// s	0x73
	0x04, 0x3F, 0x44, 0x40, 0x20,	// t	0x74
	0x3C, 0x40, 0x40, 0x20, 0x7C,	// u	0x75
	0x1C, 0x20, 0x40, 0x20, 0x1C,	// v	0x76
	0x3C, 0x40, 0x30, 0x40, 0x3C,	// w	0x77
	0x44, 0x28, 0x10, 0x28, 0x44,	// x	0x78
	0x0C, 0x50, 0x50, 0x50, 0x3C,	// y	0x79
	0x44, 0x64, 0x54, 0x4C, 0x44,	// z	0x7A
	0x00, 0x08, 0x36, 0x41, 0x00,	// {	0x7B
	0x00, 0x00, 0x7F, 0x00, 0x00,	// |	0x7C
	0x00, 0x41, 0x36, 0x08, 0x00,	// }	0x7D
	0x08, 0x08, 0x2A, 0x1C, 0x08,	// ->	0x7E
	0x08, 0x1C, 0x2A, 0x08, 0x08,	// <-	0x7F


	0x14, 0x36, 0x77, 0x36, 0x14,	// ������� �����-����	0x80
	0x00, 0x7f, 0x3e, 0x1c, 0x08,	// ������� ������		0x81
	0x08, 0x1c, 0x3e, 0x7f, 0x00,	// ������� �����		0x82
	0x04, 0x06, 0x07, 0x06, 0x04,	// ������� �����		0x83
	0x10, 0x30, 0x70, 0x30, 0x10,	// ������� ����         0x84
	0x3e, 0x41, 0x08, 0x14, 0x14,	// ��������-1			0x85
	0x41, 0x3e, 0x00, 0x00, 0x00,	// ��������-2			0x86
	0x10, 0x38, 0x7c, 0x10, 0x1f,	// enter				0x87
	0x08, 0x1c, 0x3e, 0x08, 0x08,	// backspace			0x88
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0x89
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0x8A
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0x8B
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0x8C
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0x8D
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0x8E
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0x8F
	0x02 , 0x02 , 0x02 , 0x02 , 0x02,	// '1'				0x90
	0x07 , 0x01 , 0x07 , 0x04 , 0x07,	// '2'				0x91
	0x07 , 0x01 , 0x03 , 0x01 , 0x07,	// '3'				0x92
	0x05 , 0x05 , 0x07 , 0x01 , 0x01,	// '4'				0x93
	0x07 , 0x04 , 0x07 , 0x01 , 0x07,	// '5'				0x94
	0x07 , 0x04 , 0x07 , 0x05 , 0x07,	// '6'				0x95
	0x07 , 0x01 , 0x01 , 0x01 , 0x01,	// '7'				0x96
	0x07 , 0x05 , 0x07 , 0x05 , 0x07,	// '8'				0x97
	0x07 , 0x05 , 0x07 , 0x01 , 0x07,	// '9'				0x98
	0x17 , 0x15 , 0x15 , 0x15 , 0x17,	// '10'				0x99
	0x12 , 0x12 , 0x12 , 0x12 , 0x12,	// '11'				0x9A
	0x17 , 0x11 , 0x17 , 0x14 , 0x17,	// '12'				0x9B
	0x17 , 0x11 , 0x13 , 0x11 , 0x17,	// '13'				0x9C
	0x15 , 0x15 , 0x17 , 0x11 , 0x11,	// '14'				0x9D
	0x17 , 0x14 , 0x17 , 0x11 , 0x17,	// '15'				0x9E
	0x17 , 0x14 , 0x17 , 0x15 , 0x17,	// '16'				0x9F
	0x17 , 0x11 , 0x11 , 0x11 , 0x11,	// '17'				0xA0
	0x17 , 0x15 , 0x17 , 0x15 , 0x17,	// '18'				0xA1
	0x17 , 0x15 , 0x17 , 0x11 , 0x17,	// '19'				0xA2
	0x77 , 0x15 , 0x75 , 0x45 , 0x77,	// '20'				0xA3
	0x06 , 0x0f , 0x0f , 0x0f , 0x06,	// *				0xA4
	0x1f , 0x11 , 0x11 , 0x11 , 0x1f,	// [ ]				0xA5
	0x1f , 0x15 , 0x1f , 0x15 , 0x1f,	// [*]				0xA6
	0x63 , 0x36 , 0x1c , 0x00 , 0x00,	// }				0xA7
	0x01 , 0x03 , 0x07 , 0x03 , 0x01,	// ���� ������� 1	0xA8
	0x04 , 0x06 , 0x07 , 0x06 , 0x04,	// ����� ������� 1	0xA9
	0x01 , 0x02 , 0x04 , 0x02 , 0x01,	// ���� ������� 0	0xAA
	0x04 , 0x02 , 0x01 , 0x02 , 0x04,	// ����� ������� 0	0xAB
	0x40 , 0x60 , 0x70 , 0x60 , 0x40,	// ���� ������ 1	0xA�	
	0x10 , 0x30 , 0x70 , 0x30 , 0x10,	// ����� ������	1	0xAD
	0x40 , 0x20 , 0x10 , 0x20 , 0x40,	// ���� ������ 0	0xAE
	0x10 , 0x20 , 0x40 , 0x20 , 0x10,	// ����� ������ 0	0xAF
	//
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x91
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x92
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x93
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x94
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x95
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x96
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x97
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x98
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x99
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x9A
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x9B
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x9C
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x9D
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x9E
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0x9F
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA0
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA1
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA2
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA3
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA4
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA5
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA6
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA7
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA8
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xA9
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xAA
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xAB
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xAC
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xAD
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xAE
	//0x00, 0x00, 0x00, 0x00, 0x00,	//						0xAF
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB0
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB1
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB2
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB3
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB4
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB5
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB6
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB7
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB8
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xB9
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xBA
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xBB
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xBC
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xBD
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xBE
	0x00, 0x00, 0x00, 0x00, 0x00,	//						0xBF	
	

	// -------------------------------------------------
	0x7e, 0x11, 0x11, 0x11, 0x7e,	// A	0xC0
	0x7f, 0x49, 0x49, 0x49, 0x33,	// �	0xC1
	0x7f, 0x49, 0x49, 0x49, 0x36,	// �	0xC2
	0x7f, 0x01, 0x01, 0x01, 0x03,	// �	0xC3
	0xe0, 0x51, 0x4f, 0x41, 0xff,	// �	0xC4
	0x7f, 0x49, 0x49, 0x49, 0x41,	// E	0xC5
	0x77, 0x08, 0x7f, 0x08, 0x77,	// �	0xC6
	0x41, 0x49, 0x49, 0x49, 0x36,	// �	0xC7
	0x7f, 0x10, 0x08, 0x04, 0x7f,	// �	0xC8
	0x7c, 0x21, 0x12, 0x09, 0x7c,	// �	0xC9
	0x7f, 0x08, 0x14, 0x22, 0x41,	// K	0xCA
	0x20, 0x41, 0x3f, 0x01, 0x7f,	// �	0xCB
	0x7f, 0x02, 0x0c, 0x02, 0x7f,	// M	0xCC
	0x7f, 0x08, 0x08, 0x08, 0x7f,	// H	0xCD
	0x3e, 0x41, 0x41, 0x41, 0x3e,	// O	0xCE
	0x7f, 0x01, 0x01, 0x01, 0x7f,	// �	0xCF
	0x7f, 0x09, 0x09, 0x09, 0x06,	// P	0xD0
	0x3e, 0x41, 0x41, 0x41, 0x22,	// C	0xD1
	0x01, 0x01, 0x7f, 0x01, 0x01,	// T	0xD2
	0x47, 0x28, 0x10, 0x08, 0x07,	// �	0xD3
	0x1c, 0x22, 0x7f, 0x22, 0x1c,	// �	0xD4
	0x63, 0x14, 0x08, 0x14, 0x63,	// X	0xD5
	0x7f, 0x40, 0x40, 0x40, 0xff,	// �	0xD6
	0x07, 0x08, 0x08, 0x08, 0x7f,	// �	0xD7
	0x7f, 0x40, 0x7f, 0x40, 0x7f,	// �	0xD8
	0x7f, 0x40, 0x7f, 0x40, 0xff,	// �	0xD9
	0x01, 0x7f, 0x48, 0x48, 0x30,	// �	0xDA
	0x7f, 0x48, 0x30, 0x00, 0x7f,	// �	0xDB
	0x00, 0x7f, 0x48, 0x48, 0x30,	// �	0xDC
	0x22, 0x41, 0x49, 0x49, 0x3e,	// �	0xDD
	0x7f, 0x08, 0x3e, 0x41, 0x3e,	// �	0xDE
	0x46, 0x29, 0x19, 0x09, 0x7f,	// �	0xDF
	// ��������� �����
	0x20, 0x54, 0x54, 0x54, 0x78,	// a	0xE0
	0x3c, 0x4a, 0x4a, 0x49, 0x31,	// �	0xE1
	0x7c, 0x54, 0x54, 0x28, 0x00,	// �	0xE2
	0x7c, 0x04, 0x04, 0x04, 0x0c,	// �	0xE3
	0xe0, 0x54, 0x4c, 0x44, 0xfc,	// �	0xE4
	0x38, 0x54, 0x54, 0x54, 0x18,	// e	0xE5
	0x6c, 0x10, 0x7c, 0x10, 0x6c,	// �	0xE6
	0x44, 0x44, 0x54, 0x54, 0x28,	// �	0xE7
	0x7c, 0x20, 0x10, 0x08, 0x7c,	// �	0xE8
	0x7c, 0x41, 0x22, 0x11, 0x7c,	// �	0xE9
	0x7c, 0x10, 0x28, 0x44, 0x00,	// �	0xEA
	0x20, 0x44, 0x3c, 0x04, 0x7c,	// �	0xEB
	0x7c, 0x08, 0x10, 0x08, 0x7c,	// �	0xEC
	0x7c, 0x10, 0x10, 0x10, 0x7c,	// �	0xED
	0x38, 0x44, 0x44, 0x44, 0x38,	// o	0xEE
	0x7c, 0x04, 0x04, 0x04, 0x7c,	// �	0xEF	
	0x7C, 0x14, 0x14, 0x14, 0x08,	// p 	0xF0
	0x38, 0x44, 0x44, 0x44, 0x20,	// c	0xF1
	0x04, 0x04, 0x7c, 0x04, 0x04,	// �	0xF2
	0x0C, 0x50, 0x50, 0x50, 0x3C,	// �	0xF3
	0x30, 0x48, 0xfc, 0x48, 0x30,	// �	0xF4
	0x44, 0x28, 0x10, 0x28, 0x44,	// x	0xF5
	0x7c, 0x40, 0x40, 0x40, 0xfc,	// �	0xF6
	0x0c, 0x10, 0x10, 0x10, 0x7c,	// �	0xF7
	0x7c, 0x40, 0x7c, 0x40, 0x7c,	// �	0xF8
	0x7c, 0x40, 0x7c, 0x40, 0xfc,	// �	0xF9
	0x04, 0x7c, 0x50, 0x50, 0x20,	// �	0xFA
	0x7c, 0x50, 0x50, 0x20, 0x7c,	// �	0xFB
	0x7c, 0x50, 0x50, 0x20, 0x00,	// �	0xFC
	0x28, 0x44, 0x54, 0x54, 0x38,	// �	0xFD
	0x7c, 0x10, 0x38, 0x44, 0x38,	// �	0xFE
	0x08, 0x54, 0x34, 0x14, 0x7c,	// �	0xFF
	
		
};




#endif /* FONT5X7_H_ */
