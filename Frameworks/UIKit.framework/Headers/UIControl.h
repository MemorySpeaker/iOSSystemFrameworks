//
//  UIControl.h
//  UIKit
//
//  Copyright (c) 2005-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

// 控件事件枚举
typedef NS_OPTIONS(NSUInteger, UIControlEvents) {
    // 按下
    UIControlEventTouchDown                                         = 1 <<  0,      // on all touch downs
    // 连续多次快速按下
    UIControlEventTouchDownRepeat                                   = 1 <<  1,      // on multiple touchdowns (tap count > 1)
    // 按下后在响应区域内拖动
    UIControlEventTouchDragInside                                   = 1 <<  2,
    // 按下后从响应区域内拖动到区域外
    UIControlEventTouchDragOutside                                  = 1 <<  3,
    UIControlEventTouchDragEnter                                    = 1 <<  4,
    UIControlEventTouchDragExit                                     = 1 <<  5,
    // 按下后又从区域内抬起
    UIControlEventTouchUpInside                                     = 1 <<  6,
    // 按下后又从区域外抬起
    UIControlEventTouchUpOutside                                    = 1 <<  7,
    UIControlEventTouchCancel                                       = 1 <<  8,

    // 值发生变化.例如拖动条
    UIControlEventValueChanged                                      = 1 << 12,     // sliders, etc.
    UIControlEventPrimaryActionTriggered NS_ENUM_AVAILABLE_IOS(9_0) = 1 << 13,     // semantic action: for buttons, etc.

    UIControlEventEditingDidBegin                                   = 1 << 16,     // UITextField
    UIControlEventEditingChanged                                    = 1 << 17,
    UIControlEventEditingDidEnd                                     = 1 << 18,
    UIControlEventEditingDidEndOnExit                               = 1 << 19,     // 'return key' ending editing

    // 所有触碰事件
    UIControlEventAllTouchEvents                                    = 0x00000FFF,  // for touch events
    // 所有编辑事件
    UIControlEventAllEditingEvents                                  = 0x000F0000,  // for UITextField
    UIControlEventApplicationReserved                               = 0x0F000000,  // range available for application use
    UIControlEventSystemReserved                                    = 0xF0000000,  // range reserved for internal framework use
    // 所有事件
    UIControlEventAllEvents                                         = 0xFFFFFFFF
};

// 控件内容垂直对齐方式
typedef NS_ENUM(NSInteger, UIControlContentVerticalAlignment) {
    // 居中
    UIControlContentVerticalAlignmentCenter  = 0,
    // 顶部
    UIControlContentVerticalAlignmentTop     = 1,
    // 底部
    UIControlContentVerticalAlignmentBottom  = 2,
    // 填充
    UIControlContentVerticalAlignmentFill    = 3,
};

// 控件内容水平对齐方式
typedef NS_ENUM(NSInteger, UIControlContentHorizontalAlignment) {
    // 居中
    UIControlContentHorizontalAlignmentCenter = 0,
    // 居左
    UIControlContentHorizontalAlignmentLeft   = 1,
    // 居右
    UIControlContentHorizontalAlignmentRight  = 2,
    // 填充
    UIControlContentHorizontalAlignmentFill   = 3,
};

// 控件的不同状态
typedef NS_OPTIONS(NSUInteger, UIControlState) {
    // 普通
    UIControlStateNormal       = 0,
    // 高亮
    UIControlStateHighlighted  = 1 << 0,                  // used when UIControl isHighlighted is set
    // 不可用
    UIControlStateDisabled     = 1 << 1,
    // 被选中
    UIControlStateSelected     = 1 << 2,                  // flag usable by app (see below)
    UIControlStateFocused NS_ENUM_AVAILABLE_IOS(9_0) = 1 << 3, // Applicable only when the screen supports focus
    UIControlStateApplication  = 0x00FF0000,              // additional flags available for application use
    UIControlStateReserved     = 0xFF000000               // flags reserved for internal framework use
};

@class UITouch;
@class UIEvent;

//______________________________________________________

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIControl : UIView


// 是否可用,默认YES
@property(nonatomic,getter=isEnabled) BOOL enabled;                                  // default is YES. if NO, ignores touch events and subclasses may draw differently
// 是否被选中,默认NO
@property(nonatomic,getter=isSelected) BOOL selected;                                // default is NO may be used by some subclasses or by application
// 是否高亮.默认NO
@property(nonatomic,getter=isHighlighted) BOOL highlighted;                          // default is NO. this gets set/cleared automatically when touch enters/exits during tracking and cleared on up
@property(nonatomic) UIControlContentVerticalAlignment contentVerticalAlignment;     // how to position content vertically inside control. default is center
@property(nonatomic) UIControlContentHorizontalAlignment contentHorizontalAlignment; // how to position content hozontally inside control. default is center

// 控件状态
@property(nonatomic,readonly) UIControlState state;                  // could be more than one state (e.g. disabled|selected). synthesized from other flags.
@property(nonatomic,readonly,getter=isTracking) BOOL tracking;
@property(nonatomic,readonly,getter=isTouchInside) BOOL touchInside; // valid during tracking only

// ?
- (BOOL)beginTrackingWithTouch:(UITouch *)touch withEvent:(nullable UIEvent *)event;
- (BOOL)continueTrackingWithTouch:(UITouch *)touch withEvent:(nullable UIEvent *)event;
- (void)endTrackingWithTouch:(nullable UITouch *)touch withEvent:(nullable UIEvent *)event; // touch is sometimes nil if cancelTracking calls through to this.
- (void)cancelTrackingWithEvent:(nullable UIEvent *)event;   // event may be nil if cancelled for non-event reasons, e.g. removed from window

// add target/action for particular event. you can call this multiple times and you can specify multiple target/actions for a particular event.
// passing in nil as the target goes up the responder chain. The action may optionally include the sender and the event in that order
// the action cannot be NULL. Note that the target is not retained.
// 为控件的controlEvents事件(集)添加响应
- (void)addTarget:(nullable id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;

// remove the target/action for a set of events. pass in NULL for the action to remove all actions for that target
// 移除controlEvents事件对应的响应
- (void)removeTarget:(nullable id)target action:(nullable SEL)action forControlEvents:(UIControlEvents)controlEvents;

// get info about target & actions. this makes it possible to enumerate all target/actions by checking for each event kind
// 获取所有的target
- (NSSet *)allTargets;                                                                     // set may include NSNull to indicate at least one nil target
// 获取所有支持的事件
- (UIControlEvents)allControlEvents;                                                       // list of all events that have at least one action
// 获取controlEvent发生时,与target关联的所有action
- (nullable NSArray<NSString *> *)actionsForTarget:(nullable id)target forControlEvent:(UIControlEvents)controlEvent;    // single event. returns NSArray of NSString selector names. returns nil if none

// send the action. the first method is called for the event and is a point at which you can observe or override behavior. it is called repeately by the second.
- (void)sendAction:(SEL)action to:(nullable id)target forEvent:(nullable UIEvent *)event;
- (void)sendActionsForControlEvents:(UIControlEvents)controlEvents;                        // send all actions associated with events

@end

NS_ASSUME_NONNULL_END
