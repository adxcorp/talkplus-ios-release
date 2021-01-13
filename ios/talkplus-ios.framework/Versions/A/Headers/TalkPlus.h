//
//  TalkPlus.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/21.
//

#import <Foundation/Foundation.h>
#import "TPUser.h"
#import "TPChannel.h"
#import "TPMessage.h"

@protocol TPChannelDelegate <NSObject>
@required

-(void)memberAdded:(TPChannel *)tpChannel users:(NSArray *)users;
-(void)memberLeft:(TPChannel *)tpChannel users:(NSArray *)users;
-(void)messageReceived:(TPChannel *)tpChannel message:(TPMessage *)tpMessage;
-(void)channelChanged:(TPChannel *)tpChannel;

@end

@interface TalkPlus : NSObject

+ (TalkPlus *)sharedInstance;

-(void)initWithAppId:(NSString *)appId;

-(TPUser *)getCurrentUser;

-(void)handleFCMMessage:(NSString *)payload;

-(void)loginWithAnonymous:(NSString *)userId username:(NSString *)username profileImageUrl:(NSString *)profileImageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)loginWithToken:(NSString *)loginToken userId:(NSString *)userId username:(NSString *)username profileImageUrl:(NSString *)profileImageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)logout:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)registerFCMToken:(NSString *)fcmToken success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)updateUserProfile:(NSString *)username profileImageUrl:(NSString *)profileImageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)deleteUser:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getBlockedUserList:(TPUser *)lastUser success:(void (^)(NSArray * tpUserArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)blockUser:(NSString *)targetId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unblockUser:(NSString *)targetId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getTotalUnreadCount:(void (^)(int totalCount))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getChannelList:(TPChannel *)lastChannel success:(void (^)(NSArray * tpChannelArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getPublicChannelList:(TPChannel *)lastChannel success:(void (^)(NSArray * tpChannelArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getHiddenChannelList:(TPChannel *)lastChannel success:(void (^)(NSArray * tpChannelArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)createChannelWithUserId:(NSString *)targetId channelId:(NSString *)channelId reuseChannel:(BOOL)reuseChannel maxCount:(int)maxCount hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin channelType:(NSString *)channelType channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode imageUrl:(NSString *)imageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)createChannelWithUserIds:(NSArray *)targetIds channelId:(NSString *)channelId reuseChannel:(BOOL)reuseChannel maxCount:(int)maxCount hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin channelType:(NSString *)channelType channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode imageUrl:(NSString *)imageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)updateChannel:(TPChannel *)tpChannel maxCount:(int)maxCount hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode imageUrl:(NSString *)imageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getChannelMembers:(TPChannel *)tpChannel lastUser:(TPUser *)lastUser success:(void (^)(NSArray * tpUserArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getChannelBannedMembers:(TPChannel *)tpChannel lastUser:(TPUser *)lastUser success:(void (^)(NSArray * tpUserArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getChannelMutedMembers:(TPChannel *)tpChannel lastUser:(TPUser *)lastUser success:(void (^)(NSArray * tpUserArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)sendMessage:(TPChannel *)tpChannel text:(NSString *)text type:(NSString *)type metaData:(NSDictionary *)metaData success:(void (^)(TPMessage * tpMessage))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getMessageList:(TPChannel *)tpChannel lastMessage:(TPMessage *)lastMessage success:(void (^)(NSArray * tpMessageArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)markAsReadChannel:(TPChannel *)tpChannel success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)markAsReadAllChannel:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)freezeChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unfreezeChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)hideChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)hideAllChannel:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)showChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)joinChannel:(NSString *)channelId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)joinChannel:(NSString *)channelId invitationCode:(NSString *)invitationCode success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)leaveChannel:(TPChannel *)tpChannel deleteChannelIfEmpty:(BOOL)deleteChannelIfEmpty success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)addMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)addMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)removeMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)removeMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)banMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)banMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unBanMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unBanMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)muteMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)muteMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unMuteMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unMuteMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)addChannelDelegate:(id<TPChannelDelegate>)delegate tag:(NSString *)tag;
-(void)removeChannelDelegate:(NSString *)tag;
-(void)removeAllChannelDelegate;

-(void)fireMemberAdded:(NSDictionary *)channelDict users:(NSArray *)userDictArray;
-(void)fireMemberLeft:(NSDictionary *)channelDict users:(NSArray *)userDictArray;
-(void)fireMessageReceived:(NSDictionary *)channelDict message:(NSDictionary *)messageDict;
-(void)fireChannelChanged:(NSDictionary *)channelDict;

@end
