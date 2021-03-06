//
//  TICDSDropboxSDKBasedVacuumOperation.h
//  iOSNotebook
//
//  Created by Tim Isted on 15/05/2011.
//  Copyright 2011 Tim Isted. All rights reserved.
//

#if TARGET_OS_IPHONE

#import "TICDSVacuumOperation.h"

#import <DropboxSDK/DropboxSDK.h>

/**
 `TICDSDropboxSDKBasedVacuumOperation` is a vacuum operation designed for use with a `TICDSDropboxSDKBasedDocumentSyncManager`.
 */

@interface TICDSDropboxSDKBasedVacuumOperation : TICDSVacuumOperation <DBRestClientDelegate> {
@private
    DBSession *_dbSession;
    DBRestClient *_restClient;
    
    NSDate *_oldestStoreDate;
    NSUInteger _numberOfWholeStoresToCheck;
    NSUInteger _numberOfWholeStoresThatFailedToBeChecked;
    NSUInteger _numberOfWholeStoresChecked;
    
    NSUInteger _numberOfFilesToDelete;
    NSUInteger _numberOfFilesThatFailedToBeDeleted;
    NSUInteger _numberOfFilesDeleted;
    
    NSString *_thisDocumentWholeStoreDirectoryPath;
    NSString *_thisDocumentRecentSyncsDirectoryPath;
    NSString *_thisDocumentSyncChangesThisClientDirectoryPath;
}

/** @name Properties */

/** The DropboxSDK `DBSession` for use by this operation's `DBRestClient`. */
@property (retain) DBSession *dbSession;

/** The DropboxSDK `DBRestClient` for use by this operation for methods relating to the global application directory. */
@property (nonatomic, readonly) DBRestClient *restClient;

/** The Last Modified Date of the oldest WholeStore file. */
@property (nonatomic, retain) NSDate *oldestStoreDate;

/** @name Paths */

/** The path to a given client's `WholeStore.ticdsync` file within this document's `WholeStore` directory.
 
 @param anIdentifier The unique sync identifier for the client. */
- (NSString *)pathToWholeStoreFileForClientWithIdentifier:(NSString *)anIdentifier;

/** The path to this document's `WholeStore` directory. */
@property (retain) NSString *thisDocumentWholeStoreDirectoryPath;

/** The path to this document's `RecentSyncs` directory. */
@property (retain) NSString *thisDocumentRecentSyncsDirectoryPath;

/** The path to this client's directory inside the `RecentSyncs` directory for this document. */
@property (retain) NSString *thisDocumentSyncChangesThisClientDirectoryPath;

@end

#endif