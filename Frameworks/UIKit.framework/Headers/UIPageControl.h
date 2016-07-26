//
//  UIPageControl.h
//  UIKit
//
//  Copyright (c) 2008-2015 Apple Inc. All rights reserved.
//
/*
 * 由MemorySpeaker维护
 * 联系邮箱:wangnistronger@icloud.com
 * 本文件对应维护地址:
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIPageControl : UIControl 

//总页数,默认为0
@property(nonatomic) NSInteger numberOfPages;          // default is 0
//当前页数,默认为0.该值范围为[0,numberOfPages-1)
@property(nonatomic) NSInteger currentPage;            // default is 0. value pinned to 0..numberOfPages-1

//是否在只有单页时隐藏.默认为NO
@property(nonatomic) BOOL hidesForSinglePage;          // hide the the indicator if there is only one page. default is NO

//是否延迟显示,默认为NO;如果延迟,页码变化时不会立即更新显示,直到updateCurrentPageDisplay被调用才会更新显示
//如果直接设置currentPage值,则始终直接显示,不会延迟
@property(nonatomic) BOOL defersCurrentPageDisplay;    // if set, clicking to a new page won't update the currently displayed page until -updateCurrentPageDisplay is called. default is NO
//更新显示.如果defersCurrentPageDisplay为NO,则忽略该方法.
- (void)updateCurrentPageDisplay;                      // update page display to match the currentPage. ignored if defersCurrentPageDisplay is NO. setting the page value directly will update immediately

// 根据pageCount参数返回显示所有点的最小尺寸.单个点所占用的尺寸系统已设定
- (CGSize)sizeForNumberOfPages:(NSInteger)pageCount;   // returns minimum size required to display dots for given page count. can be used to size control if page count could change

//页码指示点的一般状态颜色
@property(nullable, nonatomic,strong) UIColor *pageIndicatorTintColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;
//当前页码指示点颜色
@property(nullable, nonatomic,strong) UIColor *currentPageIndicatorTintColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
