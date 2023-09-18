//
//  MPConfigOptions.h
//  MPMonitor
//
//  Created by MPMonitor on 2023/5/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPConfigOptions : NSObject

/// 刷新间隔，定时向服务器获取最新配置，单位毫秒
/// 默认值为 30 * 60 * 1000 毫秒， 即 0.5 小时
/// 最小时间 5 分钟
@property (nonatomic, assign) NSUInteger flushInterval;

/// 上报请求是否加密，默认为 YES
@property (nonatomic, assign) BOOL needEncrypt;

/// 开启 log 打印
@property (nonatomic, assign) BOOL enableLog;

/// 禁用 SDK，默认为 NO
/// 禁用后，SDK 将不会收集事件，也不会发送网络请求
@property (nonatomic, assign) BOOL disableSDK;

/// 指定初始化方法，设置 serverURL
/// - Parameter serverURL: 数据接收地址
- (instancetype)initWithServerURL:(nonnull NSString *)serverURL;

/// 禁用 init 初始化
- (instancetype)init NS_UNAVAILABLE;

/// 禁用 new 初始化
+ (instancetype)new NS_UNAVAILABLE;

@end


/// 注入参数
@interface MPDynamicProperties : NSObject

/// 所属业务线
@property (nonatomic, copy) NSString *pLine;

/// 神策 sensorId
@property (nonatomic, copy) NSString *sensorId;

/// 用户登录唯一标识符
@property (nonatomic, copy) NSString *loginId;

/// 设备标识
@property (nonatomic, copy) NSString *deviceId;

/// 用户活跃渠道号
@property (nonatomic, copy) NSString *channelCode;

@end


@interface MPReportData : NSObject

/// 上报数据类型 ( net: 网络监控，video: 视频监控 / (xxx: 业务自定义...) )
@property (nonatomic, copy) NSString *type;
/// 结果
@property (nonatomic, copy) NSString *result;
/// 描述
@property (nonatomic, copy) NSString *desc;

@end

NS_ASSUME_NONNULL_END
