//
//  UITextField.h
//  UIKit
//
//  Copyright (c) 2005-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UITextInput.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage, UIImageView, UILabel, UIColor, UIButton;
@class UITextFieldAtomBackgroundView;
@class UITextFieldBackgroundView;
@class UITextFieldBorderView;
@class UITextFieldLabel;
@class UITextInputTraits;
@class UITextSelectionView;
@class UITextInteractionAssistant;
@class UIPopoverController;
@protocol UITextFieldDelegate;
@protocol UITextSelecting;

// 边框线样式
typedef NS_ENUM(NSInteger, UITextBorderStyle) {
    UITextBorderStyleNone, //不显示
    UITextBorderStyleLine,
    UITextBorderStyleBezel,
    UITextBorderStyleRoundedRect  //圆角矩形
};

// 相对于编辑状态阶段的模式,在某些方法中使用
typedef NS_ENUM(NSInteger, UITextFieldViewMode) {
    UITextFieldViewModeNever, //始终不
    UITextFieldViewModeWhileEditing,  //编辑状态时
    UITextFieldViewModeUnlessEditing,  //非编辑状态时
    UITextFieldViewModeAlways   //始终都
};

// 文本框. 单行文本域
NS_CLASS_AVAILABLE_IOS(2_0) @interface UITextField : UIControl <UITextInput, NSCoding> 

// 文本框中的文本,默认为nil
@property(nullable, nonatomic,copy)   NSString               *text;                 // default is nil
// 文本框中的富文本,默认为nil
@property(nullable, nonatomic,copy)   NSAttributedString     *attributedText NS_AVAILABLE_IOS(6_0); // default is nil
// 文本颜色,默认为nil,显示为不透明的黑色
@property(nullable, nonatomic,strong) UIColor                *textColor;            // default is nil. use opaque black
// 文本字体,默认nil,显示为12号
@property(nullable, nonatomic,strong) UIFont                 *font;                 // default is nil. use system font 12 pt
// 文本对齐方式,默认为左对齐NSLeftTextAlignment
@property(nonatomic)        NSTextAlignment         textAlignment;        // default is NSLeftTextAlignment
// 边框线样式,默认为UITextBorderStyleNone,不显示.如果设置为UITextBorderStyleRoundedRect圆角矩形时,自定义的背景图片会被忽略
@property(nonatomic)        UITextBorderStyle       borderStyle;          // default is UITextBorderStyleNone. If set to UITextBorderStyleRoundedRect, custom background images are ignored.
// 默认文本样式
@property(nonatomic,copy)   NSDictionary<NSString *, id>           *defaultTextAttributes NS_AVAILABLE_IOS(7_0); // applies attributes to the full range of text. Unset attributes act like default values.

// 占位提示文字;显示为70%灰色
@property(nullable, nonatomic,copy)   NSString               *placeholder;          // default is nil. string is drawn 70% gray
// 占位的富文本提示文字,默认为nil
@property(nullable, nonatomic,copy)   NSAttributedString     *attributedPlaceholder NS_AVAILABLE_IOS(6_0); // default is nil
// 是否在编辑开始时清空文本,默认为NO
@property(nonatomic)        BOOL                    clearsOnBeginEditing; // default is NO which moves cursor to location clicked. if YES, all text cleared
// 是否是的字体大小自适应与宽度,默认为NO;如果设置为YES,当宽度变化时,文本会沿着基线发生缩放,而最小尺寸为minimumFontSize指定的值
@property(nonatomic)        BOOL                    adjustsFontSizeToFitWidth; // default is NO. if YES, text will shrink to minFontSize along baseline
// 字体的最小尺寸,默认为0.0; 如果设置了adjustsFontSizeToFitWidth为YES,则应该确保最小尺寸下仍可被阅读
@property(nonatomic)        CGFloat                 minimumFontSize;      // default is 0.0. actual min may be pinned to something readable. used if adjustsFontSizeToFitWidth is YES
// 文本框代理
@property(nullable, nonatomic,weak)   id<UITextFieldDelegate> delegate;             // default is nil. weak reference
// 背景图片,默认为nil;图片会被绘制在边框矩形区域内,图片会被伸缩
@property(nullable, nonatomic,strong) UIImage                *background;           // default is nil. draw in border rect. image should be stretchable
// 不可用状态下的背景图片,默认为nil;如果background没有设置值,则会被忽略,否则图片会被绘制在边框矩形区域内,图片会被伸缩
@property(nullable, nonatomic,strong) UIImage                *disabledBackground;   // default is nil. ignored if background not set. image should be stretchable

// 是否正处于编辑状态
@property(nonatomic,readonly,getter=isEditing) BOOL editing;
@property(nonatomic) BOOL allowsEditingTextAttributes NS_AVAILABLE_IOS(6_0); // default is NO. allows editing text attributes with style operations and pasting rich text
@property(nullable, nonatomic,copy) NSDictionary<NSString *, id> *typingAttributes NS_AVAILABLE_IOS(6_0); // automatically resets when the selection changes

// You can supply custom views which are displayed at the left or right
// sides of the text field. Uses for such views could be to show an icon or
// a button to operate on the text in the field in an application-defined
// manner.
// 
// A very common use is to display a clear button on the right side of the
// text field, and a standard clear button is provided.

// 清空按钮的显示模式,默认为始终不显示UITextFieldViewModeNever
@property(nonatomic)        UITextFieldViewMode  clearButtonMode; // sets when the clear button shows up. default is UITextFieldViewModeNever

// 文本框的左视图,默认为nil
@property(nullable, nonatomic,strong) UIView              *leftView;        // e.g. magnifying glass
// 左视图的显示模式,默认为始终不显示UITextFieldViewModeNever
@property(nonatomic)        UITextFieldViewMode  leftViewMode;    // sets when the left view shows up. default is UITextFieldViewModeNever

// 文本框的右视图,默认为nil
@property(nullable, nonatomic,strong) UIView              *rightView;       // e.g. bookmarks button
// 右视图的显示模式,默认为始终不显示UITextFieldViewModeNever
@property(nonatomic)        UITextFieldViewMode  rightViewMode;   // sets when the right view shows up. default is UITextFieldViewModeNever

// drawing and positioning overrides
//用于子类重写来自定义一些元素的布局
- (CGRect)borderRectForBounds:(CGRect)bounds;
- (CGRect)textRectForBounds:(CGRect)bounds;
- (CGRect)placeholderRectForBounds:(CGRect)bounds;
- (CGRect)editingRectForBounds:(CGRect)bounds;
- (CGRect)clearButtonRectForBounds:(CGRect)bounds;
- (CGRect)leftViewRectForBounds:(CGRect)bounds;
- (CGRect)rightViewRectForBounds:(CGRect)bounds;

- (void)drawTextInRect:(CGRect)rect;
- (void)drawPlaceholderInRect:(CGRect)rect;

// Presented when object becomes first responder.  If set to nil, reverts to following responder chain.  If
// set while first responder, will not take effect until reloadInputViews is called.
// 输入源
@property (nullable, readwrite, strong) UIView *inputView;             
// 输入源附件
@property (nullable, readwrite, strong) UIView *inputAccessoryView;

@property(nonatomic) BOOL clearsOnInsertion NS_AVAILABLE_IOS(6_0); // defaults to NO. if YES, the selection UI is hidden, and inserting text will replace the contents of the field. changing the selection will automatically set this to NO.

@end

@interface UIView (UITextField)
// 让view及其subview不再作为第一响应者; 经常使用[self endEditing:YES]来快速收起键盘
- (BOOL)endEditing:(BOOL)force;    // use to make the view or any subview that is the first responder resign (optionally force)
@end

// 文本框代理
@protocol UITextFieldDelegate <NSObject>

@optional

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;        // return NO to disallow editing.
- (void)textFieldDidBeginEditing:(UITextField *)textField;           // became first responder
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;          // return YES to allow editing to stop and to resign first responder status. NO to disallow the editing session to end
- (void)textFieldDidEndEditing:(UITextField *)textField;             // may be called if forced even if shouldEndEditing returns NO (e.g. view removed from window) or endEditing:YES called

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;   // return NO to not change text

- (BOOL)textFieldShouldClear:(UITextField *)textField;               // called when clear button pressed. return NO to ignore (no notifications)
- (BOOL)textFieldShouldReturn:(UITextField *)textField;              // called when 'return' key pressed. return NO to ignore.

@end

// 文本域相关通知(键盘的弹出收起好像就是基于这些通知的)
// 开始编辑
UIKIT_EXTERN NSString *const UITextFieldTextDidBeginEditingNotification;
// 结束编辑
UIKIT_EXTERN NSString *const UITextFieldTextDidEndEditingNotification;
// 文本内容改变
UIKIT_EXTERN NSString *const UITextFieldTextDidChangeNotification;

NS_ASSUME_NONNULL_END

