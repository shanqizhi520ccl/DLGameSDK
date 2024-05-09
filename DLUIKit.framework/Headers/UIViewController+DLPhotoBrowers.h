//
//  UIViewController+DLPhotoBrowers.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/16.
//

#import <UIKit/UIKit.h>

#import "DLPhotoBrowers.h"

#import "DLBrowersModel.h"

typedef void(^DLBrowerDismissBlock)(void);

@interface UIViewController (DLPhotoBrowers)
///当前图片浏览器
@property (nonatomic, strong) DLPhotoBrowers *photoBrowers;
///关闭隐藏之后的闭包回掉
@property (nonatomic, copy) DLBrowerDismissBlock dismissBlock;

- (void)dl_showPhotoBrowers:(NSArray<DLBrowersModel *> *)soures
                sourceIndex:(NSInteger)index;

/// 删除当前资源之后的下标
/// - Parameter index: 当前的下标
- (void)dl_deletedPhotoCompleted:(NSInteger)index;


/// 设置当前图片的数据资源
/// - Parameter completed: 删除闭包回掉
- (void)dl_setDeletePhotoBlock:(DLClickDeleteBrowerBlock)completed;

/// 设置当前的图片浏览器。隐藏之后的的block回掉
/// - Parameter completed: 隐藏之后的闭包回掉
- (void)dl_setBrowerDismissCompleted:(DLBrowerDismissBlock)completed;
///设置闭包
- (void)dl_setPhotoBrowerLikeCompleted:(DLClickLikeBrowBlock)completed;

///更新当前的状态
- (void)dl_updatePhotoBrowerStatus:(BOOL)like resourceId:(NSInteger)resId;

@end
