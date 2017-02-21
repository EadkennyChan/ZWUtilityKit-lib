//
//  RegisteCrashHandle.h
//  ZWUtilityKit
//
//  Created by EadkennyChan on 16/11/16.
//  Copyright © 2016年 zwchen. All rights reserved.
//

#ifndef RegisteCrashHandle_h
#define RegisteCrashHandle_h

#import <Foundation/Foundation.h>

/*
 *  @brief:注册crash处理；并检测最后一次是否有崩溃，若有则返回崩溃信息
 */
NSArray *registeCrashHandle();

#endif /* RegisteCrashHandle_h */
