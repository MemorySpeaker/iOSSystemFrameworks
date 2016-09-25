//
//  UIScreenMode.h
//  UIKit
//
//  Copyright (c) 2009-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <CoreGraphics/CoreGraphics.h>

// 屏幕模式.   貌似没有遇到多
NS_CLASS_AVAILABLE_IOS(3_2) @interface UIScreenMode : NSObject 

//以像素为单位的尺寸
@property(readonly,nonatomic) CGSize  size;             // The width and height in pixels
//单个像素的长宽比。
@property(readonly,nonatomic) CGFloat pixelAspectRatio; // The aspect ratio of a single pixel. The ratio is defined as X/Y.

@end
