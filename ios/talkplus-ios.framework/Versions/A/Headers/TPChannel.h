//
//  TPChannel.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/21.
//

#import <Foundation/Foundation.h>
#import "TPEntity.h"
#import "TPMessage.h"

#define TP_CHANNEL_TYPE_PRIVATE                 @"private"
#define TP_CHANNEL_TYPE_PUBLIC                  @"public"
#define TP_CHANNEL_TYPE_INVITATION_ONLY         @"invitationOnly"

@interface TPChannel : TPEntity

-(id)initWithDictionary:(NSDictionary *)dict;

-(NSString *)getChannelId;

-(NSDictionary *)getMemberDictionary;
-(NSArray *)getMembers;

-(TPMessage *)getLastMessage;
-(int)getUnreadCount;
-(NSString *)getInvitationCode;

-(int)getMessageUnreadCount:(TPMessage *)tpMessage;

@end
