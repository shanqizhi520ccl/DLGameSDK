//
//  DLSystemAuthorized.h
//  DLFounction
//
//  Created by 吴涛 on 2023/3/6.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,DLAuthorizedType) {
    DLAuthorizedTypeUnknow = 0,
    ////相册类型
    DLAuthorizedTypePhoto  = 1,
    ///摄像头的权限
    DLAuthorizedTypeCamera = 2,
    ///麦克风的权限
    DLAuthorizedTypeMicroPhoto = 3,
};

typedef void(^DLSystemAuthorizedGrandBlock)(BOOL isAuthorized, BOOL granted);

@interface DLSystemAuthorized : NSObject


/// 获取当前系统权限的设置
/// - Parameters:
///   - authorized: 获取权限的类型
///   - completed: 当前的闭包回掉
+ (void)dl_systemAuthorized:(DLAuthorizedType)authorized
           grantedCompleted:(DLSystemAuthorizedGrandBlock)completed;

@end
