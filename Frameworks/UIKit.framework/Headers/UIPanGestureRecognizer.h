//
//  UIPanGestureRecognizer.h
//  UIKit
//
//  Copyright (c) 2008-2015 Apple Inc. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIGestureRecognizer.h>

// Begins:  when at least minimumNumberOfTouches have moved enough to be considered a pan
// Changes: when a finger moves while at least minimumNumberOfTouches are down
// Ends:    when all fingers have lifted

NS_ASSUME_NONNULL_BEGIN

// 拖动手势
NS_CLASS_AVAILABLE_IOS(3_2) @interface UIPanGestureRecognizer : UIGestureRecognizer 

//拖动时需要的最少手指数
@property (nonatomic)          NSUInteger minimumNumberOfTouches __TVOS_PROHIBITED;   // default is 1. the minimum number of touches required to match
//拖动时需要的最多手指数
@property (nonatomic)          NSUInteger maximumNumberOfTouches __TVOS_PROHIBITED;   // default is UINT_MAX. the maximum number of touches that can be down

//在view中的移动位移
- (CGPoint)translationInView:(nullable UIView *)view;                        // translation in the coordinate system of the specified view
- (void)setTranslation:(CGPoint)translation inView:(nullable UIView *)view;

//拖动速率
- (CGPoint)velocityInView:(nullable UIView *)view;                           // velocity of the pan in pixels/second in the coordinate system of the specified view

@end

NS_ASSUME_NONNULL_END
