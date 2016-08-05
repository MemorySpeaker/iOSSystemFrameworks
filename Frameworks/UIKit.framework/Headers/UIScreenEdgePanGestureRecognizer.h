//
//  UIScreenEdgePanGestureRecognizer.h
//  Copyright (c) 2012-2015 Apple Inc. All rights reserved.
//

#import <UIKit/UIGeometry.h>
#import <UIKit/UIPanGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

/*! This subclass of UIPanGestureRecognizer only recognizes if the user slides their finger
    in from the bezel on the specified edge. */

// 屏幕边缘拖动手势
NS_CLASS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED @interface UIScreenEdgePanGestureRecognizer : UIPanGestureRecognizer
//相对于当前屏幕朝向，触发手势的屏幕边
@property (readwrite, nonatomic, assign) UIRectEdge edges; //< The edges on which this gesture recognizes, relative to the current interface orientation
@end

NS_ASSUME_NONNULL_END
