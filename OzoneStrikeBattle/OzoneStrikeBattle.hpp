//
//  OzoneStrikeBattle.hpp
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

#include "IOKit/usb/IOUSBHostHIDDevice.h"

class org_litio_OzoneStrikeBattle : public IOUSBHostHIDDevice {

    OSDeclareDefaultStructors(org_litio_OzoneStrikeBattle)

public:
    virtual bool init(OSDictionary *dictionary = 0) override;
    virtual void free(void) override;
    virtual bool start(IOService *provider) override;
    virtual void stop(IOService *provider) override;

    virtual IOReturn newReportDescriptor(IOMemoryDescriptor** descriptor) const override;
    virtual OSString* newProductString() const override;

    unsigned char *reportDescriptor;
    UInt16 reportDescriptor_len;

    OSString *name;
};
