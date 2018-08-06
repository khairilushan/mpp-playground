#import <Foundation/Foundation.h>

@class MppSearchProjectInteractorParams, MppProjectRepositoryImpl, MppResult, MppSuccess, MppFailure, MppInteractor, MppStdlibUnit, MppSearchProjectInteractor, MppProject, MppProjectItemViewModel, MppProjectDataSourceNetwork, MppSearchProjectService, MppNetworkService, MppIosURLProtocol, MppIosHttpMethod, MppIosHttpClient, MppSearchProjectsEntity, MppJsonparser-nativeJsonElement, MppProjectEntity, MppProjectEntityOwner, MppProjectEntityOwnerCompanion, MppProjectEntityCompanion, MppSearchProjectsEntityCompanion, MppStdlibArray, MppStdlibThrowable, MppKotlinx-coroutines-core-nativeCancellationException, MppJsonparser-nativeJsonNull, MppJsonparser-nativeJsonPrimitive, MppStdlibIllegalStateException, MppStdlibRuntimeException, MppStdlibException, MppKotlinx-coroutines-core-nativeAtomicDesc, MppKotlinx-coroutines-core-nativeAtomicOp, MppKotlinx-coroutines-core-nativeOpDescriptor;

@protocol MppProjectRepository, MppKotlinx-coroutines-core-nativeDeferred, MppProjectDataSource, MppRequestParams, MppStdlibCoroutineContext, MppEntity, MppKotlinx-coroutines-core-nativeDisposableHandle, MppKotlinx-coroutines-core-nativeJob, MppStdlibCoroutineContextElement, MppStdlibCoroutineContextKey, MppStdlibSequence, MppKotlinx-coroutines-core-nativeSelectClause1, MppKotlinx-coroutines-core-nativeSelectClause0, MppIosCloseable, MppStdlibIterator, MppKotlinx-coroutines-core-nativeSelectInstance, MppStdlibSuspendFunction1, MppStdlibSuspendFunction0, MppStdlibContinuation, MppStdlibSuspendFunction;

NS_ASSUME_NONNULL_BEGIN

@interface KotlinBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end;

@interface KotlinBase (KotlinBaseCopying) <NSCopying>
@end;

__attribute__((objc_runtime_name("KotlinMutableSet")))
@interface MppMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end;

__attribute__((objc_runtime_name("KotlinMutableDictionary")))
@interface MppMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end;

@interface NSError (NSErrorKotlinException)
@property (readonly) id _Nullable kotlinException;
@end;

@protocol MppProjectRepository
@required
- (id<MppKotlinx-coroutines-core-nativeDeferred>)searchProjectParams:(MppSearchProjectInteractorParams *)params __attribute__((swift_name("searchProject(params:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface MppProjectRepositoryImpl : KotlinBase <MppProjectRepository>
- (instancetype)initWithNetwork:(id<MppProjectDataSource>)network __attribute__((swift_name("init(network:)"))) __attribute__((objc_designated_initializer));
@end;

@interface MppResult : KotlinBase
@end;

__attribute__((objc_subclassing_restricted))
@interface MppSuccess : MppResult
- (instancetype)initWithResult:(id _Nullable)result __attribute__((swift_name("init(result:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)component1 __attribute__((swift_name("component1()")));
- (MppSuccess *)doCopyResult:(id _Nullable)result __attribute__((swift_name("doCopy(result:)")));
@property (readonly) id _Nullable result;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppFailure : MppResult
- (instancetype)initWithErrorCode:(int32_t)errorCode message:(NSString *)message __attribute__((swift_name("init(errorCode:message:)"))) __attribute__((objc_designated_initializer));
- (int32_t)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (MppFailure *)doCopyErrorCode:(int32_t)errorCode message:(NSString *)message __attribute__((swift_name("doCopy(errorCode:message:)")));
@property (readonly) int32_t errorCode;
@property (readonly) NSString *message;
@end;

@protocol MppRequestParams
@required
- (NSDictionary<NSString *, NSString *> *)build __attribute__((swift_name("build()")));
@end;

@interface MppInteractor : KotlinBase
- (instancetype)initWithPreExecutionContext:(id<MppStdlibCoroutineContext>)preExecutionContext postExecutionContext:(id<MppStdlibCoroutineContext>)postExecutionContext __attribute__((swift_name("init(preExecutionContext:postExecutionContext:)"))) __attribute__((objc_designated_initializer));
- (id<MppKotlinx-coroutines-core-nativeDeferred>)buildParams:(id<MppRequestParams> _Nullable)params __attribute__((swift_name("build(params:)")));
- (void)executeParams:(id<MppRequestParams> _Nullable)params completion:(MppStdlibUnit *(^)(MppResult *))completion __attribute__((swift_name("execute(params:completion:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface MppSearchProjectInteractor : MppInteractor
- (instancetype)initWithRepository:(id<MppProjectRepository>)repository preExecutionContext:(id<MppStdlibCoroutineContext>)preExecutionContext postExecutionContext:(id<MppStdlibCoroutineContext>)postExecutionContext __attribute__((swift_name("init(repository:preExecutionContext:postExecutionContext:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPreExecutionContext:(id<MppStdlibCoroutineContext>)preExecutionContext postExecutionContext:(id<MppStdlibCoroutineContext>)postExecutionContext __attribute__((swift_name("init(preExecutionContext:postExecutionContext:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (id<MppKotlinx-coroutines-core-nativeDeferred>)buildParams:(MppSearchProjectInteractorParams * _Nullable)params __attribute__((swift_name("build(params:)")));
- (void)executeParams:(MppSearchProjectInteractorParams * _Nullable)params completion:(MppStdlibUnit *(^)(MppResult *))completion __attribute__((swift_name("execute(params:completion:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface MppSearchProjectInteractorParams : KotlinBase <MppRequestParams>
- (instancetype)initWithKeyword:(NSString *)keyword __attribute__((swift_name("init(keyword:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *keyword;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppProject : KotlinBase
- (instancetype)initWithTitle:(NSString *)title desc:(NSString *)desc author:(NSString *)author avatarUrl:(NSString *)avatarUrl pageUrl:(NSString *)pageUrl __attribute__((swift_name("init(title:desc:author:avatarUrl:pageUrl:)"))) __attribute__((objc_designated_initializer));
- (MppProjectItemViewModel *)mapToViewModel __attribute__((swift_name("mapToViewModel()")));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (NSString *)component3 __attribute__((swift_name("component3()")));
- (NSString *)component4 __attribute__((swift_name("component4()")));
- (NSString *)component5 __attribute__((swift_name("component5()")));
- (MppProject *)doCopyTitle:(NSString *)title desc:(NSString *)desc author:(NSString *)author avatarUrl:(NSString *)avatarUrl pageUrl:(NSString *)pageUrl __attribute__((swift_name("doCopy(title:desc:author:avatarUrl:pageUrl:)")));
@property (readonly) NSString *title;
@property (readonly) NSString *desc;
@property (readonly) NSString *author;
@property (readonly) NSString *avatarUrl;
@property (readonly) NSString *pageUrl;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppProjectItemViewModel : KotlinBase
- (instancetype)initWithTitle:(NSString *)title desc:(NSString *)desc author:(NSString *)author avatarUrl:(NSString *)avatarUrl pageUrl:(NSString *)pageUrl __attribute__((swift_name("init(title:desc:author:avatarUrl:pageUrl:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (NSString *)component3 __attribute__((swift_name("component3()")));
- (NSString *)component4 __attribute__((swift_name("component4()")));
- (NSString *)component5 __attribute__((swift_name("component5()")));
- (MppProjectItemViewModel *)doCopyTitle:(NSString *)title desc:(NSString *)desc author:(NSString *)author avatarUrl:(NSString *)avatarUrl pageUrl:(NSString *)pageUrl __attribute__((swift_name("doCopy(title:desc:author:avatarUrl:pageUrl:)")));
@property (readonly) NSString *title;
@property (readonly) NSString *desc;
@property (readonly) NSString *author;
@property (readonly) NSString *avatarUrl;
@property (readonly) NSString *pageUrl;
@end;

@protocol MppProjectDataSource <MppProjectRepository>
@required
@end;

__attribute__((objc_subclassing_restricted))
@interface MppProjectDataSourceNetwork : KotlinBase <MppProjectDataSource>
- (instancetype)initWithSearchProjectService:(MppSearchProjectService *)searchProjectService __attribute__((swift_name("init(searchProjectService:)"))) __attribute__((objc_designated_initializer));
@end;

@interface MppNetworkService : KotlinBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id _Nullable)parseJson:(NSString *)json __attribute__((swift_name("parse(json:)")));
- (id<MppKotlinx-coroutines-core-nativeDeferred>)requestJsonParams:(NSDictionary<NSString *, NSString *> *)params __attribute__((swift_name("requestJson(params:)")));
@property (readonly) MppIosURLProtocol *protocol;
@property (readonly) int32_t port;
@property (readonly) NSString *baseUrl;
@property (readonly) MppIosHttpMethod *httpMethod;
@property (readonly) NSString * _Nullable requestBody;
@property (readonly) NSDictionary<NSString *, NSArray<NSString *> *> *headers;
@property (readonly) NSString *path;
@property (readonly) MppIosHttpClient *client;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppSearchProjectService : MppNetworkService
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (MppSearchProjectsEntity *)parseJson:(NSString *)json __attribute__((swift_name("parse(json:)")));
@end;

@protocol MppEntity
@required
- (void)parseJsonObject:(NSDictionary<NSString *, MppJsonparser-nativeJsonElement *> *)jsonObject __attribute__((swift_name("parse(jsonObject:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface MppProjectEntity : KotlinBase <MppEntity>
- (MppProject *)mapToProject __attribute__((swift_name("mapToProject()")));
- (NSString * _Nullable)component1 __attribute__((swift_name("component1()")));
- (MppProjectEntityOwner * _Nullable)component2 __attribute__((swift_name("component2()")));
- (NSString * _Nullable)component3 __attribute__((swift_name("component3()")));
- (NSString * _Nullable)component4 __attribute__((swift_name("component4()")));
- (MppProjectEntity *)doCopyFullName:(NSString * _Nullable)fullName owner:(MppProjectEntityOwner * _Nullable)owner desc:(NSString * _Nullable)desc htmlUrl:(NSString * _Nullable)htmlUrl __attribute__((swift_name("doCopy(fullName:owner:desc:htmlUrl:)")));
@property NSString * _Nullable fullName;
@property MppProjectEntityOwner * _Nullable owner;
@property NSString * _Nullable desc;
@property NSString * _Nullable htmlUrl;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppProjectEntityOwner : KotlinBase <MppEntity>
- (NSString * _Nullable)component1 __attribute__((swift_name("component1()")));
- (NSString * _Nullable)component2 __attribute__((swift_name("component2()")));
- (MppProjectEntityOwner *)doCopyLogin:(NSString * _Nullable)login avatarUrl:(NSString * _Nullable)avatarUrl __attribute__((swift_name("doCopy(login:avatarUrl:)")));
@property NSString * _Nullable login;
@property NSString * _Nullable avatarUrl;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppProjectEntityOwnerCompanion : KotlinBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (MppProjectEntityOwner *)createJsonObject:(NSDictionary<NSString *, MppJsonparser-nativeJsonElement *> *)jsonObject __attribute__((swift_name("create(jsonObject:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface MppProjectEntityCompanion : KotlinBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (MppProjectEntity *)createJsonObject:(NSDictionary<NSString *, MppJsonparser-nativeJsonElement *> *)jsonObject __attribute__((swift_name("create(jsonObject:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface MppSearchProjectsEntity : KotlinBase <MppEntity>
- (NSArray<MppProjectEntity *> *)component1 __attribute__((swift_name("component1()")));
- (NSNumber * _Nullable)component2 __attribute__((swift_name("component2()")));
- (NSNumber * _Nullable)component3 __attribute__((swift_name("component3()")));
- (MppSearchProjectsEntity *)doCopyItems:(NSArray<MppProjectEntity *> *)items total:(NSNumber * _Nullable)total incompleteResults:(NSNumber * _Nullable)incompleteResults __attribute__((swift_name("doCopy(items:total:incompleteResults:)")));
@property NSArray<MppProjectEntity *> *items;
@property NSNumber * _Nullable total;
@property NSNumber * _Nullable incompleteResults;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppSearchProjectsEntityCompanion : KotlinBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (MppSearchProjectsEntity *)createJsonObject:(NSDictionary<NSString *, MppJsonparser-nativeJsonElement *> *)jsonObject __attribute__((swift_name("create(jsonObject:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface Mpp : KotlinBase
+ (void)mainArgs:(MppStdlibArray *)args __attribute__((swift_name("main(args:)")));
@end;

@protocol MppStdlibCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<MppStdlibCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<MppStdlibCoroutineContextElement> _Nullable)getKey:(id<MppStdlibCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<MppStdlibCoroutineContext>)minusKeyKey:(id<MppStdlibCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<MppStdlibCoroutineContext>)plusContext:(id<MppStdlibCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end;

@protocol MppStdlibCoroutineContextElement <MppStdlibCoroutineContext>
@required
@property (readonly) id<MppStdlibCoroutineContextKey> key;
@end;

@protocol MppKotlinx-coroutines-core-nativeJob <MppStdlibCoroutineContextElement>
@required
- (id<MppKotlinx-coroutines-core-nativeDisposableHandle>)attachChildChild:(id<MppKotlinx-coroutines-core-nativeJob>)child __attribute__((swift_name("attachChild(child:)")));
- (BOOL)cancelCause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));
- (void)cancelChildrenCause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("cancelChildren(cause:)")));
- (MppKotlinx-coroutines-core-nativeCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (MppStdlibThrowable *)getCompletionException __attribute__((swift_name("getCompletionException()")));
- (id<MppKotlinx-coroutines-core-nativeDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(MppStdlibUnit *(^)(MppStdlibThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));
- (id<MppKotlinx-coroutines-core-nativeDisposableHandle>)invokeOnCompletionOnCancelling_:(BOOL)onCancelling_ handler:(MppStdlibUnit *(^)(MppStdlibThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling_:handler:)")));
- (id<MppKotlinx-coroutines-core-nativeDisposableHandle>)invokeOnCompletionHandler:(MppStdlibUnit *(^)(MppStdlibThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));
- (id<MppKotlinx-coroutines-core-nativeDisposableHandle>)invokeOnCompletionHandler:(MppStdlibUnit *(^)(MppStdlibThrowable * _Nullable))handler onCancelling:(BOOL)onCancelling __attribute__((swift_name("invokeOnCompletion(handler:onCancelling:)")));
- (id<MppKotlinx-coroutines-core-nativeJob>)plusOther:(id<MppKotlinx-coroutines-core-nativeJob>)other __attribute__((swift_name("plus(other:)")));
- (BOOL)start __attribute__((swift_name("start()")));
@property (readonly) id<MppStdlibSequence> children;
@property (readonly) BOOL isActive;
@property (readonly) BOOL isCancelled;
@property (readonly) BOOL isCompleted;
@property (readonly) id<MppKotlinx-coroutines-core-nativeSelectClause0> onJoin;
@end;

@protocol MppKotlinx-coroutines-core-nativeDeferred <MppKotlinx-coroutines-core-nativeJob>
@required
- (id _Nullable)getCompleted __attribute__((swift_name("getCompleted()")));
- (MppStdlibThrowable * _Nullable)getCompletionExceptionOrNull __attribute__((swift_name("getCompletionExceptionOrNull()")));
@property (readonly) BOOL isCompletedExceptionally;
@property (readonly) BOOL isComputing;
@property (readonly) id<MppKotlinx-coroutines-core-nativeSelectClause1> onAwait;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppStdlibUnit : KotlinBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
@interface MppIosURLProtocol : KotlinBase
- (instancetype)initWithName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("init(name:defaultPort:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (int32_t)component2 __attribute__((swift_name("component2()")));
- (MppIosURLProtocol *)doCopyName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("doCopy(name:defaultPort:)")));
@property (readonly) int32_t defaultPort;
@property (readonly) NSString *name;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppIosHttpMethod : KotlinBase
- (instancetype)initWithValue:(NSString *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (MppIosHttpMethod *)doCopyValue:(NSString *)value __attribute__((swift_name("doCopy(value:)")));
@property (readonly) NSString *value;
@end;

@protocol MppIosCloseable
@required
- (void)close __attribute__((swift_name("close()")));
@end;

__attribute__((objc_subclassing_restricted))
@interface MppIosHttpClient : KotlinBase <MppIosCloseable>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end;

@interface MppJsonparser-nativeJsonElement : KotlinBase
@property (readonly) BOOL isNull;
@property (readonly) NSArray<MppJsonparser-nativeJsonElement *> *jsonArray;
@property (readonly) MppJsonparser-nativeJsonNull *jsonNull;
@property (readonly) NSDictionary<NSString *, MppJsonparser-nativeJsonElement *> *jsonObject;
@property (readonly) MppJsonparser-nativeJsonPrimitive *primitive;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppStdlibArray : KotlinBase
+ (instancetype)arrayWithSize:(int32_t)size init:(id _Nullable (^)(NSNumber *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (id _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<MppStdlibIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(id _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size;
@end;

@protocol MppKotlinx-coroutines-core-nativeDisposableHandle
@required
- (void)dispose __attribute__((swift_name("dispose()")));
@end;

@interface MppStdlibThrowable : KotlinBase
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
@property (readonly) MppStdlibThrowable * _Nullable cause;
@property (readonly) NSString * _Nullable message;
@end;

@protocol MppStdlibCoroutineContextKey
@required
@end;

@interface MppStdlibException : MppStdlibThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end;

@interface MppStdlibRuntimeException : MppStdlibException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end;

@interface MppStdlibIllegalStateException : MppStdlibRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end;

@interface MppKotlinx-coroutines-core-nativeCancellationException : MppStdlibIllegalStateException
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MppStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end;

@protocol MppStdlibSequence
@required
- (id<MppStdlibIterator>)iterator __attribute__((swift_name("iterator()")));
@end;

@protocol MppKotlinx-coroutines-core-nativeSelectClause1
@required
- (void)registerSelectClause1Select:(id<MppKotlinx-coroutines-core-nativeSelectInstance>)select block:(id<MppStdlibSuspendFunction1>)block __attribute__((swift_name("registerSelectClause1(select:block:)")));
@end;

@protocol MppKotlinx-coroutines-core-nativeSelectClause0
@required
- (void)registerSelectClause0Select:(id<MppKotlinx-coroutines-core-nativeSelectInstance>)select block:(id<MppStdlibSuspendFunction0>)block __attribute__((swift_name("registerSelectClause0(select:block:)")));
@end;

@interface MppJsonparser-nativeJsonPrimitive : MppJsonparser-nativeJsonElement
@property (readonly) BOOL boolean;
@property (readonly) NSNumber * _Nullable booleanOrNull;
@property (readonly) NSString *content;
@property (readonly) NSString * _Nullable contentOrNull;
@property (readonly) double double;
@property (readonly) NSNumber * _Nullable doubleOrNull;
@property (readonly) float float;
@property (readonly) NSNumber * _Nullable floatOrNull;
@property (readonly) int32_t int;
@property (readonly) NSNumber * _Nullable intOrNull;
@property (readonly) int64_t long;
@property (readonly) NSNumber * _Nullable longOrNull;
@end;

__attribute__((objc_subclassing_restricted))
@interface MppJsonparser-nativeJsonNull : MppJsonparser-nativeJsonPrimitive
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)jsonNull __attribute__((swift_name("init()")));
@end;

@protocol MppStdlibIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end;

@protocol MppKotlinx-coroutines-core-nativeSelectInstance
@required
- (void)disposeOnSelectHandle:(id<MppKotlinx-coroutines-core-nativeDisposableHandle>)handle __attribute__((swift_name("disposeOnSelect(handle:)")));
- (id _Nullable)performAtomicIfNotSelectedDesc:(MppKotlinx-coroutines-core-nativeAtomicDesc *)desc __attribute__((swift_name("performAtomicIfNotSelected(desc:)")));
- (id _Nullable)performAtomicTrySelectDesc:(MppKotlinx-coroutines-core-nativeAtomicDesc *)desc __attribute__((swift_name("performAtomicTrySelect(desc:)")));
- (void)resumeSelectCancellableWithExceptionException:(MppStdlibThrowable *)exception __attribute__((swift_name("resumeSelectCancellableWithException(exception:)")));
- (BOOL)trySelectIdempotent:(id _Nullable)idempotent __attribute__((swift_name("trySelect(idempotent:)")));
@property (readonly) id<MppStdlibContinuation> completion;
@property (readonly) BOOL isSelected;
@end;

@protocol MppStdlibSuspendFunction
@required
@end;

@protocol MppStdlibSuspendFunction1 <MppStdlibSuspendFunction>
@required
@end;

@protocol MppStdlibSuspendFunction0 <MppStdlibSuspendFunction>
@required
@end;

@interface MppKotlinx-coroutines-core-nativeAtomicDesc : KotlinBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)completeOp:(MppKotlinx-coroutines-core-nativeAtomicOp *)op failure:(id _Nullable)failure __attribute__((swift_name("complete(op:failure:)")));
- (id _Nullable)prepareOp:(MppKotlinx-coroutines-core-nativeAtomicOp *)op __attribute__((swift_name("prepare(op:)")));
@end;

@protocol MppStdlibContinuation
@required
- (void)resumeValue:(id _Nullable)value __attribute__((swift_name("resume(value:)")));
- (void)resumeWithExceptionException:(MppStdlibThrowable *)exception __attribute__((swift_name("resumeWithException(exception:)")));
@property (readonly) id<MppStdlibCoroutineContext> context;
@end;

@interface MppKotlinx-coroutines-core-nativeOpDescriptor : KotlinBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id _Nullable)performAffected:(id _Nullable)affected __attribute__((swift_name("perform(affected:)")));
@end;

@interface MppKotlinx-coroutines-core-nativeAtomicOp : MppKotlinx-coroutines-core-nativeOpDescriptor
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)completeAffected:(id _Nullable)affected failure:(id _Nullable)failure __attribute__((swift_name("complete(affected:failure:)")));
- (id _Nullable)prepareAffected:(id _Nullable)affected __attribute__((swift_name("prepare(affected:)")));
- (BOOL)tryDecideDecision:(id _Nullable)decision __attribute__((swift_name("tryDecide(decision:)")));
@property (readonly) BOOL isDecided;
@end;

NS_ASSUME_NONNULL_END
