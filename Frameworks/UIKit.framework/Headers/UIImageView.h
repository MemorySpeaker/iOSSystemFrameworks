//
//  UIImageView.h
//  UIKit
//
//  Copyright (c) 2006-2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIImageView : UIView 

- (instancetype)initWithImage:(nullable UIImage *)image;
- (instancetype)initWithImage:(nullable UIImage *)image highlightedImage:(nullable UIImage *)highlightedImage NS_AVAILABLE_IOS(3_0);

@property (nullable, nonatomic, strong) UIImage *image; // default is nil
@property (nullable, nonatomic, strong) UIImage *highlightedImage NS_AVAILABLE_IOS(3_0); // default is nil
@property (nonatomic, getter=isUserInteractionEnabled) BOOL userInteractionEnabled; // default is NO

@property (nonatomic, getter=isHighlighted) BOOL highlighted NS_AVAILABLE_IOS(3_0); // default is NO

// these allow a set of images to be animated. the array may contain multiple copies of the same

// 作为动画图片视图时的图片帧数组
@property (nullable, nonatomic, copy) NSArray<UIImage *> *animationImages; // The array must contain UIImages. Setting hides the single image. default is nil
// 高亮时作为动画图片视图时的图片帧数组
@property (nullable, nonatomic, copy) NSArray<UIImage *> *highlightedAnimationImages NS_AVAILABLE_IOS(3_0); // The array must contain UIImages. Setting hides the single image. default is nil

// 作为动画图片视图时的单次播放时长(秒).默认为images * 1/30,也就是默认为每秒30帧
@property (nonatomic) NSTimeInterval animationDuration;         // for one cycle of images. default is number of images * 1/30th of a second (i.e. 30 fps)
// 作为动画图片视图时的重复播放次数.默认为0,不终止
@property (nonatomic) NSInteger      animationRepeatCount;      // 0 means infinite (default is 0)

// When tintColor is non-nil, any template images set on the image view will be colorized with that color.
// The tintColor is inherited through the superview hierarchy. See UIView for more information.
@property (null_resettable, nonatomic, strong) UIColor *tintColor NS_AVAILABLE_IOS(7_0);

// 开始动画视图播放
- (void)startAnimating;
// 终止动画视图播放
- (void)stopAnimating;
// 是否正在作为动画视图播放
- (BOOL)isAnimating;

// if YES, the UIImageView will display a focused appearance when any of its immediate or distant superviews become focused
@property (nonatomic) BOOL adjustsImageWhenAncestorFocused UIKIT_AVAILABLE_TVOS_ONLY(9_0);

// if adjustsImageWhenAncestorFocused is set, the image view may display its image in a larger frame when focused.
// this layout guide can be used to align other elements with the image view's focused frame.
@property(readonly,strong) UILayoutGuide *focusedFrameGuide UIKIT_AVAILABLE_TVOS_ONLY(9_0);

@end

NS_ASSUME_NONNULL_END
