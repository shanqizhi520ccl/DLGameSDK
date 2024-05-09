//
//  DLKeychainDataStore.h
//  DLFounction
//
//  Created by 吴涛 on 2023/2/21.
//

#import <Foundation/Foundation.h>


@interface DLKeychainDataStore : NSObject

///  在keychain中存储
/// - Parameters:
///   - key: 当前的key
///   - data: value
+ (void)dl_keyChainSave:(NSString *)key value:(id)data;

/// 从keychain中捞取数据
/// - Parameter key: 当前的key
+ (id)dl_keyChainGetDataKey:(NSString *)key;

/// 删除当前keychain中存储的数据
/// - Parameter key: 当前的key
+ (void)dl_keyChainDelete:(NSString *)key;

@end
