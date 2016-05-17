//
//  ozone_strike_hid.h
//  https://github.com/gloob/Ozone-Strike-OSX-Driver
//
//  Copyright (c) 2016 Alejandro Leiva <gloob@litio.org>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef OZONE_STRIKE_HID_H
#define OZONE_STRIKE_HID_H

static const unsigned char HIDReportDescriptor[] = {
	0x05, 0x01,			//	Usage Page (Generic Desktop)	05 01 
	0x09, 0x06,			//	Usage (Keyboard)	09 06 
	0xA1, 0x01,			//	Collection (Application)	A1 01 
	0x85, 0x05,			//	    Report ID (5)	85 05 
	0x95, 0x08,			//	    Report Count (8)	95 08
	0x75, 0x01,			//	    Report Size (1)	75 0
	0x15, 0x00,			//	    Logical Minimum (0)	15 00 
	0x25, 0x01,			//	    Logical Maximum (1)	25 01 
	0x05, 0x07,			//	    Usage Page (Keyboard/Keypad)	05 07 
	0x19, 0xE0,			//	    Usage Minimum (Keyboard Left Control)	19 E0 
	0x29, 0xE7,			//	    Usage Maximum (Keyboard Right GUI)	29 E7
    0x81, 0x02,			//	    Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)	81 02
	0x29, 0x67,			//	    Usage Maximum (Keypad =)	29 67
	0x95, 0x68,			//	    Report Count (104)	95 68
    0x19, 0x00,			//	    Usage Minimum (Undefined)	19 00
    0x81, 0x02,			//	    Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)	81 02
    0x95, 0x08,			//	    Report Count (8)	95 08
    0x81, 0x01,			//	    Input (Cnst,Ary,Abs)	81 01
	0xC0,				//	End Collection	C0 
	0x05, 0x01,			//	Usage Page (Generic Desktop)	05 01 
	0x09, 0x80,			//	Usage (System Control)	09 80 
	0xA1, 0x01,			//	Collection (Application)	A1 01 
	0x85, 0x02,			//	    Report ID (2)	85 02 
	0x19, 0x81,			//	    Usage Minimum (System Power Down)	19 81 
	0x29, 0x83,			//	    Usage Maximum (System Wake Up)	29 83 
	0x15, 0x00,			//	    Logical Minimum (0)	15 00 
	0x25, 0x01,			//	    Logical Maximum (1)	25 01 
	0x95, 0x03,			//	    Report Count (3)	95 03 
	0x75, 0x01,			//	    Report Size (1)	75 01 
	0x81, 0x02,			//	    Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)	81 02 
	0x95, 0x01,			//	    Report Count (1)	95 01 
	0x75, 0x05,			//	    Report Size (5)	75 05 
	0x81, 0x01,			//	    Input (Cnst,Ary,Abs)	81 01 
	0xC0,				//	End Collection	C0 
	0x05, 0x0C,			//	Usage Page (Consumer Devices)	05 0C 
	0x09, 0x01,			//	Usage (Consumer Control)	09 01 
	0xA1, 0x01,			//	Collection (Application)	A1 01 
	0x85, 0x03,			//	    Report ID (3)	85 03 
	0x19, 0x00,			//	    Usage Minimum (Undefined)	19 00 
	0x2A, 0xFF, 0x02,		//	    Usage Maximum	2A FF 02
	0x15, 0x00,			//	    Logical Minimum (0)	15 00 
	0x26, 0xFF, 0x7F,		//	    Logical Maximum (32767)	26 FF 7F
	0x95, 0x01,			//	    Report Count (1)	95 01 
	0x75, 0x10,			//	    Report Size (16)	75 10 
	0x81, 0x00,			//	    Input (Data,Ary,Abs)	81 00 
	0xC0,				//	End Collection	C0 
	0x06, 0x00, 0xFF,		//	Usage Page (Vendor-Defined 1)	06 00 FF
	0x09, 0x01,			//	Usage (Vendor-Defined 1)	09 01 
	0xA1, 0x01,			//	Collection (Application)	A1 01 
	0x85, 0x06,			//	    Report ID (6)	85 06 
	0x15, 0x00,			//	    Logical Minimum (0)	15 00 
	0x26, 0xFF, 0x00,		//	    Logical Maximum (255)	26 FF 00
	0x09, 0x2F,			//	    Usage (Vendor-Defined 47)	09 2F 
	0x95, 0x02,			//	    Report Count (2)	95 02 
	0x75, 0x08,			//	    Report Size (8)	75 08 
	0x81, 0x02,			//	    Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)	81 02 
	0xC0,				//	End Collection	C0 
	0x06, 0x01, 0xFF,		//	Usage Page (Vendor-Defined 2)	06 01 FF
	0x09, 0x01,			//	Usage (Vendor-Defined 1)	09 01 
	0xA1, 0x01,			//	Collection (Application)	A1 01 
	0x85, 0x07,			//	    Report ID (7)	85 07 
	0x15, 0x00,			//	    Logical Minimum (0)	15 00 
	0x26, 0xFF, 0x00,		//	    Logical Maximum (255)	26 FF 00
	0x09, 0x20,			//	    Usage (Vendor-Defined 32)	09 20 
	0x75, 0x08,			//	    Report Size (8)	75 08 
	0x95, 0x07,			//	    Report Count (7)	95 07 
	0xB1, 0x02,			//	    Feature (Data,Var,Abs,NWrp,Lin,Pref,NNul,NVol,Bit)	B1 02 
	0xC0				//	End Collection	C0 
};

#endif // OZONE_STRIKE_HID_H
