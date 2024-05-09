//
//  UIViewController+DLPresent.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/6.
//

#import <UIKit/UIKit.h>

#import "DLPopuBackgroudView.h"

typedef void(^DLPresentWillDissBlock)(void);
///当前控制器
typedef void(^DLPresentDidDismissBlock)(void);

////弹出当前控制器展示的动画
typedef NS_ENUM(NSInteger,DLPresentAnitamtion) {
    DLPresentAnitamtionNone        = 0,
    DLPresentAnitamtionBottomToTop = 1,
    DLPresentAnitamtionFade        = 2,
};

@protocol DLPresentPopuDelegate;
@interface UIViewController (DLPresent)
///当前弹出的所有控制器的集合
@property (nonatomic, strong) NSMutableArray <UIViewController *>*popuControllers;
///存储将要返回的block回掉集合
@property (nonatomic, strong) NSMutableDictionary <NSString *,DLPresentWillDissBlock>*willCompletedBlocks;
///存储已经返回的block回掉集合
@property (nonatomic, strong) NSMutableDictionary <NSString *,DLPresentDidDismissBlock>*didCompletedBlocks;
///当前的动画存储
@property (nonatomic, strong) NSMutableDictionary <NSString *,NSNumber*>*animations;
///默认是的背景视图
@property (nonatomic, strong) DLPopuBackgroudView *popuBackgroudView;
///默认是light
@property (nonatomic, assign) DLPresentBackgroudColor bgColor;
///显示隐藏视图代理的回掉
@property (nonatomic, weak) id<DLPresentPopuDelegate>popuDelegate;
///当前弹出控制器的视图
@property (nonatomic, weak) UIViewController *popuSuperController;

/// 弹出一个pop控制器
/// - Parameters:
///   - controller: 需要弹出的控制器
///   - animation: 动画的类型
///   - didDismiss: 控制器隐藏的block回掉
- (void)dl_presentController:(UIViewController *)controller
                   animation:(DLPresentAnitamtion)animation
              completedBlock:(DLPresentDidDismissBlock)didDismiss;

/// 弹出一个pop控制器
/// - Parameters:
///   - controller: 需要弹出的控制器
///   - animation: 动画的类型
///   - willDismiss: 将要隐藏的时候的block回掉
///   - didDismiss: 控制器隐藏的block回掉
- (void)dl_presentController:(UIViewController *)controller
                   animation:(DLPresentAnitamtion)animation
                 willDismiss:(DLPresentWillDissBlock)willDismiss
              completedBlock:(DLPresentDidDismissBlock)didDismiss;


/// 隐藏某一个弹出的控制器
/// - Parameters:
///   - controller: 隐藏的控制器对象
///   - animation: 动画类型
- (void)dl_dismissController:(UIViewController *)controller
                   animation:(DLPresentAnitamtion)animation;

///隐藏当前控制器，所有prenent出来的控制器
- (void)dl_dismissAllControlelr;

@end


@protocol DLPresentPopuDelegate <NSObject>

@optional
/// 将要显示的视图
/// - Parameter animation: 将要显示的时候，需要显示的视图
- (void)popoWillShowAnimation:(DLPresentAnitamtion)animation;
///隐藏控制器在当前控制器实现这个代理
/// - Parameter animation: 需要的动画
- (void)dismissWillHiddenAnimation:(DLPresentAnitamtion)animation completed:(DLPresentDidDismissBlock)completed;

/// 是否需要内部自动实现点击空白区域隐藏
- (BOOL)didAutoCloseDismiss;

@end
