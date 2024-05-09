//
//  DLPhotoBrowers.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/16.
//

#import <UIKit/UIKit.h>

#import "DLBrowersModel.h"

///设置删除资源的block回掉
typedef void(^DLClickDeleteBrowerBlock)(DLBrowersModel *brower,NSInteger index);
///关闭的闭包回掉
typedef void(^DLClickCloseBrowerBlock)(void);
///点击当前是否点赞
typedef void(^DLClickLikeBrowBlock)(NSInteger resId,DLBrowerLikeStatus status);

@interface DLPhotoBrowers : UIViewController


/// 设置当前的
/// - Parameters:
///   - photos: 当前的数据源
///   - index: 开始显示的下标
- (void)dl_showPhotoBrower:(NSArray<DLBrowersModel *> *)photos sourceIndex:(NSInteger)index;

///设置闭包回掉
- (void)dl_setCloseBlock:(DLClickCloseBrowerBlock)block;

/// 删除当前资源之后的下标
/// - Parameter index: 当前的下标
- (void)dl_showPhotoBrowerDeletedPhotoCompleted:(NSInteger)index;

/// 设置当前图片的数据资源
/// - Parameter completed: 删除闭包回掉
- (void)dl_showPhotoBrowerSetDeletePhotoBlock:(DLClickDeleteBrowerBlock)completed;

///设置闭包
- (void)dl_setPhotoBrowerLikeCompleted:(DLClickLikeBrowBlock)completed;

///更新当前的状态
- (void)dl_updatePhotoBrowerStatus:(BOOL)like resourceId:(NSInteger)resId;

@end
