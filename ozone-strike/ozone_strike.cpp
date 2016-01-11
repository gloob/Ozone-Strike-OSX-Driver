//
//  ozone-strike.hpp
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

#include "ozone_strike.hpp"

// This required macro defines the class's constructors, destructors,
// and several other methods I/O Kit requires.
OSDefineMetaClassAndStructors(org_litio_driver_ozone_strike, IOUSBHostHIDDevice)

// Define the driver's superclass.
#define super IOHIDDevice

bool org_litio_driver_ozone_strike::init(OSDictionary *dict) {
    bool result = super::init(dict);
    IOLog("Initializing\n");
    return result;
}

void org_litio_driver_ozone_strike::free(void) {
    IOLog("Freeing\n");
    super::free();
}

bool org_litio_driver_ozone_strike::start(IOService *provider) {
    bool result = super::start(provider);
    IOLog("Starting\n");
    return result;
}

void org_litio_driver_ozone_strike::stop(IOService *provider) {
    IOLog("Stopping\n");
    super::stop(provider);
}

IOReturn org_litio_driver_ozone_strike::newReportDescriptor(IOMemoryDescriptor** descriptor) const {
    // TODO: Define new device descriptor struct for the keyboard.
    // Assigning current descriptor.
    return IOUSBHostHIDDevice::newReportDescriptor(descriptor);
}

OSString* org_litio_driver_ozone_strike::newProductString() const {
    OSString * string = OSDynamicCast(OSString, getProperty("ProductString"));
    
    if (!string)
        return NULL;
    
    string->retain();
    
    return string;
}
