//
//  TPMessage.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/21.
//

#import <Foundation/Foundation.h>
#import "TPEntity.h"

#define TP_MESSAGE_TYPE_TEXT        @"text"
#define TP_MESSAGE_TYPE_CUSTOM      @"custom"

@interface TPMessage : TPEntity

-(NSString *)getMessageId;
-(NSString *)getChannelId;
-(NSString *)getSenderId;
-(NSString *)getSenderName;
-(NSString *)getSenderProfileImage;
-(NSString *)getText;
-(NSString *)getType;
-(NSDictionary *)getData;
-(long)getCreatedAt;

@end
