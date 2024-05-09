//
//  NSArray+DLExtension.h
//  DLFounction
//
//  Created by 吴涛 on 2023/2/21.
//

#import <Foundation/Foundation.h>

@interface NSArray (DLExtension)

/// 根据中间插入的字符串，生成一个新的字符串
/// - Parameter joined: 需要插入的字符串
- (NSString *)dl_omponentsJoined:(NSString *)joined;

@end
