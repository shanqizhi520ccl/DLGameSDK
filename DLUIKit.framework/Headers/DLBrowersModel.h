//
//  DLBrowersModel.h
//  DLUIKitDemo
//
//  Created by 吴涛 on 2023/3/20.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,DLBrowerSourceType) {
    DLBrowerSourceTypeVideo = 0,
    DLBrowerSourceTypeImage = 1,
};

typedef NS_ENUM(NSInteger,DLBrowerLikeStatus) {
    DLBrowerLikeNoNeed = 0,
    DLBrowerLike = 1,
    DLBrowerUnLike = 2,
};

@interface DLBrowersModel : NSObject
///当前资源的类型
@property (nonatomic, assign) NSInteger resId;
///当前source的地址
@property (nonatomic, copy) NSString *source;
///视频的时候，需要用到缩略图
@property (nonatomic, copy) NSString *thumbnail;
///当前资源的类型
@property (nonatomic, assign) DLBrowerSourceType type;
///是否是已经播放
@property (nonatomic, assign) DLBrowerLikeStatus likeStatus;
///
///video1.videoExtData =  @{
///    @"playAuto" : @(1),                ///是否自动播放
///    @"showPageControl" : @(1),  ///是否显示关闭按钮
///    @"hiddenCloseInterval" : @(3)           ///延迟显示关闭按钮的时间
///    @"autoCloseVideo" : @(1),
///    @"hiddenProgressView" : @(1)
///};
///
///视频的额外信息
@property (nonatomic, strong) NSDictionary *videoExtData;

@end
