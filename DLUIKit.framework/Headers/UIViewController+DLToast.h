//
//  UIViewController+DLToast.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/19.
//

#import <UIKit/UIKit.h>


@class DLShowToastView;
@interface UIViewController (DLToast)

///当前存储未显示的toast文本
@property (nonatomic, strong) NSMutableArray <NSString *>*toastArray;
///当前显示的view
@property (nonatomic, strong) DLShowToastView *toastView;

/// 显示toast
/// - Parameters:
///   - toast: 当前toast文本
- (void)dl_showToast:(NSString *)toast;
/// 显示toast
/// - Parameters:
///   - toast: 当前toast文本
///   - offfset: 距离centerY的偏移量
- (void)dl_showToast:(NSString *)toast offCenterY:(CGFloat)offfset;

/// 显示toast
/// - Parameters:
///   - toast: 当前toast文本
///   - interval: 隐藏的时间
- (void)dl_showToast:(NSString *)toast hiddenDelay:(NSInteger)interval;

/// 显示toast
/// - Parameters:
///   - toast: 当前toast文本
///   - interval: 隐藏的时间
- (void)dl_showToast:(NSString *)toast offCenterY:(CGFloat)offfset hiddenDelay:(NSInteger)interval;

///显示当前带有结果的toast
- (void)dl_showToast:(NSString *)toast showResult:(BOOL)result;

@end

