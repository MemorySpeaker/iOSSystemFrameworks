//
//  UIBarItem.h
//  UIKit
//
//  Copyright (c) 2008-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIControl.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

// 这种以Item结尾的一般都是系统私有控件的数据模型类
NS_CLASS_AVAILABLE_IOS(2_0) @interface UIBarItem : NSObject <NSCoding, UIAppearance>

// 实例化
- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

// 是否可用
@property(nonatomic,getter=isEnabled) BOOL         enabled;      // default is YES
// 标题
@property(nullable, nonatomic,copy)             NSString    *title;        // default is nil
// 图片
@property(nullable, nonatomic,strong)           UIImage     *image;        // default is nil
// 横屏时图片
@property(nullable, nonatomic,strong)           UIImage     *landscapeImagePhone NS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED; // default is nil
// 图片的内边距
@property(nonatomic)                  UIEdgeInsets imageInsets;  // default is UIEdgeInsetsZero
@property(nonatomic)                  UIEdgeInsets landscapeImagePhoneInsets NS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED;  // default is UIEdgeInsetsZero. These insets apply only when the landscapeImagePhone property is set.
// 标签值
@property(nonatomic)                  NSInteger    tag;          // default is 0

/* You may specify the font, text color, and shadow properties for the title in the text attributes dictionary, using the keys found in NSAttributedString.h.
 */
// 设置,获取指定状态的富文本标题
- (void)setTitleTextAttributes:(nullable NSDictionary<NSString *,id> *)attributes forState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
- (nullable NSDictionary<NSString *,id> *)titleTextAttributesForState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
