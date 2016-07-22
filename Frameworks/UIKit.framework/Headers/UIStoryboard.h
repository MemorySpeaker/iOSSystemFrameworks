//
//  UIStoryboard.h
//  UIKit
//
//  Copyright 2011-2012 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

@class UIViewController;

NS_ASSUME_NONNULL_BEGIN

// 故事板对象
NS_CLASS_AVAILABLE_IOS(5_0) @interface UIStoryboard : NSObject {
}

// 实例化名称为name的storyboard,bundle参数为nil时默认为mainBundle
+ (UIStoryboard *)storyboardWithName:(NSString *)name bundle:(nullable NSBundle *)storyboardBundleOrNil;

// 获取故事版中的初始控制器对象,可能为nil
- (nullable __kindof UIViewController *)instantiateInitialViewController;
// 获取故事版中标识为identifier的控制器对象,identifier要与故事版中填的参数一致
- (__kindof UIViewController *)instantiateViewControllerWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
