//
//  OzoneStrikeBattle.cpp
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

#include <IOKit/IOLib.h>

#include "OzoneStrikeBattle.hpp"

namespace Ozone {
    #include "ozone_strike_hid.h"
}

// This required macro defines the class's constructors, destructors,
// and several other methods I/O Kit requires.
OSDefineMetaClassAndStructors(org_litio_OzoneStrikeBattle, IOUSBHostHIDDevice)

// Define the driver's superclass.
#define super IOUSBHostHIDDevice

bool org_litio_OzoneStrikeBattle::init(OSDictionary *dict) {
    bool result = super::init(dict);
    IOLog("Initializing\n");
    return result;
}

void org_litio_OzoneStrikeBattle::free(void) {
    IOLog("Freeing\n");
    super::free();
}

bool org_litio_OzoneStrikeBattle::start(IOService *provider) {
    bool result = super::start(provider);
    IOLog("Starting\n");
    return result;
}

void org_litio_OzoneStrikeBattle::stop(IOService *provider) {
    IOLog("Stopping\n");
    super::stop(provider);
}

void printBytes(OSData *data) {
    const unsigned char *bytes = (unsigned char *) data->getBytesNoCopy();
    for (int i = 0; i < data->getLength(); i++) {
        IOLog("0x%02x ", (unsigned char) bytes[i]);
    }
    IOLog("\n");
}

IOReturn org_litio_OzoneStrikeBattle::newReportDescriptor(IOMemoryDescriptor** descriptor) const {
    // TODO: Define new device descriptor struct for the keyboard.
    // Assigning current descriptor.
    IOLog("OzoneStrike::%s[%p] - Setting HID report descriptor.\n", getName(), this);
    OSData *reportDescriptor = OSData::withBytes(Ozone::HIDReportDescriptor, sizeof(Ozone::HIDReportDescriptor));
    OSData *reportDescriptorNew = OSDynamicCast(OSData, getProperty("ReportDescriptorOverride"));
    
    if (reportDescriptor == NULL) {
        IOLog("OzoneStrike::%s[%p] - reportDescriptor OSData not set.\n", getName(), this);
        return kIOReturnNoResources;
    }
    
    printBytes(reportDescriptorNew);
    printBytes(reportDescriptor);
    
    IOLog("OzoneStrike::%s[%p] - reportDescriptor OSData set (size: %d, data: %s).\n", getName(), this, reportDescriptor->getLength(), reportDescriptor->getBytesNoCopy());

    //OSData *reportDescriptor = OSDynamicCast(OSData, Ozone::HIDReportDescriptor);
    IOBufferMemoryDescriptor *bufferDescriptor = IOBufferMemoryDescriptor::withBytes(reportDescriptor->getBytesNoCopy(),
                                                                               reportDescriptor->getLength(),
                                                                               kIODirectionOutIn);
    //IOBufferMemoryDescriptor *bufferDescriptor = IOBufferMemoryDescriptor::inTaskWithOptions(kernel_task,
     //                                                                                        0,
     //                                                                                        sizeof(Ozone::HIDReportDescriptor));
/*
    if (bufferDescriptor == NULL) {
        return kIOReturnNoResources;
    }

    bufferDescriptor->writeBytes(0, Ozone::HIDReportDescriptor,sizeof(Ozone::HIDReportDescriptor));
*/
    if (bufferDescriptor) {
        *descriptor = bufferDescriptor;
        return kIOReturnSuccess;
    } else {
        bufferDescriptor->release();
        *descriptor = NULL;
        return kIOReturnNoMemory;
    }

    //return IOUSBHostHIDDevice::newReportDescriptor(descriptor);
}

OSString* org_litio_OzoneStrikeBattle::newProductString() const {
    OSString * string = OSDynamicCast(OSString, getProperty("ProductString"));

    if (!string)
        return NULL;

    string->retain();

    return string;
}
