//
//  UILabel.h
//  UIKit
//
//  Copyright (c) 2006-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIColor, UIFont;

// 文本标签
NS_CLASS_AVAILABLE_IOS(2_0) @interface UILabel : UIView <NSCoding>

// 标签文本
@property(nullable, nonatomic,copy)   NSString           *text;            // default is nil
// 文本字体,默认nil,显示为系统字体17号
@property(null_resettable, nonatomic,strong) UIFont      *font;            // default is nil (system font 17 plain)
// 文本颜色
@property(null_resettable, nonatomic,strong) UIColor     *textColor;       // default is nil (text draws black)
// 阴影颜色,默认nil,无阴影
@property(nullable, nonatomic,strong) UIColor            *shadowColor;     // default is nil (no shadow)
// 阴影偏移量
@property(nonatomic)        CGSize             shadowOffset;    // default is CGSizeMake(0, -1) -- a top shadow
// 文本对齐方式
@property(nonatomic)        NSTextAlignment    textAlignment;   // default is NSTextAlignmentLeft
// 文本省略模式,默认NSLineBreakByTruncatingTail,省略号在末尾
@property(nonatomic)        NSLineBreakMode    lineBreakMode;   // default is NSLineBreakByTruncatingTail. used for single and multiple lines of text

// the underlying attributed string drawn by the label, if set, the label ignores the properties above.
// 可以指定文本内容为富文本
@property(nullable, nonatomic,copy)   NSAttributedString *attributedText NS_AVAILABLE_IOS(6_0);  // default is nil

// the 'highlight' property is used by subclasses for such things as pressed states. it's useful to make it part of the base class as a user property

// 高亮时的颜色
@property(nullable, nonatomic,strong)               UIColor *highlightedTextColor; // default is nil
// 是否高亮
@property(nonatomic,getter=isHighlighted) BOOL     highlighted;          // default is NO

// 是否可与用户交互,默认NO
@property(nonatomic,getter=isUserInteractionEnabled) BOOL userInteractionEnabled;  // default is NO
// 是否可用
@property(nonatomic,getter=isEnabled)                BOOL enabled;                 // default is YES. changes how the label is drawn

// this determines the number of lines to draw and what to do when sizeToFit is called. default value is 1 (single line). A value of 0 means no limit
// if the height of the text reaches the # of lines or the height of the view is less than the # of lines allowed, the text will be
// truncated using the line break mode.

// 行数,如果设为0表示不限制
@property(nonatomic) NSInteger numberOfLines;

// these next 3 property allow the label to be autosized to fit a certain width by scaling the font size(s) by a scaling factor >= the minimum scaling factor
// and to specify how the text baseline moves when it needs to shrink the font.

// 字体大小自适应于宽度
@property(nonatomic) BOOL adjustsFontSizeToFitWidth;         // default is NO
// ?
@property(nonatomic) UIBaselineAdjustment baselineAdjustment; // default is UIBaselineAdjustmentAlignBaselines
// 最小字体
@property(nonatomic) CGFloat minimumScaleFactor NS_AVAILABLE_IOS(6_0); // default is 0.0


// Tightens inter-character spacing in attempt to fit lines wider than the available space if the line break mode is one of the truncation modes before starting to truncate.
// The maximum amount of tightening performed is determined by the system based on contexts such as font, line width, etc.
@property(nonatomic) BOOL allowsDefaultTighteningForTruncation NS_AVAILABLE_IOS(9_0); // default is NO

// override points. can adjust rect before calling super.
// label has default content mode of UIViewContentModeRedraw

- (CGRect)textRectForBounds:(CGRect)bounds limitedToNumberOfLines:(NSInteger)numberOfLines;
// 文本绘制到指定rect内
- (void)drawTextInRect:(CGRect)rect;


// Support for constraint-based layout (auto layout)
// If nonzero, this is used when determining -intrinsicContentSize for multiline labels
@property(nonatomic) CGFloat preferredMaxLayoutWidth NS_AVAILABLE_IOS(6_0);


// deprecated:
// 过期的

// 使用minimumScaleFactor代替
@property(nonatomic) CGFloat minimumFontSize NS_DEPRECATED_IOS(2_0, 6_0) __TVOS_PROHIBITED; // deprecated - use minimumScaleFactor. default is 0.0

// Non-functional.  Hand tune by using NSKernAttributeName to affect tracking, or consider using the allowsDefaultTighteningForTruncation property.
@property(nonatomic) BOOL adjustsLetterSpacingToFitWidth NS_DEPRECATED_IOS(6_0,7_0) __TVOS_PROHIBITED;

@end

NS_ASSUME_NONNULL_END
