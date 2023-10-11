//
//  TalkPlus.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <TalkPlus/TPEntity.h>
#import <TalkPlus/TPUser.h>
#import <TalkPlus/TPMember.h>
#import <TalkPlus/TPChannel.h>
#import <TalkPlus/TPMessage.h>

#define TALKPLUS_SDK_VERSION @"0.4.3"

@protocol TPChannelDelegate <NSObject>
@required

-(void)memberAdded:(TPChannel *)tpChannel users:(NSArray<TPMember *> *)users;
-(void)memberLeft:(TPChannel *)tpChannel users:(NSArray<TPMember *> *)users;
-(void)messageReceived:(TPChannel *)tpChannel message:(TPMessage *)tpMessage;
-(void)messageDeleted:(TPChannel *)tpChannel message:(TPMessage *)tpMessage;
-(void)channelAdded:(TPChannel *)tpChannel;
-(void)channelChanged:(TPChannel *)tpChannel;
-(void)channelRemoved:(TPChannel *)tpChannel;
-(void)publicMemberAdded:(TPChannel *)tpChannel users:(NSArray<TPMember *> *)users;
-(void)publicMemberLeft:(TPChannel *)tpChannel users:(NSArray<TPMember *> *)users;
-(void)publicChannelAdded:(TPChannel *)tpChannel;
-(void)publicChannelChanged:(TPChannel *)tpChannel;
-(void)publicChannelRemoved:(TPChannel *)tpChannel;
@optional
-(void)memberMuted:(TPChannel *)tpChannel users:(NSArray<TPMember *> *)users;
-(void)publicMemberMuted:(TPChannel *)tpChannel users:(NSArray<TPMember *> *)users;
-(void)memberUnmuted:(TPChannel *)tpChannel users:(NSArray<TPMember *> *)users;
-(void)publicMemberUnmuted:(TPChannel *)tpChannel users:(NSArray<TPMember *> *)users;
@end

@interface TalkPlus : NSObject

+ (TalkPlus *)sharedInstance;

-(void)initWithAppId:(NSString *)appId;

-(TPUser *)getCurrentUser;
-(NSString *)getDeviceUuid;

#pragma mark - User Auth
-(void)loginWithAnonymous:(NSString *)userId
                 username:(NSString *)username
          profileImageUrl:(NSString *)profileImageUrl
                 metaData:(NSDictionary *)metaData
                  success:(void (^)(TPUser *tpUser))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)loginWithAnonymous:(NSString *)userId
                 username:(NSString *)username
             profileImage:(UIImage *)profileImage
                 metaData:(NSDictionary *)metaData
                  success:(void (^)(TPUser *tpUser))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)loginWithToken:(NSString *)loginToken
               userId:(NSString *)userId
             username:(NSString *)username
      profileImageUrl:(NSString *)profileImageUrl
             metaData:(NSDictionary *)metaData
              success:(void (^)(TPUser *tpUser))successBlock
              failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)loginWithToken:(NSString *)loginToken
               userId:(NSString *)userId
             username:(NSString *)username
         profileImage:(UIImage *)profileImage
             metaData:(NSDictionary *)metaData
              success:(void (^)(TPUser *tpUser))successBlock
              failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - User Update
-(void)updateUserProfile:(NSString *)username
         profileImageUrl:(NSString *)profileImageUrl
                metaData:(NSDictionary *)metaData
                 success:(void (^)(TPUser *tpUser))successBlock
                 failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)updateUserProfile:(NSString *)username
            profileImage:(UIImage *)profileImage
                metaData:(NSDictionary *)metaData
                 success:(void (^)(TPUser *tpUser))successBlock
                 failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Push Notification Enable/Disable
-(void)enablePushNotification:(void (^)(TPUser *tpUser))successBlock
                      failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)disablePushNotification:(void (^)(TPUser *tpUser))successBlock
                       failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)enableChannelPushNotification:(TPChannel *)tpChannel
                             success:(void (^)(TPChannel *tpChannel))successBlock
                             failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)disableChannelPushNotification:(TPChannel *)tpChannel
                              success:(void (^)(TPChannel *tpChannel))successBlock
                              failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - User Block / Unblock
-(void)blockUser:(NSString *)targetId
         success:(void (^)(void))successBlock
         failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)unblockUser:(NSString *)targetId
           success:(void (^)(void))successBlock
           failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getBlockedUserList:(TPUser *)lastUser
                  success:(void (^)(NSArray<TPUser *> *tpUsers))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - User Delete / Logout
-(void)logout:(void (^)(void))successBlock
      failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)deleteUser:(void (^)(void))successBlock
          failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Create / Update
-(void)createChannelWithUserId:(NSString *)targetId
                     channelId:(NSString *)channelId
                  reuseChannel:(BOOL)reuseChannel
                maxMemberCount:(int)maxMemberCount
        hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin
                   channelType:(NSString *)channelType
                   channelName:(NSString *)channelName
                invitationCode:(NSString *)invitationCode
                      category:(NSString *)category
                   subcategory:(NSString *)subcategory
                      imageUrl:(NSString *)imageUrl
                      metaData:(NSDictionary *)metaData
                       success:(void (^)(TPChannel *tpChannel))successBlock
                       failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)createChannelWithUserIds:(NSArray *)targetIds
                      channelId:(NSString *)channelId
                   reuseChannel:(BOOL)reuseChannel
                 maxMemberCount:(int)maxMemberCount
         hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin
                    channelType:(NSString *)channelType
                    channelName:(NSString *)channelName
                 invitationCode:(NSString *)invitationCode
                       category:(NSString *)category
                    subcategory:(NSString *)subcategory
                       imageUrl:(NSString *)imageUrl
                       metaData:(NSDictionary *)metaData
                        success:(void (^)(TPChannel *tpChannel))successBlock
                        failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)updateChannel:(TPChannel *)tpChannel
      maxMemberCount:(int)maxMemberCount
hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin
         channelName:(NSString *)channelName
      invitationCode:(NSString *)invitationCode
            category:(NSString *)category
         subcategory:(NSString *)subcategory
            imageUrl:(NSString *)imageUrl
            metaData:(NSDictionary *)metaData
             success:(void (^)(TPChannel *tpChannel))successBlock
             failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)updateChannel:(TPChannel *)tpChannel
          privateTag:(NSString *)privateTag
             success:(void (^)(TPChannel * tpChannel))successBlock
             failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)updateChannel:(TPChannel *)tpChannel
         privateData:(NSDictionary *)metaData
             success:(void (^)(TPChannel * tpChannel))successBlock
             failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel
-(void)getChannel:(NSString *)channelId
          success:(void (^)(TPChannel *tpChannel))successBlock
          failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel List
-(void)getPublicChannelList:(TPChannel *)lastChannel
                    success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock
                    failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getChannelList:(TPChannel *)lastChannel
              success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock
              failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getChannelMember:(TPChannel *)tpChannel
               memberId:(NSString *)memberId
                success:(void (^)(TPMember *tpMember))successBlock
                failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getChannelMemberList:(TPChannel *)tpChannel
                   lastUser:(TPUser *)lastUser
                    success:(void (^)(NSArray<TPMember *> *tpMembers))successBlock
                    failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)updateChannel:(TPChannel *)tpChannel
          memberInfo:(NSDictionary *)memberInfo
             success:(void (^)(TPMember * tpMember))successBlock
             failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)searchChannelList:(TPChannel *)lastChannel
             channelName:(NSString *)channelName
               memberIds:(NSArray *)memberIds
                category:(NSString *)category
             subcategory:(NSString *)subcategory
                 success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock
                 failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)searchChannelList:(TPChannel *)lastChannel
             channelName:(NSString *)channelName
               memberIds:(NSArray *)memberIds
                category:(NSString *)category
             subcategory:(NSString *)subcategory
              privateTag:(NSString *)privateTag
                 success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock
                 failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)searchPublicChannelList:(TPChannel *)lastChannel
                   channelName:(NSString *)channelName
                     memberIds:(NSArray *)memberIds
                      category:(NSString *)category
                   subcategory:(NSString *)subcategory
                       success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock
                       failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)searchPublicChannelList:(TPChannel *)lastChannel
                   channelName:(NSString *)channelName
                     memberIds:(NSArray *)memberIds
                      category:(NSString *)category
                   subcategory:(NSString *)subcategory
                    privateTag:(NSString *)privateTag
                       success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock
                       failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getFilteredChannelList:(NSDictionary<NSString *, NSString *> *)filter
                      success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock
                      failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getHiddenChannelList:(TPChannel *)lastChannel
                    success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock
                    failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getTotalUnreadCount:(void (^)(int totalCount))successBlock
                   failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Member
-(void)addMemberToChannel:(TPChannel *)tpChannel
                   userId:(NSString *)userId
                  success:(void (^)(TPChannel *tpChannel))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)addMemberToChannel:(TPChannel *)tpChannel
                  userIds:(NSArray<NSString *> *)userIds
                  success:(void (^)(TPChannel *tpChannel))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)removeMemberToChannel:(TPChannel *)tpChannel
                      userId:(NSString *)userId
                     success:(void (^)(TPChannel *tpChannel))successBlock
                     failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)removeMemberToChannel:(TPChannel *)tpChannel
                     userIds:(NSArray<NSString *> *)userIds
                     success:(void (^)(TPChannel *tpChannel))successBlock
                     failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)banMemberToChannel:(TPChannel *)tpChannel
                   userId:(NSString *)userId
                  success:(void (^)(TPChannel *tpChannel))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)banMemberToChannel:(TPChannel *)tpChannel
                  userIds:(NSArray<NSString *> *)userIds
                  success:(void (^)(TPChannel *tpChannel))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)unBanMemberToChannel:(TPChannel *)tpChannel
                     userId:(NSString *)userId
                    success:(void (^)(TPChannel *tpChannel))successBlock
                    failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)unBanMemberToChannel:(TPChannel *)tpChannel
                    userIds:(NSArray<NSString *> *)userIds
                    success:(void (^)(TPChannel *tpChannel))successBlock
                    failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)muteMemberToChannel:(TPChannel *)tpChannel
                    userId:(NSString *)userId
                   success:(void (^)(TPChannel *tpChannel))successBlock
                   failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)muteMemberToChannel:(TPChannel *)tpChannel
                    userId:(NSString *)userId
           expireInMinutes:(NSInteger)expireInMinutes
                   success:(void (^)(TPChannel *tpChannel))successBlock
                   failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)muteMemberToChannel:(TPChannel *)tpChannel
                   userIds:(NSArray<NSString *> *)userIds
                   success:(void (^)(TPChannel *tpChannel))successBlock
                   failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)muteMemberToChannel:(TPChannel *)tpChannel
                   userIds:(NSArray<NSString *> *)userIds
           expireInMinutes:(NSInteger)expireInMinutes
                   success:(void (^)(TPChannel *tpChannel))successBlock
                   failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)unMuteMemberToChannel:(TPChannel *)tpChannel
                      userId:(NSString *)userId
                     success:(void (^)(TPChannel *tpChannel))successBlock
                     failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)unMuteMemberToChannel:(TPChannel *)tpChannel
                     userIds:(NSArray<NSString *> *)userIds
                     success:(void (^)(TPChannel *tpChannel))successBlock
                     failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getMutedPeers:(TPChannel *)tpChannel
            lastUser:(TPMember *)lastUser
             success:(void (^)(NSArray<TPMember *> *mutedPeers))successBlock
             failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)mutePeerToChannel:(TPChannel *)tpChannel
                 userIds:(NSArray<NSString *> *)userIds
         expireInMinutes:(NSInteger)expireInMinutes
                 success:(void (^)(TPChannel *tpChannel, NSArray<TPMember *> *mutedPeers))successBlock
                 failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)unMutePeerToChannel:(TPChannel *)tpChannel
                   userIds:(NSArray<NSString *> *)userIds
                   success:(void (^)(TPChannel *tpChannel, NSArray<TPMember *> *unMutedPeers))successBlock
                   failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Join / Leave
-(void)joinChannel:(NSString *)channelId
           success:(void (^)(TPChannel *tpChannel))successBlock
           failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)joinChannel:(NSString *)channelId
    invitationCode:(NSString *)invitationCode
           success:(void (^)(TPChannel *tpChannel))successBlock
           failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)leaveChannel:(TPChannel *)tpChannel
deleteChannelIfEmpty:(BOOL)deleteChannelIfEmpty
            success:(void (^)(void))successBlock
            failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Message
-(void)getMessageList:(TPChannel *)tpChannel
          lastMessage:(TPMessage *)lastMessage
              success:(void (^)(NSArray<TPMessage *> *tpMessages))successBlock
              failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getFileMessageList:(TPChannel *)tpChannel
              lastMessage:(TPMessage *)lastMessage
                  success:(void (^)(NSArray<TPMessage *> *tpMessages))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)deleteMessage:(TPChannel *)tpChannel
             message:(TPMessage *)tpMessage
             success:(void (^)(void))successBlock
             failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)sendMessage:(TPChannel *)tpChannel
              text:(NSString *)text
              type:(NSString *)type
          mentions:(NSArray *)mentions
   parentMessageId:(NSString *)parentMessageId
          metaData:(NSDictionary *)metaData
           success:(void (^)(TPMessage *tpMessage))successBlock
           failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)sendFileMessage:(TPChannel *)tpChannel
                  text:(NSString *)text
                  type:(NSString *)type
              mentions:(NSArray *)mentions
       parentMessageId:(NSString *)parentMessageId
              metaData:(NSDictionary *)metaData
              filePath:(NSString *)filePath
               success:(void (^)(TPMessage * tpMessage))successBlock
               failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)addMessageReaction:(TPMessage *)tpMessage
                 reaction:(NSString *)reaction
                  success:(void (^)(TPMessage * tpMessage))successBlock
                  failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)removeMessageReaction:(TPMessage *)tpMessage
                    reaction:(NSString *)reaction
                     success:(void (^)(TPMessage * tpMessage))successBlock
                     failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)markAsReadChannel:(TPChannel *)tpChannel
                 success:(void (^)(TPChannel *tpChannel))successBlock
                 failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)markAsReadAllChannel:(void (^)(void))successBlock
                    failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Hide / Show
-(void)hideChannel:(NSString *)channelId
           success:(void (^)(void))successBlock
           failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)hideAllChannel:(void (^)(void))successBlock
              failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)showChannel:(NSString *)channelId
           success:(void (^)(void))successBlock
           failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Freeze / Unfreeze
-(void)freezeChannel:(NSString *)channelId
             success:(void (^)(void))successBlock
             failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)unfreezeChannel:(NSString *)channelId
               success:(void (^)(void))successBlock
               failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Transfer Ownership
-(void)transferOwnership:(TPChannel *)tpChannel
            targetUserId:(NSString *)targetUserId
                 success:(void (^)(TPChannel * tpChannel))successBlock
                 failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - TPChannelDelegate
-(void)addChannelDelegate:(id<TPChannelDelegate>)delegate tag:(NSString *)tag;
-(void)removeChannelDelegate:(NSString *)tag;
-(void)removeAllChannelDelegate;

#pragma mark - Push Notification
-(void)registerFCMToken:(NSString *)fcmToken
                success:(void (^)(void))successBlock
                failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)handleFCMMessage:(NSString *)payload;

#pragma mark - Push Notification Settings (sound, etc.)
-(void)setChannelPush:(TPChannel *)tpChannel
                sound:(NSString *) sound
              success:(void (^)(TPChannel *tpChannel))successBlock
              failure:(void (^)(int errorCode, NSError *error))failureBlock;

@end
