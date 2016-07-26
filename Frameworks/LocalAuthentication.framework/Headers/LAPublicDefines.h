//
//  LAPublicDefines.h
//  LocalAuthentication
//
//  Copyright (c) 2014 Apple. All rights reserved.
//
/*
 * 由MemorySpeaker维护
 * 联系邮箱:wangnistronger@icloud.com
 * 本文件对应维护地址:2fix
 */

// 一些公用的宏定义
#ifndef LocalAuthentication_LAPublicDefines_h
#define LocalAuthentication_LAPublicDefines_h

// Policies
 // 验证策略
 // 只使用指纹验证
#define kLAPolicyDeviceOwnerAuthenticationWithBiometrics    1
 //使用指纹或者手机密码验证.指纹优先,如果不可用则用手机密码
#define kLAPolicyDeviceOwnerAuthentication                  2

// Options
#define kLAOptionUserFallback                               1
#define kLAOptionAuthenticationReason                       2

// Error codes
 // 一些错误码
 // 认证失败
#define kLAErrorAuthenticationFailed                       -1
// 用户取消认证
#define kLAErrorUserCancel                                 -2
#define kLAErrorUserFallback                               -3
#define kLAErrorSystemCancel                               -4
// 没有设置密码
#define kLAErrorPasscodeNotSet                             -5
// 指纹不可用
#define kLAErrorTouchIDNotAvailable                        -6
#define kLAErrorTouchIDNotEnrolled                         -7
#define kLAErrorTouchIDLockout                             -8
#define kLAErrorAppCancel                                  -9
#define kLAErrorInvalidContext                            -10

// Error domain
// 错误域字符串
#define kLAErrorDomain        "com.apple.LocalAuthentication"

#endif
