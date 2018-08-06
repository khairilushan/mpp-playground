#import <Foundation/Foundation.h>

@class GithubRepoNetworkService, GithubRepoHttpResult, GithubRepoOnRequestSuccess, GithubRepoOnRequestFailed, GithubRepoResult, GithubRepoGithubDataSourceSources, GithubRepoGithubDataSourceNetwork, GithubRepoSearchRepoInteractorImpl, GithubRepoSearchRepoInteractorImplCompanion, GithubRepoOnSuccess, GithubRepoOnFailed, GithubRepoSearchResult, GithubRepoSearchResultCompanion;

@protocol GithubRepoGithubDataSource, GithubRepoGithubRepository, GithubRepoSearchRepoInteractor, GithubRepoSerializable;

NS_ASSUME_NONNULL_BEGIN

@interface KotlinBase : NSObject
-(instancetype) init __attribute__((unavailable));
+(instancetype) new __attribute__((unavailable));
+(void)initialize __attribute__((objc_requires_super));
@end;

@interface KotlinBase (KotlinBaseCopying) <NSCopying>
@end;

__attribute__((objc_runtime_name("KotlinMutableSet")))
@interface GithubRepoMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end;

__attribute__((objc_runtime_name("KotlinMutableDictionary")))
@interface GithubRepoMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoNetworkService : KotlinBase
-(instancetype)init NS_SWIFT_NAME(init()) NS_DESIGNATED_INITIALIZER;

-(GithubRepoHttpResult*)getUrl:(NSString*)url NS_SWIFT_NAME(get(url:));
@end;

@interface GithubRepoHttpResult : KotlinBase
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoOnRequestSuccess : GithubRepoHttpResult
-(instancetype)initWithResponse:(NSString*)response NS_SWIFT_NAME(init(response:)) NS_DESIGNATED_INITIALIZER;

@property (readonly) NSString* response;
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoOnRequestFailed : GithubRepoHttpResult
-(instancetype)initWithStatusCode:(int32_t)statusCode message:(NSString*)message NS_SWIFT_NAME(init(statusCode:message:)) NS_DESIGNATED_INITIALIZER;

@property (readonly) int32_t statusCode;
@property (readonly) NSString* message;
@end;

@protocol GithubRepoGithubRepository
@required
-(GithubRepoResult*)searchKeyword:(NSString*)keyword NS_SWIFT_NAME(search(keyword:));
@end;

@protocol GithubRepoGithubDataSource <GithubRepoGithubRepository>
@required
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoGithubDataSourceSources : KotlinBase <GithubRepoGithubDataSource>
-(instancetype)initWithNetwork:(GithubRepoGithubDataSourceNetwork*)network NS_SWIFT_NAME(init(network:)) NS_DESIGNATED_INITIALIZER;

@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoGithubDataSourceNetwork : KotlinBase <GithubRepoGithubDataSource>
-(instancetype)initWithService:(GithubRepoNetworkService*)service NS_SWIFT_NAME(init(service:)) NS_DESIGNATED_INITIALIZER;

@end;

@protocol GithubRepoSearchRepoInteractor
@required
-(void)searchKeyword_:(NSString*)keyword NS_SWIFT_NAME(search(keyword_:));
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoSearchRepoInteractorImpl : KotlinBase <GithubRepoSearchRepoInteractor>
-(instancetype)initWithRepository:(id<GithubRepoGithubRepository>)repository NS_SWIFT_NAME(init(repository:)) NS_DESIGNATED_INITIALIZER;

@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoSearchRepoInteractorImplCompanion : KotlinBase
+(instancetype)alloc __attribute__((unavailable));
+(instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));

+(instancetype)companion NS_SWIFT_NAME(init());

-(id<GithubRepoSearchRepoInteractor>)create NS_SWIFT_NAME(create());
@end;

@protocol GithubRepoSerializable
@required
-(id _Nullable)serialize NS_SWIFT_NAME(serialize());
@end;

@interface GithubRepoResult : KotlinBase
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoOnSuccess : GithubRepoResult
-(instancetype)initWithResult:(id _Nullable)result NS_SWIFT_NAME(init(result:)) NS_DESIGNATED_INITIALIZER;

@property (readonly) id _Nullable result;
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoOnFailed : GithubRepoResult
-(instancetype)initWithMessage:(NSString*)message NS_SWIFT_NAME(init(message:)) NS_DESIGNATED_INITIALIZER;

@property (readonly) NSString* message;
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoSearchResult : KotlinBase
-(instancetype)initWithCount:(int32_t)count NS_SWIFT_NAME(init(count:)) NS_DESIGNATED_INITIALIZER;

-(int32_t)component1 NS_SWIFT_NAME(component1());
-(GithubRepoSearchResult*)doCopyCount:(int32_t)count NS_SWIFT_NAME(doCopy(count:));
@property (readonly) int32_t count;
@end;

__attribute__((objc_subclassing_restricted))
@interface GithubRepoSearchResultCompanion : KotlinBase
+(instancetype)alloc __attribute__((unavailable));
+(instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));

+(instancetype)companion NS_SWIFT_NAME(init());

-(GithubRepoSearchResult*)parseResponse:(NSString*)response NS_SWIFT_NAME(parse(response:));
@end;

NS_ASSUME_NONNULL_END
