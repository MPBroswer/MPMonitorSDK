//
//  MPMonitorSDK+Public.h
//  MPMonitor
//
//  Created by MPMonitor on 2023/6/5.
//

#import <Foundation/Foundation.h>

@class
MPReportData,
MPConfigOptions,
MPDynamicProperties;

NS_ASSUME_NONNULL_BEGIN

@interface MPMonitorSDK : NSObject

/// 所属业务线
@property (atomic, copy, readonly) NSString *pLine;

/// 神策 sensorId
@property (atomic, copy, readonly) NSString *sensorId;

/// 用户登录唯一标识符
@property (atomic, copy, readonly) NSString *loginId;

/// 设备标识
@property (atomic, copy, readonly) NSString *deviceId;

/// 用户活跃渠道号
@property (atomic, copy, readonly) NSString *channelCode;

#pragma mark - init instance

/// 通过配置参数，配置监控 SDK
/// 此方法调用必须符合以下条件：
///     1、必须在主线线程中调用
///     2、必须在 SDK 其他方法调用之前调用
/// @param configOptions 参数配置
+ (void)startWithConfigOptions:(nonnull MPConfigOptions *)configOptions NS_SWIFT_NAME(start(configOptions:));

/// 返回之前所初始化好的单例
/// Warning: 调用这个方法之前，必须先调用 startWithConfigOptions: 这个方法
+ (MPMonitorSDK * _Nullable)sharedInstance;

/// 禁用 SDK。调用后，SDK 将不采集事件，不发送网络请求
+ (void)disableSDK;

/// 开启 SDK。如果之前 SDK 是禁止状态，调用后将恢复数据采集功能
+ (void)enableSDK;

/// 设置当前 serverUrl , 默认不请求远程配置
/// @param serverUrl 当前的 serverUrl
- (void)setServerUrl:(NSString *)serverUrl;

/// 获取当前 serverUrl
- (NSString *)serverUrl;

/// 刷新间隔，定时向服务器获取最新配置，单位毫秒
/// 默认值为 30 * 60 * 1000 毫秒， 即 0.5 小时
/// 最小时间 5 分钟
- (NSUInteger)flushInterval;

/// 设置当前 serverUrl，并选择是否请求远程配置
/// @param serverUrl 当前的 serverUrl
/// @param isRequestRemoteConfig 是否请求远程配置
- (void)setServerUrl:(NSString *)serverUrl isRequestRemoteConfig:(BOOL)isRequestRemoteConfig API_UNAVAILABLE(macos);

#pragma mark - cache and flush

/// 通过接口设置业务线
/// - Parameter pLine: 新的业务线
- (void)pline:(NSString *)pLine;

/// 登录，设置当前用户的 loginId
/// - Parameter loginId: 当前用户的 loginId
- (void)login:(NSString *)loginId;

/// 注销，清空当前用户的 loginId
- (void)logout;

/// 通过接口设置神策 sensorId
/// - Parameter sensorId: 新的 sensorId
- (void)sensor:(NSString *)sensorId;

/// 通过接口设置设备 deviceId
/// - Parameter deviceId: 新的设备 id
- (void)device:(NSString *)deviceId;

/// 通过接口设置渠道 channelCode
/// - Parameter channelCode: 新的渠道号
- (void)channel:(NSString *)channelCode;

/// 通过接口设置参数
/// - Parameter properites: 动态参数
- (void)registerDynamicProperties:(MPDynamicProperties *(^)(void))properites;

/// SDK 的版本
- (NSString *)libVersion;

/// 删除本地缓存的全部事件  -- 暂未实现
/// 一旦调用该接口，将会删除本地缓存的全部事件，请慎用！
- (void)deleteAll;

#pragma mark - profile

/// 根据需要决定是否开启请求加密
/// - Parameter needEncrypt: YES/NO
- (void)needEncrypt:(BOOL)needEncrypt;

/// 根据需要决定是否开启 SDK log
/// - Parameter enabelLog: YES/NO
- (void)enableLog:(BOOL)enabelLog;

#pragma mark - custom

/// 上传自定义信息
/// - Parameter data: 记录数据
- (void)reportCustomRecord:(MPReportData *)data;

@end

NS_ASSUME_NONNULL_END
