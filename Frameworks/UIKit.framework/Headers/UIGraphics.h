//
//  UIGraphics.h
//  UIKit
//
//  Copyright (c) 2005-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

UIKIT_EXTERN CGContextRef __nullable UIGraphicsGetCurrentContext(void) CF_RETURNS_NOT_RETAINED;
UIKIT_EXTERN void UIGraphicsPushContext(CGContextRef context);
UIKIT_EXTERN void UIGraphicsPopContext(void);

UIKIT_EXTERN void UIRectFillUsingBlendMode(CGRect rect, CGBlendMode blendMode);
UIKIT_EXTERN void UIRectFill(CGRect rect);

UIKIT_EXTERN void UIRectFrameUsingBlendMode(CGRect rect, CGBlendMode blendMode);
UIKIT_EXTERN void UIRectFrame(CGRect rect);

UIKIT_EXTERN void UIRectClip(CGRect rect);

// UIImage context
// 图片环境

// 在内存中开启一个size尺寸的绘图环境(像素级)
UIKIT_EXTERN void     UIGraphicsBeginImageContext(CGSize size);
UIKIT_EXTERN void     UIGraphicsBeginImageContextWithOptions(CGSize size, BOOL opaque, CGFloat scale) NS_AVAILABLE_IOS(4_0);
// 从当前图片环境中获取UIImage对象
UIKIT_EXTERN UIImage* __null_unspecified UIGraphicsGetImageFromCurrentImageContext(void);
// 关闭绘图环境
UIKIT_EXTERN void     UIGraphicsEndImageContext(void); 

// PDF context

UIKIT_EXTERN BOOL UIGraphicsBeginPDFContextToFile(NSString *path, CGRect bounds, NSDictionary * __nullable documentInfo) NS_AVAILABLE_IOS(3_2);
UIKIT_EXTERN void UIGraphicsBeginPDFContextToData(NSMutableData *data, CGRect bounds, NSDictionary * __nullable documentInfo) NS_AVAILABLE_IOS(3_2);
UIKIT_EXTERN void UIGraphicsEndPDFContext(void) NS_AVAILABLE_IOS(3_2);

UIKIT_EXTERN void UIGraphicsBeginPDFPage(void) NS_AVAILABLE_IOS(3_2);
UIKIT_EXTERN void UIGraphicsBeginPDFPageWithInfo(CGRect bounds, NSDictionary * __nullable pageInfo) NS_AVAILABLE_IOS(3_2);

UIKIT_EXTERN CGRect UIGraphicsGetPDFContextBounds(void) NS_AVAILABLE_IOS(3_2);

UIKIT_EXTERN void UIGraphicsSetPDFContextURLForRect(NSURL *url, CGRect rect) NS_AVAILABLE_IOS(3_2);
UIKIT_EXTERN void UIGraphicsAddPDFContextDestinationAtPoint(NSString *name, CGPoint point) NS_AVAILABLE_IOS(3_2);
UIKIT_EXTERN void UIGraphicsSetPDFContextDestinationForRect(NSString *name, CGRect rect) NS_AVAILABLE_IOS(3_2);

NS_ASSUME_NONNULL_END
