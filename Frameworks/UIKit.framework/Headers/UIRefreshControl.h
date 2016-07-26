//
//  UIRefreshControl.h
//  UIKit
//
//  Copyright 2012-2015 Apple Inc. All rights reserved.
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
    
NS_CLASS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED @interface UIRefreshControl : UIControl

/* The designated initializer
 * This initializes a UIRefreshControl with a default height and width.
 * Once assigned to a UITableViewController, the frame of the control is managed automatically.
 * When a user has pulled-to-refresh, the UIRefreshControl fires its UIControlEventValueChanged event.
 *
*/
 //特定的初始化方法. 会自动设置默认宽高值.一旦被赋值给UITableViewController,其frame值也会自动确定.
 // 当用户下拉tableview时,会触发它的UIControlEventValueChanged事件
- (instancetype)init;

//是否正在刷新
@property (nonatomic, readonly, getter=isRefreshing) BOOL refreshing;

//渲染色
@property (null_resettable, nonatomic, strong) UIColor *tintColor;
// 可以指定一个富文本标题
@property (nullable, nonatomic, strong) NSAttributedString *attributedTitle UI_APPEARANCE_SELECTOR;

// May be used to indicate to the refreshControl that an external event has initiated the refresh action
// 可以手动开启刷新
- (void)beginRefreshing NS_AVAILABLE_IOS(6_0);
// Must be explicitly called when the refreshing has completed
// 刷新结束后必须手动停止刷新
- (void)endRefreshing NS_AVAILABLE_IOS(6_0);

@end

NS_ASSUME_NONNULL_END
