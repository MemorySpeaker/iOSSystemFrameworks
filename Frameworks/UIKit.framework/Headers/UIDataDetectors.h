//
//  UIDataDetectors.h
//  UIKit
//
//  Copyright (c) 2009-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

// 数据识别类型枚举
typedef NS_OPTIONS(NSUInteger, UIDataDetectorTypes) {
	// 手机号
    UIDataDetectorTypePhoneNumber                              = 1 << 0,          // Phone number detection
    // 链接
    UIDataDetectorTypeLink                                     = 1 << 1,          // URL detection
    // 地址
    UIDataDetectorTypeAddress NS_ENUM_AVAILABLE_IOS(4_0)       = 1 << 2,          // Street address detection
    // 日期
    UIDataDetectorTypeCalendarEvent NS_ENUM_AVAILABLE_IOS(4_0) = 1 << 3,          // Event detection

    // 不识别
    UIDataDetectorTypeNone          = 0,               // No detection at all
    // 识别所有
    UIDataDetectorTypeAll           = NSUIntegerMax    // All types
} __TVOS_PROHIBITED;
