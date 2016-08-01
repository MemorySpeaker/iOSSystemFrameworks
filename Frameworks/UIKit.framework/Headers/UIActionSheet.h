//
//  UIActionSheet.h
//  UIKit
//
//  Copyright 2010-2012 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UITextField.h>
#import <UIKit/UIView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UIActionSheetDelegate;
@class UILabel, UIToolbar, UITabBar, UIWindow, UIBarButtonItem, UIPopoverController;

// 风格枚举
typedef NS_ENUM(NSInteger, UIActionSheetStyle) {
	// 当从toolbar中显示时为Automatic,其他默认为Default
    UIActionSheetStyleAutomatic        = -1,       // take appearance from toolbar style otherwise uses 'default'
    UIActionSheetStyleDefault          = UIBarStyleDefault,
    UIActionSheetStyleBlackTranslucent = UIBarStyleBlackTranslucent,
    UIActionSheetStyleBlackOpaque      = UIBarStyleBlackOpaque ,
} __TVOS_PROHIBITED;

// 行为列表.8.3后弃用,使用UIAlertController替代
NS_CLASS_DEPRECATED_IOS(2_0, 8_3, "UIActionSheet is deprecated. Use UIAlertController with a preferredStyle of UIAlertControllerStyleActionSheet instead") __TVOS_PROHIBITED
@interface UIActionSheet : UIView

// 快速实例化方法
- (instancetype)initWithTitle:(nullable NSString *)title delegate:(nullable id<UIActionSheetDelegate>)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle otherButtonTitles:(nullable NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION NS_EXTENSION_UNAVAILABLE_IOS("Use UIAlertController instead.");

// 代理
@property(nullable,nonatomic,weak) id<UIActionSheetDelegate> delegate;
// 标题
@property(nonatomic,copy) NSString *title;
// 风格
@property(nonatomic) UIActionSheetStyle actionSheetStyle; // default is UIActionSheetStyleAutomatic. ignored if alert is visible

// adds a button with the title. returns the index (0 based) of where it was added. buttons are displayed in the order added except for the
// destructive and cancel button which will be positioned based on HI requirements. buttons cannot be customized.
// 添加一个按钮,返回按钮添加后的索引
- (NSInteger)addButtonWithTitle:(nullable NSString *)title;    // returns index of button. 0 based.
// 返回buttonIndex处按钮的标题
- (nullable NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;
// 按钮数量
@property(nonatomic,readonly) NSInteger numberOfButtons;
// 取消按钮索引
@property(nonatomic) NSInteger cancelButtonIndex;      // if the delegate does not implement -actionSheetCancel:, we pretend this button was clicked on. default is -1
// "销毁"类型按钮索引
@property(nonatomic) NSInteger destructiveButtonIndex;        // sets destructive (red) button. -1 means none set. default is -1. ignored if only one button

// 首个其他类型的索引
@property(nonatomic,readonly) NSInteger firstOtherButtonIndex;	// -1 if no otherButtonTitles or initWithTitle:... not used
// 是否可见
@property(nonatomic,readonly,getter=isVisible) BOOL visible;

// show a sheet animated. you can specify either a toolbar, a tab bar, a bar button item or a plain view. We do a special animation if the sheet rises from
// a toolbar, tab bar or bar button item and we will automatically select the correct style based on the bar style. if not from a bar, we use
// UIActionSheetStyleDefault if automatic style set
// 调用不同显示方法时,系统会自动切换不同的显示动画效果.如果你设置的显示风格不合理,系统也会自动替换
- (void)showFromToolbar:(UIToolbar *)view;
- (void)showFromTabBar:(UITabBar *)view;
- (void)showFromBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated NS_AVAILABLE_IOS(3_2);
- (void)showFromRect:(CGRect)rect inView:(UIView *)view animated:(BOOL)animated NS_AVAILABLE_IOS(3_2);
// 在view中显示
- (void)showInView:(UIView *)view;

// hides alert sheet or popup. use this method when you need to explicitly dismiss the alert.
// it does not need to be called if the user presses on a button
// 模拟点击buttonIndex后释放视图的效果
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

@end


//代理方法
__TVOS_PROHIBITED
@protocol UIActionSheetDelegate <NSObject>
@optional

// Called when a button is clicked. The view will be automatically dismissed after this call returns
// 点击了buttonIndex处按钮
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex NS_DEPRECATED_IOS(2_0, 8_3) __TVOS_PROHIBITED;

// Called when we cancel a view (eg. the user clicks the Home button). This is not called when the user clicks the cancel button.
// If not defined in the delegate, we simulate a click in the cancel button
// 当被取消时(不是用户点击了取消按钮,而是用户按下home键或者有电话呼入时的情况)调用
- (void)actionSheetCancel:(UIActionSheet *)actionSheet NS_DEPRECATED_IOS(2_0, 8_3) __TVOS_PROHIBITED;

// 将要显示
- (void)willPresentActionSheet:(UIActionSheet *)actionSheet NS_DEPRECATED_IOS(2_0, 8_3)__TVOS_PROHIBITED;  // before animation and showing view
// 已经显示
- (void)didPresentActionSheet:(UIActionSheet *)actionSheet NS_DEPRECATED_IOS(2_0, 8_3) __TVOS_PROHIBITED;  // after animation

// 将要消失
- (void)actionSheet:(UIActionSheet *)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex NS_DEPRECATED_IOS(2_0, 8_3) __TVOS_PROHIBITED; // before animation and hiding view
// 已经消失
- (void)actionSheet:(UIActionSheet *)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex NS_DEPRECATED_IOS(2_0, 8_3) __TVOS_PROHIBITED;  // after animation

@end

NS_ASSUME_NONNULL_END

