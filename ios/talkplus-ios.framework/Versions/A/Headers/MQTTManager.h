//
//  MQTTManager.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/24.
//

#import <Foundation/Foundation.h>

typedef void(^MQTTNewMessageBlock)(NSData *data);

@interface MQTTManager : NSObject

+ (MQTTManager *)sharedInstance;

-(void)setAppId:(NSString *)appId;
-(void)setMqttEndpoint:(NSString *)mqttEndpoint;
-(void)setSessionId:(NSString *)sessionId;
-(void)setPassword:(NSString *)password;
-(void)connect:(MQTTNewMessageBlock)callback;
-(void)disconnect;

@end
