//
//  UIAlertView.h
//  UIKit
//
//  Copyright 2010-2012 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UITextField.h>
#import <UIKit/UIView.h>

NS_ASSUME_NONNULL_BEGIN

// 警告框类型
typedef NS_ENUM(NSInteger, UIAlertViewStyle) {
	// 默认
    UIAlertViewStyleDefault = 0,
    // 有一个密码文本域
    UIAlertViewStyleSecureTextInput,
    // 有一个普通文本域
    UIAlertViewStylePlainTextInput,
    // 有类似于登录的普通文本域和密码文本域
    UIAlertViewStyleLoginAndPasswordInput
} __TVOS_PROHIBITED;

@protocol UIAlertViewDelegate;
@class UILabel, UIToolbar, UITabBar, UIWindow, UIBarButtonItem, UIPopoverController;

// 警告框,9.0后使用UIAlertController代替
NS_CLASS_DEPRECATED_IOS(2_0, 9_0, "UIAlertView is deprecated. Use UIAlertController with a preferredStyle of UIAlertControllerStyleAlert instead") __TVOS_PROHIBITED
@interface UIAlertView : UIView

// 实例化
- (instancetype)initWithTitle:(nullable NSString *)title message:(nullable NSString *)message delegate:(nullable id /*<UIAlertViewDelegate>*/)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle otherButtonTitles:(nullable NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION NS_EXTENSION_UNAVAILABLE_IOS("Use UIAlertController instead.");

- (id)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;
- (nullable instancetype) initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

// 代理
@property(nullable,nonatomic,weak) id /*<UIAlertViewDelegate>*/ delegate;
// 标题
@property(nonatomic,copy) NSString *title;
// 信息
@property(nullable,nonatomic,copy) NSString *message;   // secondary explanation text


// adds a button with the title. returns the index (0 based) of where it was added. buttons are displayed in the order added except for the
// cancel button which will be positioned based on HI requirements. buttons cannot be customized.
// 添加按钮,返回按钮的索引
- (NSInteger)addButtonWithTitle:(nullable NSString *)title;    // returns index of button. 0 based.
// buttonIndex处按钮的标题
- (nullable NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;
// 按钮数量
@property(nonatomic,readonly) NSInteger numberOfButtons;
// 取消按钮的索引
@property(nonatomic) NSInteger cancelButtonIndex;      // if the delegate does not implement -alertViewCancel:, we pretend this button was clicked on. default is -1

// 第一个其他类型按钮的索引
@property(nonatomic,readonly) NSInteger firstOtherButtonIndex;	// -1 if no otherButtonTitles or initWithTitle:... not used
// 是否可见
@property(nonatomic,readonly,getter=isVisible) BOOL visible;

// shows popup alert animated.
// 显示警告框
- (void)show;

// hides alert sheet or popup. use this method when you need to explicitly dismiss the alert.
// it does not need to be called if the user presses on a button
// 模拟点击buttonIndex处按钮效果
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

// Alert view style - defaults to UIAlertViewStyleDefault
// 风格
@property(nonatomic,assign) UIAlertViewStyle alertViewStyle NS_AVAILABLE_IOS(5_0);

// Retrieve a text field at an index
// The field at index 0 will be the first text field (the single field or the login field), the field at index 1 will be the password field. */
// 如果有文本域时获取textFieldIndex索引的文本域文本
- (nullable UITextField *)textFieldAtIndex:(NSInteger)textFieldIndex NS_AVAILABLE_IOS(5_0);


@end

// 代理
__TVOS_PROHIBITED
@protocol UIAlertViewDelegate <NSObject>
@optional

// Called when a button is clicked. The view will be automatically dismissed after this call returns
// 点击了buttonIndex处按钮
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex NS_DEPRECATED_IOS(2_0, 9_0);

// Called when we cancel a view (eg. the user clicks the Home button). This is not called when the user clicks the cancel button.
// If not defined in the delegate, we simulate a click in the cancel button
// 非正常情况下的取消
- (void)alertViewCancel:(UIAlertView *)alertView NS_DEPRECATED_IOS(2_0, 9_0);

// 将要,已经显示
- (void)willPresentAlertView:(UIAlertView *)alertView NS_DEPRECATED_IOS(2_0, 9_0);  // before animation and showing view
- (void)didPresentAlertView:(UIAlertView *)alertView NS_DEPRECATED_IOS(2_0, 9_0);  // after animation

// 将要,已经消失
- (void)alertView:(UIAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex NS_DEPRECATED_IOS(2_0, 9_0); // before animation and hiding view
- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex NS_DEPRECATED_IOS(2_0, 9_0);  // after animation

// Called after edits in any of the default fields added by the style
// ?
- (BOOL)alertViewShouldEnableFirstOtherButton:(UIAlertView *)alertView NS_DEPRECATED_IOS(2_0, 9_0);

@end

NS_ASSUME_NONNULL_END
