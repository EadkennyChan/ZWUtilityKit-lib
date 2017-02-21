//
//  CrashHandle.h
//  ZWUtilityKit
//
//  Created by 陈正旺 on 14/12/15.
//  Copyright (c) 2014年 zwchen. All rights reserved.
//
/* ------------------------------------------------------
 *
 * @description：主要处理程序崩溃,发送日志以反馈
 *
 * @brief:需要添加MessageUI.framework
 * @update time: 2014-12-16
 *
 * ------------------------------------------------------*/

#import <Foundation/Foundation.h>
#import <MessageUI/MFMailComposeViewController.h>

@interface CrashHandle : UIViewController

+ (CrashHandle *)getInstance;
@property (nonatomic, assign)BOOL bShowTip;//发送成功后是否需要提示，default is NO;

/*
 *  @brief:检测上次是否是因为崩溃而退出
 */
+ (void)checkLastCrash;
/*
 *  @brief:手动发送邮件到反馈地址
 *  @pram:strSubject,报告邮件标题,若为nil,则采用默认
 *      strMailContents,邮件内容
 */
+ (void)sendReportMail:(NSString *)strSubject mailContents:(NSString *)strMailContents;
+ (void)sendReportMail;

@end

#pragma mark - 邮件反馈
/*
 *  @brief:设置发送邮件的地址和标题
 *  @pram:strMailAddr,报告地址,若为nil,则采用默认
 *      strSubject,报告邮件标题,若为nil,则采用默认
 */
//FOUNDATION_EXPORT void setReportMail(NSString *strMailAddr, NSString *strSubject);
/*
 *  @brief:恢复默认邮件地址和标题
 */
//FOUNDATION_EXPORT void defaultReportMailInfo();
/*
 *  @brief:App 崩溃捕捉方法。需在- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions中
 *  调用NSSetUncaughtExceptionHandler(&UncaughtExceptionHandler);
 */
FOUNDATION_EXPORT void UncaughtExceptionHandler(NSException *exception);