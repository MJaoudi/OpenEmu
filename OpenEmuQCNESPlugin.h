/*
 Copyright (c) 2009, OpenEmu Team
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Cocoa/Cocoa.h>

@class GameCore;
@class GameAudio, GameBuffer;

@interface OpenEmuQCNES : QCPlugIn
{
	// init stuff
	NSBundle* bundle;
	GameCore* gameCore;
	GameAudio*  gameAudio;
	GameBuffer* gameBuffer;
	BOOL loadedRom;
	BOOL romFinishedLoading;
	BOOL hasNmtRam;
	BOOL hasChrRom;
	NSMutableArray* persistantControllerData;
	NSRecursiveLock * gameLock;
}

/*
Declare here the Obj-C 2.0 properties to be used as input and output ports for the plug-in e.g.
You can access their values in the appropriate plug-in methods using self.inputFoo or self.inputBar
*/

@property (assign) NSString* inputRom;
@property (assign) NSArray * inputControllerData;
@property (assign) double inputVolume;
@property (assign) NSString* inputSaveStatePath;
@property (assign) NSString* inputLoadStatePath;
@property (assign) BOOL inputPauseEmulation;
@property (assign) NSString* inputCheatCode;

@property (assign) BOOL inputEnableRewinder;
@property (assign) NSUInteger inputRewinderDirection;
@property (assign) BOOL inputEnableRewinderBackwardsSound;
// @property (assign) BOOL inputRewinderReset;

@property (assign) BOOL inputNmtRamCorrupt;
@property (assign) double inputNmtRamOffset;
@property (assign) double inputNmtRamValue;

@property (assign) BOOL inputChrRamCorrupt;
@property (assign) double inputChrRamOffset;
@property (assign) double inputChrRamValue;

@property (assign) id <QCPlugInOutputImageProvider>outputImage;

@end

@interface OpenEmuQCNES (Execution)
- (BOOL) controllerDataValidate:(NSArray*) cData;
- (void) handleControllerData;
- (void) refresh;
- (void) loadRom: (NSString*) romPath;
- (void) saveState: (NSString *) fileName;
- (BOOL) loadState: (NSString *) fileName;
- (void) setCode:(NSString*)cheatCode;
- (void) enableRewinder:(BOOL) rewind;

@end

