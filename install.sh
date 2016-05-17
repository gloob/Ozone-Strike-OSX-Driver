#!/bin/sh
rm -rf build
xcodebuild -project OzoneStrikeBattle.xcodeproj
sudo kextunload /System/Library/Extensions/OzoneStrikeBattle.kext
sudo rm -rf /System/Library/Extensions/OzoneStrikeBattle.kext
sudo cp -r build/Release/OzoneStrikeBattle.kext /System/Library/Extensions/OzoneStrikeBattle.kext && sudo kextutil -v /System/Library/Extensions/OzoneStrikeBattle.kext && sudo kextload /System/Library/Extensions/OzoneStrikeBattle.kext
kextstat | grep -i OzoneStrikeBattle
