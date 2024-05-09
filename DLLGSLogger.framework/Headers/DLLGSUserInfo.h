//
//  DLLGSUserInfo.h
//  DLLGSLogger
//
//  Created by 吴涛 on 2023/2/4.
//

#import <Foundation/Foundation.h>


@interface DLLGSUserInfo : NSObject
///当前手机的语言
@property (nonatomic, copy, readonly) NSString *language;
///当前项目的名称
@property (nonatomic, copy, readonly) NSString *projectName;
///当前项目的版本号
@property (nonatomic, copy, readonly) NSString *appVersion;
///当前项目的build号
@property (nonatomic, copy, readonly) NSString *appBuildNum;
///当前终端的名称
@property (nonatomic, copy, readonly) NSString *deviceName;
///当前项目的版本号
@property (nonatomic, copy, readonly) NSString *deviceVersion;
///当前app的名称，iOS独有的
@property (nonatomic, copy, readonly) NSString *deviceModel;
///当前终端唯一的标识符
@property (nonatomic, copy, readonly) NSString *deviceUUID;
///混淆一下，获取idfv
@property (nonatomic, copy, readonly) NSString *deviceVFDI;
///当前手机的内存使用率
@property (nonatomic, copy, readonly) NSString *deviceMemoryUsage_a;
///当前手机的内存使用率
@property (nonatomic, copy, readonly) NSString *deviceMemoryUsage_u;
///当前手机的cpu使用率
@property (nonatomic, assign, readonly) float deviceCpuUsage;
///当前手机的cpu使用率
@property (nonatomic, assign) BOOL isDebug;
///当前用户的昵称
@property (nonatomic, copy) NSString *nickName;
///当前用户的id，唯一标识符
@property (nonatomic, copy) NSString *uid;
///用户的性别
@property (nonatomic, assign) NSInteger sex;
///注册类型
@property (nonatomic, assign) NSInteger reginType;
///当前的状态
@property (nonatomic, assign) int playingStatus;

@end
