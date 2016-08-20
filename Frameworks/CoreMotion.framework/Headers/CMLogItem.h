/*
 *  CMLogItem.h
 *  CoreMotion
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 产生的数据项的共有父类
NS_CLASS_AVAILABLE(NA,4_0)
@interface CMLogItem : NSObject <NSSecureCoding, NSCopying>
{
@private
	id _internalLogItem;
}

/*
 *  timestamp
 *  
 *  Discussion:
 *    Time at which the item is valid.
 *
 */
//数据产生时的时间戳
@property(readonly, nonatomic) NSTimeInterval timestamp;

@end

NS_ASSUME_NONNULL_END
