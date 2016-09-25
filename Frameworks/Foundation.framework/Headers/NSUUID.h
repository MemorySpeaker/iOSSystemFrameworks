/*	NSUUID.h
        Copyright (c) 2011-2015, Apple Inc. All rights reserved.
*/

//UUID含义是通用(宇宙)唯一识别码 (Universally Unique Identifier)

#import <Foundation/NSObject.h>
#include <CoreFoundation/CFUUID.h>
#include <uuid/uuid.h>

/* Note: NSUUID is not toll-free bridged with CFUUID. Use UUID strings to convert between CFUUID and NSUUID, if needed. NSUUIDs are not guaranteed to be comparable by pointer value (as CFUUIDRef is); use isEqual: to compare two NSUUIDs. */

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_8, 6_0)
@interface NSUUID : NSObject <NSCopying, NSSecureCoding>

/* Create a new autoreleased NSUUID with RFC 4122 version 4 random bytes */
// 使用 WTF? 生成一个UUID对象
+ (instancetype)UUID;

/* Create a new NSUUID with RFC 4122 version 4 random bytes */
// 使用 WTF? 生成一个UUID对象
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/* Create an NSUUID from a string such as "E621E1F8-C36C-495A-93FC-0C247A3E6E5F". Returns nil for invalid strings. */
// 将string转换为对应的UUID对象,如果失败返回nil
- (nullable instancetype)initWithUUIDString:(NSString *)string;

/* Create an NSUUID with the given bytes */
- (instancetype)initWithUUIDBytes:(const uuid_t)bytes;

/* Get the individual bytes of the receiver */
- (void)getUUIDBytes:(uuid_t)uuid;

/* Return a string description of the UUID, such as "E621E1F8-C36C-495A-93FC-0C247A3E6E5F" */
//返回UUID的字符串表示对象,例如"E621E1F8-C36C-495A-93FC-0C247A3E6E5F"
@property (readonly, copy) NSString *UUIDString;

@end

NS_ASSUME_NONNULL_END
