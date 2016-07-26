/*	NSRange.h
	Copyright (c) 1994-2015, Apple Inc. All rights reserved.
*/
/*
 * 由MemorySpeaker维护
 * 联系邮箱:wangnistronger@icloud.com
 * 本文件对应维护地址:
 */   

#import <Foundation/NSValue.h>
#import <Foundation/NSObjCRuntime.h>

@class NSString;

NS_ASSUME_NONNULL_BEGIN

//定义_NSRange结构体并定义为NSRange类型
typedef struct _NSRange {
    //起始位置
    NSUInteger location;
    //长度
    NSUInteger length;
} NSRange;

// 定义NSRange结构体指针类型
typedef NSRange *NSRangePointer;

//创建NSRange
NS_INLINE NSRange NSMakeRange(NSUInteger loc, NSUInteger len) {
    NSRange r;
    r.location = loc;
    r.length = len;
    return r;
}

//获取范围内最大值
NS_INLINE NSUInteger NSMaxRange(NSRange range) {
    return (range.location + range.length);
}

//loc点是否在range范围内
NS_INLINE BOOL NSLocationInRange(NSUInteger loc, NSRange range) {
    return (!(loc < range.location) && (loc - range.location) < range.length) ? YES : NO;
}

//判断两个range是否相等
NS_INLINE BOOL NSEqualRanges(NSRange range1, NSRange range2) {
    return (range1.location == range2.location && range1.length == range2.length);
}

//range1与range2并集
FOUNDATION_EXPORT NSRange NSUnionRange(NSRange range1, NSRange range2);
//range1与range2交集
FOUNDATION_EXPORT NSRange NSIntersectionRange(NSRange range1, NSRange range2);
//range与字符串互转:range转字符串
FOUNDATION_EXPORT NSString *NSStringFromRange(NSRange range);
//range与字符串互转:字符串转range
FOUNDATION_EXPORT NSRange NSRangeFromString(NSString *aString);

// 对NSValue增加分类,实现对NSRange的对象封装及解封
@interface NSValue (NSValueRangeExtensions)

//对于range的对象封装与获取
+ (NSValue *)valueWithRange:(NSRange)range;
@property (readonly) NSRange rangeValue;

@end

NS_ASSUME_NONNULL_END
