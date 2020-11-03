//
//  MQTTManager.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/24.
//

#import <Foundation/Foundation.h>
#import "AWSIoT.h"

@interface MQTTManager : NSObject

+ (MQTTManager *)sharedInstance;

-(void)setIotEndpoint:(NSString *)iotEndpoint;
-(void)setSessionId:(NSString *)sessionId;
-(void)connect:(AWSIoTMQTTNewMessageBlock)callback;
-(void)disconnect;

@end
