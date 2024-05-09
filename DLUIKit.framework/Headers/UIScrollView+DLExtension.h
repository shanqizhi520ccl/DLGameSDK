//
//  UIScrollView+DLExtension.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/8.
//

#import <UIKit/UIKit.h>

@interface UIScrollView (DLExtension)

@end


@protocol DLRefreshDelegate;
@class DLHudView;
@interface UIScrollView (DLRefresh)
///头部刷新视图
@property (nonatomic, strong) UIView *r_headerView;
///尾部刷新视图
@property (nonatomic, strong) UIView *r_footerView;
///
@property (nonatomic, weak) id<DLRefreshDelegate>refreshDelegate;
/// 添加当前头部刷新
/// - Parameter selecter: 刷新方法
- (void)dl_headerRefresh;
///头部手动调用刷新
- (void)dl_headerBeginRefresh;
/// 结束刷新
- (void)dl_headerEndRefresh;

/// 添加当前尾部刷新
/// - Parameter selecter: 刷新方法
- (void)dl_footerRefresh:(BOOL)show;
///尾部手动调用刷新
- (void)dl_footerBeginRefresh;
/// 结束刷新
- (void)dl_footerEndRefresh;

@end


@protocol DLRefreshDelegate <NSObject>
/// 头部开始刷新相应
- (void)headerRefreshBegin;
/// 尾部开始刷新相应
- (void)footerRefreshBegin;

@end
