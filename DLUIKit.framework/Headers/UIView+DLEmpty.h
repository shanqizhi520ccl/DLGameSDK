//
//  UIView+DLEmpty.h
//  DLUIKit
//
//  Created by 吴涛 on 2023/3/3.
//

#import <UIKit/UIKit.h>
#import <SVGAPlayer/SVGAPlayer.h>

@class SVGAVideoEntity;
@class DLEmptyView;
@class DLAnimationEmptyView;
@interface UIView (DLEmpty)

///当前显示的空视图页面
@property (nonatomic, strong) DLEmptyView *showEmptyView;
///
@property (nonatomic, strong) DLAnimationEmptyView *showAnimationView;

/// 显示空页面的方法
/// - Parameters:
///   - image: 当前页面的图片
///   - size: 当前的图片大小size
///   - offset: 距离中间距离的offset
- (void)dl_showEmptyImage:(UIImage *)image imageSize:(CGSize)size imageCenterYOffSet:(CGFloat)offset;

/// 显示空页面的方法
/// - Parameters:
///   - image: 当前页面的图片
///   - size: 当前的图片大小size
///   - emptyMsg: 空页面的标题
///   - offset:距离中间距离的offset
- (void)dl_showEmptyImage:(UIImage *)image imageSize:(CGSize)size emptyMsg:(NSString *)emptyMsg imageCenterYOffSet:(CGFloat)offset;


/// 空页面播放svga动画的的方法
/// - Parameters:
///   - entity: svga播放的实体
///   - size: 当前的size
///   - emptyMsg: 空页面的文字显示
- (void)dl_showEmptyViewAnimation:(SVGAVideoEntity *)entity
                    animationSize:(CGSize)size
                         emptyMsg:(NSString *)emptyMsg;

/// 空页面播放svga动画的的方法
/// - Parameters:
///   - entity: svga播放的实体
///   - size: 当前的size
///   - emptyMsg: 空页面的文字显示
///   - offset: 基于上面的偏移量
///   - msgSpace: msg与icon的间距
- (void)dl_showEmptyViewAnimation:(SVGAVideoEntity *)entity
                    animationSize:(CGSize)size
                         emptyMsg:(NSString *)emptyMsg
               imageCenterYOffSet:(CGFloat)offset
                         msgSpace:(CGFloat)msgSpace;

/// 显示请求页面失败的页面
- (void)dl_showFailedPageRetryBlock:(dispatch_block_t)retry imageCenterYOffSet:(CGFloat)offset;

/// 隐藏当前的空视图
- (void)dl_hiddenEmpty;

@end
