//
//  DLLGSLoggerManager.h
//  DLLGSLogger
//
//  Created by 吴涛 on 2023/2/4.
//

#import <Foundation/Foundation.h>

#import "DLLGSUserInfo.h"

////CT的值，一般是固定，表示点击事件
FOUNDATION_EXTERN NSString * const _Nonnull DLCTValueClickValue;
///CT的值，一般都是固定，表示曝光事件
FOUNDATION_EXTERN NSString * const _Nonnull DLCTValueExposeValue;


@interface DLLGSLoggerManager : NSObject

/// 单例对象
+ (instancetype _Nonnull )shareInstance;

/// 初始化当前的模型
/// - Parameters:
///   - urlString: 当前lgs的值
- (void)initLGSUrl:(NSString * _Nullable)urlString;

/// 更新当前用户的基本信息
/// - Parameter user: 当前信息
- (void)setLGSUser:(DLLGSUserInfo *_Nonnull)user;

/// 设置当前打点的重要的值，定时器定时发送
/// - Parameters:
///   - ct: ct的值
///   - dt: dt的值
///   - et: et的值
///   - ft: ft的值可以为空
- (void)sendLogCTValue:(NSString * _Nonnull)ct
               DTValue:(NSString * _Nonnull)dt
               ETValue:(NSString * _Nonnull)et
               FTValue:(NSString  * _Nullable )ft;

/// 设置当前打点的值，定时器定时发送
/// - Parameters:
///   - ct: ct的值
///   - dt: dt的值
///   - et: et的值
///   - ft: ft的值可以为空
///   - params: 其他自己默认的值,可以为空
- (void)sendLogCTValue:(NSString * _Nonnull)ct
               DTValue:(NSString * _Nonnull)dt
               ETValue:(NSString * _Nonnull)et
               FTValue:(NSString * _Nullable)ft
           otherParams:(NSDictionary  * _Nullable )params;

/// 设置当前打点的重要的值,立马马上发送
/// - Parameters:
///   - ct: ct的值
///   - dt: dt的值
///   - et: et的值
///   - ft: ft的值可以为空
- (void)sendImmediatelyLogCTValue:(NSString * _Nonnull)ct
                          DTValue:(NSString * _Nonnull)dt
                          ETValue:(NSString * _Nonnull)et
                          FTValue:(NSString  * _Nullable )ft;

/// 设置当前打点的值，立马马上发送
/// - Parameters:
///   - ct: ct的值
///   - dt: dt的值
///   - et: et的值
///   - params: 其他自己默认的值
- (void)sendImmediatelyLogCTValue:(NSString * _Nonnull)ct
                          DTValue:(NSString * _Nonnull)dt
                          ETValue:(NSString * _Nonnull)et
                          FTValue:(NSString * _Nullable)ft
                      otherParams:(NSDictionary  * _Nullable )params;



/// 更新当前的游戏状态
/// - Parameter status: 1游戏中 2不在游戏中
- (void)updateUserPlayingStatus:(int)status;

@end
