//
//  MPConstants.h
//  MPMonitor
//
//  Created by MPMonitor on 2023/5/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPConstants : NSObject

/// 线程一致（通过是否是同一队列判断）
BOOL mp_is_same_queue(dispatch_queue_t queue);

/// 线程安全
void mp_dispatch_safe_sync(dispatch_queue_t queue, DISPATCH_NOESCAPE dispatch_block_t block);

/// 主线程异步执行（通过当前队列是否是主队列，来判断是否在主线程）
void mp_dispatch_main_async_safe(dispatch_block_t block);

@end

NS_ASSUME_NONNULL_END
