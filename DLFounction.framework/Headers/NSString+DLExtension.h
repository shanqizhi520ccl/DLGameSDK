//
//  NSString+DLExtension.h
//  DLFounction
//
//  Created by 吴涛 on 2023/2/20.
//

#import <Foundation/Foundation.h>

@interface NSString (DLExtension)

/// 生成服务器需要的随机数
/// - Parameter max: 最大长度
+ (NSString *)dl_getRequestRandomNonce:(NSInteger)max;

@end



@interface NSString (DLUrl)
/// url编码
- (NSString *)dl_urlEncode;

@end


@interface NSString (DLJson)
/// json字符串转字典
- (NSDictionary *)dl_jsonToDict;

@end
