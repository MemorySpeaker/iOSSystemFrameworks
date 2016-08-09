/*
 *  CMError.h
 *  CoreMotion
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 */

/*
 *  CMError
 *  
 *  Discussion:
 *    Error returned as code to NSError from CoreMotion.
 */
 // CoreMotion框架中一些错误枚举,枚举项用于做NSError的错误码
typedef enum {
	// 空值
	CMErrorNULL = 100,
	// 设备需要移动起来
	CMErrorDeviceRequiresMovement,
	// 真北不可用
	CMErrorTrueNorthNotAvailable,
	// 未知
	CMErrorUnknown,
	// 运动数据不可用
	CMErrorMotionActivityNotAvailable,
	// 运动数据访问没有被授权
	CMErrorMotionActivityNotAuthorized,
	CMErrorMotionActivityNotEntitled,
	// 计步器不可用
	CMErrorInvalidParameter,
	CMErrorInvalidAction,
	// 不可用
	CMErrorNotAvailable,
	CMErrorNotEntitled,
	// 未授权
	CMErrorNotAuthorized
} CMError;
